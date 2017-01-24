/***********************************************************************
!!!!!! DO NOT MODIFY !!!!!!

Source: Host.sln

This file is generated by Workflow compiler
https://github.com/vczh-libraries
***********************************************************************/

#ifndef VCZH_WORKFLOW_COMPILER_GENERATED_DEMO
#define VCZH_WORKFLOW_COMPILER_GENERATED_DEMO

#include "../../../../Source/GacUI.h"
#ifndef VCZH_DEBUG_NO_REFLECTION
#include "../../../../Source/Reflection/TypeDescriptors/GuiReflectionTemplates.h"
#include "../../../../Source/Reflection/TypeDescriptors/GuiReflectionEvents.h"
#endif

#if defined( _MSC_VER)
#pragma warning(push)
#pragma warning(disable:4250)
#elif defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wparentheses-equality"
#elif defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wparentheses-equality"
#endif

namespace vl_workflow_global
{
	class __vwsnc1_Demo_demo_MainWindowConstructor___vwsn_initialize_instance___vl_reflection_description_IValueSubscription;
	class __vwsnc2_Demo_demo_MainWindowConstructor___vwsn_initialize_instance__Subscribe__vl_reflection_description_IValueListener;
	struct __vwsnf1_Demo_demo_MainWindowConstructor___vwsn_initialize_instance__;
	struct __vwsnf2_Demo_demo_MainWindowConstructor___vwsn_initialize_instance__;
	struct __vwsnf3_Demo_demo_MainWindowConstructor___vwsn_initialize_instance__;
	struct __vwsnf5_Demo_demo_MainWindowConstructor___vwsn_initialize_instance__;
	struct __vwsnf6_Demo_demo_MainWindowConstructor___vwsn_initialize_instance__;
	struct __vwsno4_Demo_demo_MainWindowConstructor___vwsn_initialize_instance__;
}

namespace demo
{
	class MainWindowConstructor;
	class MainWindow;

