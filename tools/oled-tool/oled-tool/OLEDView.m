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
}
@property (strong, nonatomic) NSImage *image;
@property (assign, nonatomic) CGSize size;
@end

@implementation OLEDView

- (void)setImage:(NSImage *)image size:(CGSize)size {

        self.image = image;
        self.size = size;
        [self extractImageFile:image];
    [self setNeedsDisplay:YES];
}

- (void)extractImageFile:(NSImage *)image {
    NSRect imageRect = NSMakeRect(0, 0, image.size.width, image.size.height);
    CGImageRef imageRef = [image CGImageForProposedRect:&imageRect context:nil hints:nil];
    size_t width = CGImageGetWidth(imageRef);
    size_t height = CGImageGetHeight(imageRef);
    originWidth = width;
    originHeight = height;
    
    textureData = (unsigned char *)malloc(width * height * 4);
    
    CGColorSpaceRef colorSpace = CGColorSpaceCreateDeviceRGB();
    NSUInteger bytesPerPixel = 4;
    NSUInteger bytesPerRow = bytesPerPixel * width;
    NSUInteger bitsPerComponent = 8;
    
    CGContextRef context = CGBitmapContextCreate(textureData, width, height,
                                                 bitsPerComponent, bytesPerRow, colorSpace,
                                                 kCGImageAlphaPremultipliedLast | kCGBitmapByteOrder32Big);
    CGColorSpaceRelease(colorSpace);
    if (context) {
        CGAffineTransform flipVertical = CGAffineTransformMake(1, 0, 0, -1, 0, height);
        CGContextConcatCTM(context, flipVertical);
        CGContextDrawImage(context, CGRectMake(0, 0, width, height), imageRef);
    }
    CGContextRelease(context);
}

- (bool)colorTest:(CGFloat)x y:(CGFloat)y {
    if (textureData != NULL) {
        int bytesPerPixel = 4;// R G B A  4 bytes
        int bytesPerRow = originWidth * bytesPerPixel;
        int loc = y * bytesPerRow + x * bytesPerPixel;
        unsigned char rComponent = *(textureData + loc);
        unsigned char aComponent = *(textureData + loc + 3);
        return rComponent > 0xff / 2.0;
    }
    return false;
}

- (void)drawRect:(NSRect)dirtyRect {
    [super drawRect:dirtyRect];
    CGFloat widthPerPixel = self.frame.size.width / 128;
    CGFloat heightPerPixel = self.frame.size.height / 32;
    CGContextRef context = (CGContextRef)[[NSGraphicsContext currentContext] graphicsPort];
    CGContextSetFillColorWithColor(context, [[NSColor redColor] CGColor]);
    CGContextSetStrokeColorWithColor(context, [[NSColor whiteColor] CGColor]);
    for (int i = 0; i < 128; ++i) {
        for (int j = 0; j < 32; ++j) {
            if ([self colorTest:i y:j]) {
                CGContextSetFillColorWithColor(context, [[NSColor greenColor] CGColor]);
            } else {
                CGContextSetFillColorWithColor(context, [[NSColor redColor] CGColor]);
            }
            CGContextFillRect(context, CGRectMake(i * widthPerPixel, j * heightPerPixel, widthPerPixel, heightPerPixel));
//            CGContextStrokeRect(context, CGRectMake(i * widthPerPixel, j * heightPerPixel, widthPerPixel, heightPerPixel));
        }
    }
}

@end
