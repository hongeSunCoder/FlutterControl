//
//  FlutterBinaryMessenger.h
//  FlutterControl
//
//  Created by 孙红杰 on 2022/11/15.
//

#ifndef FlutterBinaryMessenger_h
#define FlutterBinaryMessenger_h


typedef void (^FlutterBinaryReply)(NSData* _Nullable reply);

typedef void (^FlutterBinaryMessageHandler)(NSData* _Nullable message, FlutterBinaryReply reply);

typedef int64_t FlutterBinaryMessengerConnection;


@protocol FlutterTaskQueue;


@protocol FlutterBinaryMessenger <NSObject>


@optional
- (NSObject<FlutterTaskQueue>*)makeBackgroundTaskQueue;

- (FlutterBinaryMessengerConnection)
    setMessageHandlerOnChannel:(NSString*)channel
    binaryMessageHandler:(FlutterBinaryMessageHandler _Nullable)handler
    taskQueue:(NSObject<FlutterTaskQueue>* _Nullable)taskQueue;


@required

- (void)sendOnChannel:(NSString*)channel message:(NSData* _Nullable)message;

- (void)sendOnChannel:(NSString*)channel
              message:(NSData* _Nullable)message
          binaryReply:(FlutterBinaryReply _Nullable)callback;


- (FlutterBinaryMessengerConnection)setMessageHandlerOnChannel:(NSString*)channel
                                          binaryMessageHandler:(FlutterBinaryMessageHandler _Nullable)hander;


- (void)cleanUpConnection:(FlutterBinaryMessengerConnection)connection;


@end

#endif /* FlutterBinaryMessenger_h */
