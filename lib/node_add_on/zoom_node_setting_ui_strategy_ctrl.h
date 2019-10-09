#ifndef _ZOOM_NODE_SETTING_UI_STRATEGY_CTRL_H_
#define _ZOOM_NODE_SETTING_UI_STRATEGY_CTRL_H_
#include "zoom_node_common_include.h"
#include "zoom_native_sdk_wrap_core.h"
#include "zoom_singleton_wrap_class.h"

extern ZNativeSDKWrap _g_native_wrap;
class ZOOM_NODE_HIDE ZoomNodeSettingUIStrategyCtrlWrap :
	public ZoomWrapObject<ZoomNodeSettingUIStrategyCtrlWrap >
{
	friend class ZoomWrapObject<ZoomNodeSettingUIStrategyCtrlWrap >;
private:
	ZoomNodeSettingUIStrategyCtrlWrap();
	~ZoomNodeSettingUIStrategyCtrlWrap();
public:
	/// \brief Hide the link to check the advanced settings on the General Setting page or not.
	/// \param 1.bDisable(bool) TRUE indicates to hide the link.
	static void DisableAdvancedFeatures4GeneralSetting(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Hide the Account Setting page or not.
	/// \param 1.bDisable(bool) TRUE indicates to hide the account setting page.
	static void DisableAccountSettingTabPage(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Custome the tab page show or hide
	/// \param 1.bShowAccessibility(bool)  True indicates to show accessibility page.
	/// \param 2.bShowAdvancedFeature(bool) True indicates to show advance feature page.
	/// \param 3.bShowAudio(bool) True indicates to show audio page.
	/// \param 4.bShowFeedback(bool)  True indicates to show feed back page.
	/// \param 5.bShowGeneral(bool)  True indicates to show general page.
	/// \param 6.bSHowRecording(bool)  True indicates to show recording page.
	/// \param 7.bShowStatistics(bool)  True indicates to show staticstics page.
	/// \param 8.bShowVideo(bool)  True indicates to show video page.
	/// \param 9.bShowVirtualBackGround(bool)  True indicates to show virtual background page.
	static void ConfSettingDialogShownTabPage(const v8::FunctionCallbackInfo<v8::Value>& args);
	static v8::Persistent<v8::Function> constructor;
};
template<>
static void InitClassAttribute<ZoomNodeSettingUIStrategyCtrlWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomNodeSettingUIStrategyCtrlWrap"));
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	NODE_SET_PROTOTYPE_METHOD(tpl, "DisableAdvancedFeatures4GeneralSetting", ZoomNodeSettingUIStrategyCtrlWrap::DisableAdvancedFeatures4GeneralSetting);
	NODE_SET_PROTOTYPE_METHOD(tpl, "DisableAccountSettingTabPage", ZoomNodeSettingUIStrategyCtrlWrap::DisableAccountSettingTabPage);
	NODE_SET_PROTOTYPE_METHOD(tpl, "ConfSettingDialogShownTabPage", ZoomNodeSettingUIStrategyCtrlWrap::ConfSettingDialogShownTabPage);
}
template<>
static v8::Persistent<v8::Function>* GetConstructor<ZoomNodeSettingUIStrategyCtrlWrap >() {
	return &ZoomNodeSettingUIStrategyCtrlWrap::constructor;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#endif
