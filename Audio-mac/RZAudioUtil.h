//
//  RZAudioUtil.h
//  RZPaas_macOS
//
//  Created by yxibng on 2020/9/29.
//

#import <Foundation/Foundation.h>
#import <AudioToolbox/AudioToolbox.h>
NS_ASSUME_NONNULL_BEGIN

#if TARGET_OS_OSX

OSStatus GetIOBufferFrameSizeRange(AudioObjectID inDeviceID,
                                   UInt32 *outMinimum,
                                   UInt32 *outMaximum);


OSStatus SetCurrentIOBufferFrameSize(AudioObjectID inDeviceID,
                                     UInt32 inIOBufferFrameSize);


OSStatus GetCurrentIOBufferFrameSize(AudioObjectID inDeviceID,
                                     UInt32 *outIOBufferFrameSize);

OSStatus AudioUnitSetCurrentIOBufferFrameSize(AudioUnit inAUHAL,
                                              UInt32 inIOBufferFrameSize);

OSStatus AudioUnitGetCurrentIOBufferFrameSize(AudioUnit inAUHAL,
                                              UInt32 *outIOBufferFrameSize);
#endif

OSStatus AudioUnitSetMaxIOBufferFrameSize(AudioUnit inAUHAL,
                                          UInt32 inIOBufferFrameSize);
OSStatus AudioUnitGetMaxIOBufferFrameSize(AudioUnit inAUHAL,
                                          UInt32 *outIOBufferFrameSize);



@interface RZAudioUtil : NSObject
//uint 16, 平面存储
+ (AudioStreamBasicDescription)intFormatWithNumberOfChannels:(UInt32)channels
                                                  sampleRate:(float)sampleRate;

//float 32, 平面存储
+ (AudioStreamBasicDescription)floatFormatWithNumberOfChannels:(UInt32)channels
                                                    sampleRate:(float)sampleRate;

//uint 16, 平面 or 交错
+ (AudioStreamBasicDescription)intFormatWithNumberOfChannels:(UInt32)channels
                                                  sampleRate:(float)sampleRate
                                               isInterleaved:(BOOL)isInterleaved;

//float 32, 平面 or 交错
+ (AudioStreamBasicDescription)floatFormatWithNumberOfChannels:(UInt32)channels
                                                    sampleRate:(float)sampleRate
                                                 isInterleaved:(BOOL)isInterleaved;

//根据 AudioStreamBasicDescription，申请AudioBufferList
+ (AudioBufferList *)audioBufferListWithNumberOfFrames:(UInt32)frames
                                          streamFormat:(AudioStreamBasicDescription)asbd;


//判断是否是交错类型
+ (BOOL)isInterleaved:(AudioStreamBasicDescription)asbd;

//释放 AudioBufferList
+ (void)freeAudioBufferList:(AudioBufferList *)bufferList;

@end

NS_ASSUME_NONNULL_END