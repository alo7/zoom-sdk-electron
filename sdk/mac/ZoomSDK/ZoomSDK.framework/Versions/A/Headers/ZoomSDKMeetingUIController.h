//
//  ZoomSDKMeetingUIController.h
//  ZoomSDK
//
//  Created by TOTTI on 8/4/17.
//  Copyright © 2017 Zoom Video Communications,Inc. All rights reserved.
//
@protocol ZoomSDKMeetingUIControllerDelegate <NSObject>
/**
 * @brief Callback of clicking invite button in toolbar. If user wants to customize the invitation UI, set _disableToolbarInviteButtonClickOriginAction to YES in ZoomSDKMeetingConfiguration.
 */
- (void)onToolbarInviteButtonClick;

/**
 * @brief Notification when participant clicks LEAVE MEETING button. 
 * @param participantID The ID of participant who leaves meeting.
 */
- (void)onClickLeaveMeeting:(unsigned int)participantID;

/**
 * @brief Notification when SHARE button in toolbar is clicked.
 */
- (void)onToolbarShareButtonClick;

/**
 * @brief Notification of showing the window of leaving meeting.
 */
-(void)onNeedShowLeaveMeetingWindow;

/**
 * @brief Notification when participant button is clicked.
 */
-(void)onParticipantButtonClicked;

/**
 * @brief Notification when custom LIVE button is clicked. 
 */
-(void)onCustomLiveButtonClicked;
@end

@interface ZoomSDKMeetingUIController :NSObject
{
    id<ZoomSDKMeetingUIControllerDelegate> _delegate;
}
@property(nonatomic, assign) id<ZoomSDKMeetingUIControllerDelegate> delegate;

/**
 * @brief Whether to show components in meeting and meeting controls.
 * @param component The enum of meeting components.
 * @param window The pointer to the window. When the function calls successfully, the 'window' will be the meeting component window.
 * @param show YES means to show the components, NO to hide
 * @param inPanel YES means to show the components in panel, otherwise No.
 * @param componentFrame The frame of the meeting component.
 * @return If the function succeeds, it will return ZoomSDKError_success, otherwise failed.	
 */  
- (ZoomSDKError)showMeetingComponent:(MeetingComponent)component window:(NSWindow**)window show:(BOOL)show InPanel:(BOOL)inPanel frame:(NSRect)componentFrame;

/**
 * @brief Enter full screen mode.
 * @param fullScreen Set it to YES to enter full screen, otherwise set it to NO. 
 * @param firstView Set it to YES to enter full screen mode on the first view, otherwise set it to NO.
 * @param secondView Set it to YES to enter full screen mode on the second view, otherwise set it to NO.
 * @return If the function succeeds, it will return ZoomSDKError_success, otherwise failed.
 */ 
- (ZoomSDKError)enterFullScreen:(BOOL)fullScreen firstMonitor:(BOOL)firstView DualMonitor:(BOOL)secondView;
/**
 * @brief Switch to video wall view.
 * @return If the function succeeds, it will return ZoomSDKError_success, otherwise failed.								   
 */ 
- (ZoomSDKError)switchToVideoWallView;
/**
 * @brief Switch to the mode of showing the current speaker.
 * @return If the function succeeds, it will return ZoomSDKError_success, otherwise failed.
 */ 
- (ZoomSDKError)switchToActiveSpeakerView;
/**
 * @brief Determine if the meeting is in minimize window mode.
 * @return YES means that it is in minimize window mode, otherwise not.
 */ 
- (BOOL)isInMiniVideoMode;

/**
 * @brief Switch UI between mini video and mini bar(without video), it works only when isInMiniVideoMode = YES.
 * @return If the function succeeds, it will return the ZoomSDKError_Success, otherwise failed.
 */
- (ZoomSDKError)switchMiniVideoModeUI;

//share video
//- (ZoomSDKError)moveFloatVideoWindow:(NSPoint)position;
/**
 * @brief Minimize the float video window or switch to large scale mode when sharing.
 * @param bMin YES means to minimize float video window, NO to show large scale float video.
 * @return If the function succeeds, it will return ZoomSDKError_success, otherwise failed.
 */
- (ZoomSDKError)minimizeShareFloatVideoWindow:(BOOL)bMin;
/**
 * @brief Switch float video display mode to active speaker.
 * @return If the function succeeds, it will return ZoomSDKError_success, otherwise failed. 
 */
- (ZoomSDKError)switchFloatVideoToActiveSpeakerMode;
/**
 * @brief Switch float video display mode to gallery view mode.
 * @return If the function succeeds, it will return ZoomSDKError_success, otherwise failed.
 */
- (ZoomSDKError)switchFloatVideoToGalleryMode;

/**
 * @brief Display or not the user who does not turn on the video in the video wall mode.
 * @return If the function succeeds, it will return the ZoomSDKError_Success, otherwise failed.
 */
- (ZoomSDKError)hideOrShowNoVideoUserOnVideoWall:(BOOL)hide;

/**
 * @brief Get the page information in video wall mode.
 * @param currentPageNum The number of current page.
 * @param totalPageNum The number of total pages.
 * @return If the function succeeds, it will return the ZoomSDKError_Success, otherwise failed.
 */
- (ZoomSDKError)getWallViewPageInfo:(int*)currentPageNum TotalPageNum:(int*)totalPageNum;

/**
 * @brief Display previous or following page of video wall in the meeting.
 * @param nextPage Set it to YES to display following page of video wall, NO to display previous page.
 * @return If the function succeeds, it will return the ZoomSDKError_Success, otherwise failed.
 */
- (ZoomSDKError)showPreOrNextPageWallView:(BOOL)nextPage;

/**
 * @brief Active the principal window of meeting and place it on top.
 * @return If the function succeeds, it will return the ZoomSDKError_Success, otherwise failed.
 */
- (ZoomSDKError)backToMeeting;

@end
