#include "zoom_node_meeting_h323_ctrl.h"


ZoomNodeMeetingH323CtrlWrap::ZoomNodeMeetingH323CtrlWrap()
{
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingH323Ctrl().SetSink(&_g_node_meetingH323_cb);
}

ZoomNodeMeetingH323CtrlWrap::~ZoomNodeMeetingH323CtrlWrap()
{
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingH323Ctrl().SetSink(NULL);
}
void ZoomNodeMeetingH323CtrlWrap::CallOutH323(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 5) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments")));
		return;
	}

	if (!args[0]->IsString() ||
		!args[1]->IsString() ||
		!args[2]->IsString() ||
		!args[3]->IsNumber() ||
		!args[4]->IsFunction()
		)
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments")));
		return;
	}

	ZoomSTRING zn_deviceName;
	zoom_v8toc(args[0].As<v8::String>(), zn_deviceName);
	ZoomSTRING zn_deviceIP;
	zoom_v8toc(args[1].As<v8::String>(), zn_deviceIP);
	ZoomSTRING zn_deviceE164num;
	zoom_v8toc(args[2].As<v8::String>(), zn_deviceE164num);
	ZNH323DeviceType zn_type;
	zn_type = (ZNH323DeviceType)args[3].As<v8::Integer >()->Value();

	v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[4]);
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
	ZoomNodeSinkHelper::GetInst().onH323CalloutStatusNotify = cb;

	ZNSDKError err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingH323Ctrl().CallOutH323(zn_deviceName, zn_deviceIP, zn_deviceE164num, zn_type);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingH323CtrlWrap::CancelCallOutH323(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments")));
		return;
	}

	if (!args[0]->IsFunction()
		)
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments")));
		return;
	}


	v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
	ZoomNodeSinkHelper::GetInst().onH323CalloutStatusNotify = cb;

	ZNSDKError err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingH323Ctrl().CancelCallOutH323();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingH323CtrlWrap::GetH323Address(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();

	ZNList<ZoomSTRING> h323AddressList = _g_native_wrap.GetMeetingServiceWrap().GetMeetingH323Ctrl().GetH323Address();
	
	v8::Local<v8::Array> nodes = v8::Array::New(isolate);
	for (int i = 0; i < h323AddressList.getLength(); ++i) {
		v8::HandleScope scope(isolate);
		v8::Local<v8::Object> node = v8::Object::New(isolate);
		node->Set(v8::String::NewFromUtf8(isolate, "H323Address"), v8::String::NewFromUtf8(isolate, zs2s(h323AddressList.get(i)).c_str()));
		nodes->Set(i, node);
	}
	args.GetReturnValue().Set(nodes);
}
void ZoomNodeMeetingH323CtrlWrap::GetH323Password(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZoomSTRING zn_h323Password;
	zn_h323Password = _g_native_wrap.GetMeetingServiceWrap().GetMeetingH323Ctrl().GetH323Password();

	v8::Local<v8::String> bret = v8::String::NewFromUtf8(isolate, zs2s(zn_h323Password).c_str());
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingH323CtrlWrap::GetCalloutH323DviceList(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();

	ZNList<ZNH323DeviecInfo> h323DeviceList = _g_native_wrap.GetMeetingServiceWrap().GetMeetingH323Ctrl().GetCalloutH323DviceList();

	v8::Local<v8::Array> nodes = v8::Array::New(isolate);
	for (int i = 0; i < h323DeviceList.getLength(); ++i) {
		v8::HandleScope scope(isolate);
		v8::Local<v8::Object> node = v8::Object::New(isolate);
		node->Set(v8::String::NewFromUtf8(isolate, "H323DeviceName"), v8::String::NewFromUtf8(isolate, zs2s(h323DeviceList.get(i).h323_deviceName).c_str()));
		node->Set(v8::String::NewFromUtf8(isolate, "H323DeviceIP"), v8::String::NewFromUtf8(isolate, zs2s(h323DeviceList.get(i).h323_deviceIP).c_str()));
		node->Set(v8::String::NewFromUtf8(isolate, "H323DeviceE164Name"), v8::String::NewFromUtf8(isolate, zs2s(h323DeviceList.get(i).h323_deviceE164Name).c_str()));
		node->Set(v8::String::NewFromUtf8(isolate, "H323DeviceType"), v8::Integer::New(isolate, (int32_t)h323DeviceList.get(i).h323_DeviceType));
		nodes->Set(i, node);
	}
	args.GetReturnValue().Set(nodes);
}
void ZoomNodeMeetingH323CtrlWrap::SetH323CallOutStatusCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments")));
		return;
	}

	if (!args[0]->IsFunction()
		)
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments")));
		return;
	}

	v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
	ZoomNodeSinkHelper::GetInst().onH323CalloutStatusNotify = cb;

	ZNSDKError err = ZNSDKERR_SUCCESS;
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
