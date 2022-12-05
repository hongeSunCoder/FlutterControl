//
//  FlutterViewController.m
//  FlutterControl
//
//  Created by 孙红杰 on 2022/11/11.
//


#import <memory.h>

#include "weak_ptr.hpp"
#include "scoped_nsobject.h"

#import "FlutterViewController.h"

@interface FlutterViewController ()
@property(nonatomic, readwrite) BOOL displayingFlutterUI;

@end

@implementation FlutterViewController {
    std::unique_ptr<fml::WeakPtrFactory<FlutterViewController>> _weakFactory;
    
    
}



 


- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
}

- (instancetype)init {
    return [self initWithProject:nil nibName:nil bundle:nil];
}

- (instancetype)initWithProject:(FlutterDartProject *)project nibName:(NSString *)nibName bundle:(NSBundle *)nibBundle {
    self = [super initWithNibName:nibName bundle:nibBundle];
    if (self) {
        [self sharedSetupWithProject:project initialRoute:nil];
    }
    return self;
}

- (void)sharedSetupWithProject:(nullable FlutterDartProject*)project initialRoute:(nullable NSString*)initialRoute {
    if (!project) {
        project = [[FlutterDartProject alloc] init];
    }
    
    auto engine = fml::scoped_nsobject<FlutterEngine>{[[FlutterEngine alloc]
                                                       initWithName:@"io.flutter"
                                                       project:project
                                        allowHeadlessExecution:self.engineAllowHeadlessExecution
                                            restorationEnabled:[self restorationIdentifier] != nil]};
    
    if (!engine) {
        return;
    }
    
    _engine = engine;
}


@end
