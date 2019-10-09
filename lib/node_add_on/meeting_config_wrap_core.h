#pragma once
#include "zoom_native_sdk_wrap_core_def.h"
#include "zoom_sinks_wrap_class.h"


class ZMeetingConfigWrap
{
public:
	ZMeetingConfigWrap();
	virtual ~ZMeetingConfigWrap();
	void Init();
	void Uninit();
	void SetSink(ZNativeSDKMeetingConfigWrapFreemeetingSink* pSink);

	ZNSDKError EnableInviteButtonOnMeetingUI(bool bEnable);
	void SetFloatVideoPos(ZNWndPosition position);
	void SetBottomFloatToolbarWndVisibility(bool bShow);
	void SetSharingToolbarVisibility(bool bShow);
	void SetDirectShareMonitorID(ZoomSTRING monitorID);
	void SetMeetingUIPos(ZNWndPosition position);
	void DisableWaitingForHostDialog(bool bDisable);
	void HideMeetingInfoFromMeetingUITitle(bool bHide);
	void SetMeetingIDForMeetingUITitle(unsigned long long meetingNumber);
	void DisablePopupMeetingWrongPSWDlg(bool bDisable);
	void EnableAutoEndOtherMeetingWhenStartMeeting(bool bEnable);
	void EnableLButtonDBClick4SwitchFullScreenMode(bool bEnable);
	void SetFloatVideoWndVisibility(bool bShow);
	void PrePopulateWebinarRegistrationInfo(ZoomSTRING email, ZoomSTRING userName);

	void Reset();
	void EnableAutoAdjustSpeakerVolumeWhenJoinAudio(bool bEnable);
	void EnableAutoAdjustMicVolumeWhenJoinAudio(bool bEnable);
	void ConfigDSCP(int dscpAudio, int dscpVideo, bool bReset);
	
	void EnableHideFullPhoneNumber4PureCallinUser(bool bHide);
	void EnableLengthLimitationOfMeetingNumber(bool bEnable);
	void EnableShareIOSDevice(bool bEnable);
	void EnableShareWhiteBoard(bool bEnable);
	void ForceDisableMultiShare(bool bDisable);
	void SetMaxDurationForOnlyHostInMeeting(int nDuration);
	void EnableLocalRecordingConvertProgressBarDialog(bool bShow);

	ZNFreeMeetingEndingReminderType GetReminderType();
	ZNSDKError UpgradeMeeting();
	ZNSDKError UpgradeAccount();
	ZNSDKError CancelUpdate();

	//callback
	void onFreeMeetingNeedToUpgrade(ZNFreeMeetingNeedUpgradeType type, ZoomSTRING gift_url);
	void onFreeMeetingUpgradeToGiftFreeTrialStart();
	void onFreeMeetingUpgradeToGiftFreeTrialStop();
	void onFreeMeetingUpgradeToProMeeting();

private:
	ZNativeSDKMeetingConfigWrapFreemeetingSink* m_pSink;
};
