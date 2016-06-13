//
//  CCHTTPRequestConfig.h
//  CCASIHTTPRequest
//
//  Created by 李飞恒 on 16/3/18.
//  Copyright © 2016年 MuZiLee. All rights reserved.
//

// ======
// 调试输出配置选项
// ======

// 如果将使用指定的函数定义调试日志记录
// 否则使用NSLog
#ifndef ASI_DEBUG_LOG
#define ASI_DEBUG_LOG NSLog
#endif

// 设置为1时,ASIHTTPRequests会将正在运行中的请求信息打印到控制台
#ifndef DEBUG_REQUEST_STATUS
#define DEBUG_REQUEST_STATUS 0
#endif

// 设置为1时,ASIFormDataRequests会将请求体中的信息打印到控制台
#ifndef DEBUG_FORM_DATA_REQUEST
#define DEBUG_FORM_DATA_REQUEST 0
#endif

// 设置为1时,ASIHTTPRequests会将带宽调节信息打印到控制台
#ifndef DEBUG_THROTTLING
#define DEBUG_THROTTLING 0
#endif

// 当设置为1,ASIHTTPRequests会将持久连接的信息打印到控制台
#ifndef DEBUG_PERSISTENT_CONNECTIONS
#define DEBUG_PERSISTENT_CONNECTIONS 0
#endif

// 设置为1时,ASIHTTPRequests会将HTTP身份验证信息(Basic,Digest 或 NTLM)打印到控制台
#ifndef DEBUG_HTTP_AUTHENTICATION
#define DEBUG_HTTP_AUTHENTICATION 0
#endif

