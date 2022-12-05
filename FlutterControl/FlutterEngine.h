//
//  FlutterEngine.h
//  FlutterControl
//
//  Created by 孙红杰 on 2022/11/11.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "FlutterBinaryMessenger.h"
#import "FlutterDartProject.h"
#import "FlutterPlugin.h"
#import "FlutterTexture.h"


NS_ASSUME_NONNULL_BEGIN

@interface FlutterEngine : NSObject <FlutterTextureRegistry, FlutterPluginRegistry>

- (instancetype)initWithName:(NSString*)labelPrefix;

- (instancetype)initWithName:(NSString*)lablePrefix
                     project:(nullable FlutterDartProject*)project
      allowHeadlessExecution:(BOOL)allowHeadlessExecution
          restorationEnabled:(BOOL)restorationEnabled NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
