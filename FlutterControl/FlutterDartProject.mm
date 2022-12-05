//
//  FlutterDartProject.m
//  FlutterControl
//
//  Created by 孙红杰 on 2022/11/11.
//


#import "FlutterViewController.h"
#import "FlutterDartProject.h"





#include "syslog.h"
#include <sstream>
#include <string>



#include "scoped_nsobject.h"
#include "../fml/mapping.hpp"

#include "settings.h"
#include "../shell/common/switches.hpp"





flutter::Settings FTDefaultSettingsForBundle(NSBundle *bundle) {
    
    NSBundle *mainBundle = [NSBundle mainBundle];
    NSBundle *engineBundle = [NSBundle bundleForClass:[FlutterViewController class]];
    
    if (bundle == nil) {
        bundle = [NSBundle bundleWithIdentifier:[FlutterDartProject defaultBundleIdentifier]];
    }
    if (bundle == nil) {
        bundle = mainBundle;
    }
    
    return flutter::SettingsFromCommandLine(0);
    
}


@implementation FlutterDartProject {
    flutter::Settings _settings;
}

- (instancetype)initWithPrecompiledDartBundle:(NSBundle *)bundle {
    self = [super init];
    
    if (self) {
        _settings = FTDefaultSettingsForBundle(bundle);
    }
    return self;
}



@end
