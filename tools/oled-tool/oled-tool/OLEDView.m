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
@property (strong, nonatomic) NSBitmapImageRep *rawImg;
@end

@implementation OLEDView

- (void)setImage:(NSImage *)image size:(CGSize)size {
    self.image = image;
    self.size = size;
    self.rawImg = [NSBitmapImageRep imageRepWithData:[image TIFFRepresentation]];
    [self setNeedsDisplay:YES];
}

- (bool)colorTest:(CGFloat)x y:(CGFloat)y {
    NSColor *color =  [self.rawImg colorAtX:x y:self.image.size.height - y];
    return [color alphaComponent] == 1;
}

- (void)drawRect:(NSRect)dirtyRect {
    [super drawRect:dirtyRect];
    CGFloat scaleX = self.image.size.width / self.frame.size.width;
    CGFloat scaleY = self.image.size.height / self.frame.size.height;
    CGFloat scale = scaleX > scaleY ? scaleX : scaleY;
    CGFloat widthPerPixel = 1 / scale;
    CGFloat heightPerPixel = widthPerPixel * 1.5;
    CGFloat originX = (self.frame.size.width - self.image.size.width * widthPerPixel) / 2;
    CGFloat originY = (self.frame.size.height - self.image.size.height * heightPerPixel) / 2;
    CGContextRef context = (CGContextRef)[[NSGraphicsContext currentContext] graphicsPort];
    CGContextSetFillColorWithColor(context, [[NSColor grayColor] CGColor]);
    CGContextFillRect(context, dirtyRect);
    
    CGContextSetFillColorWithColor(context, [[NSColor redColor] CGColor]);
    CGContextSetStrokeColorWithColor(context, [[NSColor whiteColor] CGColor]);
    for (int i = 0; i < 128; ++i) {
        for (int j = 0; j < 32; ++j) {
            if ([self colorTest:i y:j]) {
                CGContextSetFillColorWithColor(context, [[NSColor blueColor] CGColor]);
            } else {
                CGContextSetFillColorWithColor(context, [[NSColor blackColor] CGColor]);
            }
            CGContextFillEllipseInRect(context, CGRectMake(originX + i * widthPerPixel, originY + j * heightPerPixel, widthPerPixel, heightPerPixel));
        }
    }
}

@end
