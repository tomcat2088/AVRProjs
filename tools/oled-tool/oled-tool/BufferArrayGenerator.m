//
//  BufferArrayGenerator.m
//  oled-tool
//
//  Created by wangyang on 2017/3/2.
//  Copyright © 2017年 wangyang. All rights reserved.
//

#import "BufferArrayGenerator.h"

@implementation BufferArrayGenerator
+ (NSString *)gen:(NSArray *)buffer {
    NSString *template = @"static uint8_t buffer[32 * 128 / 8] = {";
    for (int i = 0; i < [buffer count]; ++i) {
        template = [template stringByAppendingFormat:@"0x%x,", [buffer[i] unsignedIntValue]];
    }
    template = [template stringByAppendingString:@"};"];
    return template;
}
@end
