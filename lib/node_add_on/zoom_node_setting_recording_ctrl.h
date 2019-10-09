#ifndef _ZOOM_NODE_SETTING_RECORDING_CTRL_H_
#define _ZOOM_NODE_SETTING_RECORDING_CTRL_H_
#include "zoom_node_common_include.h"
#include "zoom_native_sdk_wrap_core.h"
#include "zoom_singleton_wrap_class.h"

extern ZNativeSDKWrap _g_native_wrap;

class ZOOM_NODE_HIDE ZoomNodeSettingRecordingCtrlWrap :
	public ZoomWrapObject<ZoomNodeSettingRecordingCtrlWrap >
{
	friend class ZoomWrapObject<ZoomNodeSettingRecordingCtrlWrap >;
private:
	ZoomNodeSettingRecordingCtrlWrap();
	~ZoomNodeSettingRecordingCtrlWrap();
public:
	/// \brief Set the path to save the recording file.
	/// \param 1. szPath(string) Specify the path to save the recording file.
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	static void SetRecordingPath(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Get the path to save the recording file.
	/// \return The path to save the recording file.
	static void GetRecordingPath(const v8::FunctionCallbackInfo<v8::Value>& args);
	
	
	static v8::Persistent<v8::Function> constructor;
};
template<>
static void InitClassAttribute<ZoomNodeSettingRecordingCtrlWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomNodeSettingRecordingCtrlWrap"));
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetRecordingPath", ZoomNodeSettingRecordingCtrlWrap::SetRecordingPath);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetRecordingPath", ZoomNodeSettingRecordingCtrlWrap::GetRecordingPath);
	
}
template<>
static v8::Persistent<v8::Function>* GetConstructor<ZoomNodeSettingRecordingCtrlWrap >() {
	return &ZoomNodeSettingRecordingCtrlWrap::constructor;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



#endif
