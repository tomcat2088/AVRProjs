//
//  FontGenerator.h
//  oled-tool
//
//  Created by wangyang on 2017/3/2.
//  Copyright © 2017年 wangyang. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface FontGenerator : NSObject
+ (NSImage *)charactorBitmap:(NSString *)str;
+ (NSArray *)bufferForCharactorBitmap:(NSImage *)image;
+ (NSString *)genDefaultTable;
+ (NSString *)genFontTable:(NSString *)tabl;
+ (NSArray *)bufferForCharactor:(char)charactor inFontLib:(uint8_t *)buffer;
@end
