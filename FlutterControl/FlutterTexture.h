//
//  FlutterTexture.h
//  FlutterControl
//
//  Created by 孙红杰 on 2022/11/15.
//

#ifndef FlutterTexture_h
#define FlutterTexture_h

#import <CoreMedia/CoreMedia.h>
#import <Foundation/Foundation.h>


@protocol FlutterTexture <NSObject>

- (CVPixelBufferRef _Nullable)copyPixelBuffer;

@optional
- (void)onTextureUnregistered:(NSObject<FlutterTexture>*)texture;

@end


@protocol FlutterTextureRegistry <NSObject>

- (int64_t)registerTexture:(NSObject<FlutterTexture>*)texture;

- (void)textureFrameAvailable:(int64_t)textureId;


- (void)unregisterTexture:(int64_t)textureId;

@end

#endif /* FlutterTexture_h */
