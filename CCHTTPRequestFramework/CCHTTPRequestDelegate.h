//
//  CCHTTPRequestDelegate.h
//  CCASIHTTPRequest
//
//  Created by 李飞恒 on 16/3/19.
//  Copyright © 2016年 MuZiLee. All rights reserved.
//


@class ASIHTTPRequest;

@protocol CCHTTPRequsetDelegate <NSObject>
@optional

// 这些是请求状态默认的委托方法
// 您可以使用不同的设置方法,如:didStartSelector / didFinishSelector / didFailSelector
/**
 *  启动请求
 *
 *  @param request 请求对象
 */
- (void)requestStarted:(ASIHTTPRequest *)request;
/**
 *  请求响应(获得服务器响应的回调,该代理可获得服务器返回的响应头)
 *
 *  @param request         请求对象
 *  @param responseHeaders 响应头
 */
- (void)request:(ASIHTTPRequest *)request didReceiveResponseHeaders:(NSDictionary *)responseHeaders;
/**
 *  请求响应代理(将要重新请求时的回调,可以获得再次唤醒网络时的URL)
 *
 *  @param request 请求对象
 *  @param newURL  需要重新定向的URL
 */
- (void)request:(ASIHTTPRequest *)request willRedirectToURL:(NSURL *)newURL;
/**
 *  请求响应代理(请求完成时回调)
 *
 *  @param request 请求对象
 */
- (void)requestFinished:(ASIHTTPRequest *)request;
/**
 *  请求响应代理(请求失败的回调)
 *
 *  @param request 请求对象
 */
- (void)requestFailed:(ASIHTTPRequest *)request;
/**
 *  请求响应代理(请求重定向的回调)
 *
 *  @param request 请求对象
 */
- (void)requestRedirected:(ASIHTTPRequest *)request;



// 当此代理被调用时,它将处理所有请求对象输入的数据,这意味着responseData / responseString / downloadDestinationPath等等方法将会被忽略
// 你可以通过设置didReceiveDataSelector方法,调用不同的请求方法
- (void)request:(ASIHTTPRequest *)request didReceiveData:(NSData *)data;

// 如果delegate实现其中的一个建立作证,它将被要求提供凭证(request请求对象是否是授权的),当没有可用的
// 这两个delegate任选一个,可以重启([request retryUsingSuppliedCredentials])或 取消([request cancelAuthentication])请求 然后建立凭证
/**
 *  验证请求对象的身份
 *
 *  @param request 鉴定对象
 */
- (BOOL)authenticationNeededForRequest:(ASIHTTPRequest *)request;
/**
 *  请求对象需要鉴定代理对象
 *
 *  @param request 鉴定对象
 */
- (void)proxyAuthenticationNeededForRequest:(ASIHTTPRequest *)request;

@end
