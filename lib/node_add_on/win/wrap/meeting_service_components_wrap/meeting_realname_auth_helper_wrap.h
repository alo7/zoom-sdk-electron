#pragma once
#include "../common_include.h"
BEGIN_ZOOM_SDK_NAMESPACE
class IMeetingServiceWrap;
IZoomRealNameAuthMeetingHelper* InitIZoomRealNameAuthMeetingHelperFunc(IZoomRealNameAuthMeetingEvent* pEvent, IMeetingServiceWrap* pOwner);
void UninitIZoomRealNameAuthMeetingHelperFunc(IZoomRealNameAuthMeetingHelper* obj);
BEGIN_CLASS_DEFINE_WITHCALLBACK(IZoomRealNameAuthMeetingHelper, IZoomRealNameAuthMeetingEvent)
NORMAL_CLASS(IZoomRealNameAuthMeetingHelper)
INIT_UNINIT_WITHEVENT_AND_OWNSERVICE(IZoomRealNameAuthMeetingHelper, IMeetingServiceWrap)

bool SetEvent(IZoomRealNameAuthMeetingEvent* pEvent)
{
	external_cb = pEvent;
	return true;
}

//virtual bool EnableZoomAuthRealNameMeetingUIShown(bool enable) = 0;
DEFINE_FUNC_1(EnableZoomAuthRealNameMeetingUIShown, bool, bool, enable)
//virtual IZoomRetrieveSMSVerificationCodeHandler* GetResendSMSVerificationCodeHandler() = 0;
DEFINE_FUNC_0(GetResendSMSVerificationCodeHandler, IZoomRetrieveSMSVerificationCodeHandler*)
//virtual IZoomVerifySMSVerificationCodeHandler* GetReVerifySMSVerificationCodeHandler() = 0;
DEFINE_FUNC_0(GetReVerifySMSVerificationCodeHandler, IZoomVerifySMSVerificationCodeHandler*)
//virtual IVector<IZoomRealNameAuthCountryInfo* >* GetSupportPhoneNumberCountryList() = 0;
DEFINE_FUNC_0(GetSupportPhoneNumberCountryList, IVector<IZoomRealNameAuthCountryInfo* >*)
/*
//virtual void onNeedRealNameAuthMeetingNotification(const zTCHAR* bind_phone_url, const zTCHAR* signup_url) = 0;
CallBack_FUNC_2(onNeedRealNameAuthMeetingNotification, const zTCHAR*, bind_phone_url, const zTCHAR*, signup_url);
//virtual void onNeedRealNameAuthMeetingNotification(IVector<IZoomRealNameAuthCountryInfo* >* support_country_list, const zTCHAR* privacy_url, IZoomRetrieveSMSVerificationCodeHandler* handler) = 0;
CallBack_FUNC_3(onNeedRealNameAuthMeetingNotification, IVector<IZoomRealNameAuthCountryInfo* >*, support_country_list, const zTCHAR*, privacy_url, IZoomRetrieveSMSVerificationCodeHandler*, handler);
*/
virtual void onNeedRealNameAuthMeetingNotification(const zTCHAR* bind_phone_url, const zTCHAR* signup_url)
{
	if (NULL != m_conNeedRealNameAuthMeetingNotification_2param)
		m_conNeedRealNameAuthMeetingNotification_2param(bind_phone_url, signup_url);
	if (NULL != external_cb)
		external_cb->onNeedRealNameAuthMeetingNotification(bind_phone_url, signup_url);
}
std::function<void(const zTCHAR*, const zTCHAR*)> m_conNeedRealNameAuthMeetingNotification_2param;

virtual void onNeedRealNameAuthMeetingNotification(IVector<IZoomRealNameAuthCountryInfo* >* support_country_list, const zTCHAR* privacy_url, IZoomRetrieveSMSVerificationCodeHandler* handler)
{
	if (NULL != m_conNeedRealNameAuthMeetingNotification_3param)
		m_conNeedRealNameAuthMeetingNotification_3param(support_country_list, privacy_url, handler);
	if (NULL != external_cb)
		external_cb->onNeedRealNameAuthMeetingNotification(support_country_list, privacy_url, handler);
}
std::function<void(IVector<IZoomRealNameAuthCountryInfo* >*, const zTCHAR*, IZoomRetrieveSMSVerificationCodeHandler*)> m_conNeedRealNameAuthMeetingNotification_3param;

//virtual void onRetrieveSMSVerificationCodeResultNotification(SMSVerificationCodeErr result, IZoomVerifySMSVerificationCodeHandler* handler) = 0;
CallBack_FUNC_2(onRetrieveSMSVerificationCodeResultNotification, SMSVerificationCodeErr, result, IZoomVerifySMSVerificationCodeHandler*, handler)
//virtual void onVerifySMSVerificationCodeResultNotification(SMSVerificationCodeErr result) = 0;
CallBack_FUNC_1(onVerifySMSVerificationCodeResultNotification, SMSVerificationCodeErr, result)

END_CLASS_DEFINE(IZoomRealNameAuthMeetingHelper)
END_ZOOM_SDK_NAMESPACE