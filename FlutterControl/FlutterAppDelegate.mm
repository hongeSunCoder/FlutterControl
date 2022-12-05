//
//  FlutterAppDelegate.m
//  FlutterControl
//
//  Created by 孙红杰 on 2022/11/11.
//

#import "FlutterAppDelegate.h"
#import "FlutterViewController.h"
#import "FlutterPluginAppLifeCycleDelegate.h"
#import "FlutterPluginAppLifeCycleDelegate_internal.h"

@interface FlutterAppDelegate ()

@property(nonatomic, copy) FlutterViewController* (^rootFlutterViewControllerGetter)(void);

@end


@implementation FlutterAppDelegate {
    FlutterPluginAppLifeCycleDelegate* _lifeCycleDelegate;
}

- (instancetype)init {
    if (self = [super init]) {
        _lifeCycleDelegate = [[FlutterPluginAppLifeCycleDelegate alloc] init];
    }
    return self;
}

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary<UIApplicationLaunchOptionsKey,id> *)launchOptions {
    return [_lifeCycleDelegate application:application didFinishLaunchingWithOptions:launchOptions];
}

- (BOOL)application:(UIApplication *)application willFinishLaunchingWithOptions:(NSDictionary<UIApplicationLaunchOptionsKey,id> *)launchOptions {
    return [_lifeCycleDelegate application:application willFinishLaunchingWithOptions:launchOptions];
}

- (FlutterViewController*)rootFlutterViewController {
    if (_rootFlutterViewControllerGetter != nil) {
        return _rootFlutterViewControllerGetter();
    }
    
    
    UIViewController *rootViewController = _window.rootViewController;
    if ([rootViewController isKindOfClass:[FlutterViewController class]]) {
        return (FlutterViewController*)rootViewController;
    }
    return nil;
}


- (void)addApplicationLifeCycleDelegate:(NSObject<FlutterApplicationLifeCycleDelegate> *)delegate {
    [_lifeCycleDelegate addDelegate:delegate];
}

- (NSObject<FlutterPluginRegistrar> *)registrarForPlugin:(NSString *)pluginKey {
    FlutterViewController *flutterRootViewController = [self rootFlutterViewController];
    if (flutterRootViewController) {
        return [[flutterRootViewController pluginRegistry] registrarForPlugin:pluginKey];
    }
    
    return nil;
}

- (BOOL)hasPlugin:(NSString *)pluginKey {
    FlutterViewController *flutterRootViewController = [self rootFlutterViewController];
    if (flutterRootViewController) {
        return [[flutterRootViewController pluginRegistry] hasPlugin:pluginKey];
    }
    
    return false;
}
- (NSObject*)valuePublishedByPlugin:(NSString *)pluginKey {
    FlutterViewController *flutterRootViewController = [self rootFlutterViewController];
    if (flutterRootViewController) {
        return [[flutterRootViewController pluginRegistry] valuePublishedByPlugin:pluginKey];
    }
    return nil;
}


- (BOOL)respondsToSelector:(SEL)aSelector {
    if ([_lifeCycleDelegate isSelectorAddedDynamically:aSelector]) {
        return [self delegateRespondsSelectorToPlugin:aSelector];
    }
    
    return [super respondsToSelector:aSelector];
}


- (BOOL)delegateRespondsSelectorToPlugin:(SEL)selector {
    if ([_lifeCycleDelegate hasPluginThatRespondsToSelector:selector]) {
        return [_lifeCycleDelegate respondsToSelector:selector];
    }
    
    return NO;
}


- (id)forwardingTargetForSelector:(SEL)aSelector {
    if ([_lifeCycleDelegate isSelectorAddedDynamically:aSelector]) {
        return _lifeCycleDelegate;
    }
    
    return [super forwardingTargetForSelector:aSelector];
}





@end
