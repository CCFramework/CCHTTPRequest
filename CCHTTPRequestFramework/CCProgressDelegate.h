//
//  CCProgressDelegate.h
//  CCASIHTTPRequest
//
//  Created by 李飞恒 on 16/3/19.
//  Copyright © 2016年 MuZiLee. All rights reserved.
//

/*
 进度条代理
 */


@class ASIHTTPRequest;

@protocol CCProgressDelegate <NSObject>

@optional

// 这些方法用于更新UIProgressViews(iPhone操作系统)或NSProgressIndicators(Mac OS X)
// 如果你使用自定义的请求进度代理,你会发现它更容易实现didReceiveBytes / didSendBytes代替
#if TARGET_OS_IOS
- (void)setProgress:(float)newProgress;
#else
- (void)setDoubleValue:(double)newProgress;
- (void)setMaxValue:(double)newMax;
#endif


/**
 *  调用这个请求接收器,可以接收到data的长度(bytes)字节
 *
 *  @param request 请求对象
 *  @param bytes   字节长度
 */
- (void)request:(ASIHTTPRequest *)request didReceiveBytes:(long long)bytes;

/**
 *  获取请求时发送的data长度(因为CFNetwork,不限制发送数量,首长32KB)
 *  如果请求需要删除上传进度,字节就可能会小于零(因为重新运行请求时可能会有这种情况)
 *
 *  @param request 请求对象
 *  @param bytes   发送字节长度
 */
- (void)request:(ASIHTTPRequest *)request didSendBytes:(long long)bytes;


/**
 *  需要改变下载内容时调用(增量会跟旧的下载内容叠加)
 *
 *  @param request   请求对象
 *  @param newLength 新下载的内容长度(增量)
 */
- (void)request:(ASIHTTPRequest *)request incrementDownloadSizeBy:(long long)newLength;

// 当一个请求需要改变上传内容的长度
// 新的长度小于零的时候,这个请求对象可能会移除这个缓冲区来跟踪进度
- (void)request:(ASIHTTPRequest *)request incrementUploadSizeBy:(long long)newLength;
@end

