//
//  FlutterDartProject.h
//  FlutterControl
//
//  Created by 孙红杰 on 2022/11/11.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface FlutterDartProject : NSObject

- (instancetype)initWithPrecompiledDartBundle:(nullable NSBundle*)bundle;

+ (NSString*)defaultBundleIdentifier;

@end

NS_ASSUME_NONNULL_END
