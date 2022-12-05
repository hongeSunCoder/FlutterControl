//
//  FlutterPluginAppLifeCycleDelegate.m
//  FlutterControl
//
//  Created by 孙红杰 on 2022/11/14.
//

#import "FlutterPluginAppLifeCycleDelegate.h"
#import "FlutterPluginAppLifeCycleDelegate_internal.h"
#import "FlutterViewController.h"



static const SEL kSelectorsHandledByPlugins[] = {
    @selector(application:didReceiveRemoteNotification:fetchCompletionHandler:),
    @selector(application:performFetchWithCompletionHandler:)
};


@implementation FlutterPluginAppLifeCycleDelegate {
    
    NSPointerArray* _delegates;
}

- (instancetype)init {
    if (self = [super init]) {
        _delegates = [NSPointerArray weakObjectsPointerArray];
    }
    return self;
}

- (BOOL)application:(UIApplication*)application didFinishLaunchingWithOptions:(NSDictionary*)launchOptions {
    for (NSObject<FlutterApplicationLifeCycleDelegate>* delegate in [_delegates allObjects]) {
        if (!delegate) {
            continue;
        }
        
        if ([delegate respondsToSelector:_cmd]) {
            if (![delegate application:application didFinishLaunchingWithOptions:launchOptions]) {
                return  NO;
            }
        }
    }
    
    return YES;
}

- (BOOL)application:(UIApplication*)application
    willFinishLaunchingWithOptions:(NSDictionary*)launchOptions {
  //flutter::DartCallbackCache::LoadCacheFromDisk();
  for (NSObject<FlutterApplicationLifeCycleDelegate>* delegate in [_delegates allObjects]) {
    if (!delegate) {
      continue;
    }
    if ([delegate respondsToSelector:_cmd]) {
      if (![delegate application:application willFinishLaunchingWithOptions:launchOptions]) {
        return NO;
      }
    }
  }
  return YES;
}

- (void)addDelegate:(NSObject<FlutterApplicationLifeCycleDelegate>*)delegate {
    [_delegates addPointer:(__bridge void*)delegate];
    if (IsPowerOfTwo([_delegates count])) {
        [_delegates compact];
    }
}

static BOOL IsPowerOfTwo(NSUInteger x) {
    return x!=0 && ( x & (x-1) ) == 0;
}


- (BOOL)isSelectorAddedDynamically:(SEL)selector {
    for (const SEL aSelector: kSelectorsHandledByPlugins) {
        if (selector == aSelector) {
            return YES;
        }
    }
    return NO;
}

- (BOOL)hasPluginThatRespondsToSelector:(SEL)selector {
    for (NSObject<FlutterApplicationLifeCycleDelegate>* delegate in [_delegates allObjects]) {
        if (!delegate) {
            continue;;
        }
        
        if ([delegate respondsToSelector:selector]) {
            return YES;
        }
    }
    return NO;
}



@end
