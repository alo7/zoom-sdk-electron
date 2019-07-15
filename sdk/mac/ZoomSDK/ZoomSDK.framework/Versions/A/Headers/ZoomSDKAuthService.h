//
//  ZoomSDKAuthService.h
//  ZoomSDK
//
//  Created by TOTTI on 7/18/16.
//  Copyright (c) 2016 Zoom Video Communications,Inc. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "ZoomSDKErrors.h"

@interface ZoomSDKAccountInfo : NSObject
{
    ZoomSDKUserType _userType;
    NSString*   _displayName;
}
/**
 * @brief Get user's screen name.
 * @return If the function succeeds, it will return user's screen name. 
 */
- (NSString*) getDisplayName;
/**
 * @brief Get the type of user.
 * @return If the function succeeds, it will return the type of the user,
 */
- (ZoomSDKUserType) getSDKUserType;
@end

@protocol ZoomSDKAuthDelegate;
/**
 * @brief Callback event of ZOOM SDK authorization. 
 * Authorize Zoom SDK and the custom application with the key/secret before usage. Once authorize successfully, ZoomSDKAuthDelegate will return ZoomSDKAuthError_Success via onZoomSDKAuthReturn.
 * @note You should authorize ZOOM SDK firstly before using it, or no, it may not work.
 */
@interface ZoomSDKAuthService : NSObject
{
    BOOL _isAuthorized;
    BOOL _isLogin;
    id<ZoomSDKAuthDelegate> _delegate;
    
}
@property (assign, nonatomic) id<ZoomSDKAuthDelegate> delegate;


/**
 * @brief Authenticate SDK.
 * @param key The key of your client, also known as API key. 
 * @param secret The secret of your client. DO NOT publish it.
 * @note If the client key or secret is empty, user will get error:ZoomSDKError_InvalidPrameter directly.
 * @return If the function succeeds, it will return ZoomSDKError_success, meanwhile it will return SDK auth when calling synchronously onZoomSDKAuthReturn. 
 */
- (ZoomSDKError)sdkAuth:(NSString*)key appSecret:(NSString*)secret;

/**
 * @brief Determine if SDK is authorized.
 * @return YES means that it is authorized, otherwise failed.
 */
- (BOOL)isAuthorized;

/**
 * @brief Login ZOOM with email.
 * @param userName The email for login.
 * @param password The password for login.
 * @param rememberMe Set it to YES so that user can login automatically next time, otherwise not.
 * @return If the function succeeds, it will return ZoomSDKError_success, meanwhile it will return SDK authentication when calling asynchronously onZoomSDKAuthReturn. 
 */
- (ZoomSDKError)login:(NSString*)userName Password:(NSString*)password RememberMe:(BOOL)rememberMe;

/**
 * @brief Login ZOOM with SSO token.
 * @param ssoToken User's token information.
 * @param rememberMe Set it to YES so that user can login automatically next time, otherwise not.
 * @return If the function succeeds, it will return ZoomSDKError_success, meanwhile it will call asynchronously onZoomSDKLogin.
 */
- (ZoomSDKError)loginSSO:(NSString*)ssoToken NS_DEPRECATED_MAC(1.0, 4.3);
- (ZoomSDKError)loginSSO:(NSString*)ssoToken RememberMe:(BOOL)rememberMe NS_AVAILABLE_MAC(4.3);
/**
 * @brief Logout ZOOM.
 * @return If the function succeeds, it will return ZoomSDKError_success, meanwhile it will call asynchronously onZoomSDKLogout.
 */
- (ZoomSDKError)logout;

/**
 * @brief Get user's account information. 
 * @return When user logged in, it will return ZoomSDKAccountInfo object if the function calls successfully. Otherwise returns nil.
 */
- (ZoomSDKAccountInfo*)getAccountInfo;

/**
 * @brief Get SDK identity.
 * @return The SDK identity.
 */
- (NSString*)getSDKIdentity;
@end


@protocol ZoomSDKAuthDelegate <NSObject>

@required
/**
 * @brief Specify to get the response of ZOOM SDK authorization. 
 * @param returnValue Notify user that the authentication status changes.
 *
 */
- (void)onZoomSDKAuthReturn:(ZoomSDKAuthError)returnValue;

@optional
/**
 * @brief Specify to get the response of ZOOM SDK Login. 
 * @param loginStatus Notify user of login status.
 *
 */
- (void)onZoomSDKLogin:(ZoomSDKLoginStatus)loginStatus failReason:(NSString*)reason;

/**
 * @brief Specify to get the response of ZOOM SDK logout.
 */
- (void)onZoomSDKLogout;

/**
 * @brief Specify to get the response if ZOOM identity is expired.
 * @note User will be forced to logout once ZOOM SDK identity expired.
 */
- (void)onZoomIdentityExpired;

@end
