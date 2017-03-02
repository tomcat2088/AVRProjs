//
//  OLEDView.h
//  oled-tool
//
//  Created by wangyang on 2017/2/27.
//  Copyright © 2017年 wangyang. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface OLEDView : NSView
- (void)setImage:(NSImage *)image size:(CGSize)size;
- (void)extractImageFile:(NSImage *)image;

- (NSArray *)genOLEDBuffer;
- (void)loadOLEDBuffer:(uint8_t *)buffer len:(int)bufferLen;
@end
