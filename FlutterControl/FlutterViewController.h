//
//  FlutterViewController.h
//  FlutterControl
//
//  Created by 孙红杰 on 2022/11/11.
//

#ifndef FlutterViewController_h
#define FlutterViewController_h

#import <UIKit/UIKit.h>
#include <sys/cdefs.h>

#import "FlutterBinaryMessenger.h"
#import "FlutterPlugin.h"
#import "FlutterTexture.h"
#import "FlutterDartProject.h"
#import "FlutterEngine.h"

@interface FlutterViewController : UIViewController <FlutterTextureRegistry, FlutterPluginRegistry>


- (instancetype)initWithEngine:(FlutterEngine*)engine nibName:(nullable NSString*)nibName bundle:(nullable NSBundle*)nibBundle NS_DESIGNATED_INITIALIZER;


- (instancetype)initWithProject:(nullable FlutterDartProject*)project nibName:(nullable NSString*)nibName bundle:(nullable NSBundle*)nibBundle NS_DESIGNATED_INITIALIZER;

- (instancetype)initWithProject:(nullable FlutterDartProject*)project initialRoute:(nullable NSString*)initialRoute nibName:(nullable NSString*)nibName bundle:(nullable NSString*)nibBundle NS_DESIGNATED_INITIALIZER;


- (void)setFlutterViewDidRenderCallback:(void (^)(void))callback;

- (NSString*)lookupKeyForAsset:(NSString*)asset;

- (NSString*)lookupKeyForAsset:(NSString*)asset fromPackage:(NSString*)package;

//deprecated
- (void)setInitialRoute:(NSString*)route;


- (void)popRoute;

- (void)pushRoute:(NSString*)route;

- (id<FlutterPluginRegistry>)pluginRegistry;

@property(nonatomic, readonly, getter=isDisplayingFlutterUI)BOOL displayingFlutterUI;

@property(strong, nonatomic, nullable)UIView* splashScreenView;

- (BOOL)loadDefaultSplashScreenView;

@property(nonatomic, getter=isViewOpaque)BOOL viewOpaque;

@property(weak, nonatomic, readonly)FlutterEngine* engine;

@property(nonatomic, readonly)NSObject<FlutterBinaryMessenger>* binaryMessenger;


@property(nonatomic, readonly)BOOL engineAllowHeadlessExecution;

@end


//@implementation FlutterViewController
//{
//    FlutterEngine* _engine;
//}
//
//- (instancetype)initWithEngine:(FlutterEngine*)engine {
//    self = [super initWithNibName:nil bundle:nil];
//
//    if (self) {
//
//    }
//    return self;
//}
//
//@end


#endif /* FlutterViewController_h */
