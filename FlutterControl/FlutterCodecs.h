//
//  FlutterCodecs.h
//  FlutterControl
//
//  Created by 孙红杰 on 2022/11/15.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


@protocol FlutterMessageCodec

+ (instancetype)sharedInstance;

- (NSData* _Nullable)encode:(id _Nullable)message;

- (id _Nullable)decode:(NSData* _Nullable)message;

@end


@interface FlutterBinaryCodec : NSObject <FlutterMessageCodec>
@end



@interface FlutterStringCodec : NSObject <FlutterMessageCodec>
@end


@interface FlutterJSONMessageCodec : NSObject <FlutterMessageCodec>
@end




@interface FlutterStandardWriter : NSObject


- (instancetype)intiWithData:(NSMutableData*)data;

- (void)writeByte:(UInt8)value;

- (void)writeBytes:(const void*)bytes length:(NSUInteger)length;

- (void)writeData:(NSData*)data;

- (void)writeSize:(UInt32)size;

- (void)writeAlignment:(UInt8)alignment;

- (void)writeUTF8:(NSString*)value;


// supported data types:
// NSNull, NSNumber, NSString(as UTF-8), FlutterStandardTypedData, NSArray of..., NSDictionary of...
- (void)writeValue:(id)value;

@end

NS_ASSUME_NONNULL_END
