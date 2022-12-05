//
//  FlutterAppDelegate.h
//  FlutterControl
//
//  Created by 孙红杰 on 2022/11/11.
//

#ifndef FlutterAppDelegate_h
#define FlutterAppDelegate_h

#import <UIKit/UIKit.h>
#import "FlutterPlugin.h"
#import "FlutterMacros.h"


FLUTTER_DARWIN_EXPORT
@interface FlutterAppDelegate : UIResponder <UIApplicationDelegate, FlutterPluginRegistry, FlutterAppLifeCycleProvider>

@property(strong, nonatomic) UIWindow* window;

@end

#endif /* FlutterAppDelegate_h */