	class MainWindowConstructor : public ::vl::Object, public ::vl::reflection::Description<MainWindowConstructor>
	{
		friend class ::vl_workflow_global::__vwsnc1_Demo_demo_MainWindowConstructor___vwsn_initialize_instance___vl_reflection_description_IValueSubscription;
		friend class ::vl_workflow_global::__vwsnc2_Demo_demo_MainWindowConstructor___vwsn_initialize_instance__Subscribe__vl_reflection_description_IValueListener;
		friend struct ::vl_workflow_global::__vwsnf1_Demo_demo_MainWindowConstructor___vwsn_initialize_instance__;
		friend struct ::vl_workflow_global::__vwsnf2_Demo_demo_MainWindowConstructor___vwsn_initialize_instance__;
		friend struct ::vl_workflow_global::__vwsnf3_Demo_demo_MainWindowConstructor___vwsn_initialize_instance__;
		friend struct ::vl_workflow_global::__vwsnf5_Demo_demo_MainWindowConstructor___vwsn_initialize_instance__;
		friend struct ::vl_workflow_global::__vwsnf6_Demo_demo_MainWindowConstructor___vwsn_initialize_instance__;
		friend struct ::vl_workflow_global::__vwsno4_Demo_demo_MainWindowConstructor___vwsn_initialize_instance__;
#ifndef VCZH_DEBUG_NO_REFLECTION
		friend struct ::vl::reflection::description::CustomTypeDescriptorSelector<MainWindowConstructor>;
#endif
	protected:
		::demo::MainWindow* self = static_cast<::demo::MainWindow*>(nullptr);
		::vl::presentation::controls::GuiSinglelineTextBox* textBoxS = static_cast<::vl::presentation::controls::GuiSinglelineTextBox*>(nullptr);
		::vl::presentation::controls::GuiMultilineTextBox* textBoxM = static_cast<::vl::presentation::controls::GuiMultilineTextBox*>(nullptr);
		::vl::presentation::controls::GuiDocumentLabel* documentTextBox = static_cast<::vl::presentation::controls::GuiDocumentLabel*>(nullptr);
		::vl::presentation::controls::GuiDocumentViewer* documentViewer = static_cast<::vl::presentation::controls::GuiDocumentViewer*>(nullptr);
		::vl::presentation::controls::GuiDocumentLabel* documentLabel = static_cast<::vl::presentation::controls::GuiDocumentLabel*>(nullptr);
		::vl::presentation::compositions::GuiTableComposition* __vwsn_precompile_0 = static_cast<::vl::presentation::compositions::GuiTableComposition*>(nullptr);
		::vl::presentation::compositions::GuiCellComposition* __vwsn_precompile_1 = static_cast<::vl::presentation::compositions::GuiCellComposition*>(nullptr);
		::vl::presentation::controls::GuiTab* __vwsn_precompile_2 = static_cast<::vl::presentation::controls::GuiTab*>(nullptr);
		::vl::presentation::controls::GuiTabPage* __vwsn_precompile_3 = static_cast<::vl::presentation::controls::GuiTabPage*>(nullptr);
		::vl::presentation::compositions::GuiTableComposition* __vwsn_precompile_4 = static_cast<::vl::presentation::compositions::GuiTableComposition*>(nullptr);
		::vl::presentation::compositions::GuiCellComposition* __vwsn_precompile_5 = static_cast<::vl::presentation::compositions::GuiCellComposition*>(nullptr);
		::vl::presentation::compositions::GuiBoundsComposition* __vwsn_precompile_6 = static_cast<::vl::presentation::compositions::GuiBoundsComposition*>(nullptr);
		::vl::presentation::compositions::GuiCellComposition* __vwsn_precompile_7 = static_cast<::vl::presentation::compositions::GuiCellComposition*>(nullptr);
		::vl::presentation::compositions::GuiBoundsComposition* __vwsn_precompile_8 = static_cast<::vl::presentation::compositions::GuiBoundsComposition*>(nullptr);
		::vl::presentation::controls::GuiTabPage* __vwsn_precompile_9 = static_cast<::vl::presentation::controls::GuiTabPage*>(nullptr);
		::vl::presentation::compositions::GuiTableComposition* __vwsn_precompile_10 = static_cast<::vl::presentation::compositions::GuiTableComposition*>(nullptr);
		::vl::presentation::compositions::GuiCellComposition* __vwsn_precompile_11 = static_cast<::vl::presentation::compositions::GuiCellComposition*>(nullptr);
		::vl::presentation::compositions::GuiBoundsComposition* __vwsn_precompile_12 = static_cast<::vl::presentation::compositions::GuiBoundsComposition*>(nullptr);
		::vl::presentation::compositions::GuiCellComposition* __vwsn_precompile_13 = static_cast<::vl::presentation::compositions::GuiCellComposition*>(nullptr);
		::vl::presentation::compositions::GuiBoundsComposition* __vwsn_precompile_14 = static_cast<::vl::presentation::compositions::GuiBoundsComposition*>(nullptr);
		::vl::presentation::compositions::GuiCellComposition* __vwsn_precompile_15 = static_cast<::vl::presentation::compositions::GuiCellComposition*>(nullptr);
		::vl::presentation::compositions::GuiBoundsComposition* __vwsn_precompile_16 = static_cast<::vl::presentation::compositions::GuiBoundsComposition*>(nullptr);
		::vl::presentation::compositions::GuiBoundsComposition* __vwsn_precompile_17 = static_cast<::vl::presentation::compositions::GuiBoundsComposition*>(nullptr);
		::vl::presentation::compositions::GuiCellComposition* __vwsn_precompile_18 = static_cast<::vl::presentation::compositions::GuiCellComposition*>(nullptr);
		::vl::presentation::controls::GuiButton* __vwsn_precompile_19 = static_cast<::vl::presentation::controls::GuiButton*>(nullptr);
		::vl::presentation::compositions::GuiCellComposition* __vwsn_precompile_20 = static_cast<::vl::presentation::compositions::GuiCellComposition*>(nullptr);
		::vl::presentation::controls::GuiButton* __vwsn_precompile_21 = static_cast<::vl::presentation::controls::GuiButton*>(nullptr);
		::vl::presentation::compositions::GuiCellComposition* __vwsn_precompile_22 = static_cast<::vl::presentation::compositions::GuiCellComposition*>(nullptr);
		::vl::presentation::controls::GuiButton* __vwsn_precompile_23 = static_cast<::vl::presentation::controls::GuiButton*>(nullptr);
		::vl::presentation::compositions::GuiBoundsComposition* __vwsn_precompile_24 = static_cast<::vl::presentation::compositions::GuiBoundsComposition*>(nullptr);
		void __vwsn_initialize_instance_(::demo::MainWindow* __vwsn_this_, ::vl::presentation::GuiResourcePathResolver* __vwsn_resolver_);
	public:
		MainWindowConstructor();
	};

}
/***********************************************************************
Global Variables and Functions
***********************************************************************/

namespace vl_workflow_global
{
	class Demo
	{
	public:

		::vl::presentation::FontProperties ChangeFontSize(::vl::presentation::FontProperties oldFont, ::vl::vint32_t deltaSize);

		static Demo& Instance();
	};
}

#if defined( _MSC_VER)
#pragma warning(pop)
#elif defined(__GNUC__)
#pragma GCC diagnostic pop
#elif defined(__clang__)
#pragma clang diagnostic pop
#endif

#endif
