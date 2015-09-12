﻿/***********************************************************************
Vczh Library++ 3.0
Developer: Zihan Chen(vczh)
GacUI::VScrollTemplate

This file is generated by: Vczh GacUI Resource Code Generator
***********************************************************************/

#ifndef VCZH_GACUI_RESOURCE_CODE_GENERATOR_GacStudioUI_VScrollTemplate
#define VCZH_GACUI_RESOURCE_CODE_GENERATOR_GacStudioUI_VScrollTemplate

#include "GacStudioUIPartialClasses.h"

namespace darkskin
{
	class VScrollTemplate : public darkskin::VScrollTemplate_<darkskin::VScrollTemplate>
	{
		friend class darkskin::VScrollTemplate_<darkskin::VScrollTemplate>;
		friend struct vl::reflection::description::CustomTypeDescriptorSelector<darkskin::VScrollTemplate>;
	protected:

		// #region CLASS_MEMBER_GUIEVENT_HANDLER (DO NOT PUT OTHER CONTENT IN THIS #region.)
		void OnHandleMouseDown(GuiGraphicsComposition* sender, vl::presentation::compositions::GuiMouseEventArgs& arguments);
		void OnHandleMouseMove(GuiGraphicsComposition* sender, vl::presentation::compositions::GuiMouseEventArgs& arguments);
		void OnHandleMouseUp(GuiGraphicsComposition* sender, vl::presentation::compositions::GuiMouseEventArgs& arguments);
		// #endregion CLASS_MEMBER_GUIEVENT_HANDLER
	public:
		VScrollTemplate();
	};
}

#endif
