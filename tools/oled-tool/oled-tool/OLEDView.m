//
//  OLEDView.m
//  oled-tool
//
//  Created by wangyang on 2017/2/27.
//  Copyright © 2017年 wangyang. All rights reserved.
//

#import "OLEDView.h"

@interface OLEDView () {
    unsigned char *textureData;
    CGFloat originWidth;
    CGFloat originHeight;
    uint8_t * buffer;
}
@property (strong, nonatomic) NSImage *image;
@property (assign, nonatomic) CGSize size;
@property (strong, nonatomic) NSBitmapImageRep *rawImg;
@property (strong, nonatomic) NSArray *imageData;
@end

@implementation OLEDView

- (void)awakeFromNib {
    [super awakeFromNib];
    buffer = NULL;
}

- (void)setImage:(NSImage *)image size:(CGSize)size {
    self.image = image;
    self.size = size;
    self.rawImg = [NSBitmapImageRep imageRepWithData:[image TIFFRepresentation]];
    [self setNeedsDisplay:YES];
}

- (bool)colorTest:(CGFloat)x y:(CGFloat)y {
    if (buffer != NULL) {
        int loc = (int)(31 - y) / 8 * 128 + x;
        uint8_t dot = buffer[loc];
        uint8_t mask = 0x01 << ((int)y % 8);
        uint8_t val = dot & mask;
        return val > 0;
    }
    NSColor *color =  [self.rawImg colorAtX:x y:y];
    return [color alphaComponent] == 1;
}

- (void)drawRect:(NSRect)dirtyRect {
    [super drawRect:dirtyRect];
    CGFloat scaleX = 128 / self.frame.size.width;
    CGFloat scaleY = 32 / self.frame.size.height;
    CGFloat scale = scaleX > scaleY ? scaleX : scaleY;
    CGFloat widthPerPixel = 1 / scale;
    CGFloat heightPerPixel = widthPerPixel * 1.5;
    CGFloat originX = (self.frame.size.width - 128 * widthPerPixel) / 2;
    CGFloat originY = (self.frame.size.height - 32 * heightPerPixel) / 2;
    CGContextRef context = (CGContextRef)[[NSGraphicsContext currentContext] graphicsPort];
    CGContextSetFillColorWithColor(context, [[NSColor grayColor] CGColor]);
    CGContextFillRect(context, dirtyRect);
    
    CGContextSetFillColorWithColor(context, [[NSColor redColor] CGColor]);
    CGContextSetStrokeColorWithColor(context, [[NSColor whiteColor] CGColor]);
    for (int i = 0; i < 128; ++i) {
        for (int j = 0; j < 32; ++j) {
            if (buffer != NULL) {
                if ([self colorTest:i y:j]) {
                    CGContextSetFillColorWithColor(context, [[NSColor blueColor] CGColor]);
                } else {
                    CGContextSetFillColorWithColor(context, [[NSColor blackColor] CGColor]);
                }

            } else {
            if ([self colorTest:i / 128.0 * self.image.size.width y:j / 32.0 * self.image.size.height]) {
                CGContextSetFillColorWithColor(context, [[NSColor blueColor] CGColor]);
            } else {
                CGContextSetFillColorWithColor(context, [[NSColor blackColor] CGColor]);
            }
            }
            CGContextFillEllipseInRect(context, CGRectMake(originX + i * widthPerPixel, originY + j * heightPerPixel, widthPerPixel, heightPerPixel));
        }
    }
}

- (NSArray *)genOLEDBuffer {
    NSMutableArray *bufferOLED = [NSMutableArray new];
    for (int j = 0; j < 32 / 8; ++j) {
        for (int i = 0; i < 128; ++i) {
            uint8_t dot = 0x00;
            for (uint8_t k = 0; k < 8; ++k) {
                BOOL blin = [self colorTest:i y:j * 8 + k];
                uint8_t val = blin ? 0xff : 0x00;
                dot |= (0x01 << k) & val;
            }
            [bufferOLED addObject:@(dot)];
        }
    }
    return [bufferOLED copy];
}

- (void)loadOLEDBuffer:(uint8_t *)buff len:(int)bufferLen {
    buffer = buff;
    [self setNeedsDisplay:YES];
}

@end
