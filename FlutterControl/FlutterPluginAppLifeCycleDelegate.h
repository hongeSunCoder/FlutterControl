//
//  FlutterPluginAppLifeCycleDelegate.h
//  FlutterControl
//
//  Created by 孙红杰 on 2022/11/14.
//

#import "FlutterPlugin.h"
NS_ASSUME_NONNULL_BEGIN



@interface FlutterPluginAppLifeCycleDelegate : NSObject

- (BOOL)application:(UIApplication*)application didFinishLaunchingWithOptions:(NSDictionary*)launchOptions;


- (BOOL)application:(UIApplication*)application
    willFinishLaunchingWithOptions:(NSDictionary*)launchOptions;

- (void)addDelegate:(NSObject<FlutterApplicationLifeCycleDelegate>*)delegate;

@end

NS_ASSUME_NONNULL_END
