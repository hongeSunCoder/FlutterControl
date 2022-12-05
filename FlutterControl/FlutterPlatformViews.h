//
//  FlutterPlatformViews.h
//  FlutterControl
//
//  Created by 孙红杰 on 2022/11/15.
//

#import <UIKit/UIKit.h>
#import "FlutterCodecs.h"


NS_ASSUME_NONNULL_BEGIN

@protocol FlutterPlatformViews <NSObject>

- (UIView*)view;

@end

@protocol FlutterPlatformViewFactory <NSObject>


- (NSObject<FlutterPlatformView>*)createWithFrame:(CGRect)frame
                                   viewIdentifier:(int64_t)viewId
                                        arguments:(id _Nullable)args;

@optional
- (NSObject<FlutterMessageCodec>*)createArgsCodec;

@end

NS_ASSUME_NONNULL_END
