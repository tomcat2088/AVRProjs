//
//  ViewController.h
//  oled-tool
//
//  Created by wangyang on 2017/2/27.
//  Copyright © 2017年 wangyang. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "OLEDView.h"

@interface ViewController : NSViewController
@property (weak) IBOutlet NSImageView *imgView;
@property (weak) IBOutlet OLEDView *outputView;
@property (weak) IBOutlet NSImageView *inputImageView;
@property (weak) IBOutlet NSTextView *outputTextView;
@property (weak) IBOutlet NSTextField *oledWidth;
@property (weak) IBOutlet NSTextField *oledHeight;

@end

