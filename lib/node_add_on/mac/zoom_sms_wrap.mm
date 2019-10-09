
#include "../zoom_sdk_sms_helper_wrap_core.h"

ZSDKSMSHelperWrap::ZSDKSMSHelperWrap()
{
    
}

ZSDKSMSHelperWrap::~ZSDKSMSHelperWrap()
{
    
}

void ZSDKSMSHelperWrap::Init()
{
    
}

void ZSDKSMSHelperWrap::Uninit()
{
    
}

void ZSDKSMSHelperWrap::SetSink(ZNativeSDKSMSHelperWrapSink *pSink)
{
    
}

bool ZSDKSMSHelperWrap::EnableZoomAuthRealNameMeetingUIShown(bool enable)
{
    return false;
}

bool ZSDKSMSHelperWrap::GetResendSMSVerificationCodeHandler()
{
    return false;
}

bool ZSDKSMSHelperWrap::Retrieve(std::string country_code, std::string phone_number)
{
    return false;
}

bool ZSDKSMSHelperWrap::Retrieve_CancelAndLeaveMeeting()
{
    return false;
}

bool ZSDKSMSHelperWrap::GetReVerifySMSVerificationCodeHandler()
{
    return false;
}

bool ZSDKSMSHelperWrap::Verify(std::string country_code, std::string phone_number, std::string verification_code)
{
    return false;
}

bool ZSDKSMSHelperWrap::Verify_CancelAndLeaveMeeting()
{
    return false;
}

ZNList<ZNZoomRealNameAuthCountryInfo> ZSDKSMSHelperWrap::GetSupportPhoneNumberCountryList()
{
    ZNList<ZNZoomRealNameAuthCountryInfo> info;
    return info;
}


void ZSDKSMSHelperWrap::onNeedRealNameAuthMeetingNotification(std::string bind_phone_url, std::string signup_url){
    
}

void ZSDKSMSHelperWrap::onNeedRealNameAuthMeetingNotification(ZNList<ZNZoomRealNameAuthCountryInfo> support_country_list, std::string privacy_url)
{
    
}

void ZSDKSMSHelperWrap::onRetrieveSMSVerificationCodeResultNotification(ZNSMSVerificationCodeErr result){
    
}

void ZSDKSMSHelperWrap::onVerifySMSVerificationCodeResultNotification(ZNSMSVerificationCodeErr result){
    
}
