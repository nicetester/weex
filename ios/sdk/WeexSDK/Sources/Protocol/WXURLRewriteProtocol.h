/**
 * Created by Weex.
 * Copyright (c) 2016, Alibaba, Inc. All rights reserved.
 *
 * This source code is licensed under the Apache Licence 2.0.
 * For the full copyright and license information,please view the LICENSE file in the root directory of this source tree.
 */

#import <Foundation/Foundation.h>

@class WXSDKInstance;

typedef enum : NSUInteger {
    WXResourceTypeBundle,
    WXResourceTypeImage,
    WXResourceTypeFont,
    WXResourceTypeVideo,
    WXResourceTypeLink,
    WXResourceTypeOthers
} WXResourceType;

#define WX_REWRITE_URL(url, resourceType, instance)\
do {\
    id<WXURLRewriteProtocol> rewriteHandler = [WXHandlerFactory handlerForProtocol:@protocol(WXURLRewriteProtocol)];\
    return [rewriteHandler rewriteURL:url withResourceType:resourceType withInstance:instance]; \
} while(0);

@protocol WXURLRewriteProtocol <NSObject>

/**
 * @abstract rewrite and complete URL
 *
 * @param url The original URL to be rewritten
 *
 * @param resourceType resource type which the url is sent for
 *
 * @param instance related instance
 *
 * @return a new url
 */
- (NSURL *)rewriteURL:(NSString *)url withResourceType:(WXResourceType)resourceType withInstance:(WXSDKInstance *)instance;

@end