#include "GuiInstanceLoader_WorkflowCodegen.h"
#include "../../Reflection/TypeDescriptors/GuiReflectionEvents.h"
#include "../../Resources/GuiParserManager.h"

namespace vl
{
	namespace presentation
	{
		using namespace workflow;
		using namespace workflow::analyzer;
		using namespace reflection::description;
		using namespace collections;

/***********************************************************************
Workflow_CreateModuleWithUsings
***********************************************************************/

		Ptr<workflow::WfModule> Workflow_CreateModuleWithUsings(Ptr<GuiInstanceContext> context)
		{
			auto module = MakePtr<WfModule>();
			module->name.value = L"<auto-generated>";

			vint index = context->namespaces.Keys().IndexOf(GlobalStringKey());
			if (index != -1)
			{
				auto nss = context->namespaces.Values()[index];
				FOREACH(Ptr<GuiInstanceNamespace>, ns, nss->namespaces)
				{
					auto path = MakePtr<WfModuleUsingPath>();
					module->paths.Add(path);

					auto pathCode = ns->prefix + L"*" + ns->postfix;
					auto reading = pathCode.Buffer();
					while (reading)
					{
						auto delimiter = wcsstr(reading, L"::");
						auto begin = reading;
						auto end = delimiter ? delimiter : begin + wcslen(reading);

						auto wildcard = wcschr(reading, L'*');
						if (wildcard >= end)
						{
							wildcard = nullptr;
						}

						auto item = MakePtr<WfModuleUsingItem>();
						path->items.Add(item);
						if (wildcard)
						{
							if (begin < wildcard)
							{
								auto fragment = MakePtr<WfModuleUsingNameFragment>();
								item->fragments.Add(fragment);
								fragment->name.value = WString(begin, vint(wildcard - begin));
							}
							{
								auto fragment = MakePtr<WfModuleUsingWildCardFragment>();
								item->fragments.Add(fragment);
							}
							if (wildcard + 1 < end)
							{
								auto fragment = MakePtr<WfModuleUsingNameFragment>();
								item->fragments.Add(fragment);
								fragment->name.value = WString(wildcard + 1, vint(end - wildcard - 1));
							}
						}
						else if (begin < end)
						{
							auto fragment = MakePtr<WfModuleUsingNameFragment>();
							item->fragments.Add(fragment);
							fragment->name.value = WString(begin, vint(end - begin));
						}

						if (delimiter)
						{
							reading = delimiter + 2;
						}
						else
						{
							reading = nullptr;
						}
					}
				}
			}
			return module;
		}

/***********************************************************************
Workflow_InstallClass
***********************************************************************/

		Ptr<workflow::WfClassDeclaration> Workflow_InstallClass(const WString& className, Ptr<workflow::WfModule> module)
		{
			auto decls = &module->declarations;
			auto reading = className.Buffer();
			while (true)
			{
				auto delimiter = wcsstr(reading, L"::");
				if (delimiter)
				{
					auto ns = MakePtr<WfNamespaceDeclaration>();
					ns->name.value = WString(reading, delimiter - reading);
					decls->Add(ns);
					decls = &ns->declarations;
				}
				else
				{
					auto ctorClass = MakePtr<WfClassDeclaration>();
					ctorClass->kind = WfClassKind::Class;
					ctorClass->constructorType = WfConstructorType::Undefined;
					ctorClass->name.value = reading;
					decls->Add(ctorClass);
					return ctorClass;
				}
				reading = delimiter + 2;
			}
		}

/***********************************************************************
Workflow_InstallCtorClass
***********************************************************************/
		
