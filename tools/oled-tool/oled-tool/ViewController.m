//
//  ViewController.m
//  oled-tool
//
//  Created by wangyang on 2017/2/27.
//  Copyright © 2017年 wangyang. All rights reserved.
//

#import "ViewController.h"
#import "BufferArrayGenerator.h"
#import "FontGenerator.h"

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
}

- (IBAction)imgSelectButtonClicked:(id)sender {
    NSOpenPanel* panel = [NSOpenPanel openPanel];
    panel.allowedFileTypes = @[@"png", @"jpg", @"jpeg", @"gif", @"bmp"];
    [panel beginWithCompletionHandler:^(NSInteger result){
        if (result == NSFileHandlingPanelOKButton) {
            NSURL*  theDoc = [[panel URLs] objectAtIndex:0];
            NSImage *image = [[NSImage alloc] initWithContentsOfURL:theDoc];
            self.inputImageView.image = image;
        }
    }];
}
- (IBAction)fontTableButtonClicked:(id)sender {
    NSString *fontTable = [FontGenerator genDefaultTable];
    [self.outputTextView setString:fontTable];
}

- (IBAction)imageGenOLEDButtonClicked:(id)sender {
    if (self.inputImageView.image) {
        [self.outputView setImage:self.inputImageView.image  size:CGSizeMake([self.oledWidth.stringValue integerValue], [self.oledHeight.stringValue integerValue])];
        
        NSArray *buffer = [self.outputView genOLEDBuffer];
        NSString *bytesStr = [BufferArrayGenerator gen:buffer];
        [self.outputTextView setString:bytesStr];
    } else {
        NSAlert *alert = [[NSAlert alloc] init];
        alert.messageText = @"没有选择图片";
        alert.alertStyle = NSAlertStyleWarning;
        [alert runModal];
    }
}

- (IBAction)saveButtonClicked:(id)sender {
    NSString *bytesStr = self.outputTextView.string;
    NSSavePanel* panel = [NSSavePanel savePanel];
    panel.representedFilename = @".h";
    [panel beginWithCompletionHandler:^(NSInteger result){
        if (result == NSFileHandlingPanelOKButton) {
            NSURL*  theDoc = [panel URL];
            [bytesStr writeToURL:theDoc atomically:YES encoding:NSUTF8StringEncoding error:nil];
        }
    }];
}

@end
