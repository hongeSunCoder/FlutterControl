//
//  FlutterPluginAppLifeCycleDelegate_internal.h
//  FlutterControl
//
//  Created by 孙红杰 on 2022/11/15.
//

#ifndef FlutterPluginAppLifeCycleDelegate_internal_h
#define FlutterPluginAppLifeCycleDelegate_internal_h


@interface FlutterPluginAppLifeCycleDelegate ()

- (BOOL)isSelectorAddedDynamically:(SEL)selector;

- (BOOL)hasPluginThatRespondsToSelector:(SEL)selector;

@end


#endif /* FlutterPluginAppLifeCycleDelegate_internal_h */
