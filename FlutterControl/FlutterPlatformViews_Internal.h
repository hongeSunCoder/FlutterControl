//
//  FlutterPlatformViews_Internal.h
//  FlutterControl
//
//  Created by 孙红杰 on 2022/11/15.
//

NS_ASSUME_NONNULL_BEGIN

#import <Foundation/Foundation.h>


#import "FlutterBinaryMessenger.h"
#import "FlutterPlugin.h"
#import "FlutterPlatformViews.h"


@interface FlutterClippingMaskView : UIView

- (void)clipRect:(const SkRect&)clipSkRect matrix:(const CATransform3D&)matrix;

- (void)clipRRect:(const SkRRect&)clipSkRect matrix:(const CATransform3D&)matrix;

- (void)clipPath:(const SkPath&)path matrix:(const CATranform3D&)matrix;

@end


@interface PlatformViewFilter : NSObject

@property(assign, nonatomic, readonly)CGRect frame;

@property(assign, nonatomic, readonly)CGFloat blurRadius;

@property(nonatomic, retain, readonly)UIVisualEffectView* backdropFilterView;

+ (void)resetPreparation;

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithFrame:(CGRect)frame blurRadius:(CGFloat)blurRadius visualEffectView:(UIVisualEffectView*)visualEffectView NS_DESIGNATED_INITIALIZER;

@end


@interface ChildClippingView : UIView

- (void)applyBlurBackdropFilters:(NSArray<PlatformViewFilter*>*)filters;

@end


namespace flutter {


class FlutterPlatformViewController {
public:
    FlutterPlatformViewController();
    
    ~FlutterPlatformViewController();
    
private:
    static const size_t kMaxLayerAllocations = 2;
    
}

}

NS_ASSUME_NONNULL_END
