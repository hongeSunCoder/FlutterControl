//
//  FlutterPlugin.h
//  FlutterControl
//
//  Created by 孙红杰 on 2022/11/14.
//

#ifndef FlutterPlugin_h
#define FlutterPlugin_h



#import <UIKit/UIKit.h>
#import "FlutterBinaryMessenger.h"
#import "FlutterTexture.h"


@protocol FlutterApplicationLifeCycleDelegate <NSObject>

@optional

- (BOOL)application:(UIApplication*)application
    didFinishLaunchingWithOptions:(NSDictionary*)launchOptions;


- (BOOL)application:(UIApplication*)application
    willFinishLaunchingWithOptions:(NSDictionary*)launchOptions;

@end

@protocol FlutterAppLifeCycleProvider <NSObject>

- (void)addApplicationLifeCycleDelegate:(NSObject<FlutterApplicationLifeCycleDelegate>*)delegate;

@end


// Registration context for a single 'FlutterPlugin'
// providing a one stop shop for the plugin to access to contextual information
// and register callbacks for various application events.
@protocol FlutterPluginRegistrar <NSObject>

- (NSObject<FlutterBinaryMessenger>*)messenger;

- (NSObject<FlutterTextureRegistry>*)textures;




@end

// manage cross-plugin level.
// create registrar
@protocol FlutterPluginRegistry <NSObject>

- (nullable NSObject<FlutterPluginRegistrar>*)registrarForPlugin:(NSString*)pluginKey;


- (BOOL)hasPlugin:(NSString*)pluginKey;


- (nullable NSObject*)valuePublishedByPlugin:(NSString*)pluginKey;

@end

#endif /* FlutterPlugin_h */
