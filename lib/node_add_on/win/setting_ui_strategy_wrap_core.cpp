
#include "../setting_ui_strategy_wrap_core.h"
#include "wrap/sdk_wrap.h"
#include "zoom_native_to_wrap.h"

ZSettingUIStrategyWrap::ZSettingUIStrategyWrap()
{
	
}
ZSettingUIStrategyWrap::~ZSettingUIStrategyWrap()
{
	Uninit();
}
void ZSettingUIStrategyWrap::Init()
{
	
}
void ZSettingUIStrategyWrap::Uninit()
{
	
}
void ZSettingUIStrategyWrap::DisableAdvancedFeatures4GeneralSetting(bool bDisable)
{
	ZOOM_SDK_NAMESPACE::ISettingUIStrategy* pSettingUIStrategy = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().GetSettingUIStrategy();
	if (pSettingUIStrategy)
	{
		pSettingUIStrategy->DisableAdvancedFeatures4GeneralSetting(bDisable);
	}
}
void ZSettingUIStrategyWrap::DisableAccountSettingTabPage(bool bDisable)
{
	ZOOM_SDK_NAMESPACE::ISettingUIStrategy* pSettingUIStrategy = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().GetSettingUIStrategy();
	if (pSettingUIStrategy)
	{
		pSettingUIStrategy->DisableAccountSettingTabPage(bDisable);
	}
}
void ZSettingUIStrategyWrap::ConfSettingDialogShownTabPage(ZNSettingDlgShowTabPageOption showOption)
{
	ZOOM_SDK_NAMESPACE::SettingDlgShowTabPageOption sdk_showOption;
	sdk_showOption.bShowAccessibility = showOption.z_bShowAccessibility;
	sdk_showOption.bShowAdvancedFeature = showOption.z_bShowAdvancedFeature;
	sdk_showOption.bShowAudio = showOption.z_bShowAudio;
	sdk_showOption.bShowFeedback = showOption.z_bShowFeedback;
	sdk_showOption.bShowGeneral = showOption.z_bShowGeneral;
	sdk_showOption.bSHowRecording = showOption.z_bSHowRecording;
	sdk_showOption.bShowStatistics = showOption.z_bShowStatistics;
	sdk_showOption.bShowVideo = showOption.z_bShowVideo;
	sdk_showOption.bShowVirtualBackGround = showOption.z_bShowVirtualBackGround;
	ZOOM_SDK_NAMESPACE::ISettingUIStrategy* pSettingUIStrategy = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().GetSettingUIStrategy();
	if (pSettingUIStrategy)
	{
		pSettingUIStrategy->ConfSettingDialogShownTabPage(sdk_showOption);
	}
}
