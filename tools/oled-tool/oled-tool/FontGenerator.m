//
//  FontGenerator.m
//  oled-tool
//
//  Created by wangyang on 2017/3/2.
//  Copyright © 2017年 wangyang. All rights reserved.
//

#import "FontGenerator.h"
#import <AppKit/AppKit.h>

@implementation FontGenerator
+ (NSImage *)charactorBitmap:(NSString *)str {
    NSDictionary *attrs = @{NSFontAttributeName: [NSFont fontWithName:@"Arial" size:30]};
    NSSize textSize =  [str sizeWithAttributes:attrs];
    if (textSize.width == 0 || textSize.height == 0) {
        textSize.width = 40;
        textSize.height = 40;
    }
    NSImage *image = [[NSImage alloc] initWithSize:NSMakeSize(textSize.width, textSize.height)];
    [image lockFocus];
    [str drawInRect:NSMakeRect(0, 0, textSize.width, textSize.height) withAttributes: attrs];
    [image unlockFocus];
    return image;
}

+ (NSArray *)bufferForCharactorBitmap:(NSImage *)image {
    NSBitmapImageRep *rawImg = [NSBitmapImageRep imageRepWithData:[image TIFFRepresentation]];
    int height = 8;
    int width = 2 + (int)(height / image.size.height * image.size.width);
    NSMutableArray *bufferOLED = [NSMutableArray new];
    for (int i = 0; i < width; ++i) {
        uint8_t dot = 0x00;
        for (uint8_t k = 0; k < 8; ++k) {
            int imageX = (CGFloat)i / width * image.size.width;
            int imageY = (CGFloat)k / height * image.size.height;
            BOOL blin = [rawImg colorAtX:imageX y:image.size.height - imageY].alphaComponent > 0;
            uint8_t val = blin ? 0xff : 0x00;
            dot |= (0x01 << k) & val;
        }
        [bufferOLED addObject:@(dot)];
    }
    return [bufferOLED copy];
}

+ (NSString *)genDefaultTable {
     NSString *table = @"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890.?!#";
//    for (uint8_t ch = 0x20; ch <= 0xfe; ++ch) {
//        table = [table stringByAppendingFormat:@"%c", ch];
//    }
    return [self genFontTable:table];
}

+ (NSString *)genFontTable:(NSString *)table {
    NSMutableDictionary *tableDic = [NSMutableDictionary new];
    for (int count = 0; count < table.length; ++count) {
        NSString *key = [NSString stringWithFormat:@"%c", [table characterAtIndex:count]];
        NSImage *img = [FontGenerator charactorBitmap:key];
        NSArray *buf = [FontGenerator bufferForCharactorBitmap:img];
        
        [tableDic setObject:buf forKey:key];
    }

    return [self genFontTableFromDictionary:tableDic];
}

+ (NSString *)genFontTableFromDictionary:(NSDictionary *)table {
    int charactorCount = (int)[table count];
    NSString *result = @"static uint8_t fontLib[] = {";
    result = [result stringByAppendingFormat:@"0x%x, ", (uint8_t)charactorCount];
    
    NSArray *keys = [table.allKeys sortedArrayUsingComparator:^NSComparisonResult(id  _Nonnull obj1, id  _Nonnull obj2) {
        char ch1 = [obj1 characterAtIndex:0];
        char ch2 = [obj2 characterAtIndex:0];
        return ch1 < ch2;
    }];
    
    for (NSString *key in keys) {
        char ch = [key characterAtIndex:0];
        result = [result stringByAppendingFormat:@"0x%x, ", (uint8_t)ch];
    }
    
    for (NSString *key in keys) {
        NSArray *data = table[key];
        result = [result stringByAppendingFormat:@"0x%x, ", (uint8_t)data.count];
    }
    
    for (NSString *key in keys) {
        NSArray *data = table[key];
        for (NSNumber *number in data) {
             result = [result stringByAppendingFormat:@"0x%x, ", (uint8_t)[number unsignedIntValue]];
        }
    }
    result = [result stringByAppendingString:@"};"];
    return result;
}

+ (NSArray *)bufferForCharactor:(char)charactor inFontLib:(uint8_t *)buffer {
    int chCount = buffer[0];
    int chIndex = 0;
    for (int i = 1; i <= chCount; ++i) {
        if (buffer[i] == charactor) {
            chIndex = i - 1;
        }
    }
    int rangeIndex = 1 + chCount + chIndex;
    int len = buffer[rangeIndex];
    int rangeStart = 1 + chCount * 2;
    for (int i = 0; i < chIndex; ++i) {
        rangeStart += buffer[1 + chCount + i];
    }
    int rangeEnd = rangeStart + len - 1;
    
    NSMutableArray *data = [NSMutableArray new];
    for (int i = rangeStart; i <= rangeEnd; ++i) {
        [data addObject:@(buffer[i])];
    }
    return data;
}

@end
