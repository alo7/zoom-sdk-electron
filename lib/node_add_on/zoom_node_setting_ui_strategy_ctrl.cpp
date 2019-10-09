#include "zoom_node_setting_ui_strategy_ctrl.h"


ZoomNodeSettingUIStrategyCtrlWrap::ZoomNodeSettingUIStrategyCtrlWrap()
{

}

ZoomNodeSettingUIStrategyCtrlWrap::~ZoomNodeSettingUIStrategyCtrlWrap()
{

}
void ZoomNodeSettingUIStrategyCtrlWrap::DisableAdvancedFeatures4GeneralSetting(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments")));
		return;
	}

	if (!args[0]->IsBoolean())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments")));
		return;
	}

	bool zn_bDisable;
	zoom_v8toc(args[0].As<v8::Boolean>(), zn_bDisable);

	ZNSDKError err = ZNSDKERR_SUCCESS;
	_g_native_wrap.GetSettingServiceWrap().GetSettingStrategyCtrl().DisableAdvancedFeatures4GeneralSetting(zn_bDisable);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingUIStrategyCtrlWrap::DisableAccountSettingTabPage(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments")));
		return;
	}

	if (!args[0]->IsBoolean())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments")));
		return;
	}

	bool zn_bDisable;
	zoom_v8toc(args[0].As<v8::Boolean>(), zn_bDisable);

	ZNSDKError err = ZNSDKERR_SUCCESS;
	_g_native_wrap.GetSettingServiceWrap().GetSettingStrategyCtrl().DisableAccountSettingTabPage(zn_bDisable);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingUIStrategyCtrlWrap::ConfSettingDialogShownTabPage(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 9) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments")));
		return;
	}

	if (!args[0]->IsBoolean() ||
		!args[1]->IsBoolean() ||
		!args[2]->IsBoolean() ||
		!args[3]->IsBoolean() ||
		!args[4]->IsBoolean() ||
		!args[5]->IsBoolean() ||
		!args[6]->IsBoolean() ||
		!args[7]->IsBoolean() ||
		!args[8]->IsBoolean()
		)
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments")));
		return;
	}
	ZNSettingDlgShowTabPageOption zn_settingDlgShowTabPageOption;
	zoom_v8toc(args[0].As<v8::Boolean>(), zn_settingDlgShowTabPageOption.z_bShowAccessibility);
	zoom_v8toc(args[1].As<v8::Boolean>(), zn_settingDlgShowTabPageOption.z_bShowAdvancedFeature);
	zoom_v8toc(args[2].As<v8::Boolean>(), zn_settingDlgShowTabPageOption.z_bShowAudio);
	zoom_v8toc(args[3].As<v8::Boolean>(), zn_settingDlgShowTabPageOption.z_bShowFeedback);
	zoom_v8toc(args[4].As<v8::Boolean>(), zn_settingDlgShowTabPageOption.z_bShowGeneral);
	zoom_v8toc(args[5].As<v8::Boolean>(), zn_settingDlgShowTabPageOption.z_bSHowRecording);
	zoom_v8toc(args[6].As<v8::Boolean>(), zn_settingDlgShowTabPageOption.z_bShowStatistics);
	zoom_v8toc(args[7].As<v8::Boolean>(), zn_settingDlgShowTabPageOption.z_bShowVideo);
	zoom_v8toc(args[8].As<v8::Boolean>(), zn_settingDlgShowTabPageOption.z_bShowVirtualBackGround);
	
	ZNSDKError err = ZNSDKERR_SUCCESS;
	_g_native_wrap.GetSettingServiceWrap().GetSettingStrategyCtrl().ConfSettingDialogShownTabPage(zn_settingDlgShowTabPageOption);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