		Ptr<workflow::WfBlockStatement> Workflow_InstallCtorClass(types::ResolvingResult& resolvingResult, Ptr<workflow::WfModule> module)
		{
			auto ctorClass = Workflow_InstallClass(resolvingResult.context->className + L"Constructor", module);
			Workflow_CreateVariablesForReferenceValues(ctorClass, resolvingResult);

			auto thisParam = MakePtr<WfFunctionArgument>();
			thisParam->name.value = L"<this>";
			{
				auto elementType = MakePtr<TypeDescriptorTypeInfo>(resolvingResult.rootTypeDescriptor, TypeInfoHint::Normal);
				auto pointerType = MakePtr<RawPtrTypeInfo>(elementType);

				thisParam->type = GetTypeFromTypeInfo(pointerType.Obj());
			}

			auto resolverParam = MakePtr<WfFunctionArgument>();
			resolverParam->name.value = L"<resolver>";
			{
				auto elementType = MakePtr<TypeDescriptorTypeInfo>(description::GetTypeDescriptor<GuiResourcePathResolver>(), TypeInfoHint::Normal);
				auto pointerType = MakePtr<RawPtrTypeInfo>(elementType);

				resolverParam->type = GetTypeFromTypeInfo(pointerType.Obj());
			}

			auto block = MakePtr<WfBlockStatement>();

			auto func = MakePtr<WfFunctionDeclaration>();
			func->anonymity = WfFunctionAnonymity::Named;
			func->name.value = L"<initialize-instance>";
			func->arguments.Add(thisParam);
			func->arguments.Add(resolverParam);
			func->returnType = GetTypeFromTypeInfo(TypeInfoRetriver<void>::CreateTypeInfo().Obj());
			func->statement = block;

			{
				auto att = MakePtr<WfAttribute>();
				att->category.value = L"cpp";
				att->name.value = L"Protected";
				func->attributes.Add(att);
			}

			auto member = MakePtr<WfClassMember>();
			member->kind = WfClassMemberKind::Normal;
			member->declaration = func;
			ctorClass->members.Add(member);

			return block;
		}

/***********************************************************************
Variable
***********************************************************************/

		void Workflow_CreatePointerVariable(Ptr<workflow::WfClassDeclaration> ctorClass, GlobalStringKey name, description::ITypeDescriptor* type, description::ITypeInfo* typeOverride)
		{
			auto var = MakePtr<WfVariableDeclaration>();
			var->name.value = name.ToString();

			{
				auto att = MakePtr<WfAttribute>();
				att->category.value = L"cpp";
				att->name.value = L"Protected";
				var->attributes.Add(att);
			}

			if (typeOverride)
			{
				var->type = GetTypeFromTypeInfo(typeOverride);
			}

			if (!var->type)
			{
				if (auto ctors = type->GetConstructorGroup())
				{
					if (ctors->GetMethodCount() > 0)
					{
						auto ctor = ctors->GetMethod(0);
						var->type = GetTypeFromTypeInfo(ctor->GetReturn());
					}
				}
			}

			if (!var->type)
			{
				auto elementType = MakePtr<TypeDescriptorTypeInfo>(type, TypeInfoHint::Normal);
				auto pointerType = MakePtr<RawPtrTypeInfo>(elementType);

				var->type = GetTypeFromTypeInfo(pointerType.Obj());
			}

			auto literal = MakePtr<WfLiteralExpression>();
			literal->value = WfLiteralValue::Null;
			var->expression = literal;

			auto member = MakePtr<WfClassMember>();
			member->kind = WfClassMemberKind::Normal;
			member->declaration = var;

			ctorClass->members.Add(member);
		}
		
		void Workflow_CreateVariablesForReferenceValues(Ptr<workflow::WfClassDeclaration> ctorClass, types::ResolvingResult& resolvingResult)
		{
			const auto& typeInfos = resolvingResult.typeInfos;
			for (vint i = 0; i < typeInfos.Count(); i++)
			{
				auto key = typeInfos.Keys()[i];
				auto value = typeInfos.Values()[i].typeDescriptor;

				ITypeInfo* typeOverride = nullptr;
				vint index = resolvingResult.typeOverrides.Keys().IndexOf(key);
				if (index != -1)
				{
					typeOverride = resolvingResult.typeOverrides.Values()[index].Obj();
				}
				Workflow_CreatePointerVariable(ctorClass, key, value, typeOverride);
			}
		}
	}
}