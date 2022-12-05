//
//  FlutterEngine.m
//  FlutterControl
//
//  Created by 孙红杰 on 2022/11/11.
//

#import "FlutterEngine.h"
#include "scoped_nsobject.h"

#include <memory>
#include "thread_host.hpp"
#include "message_loop.hpp"
//#include "shell.hpp"
#include "switches.hpp"


#include "FlutterDartProject.h"
#import "FlutterViewController.h"


@interface FlutterEngine ()



@end

@implementation FlutterEngine {
    fml::scoped_nsobject<FlutterDartProject> _dartProject;
    std::shared_ptr<flutter::ThreadHost> _threadHost;
//    std::unique_ptr<flutter::Shell> _shell;
    NSString *_labelPrefix;
    
    
    
    
    
    
    
    FlutterViewController *_viewController;
    FlutterDartProject *_dartProject;
}

- (instancetype)initWithName:(NSString *)labelPrefix
                     project:(nullable FlutterDartProject *)project
      allowHeadlessExecution:(BOOL)allowHeadlessExecution
          restorationEnabled:(BOOL)restorationEnabled {
    self = [super init];
    
    if (project == nil) {
        _dartProject.reset([[FlutterDartProject alloc] init]);
    }
    else {
        _dartProject.reset(project);
    }
    
    
    
    
    return self;
}

@end
