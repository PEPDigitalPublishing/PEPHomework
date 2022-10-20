//
//  PEPHomeworkViewController.h
//  HomeworkSample
//
//  Created by 李沛倬 on 2019/7/5.
//  Copyright © 2019 PEP. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <WebKit/WebKit.h>
#import "PEPHomeworkJavaScriptManager.h"

/** 作业模块中的上传图片功能由接入方实现，接入方务必实现此通知。通知中的object参数为字典，结构为：@{上传路径：需要上传的图片UIImage} */
static NSString * _Nonnull const PHNotificationNameShouldImage = @"PHNotificationNameShouldImage";

/** 用户会话过期时将发送此通知 */
static NSString * _Nonnull const PHNotificationNameUserSessionInvalid = @"PHNotificationNameUserSessionInvalid";

/** 用户在其他设备登录，当前用户被踢出时发送此通知 */
static NSString * _Nonnull const PHNotificationNameUserOut = @"PHNotificationNameUserOut";



NS_ASSUME_NONNULL_BEGIN

typedef void(^PEPHomeworkTimeBlock)(NSInteger timeSpan);

@protocol PEPHomeworkViewControllerDelegate;

@interface PEPHomeworkViewController : UIViewController<PEPHomeworkJavaScriptManagerProtocol>

@property (nonatomic, strong, readonly) WKWebView *webView;

@property (nonatomic, strong, readonly) NSURL *URL;

/**返回学习时间*/
@property(nonatomic,copy)PEPHomeworkTimeBlock block;

@property (nonatomic, assign) BOOL needsRefreshControl;

/** 当cookie发生变化之后（如重新登录），需要将此参数设置为true，以便在reload的时候重新设置cookie。 */
@property (nonatomic, assign) BOOL reloadForCookieChanged;

/**
 配置BaseURL。接入作业模块时务必最先调用此方法，否则将不会正常打开页面

 @param baseURL baseURL
 */
+ (void)configationBaseURL:(NSString *)baseURL;

/**
 接入作业模块时务必使用此方法初始化PEPHomeworkViewController，传入cookie中的用户会话信息，以确保跟项目中的登录用户保持信息同步。
 若未使用该方法初始化，则内部将自动从NSHTTPCookieStorage.sharedHTTPCookieStorage取出相关cookie进行赋值

 @param JSESSIONID JSESSIONID
 @param GSID GSID
 */
- (instancetype)initWithJSESSIONID:(NSString *)JSESSIONID GSID:(NSString *)GSID;

- (void)loadRequestWithURL:(NSURL *)url;

- (void)reload;

/**
 作业模块中的上传图片功能由接入方实现，接入方务必实现名为「PHNotificationNameShouldImage」的通知。通知中的object参数为需要上传的图片(UIImage对象，未压缩)
 图片上传完成后务必调用此方法。

 @param url 上传后的图片在服务器上的存储地址。作业模块中的相关页面将根据该参数刷新页面并将该图片显示出来。
 */
- (void)imageDidUploadedAtURLString:(NSString *)url;


// MARK: - Loading

@property (nonatomic, strong, readonly) UIView *loadingView;

- (void)showLoadingView;

/** progress: 0 ~ 1 */
- (void)showLoadingViewProgress:(CGFloat)progress;

- (void)showLoadingViewWithTitle:(NSString *)title;

- (void)hideLoadingView;

@end


NS_ASSUME_NONNULL_END
