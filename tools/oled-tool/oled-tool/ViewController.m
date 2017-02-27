//
//  ViewController.m
//  oled-tool
//
//  Created by wangyang on 2017/2/27.
//  Copyright © 2017年 wangyang. All rights reserved.
//

#import "ViewController.h"

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];

    // Do any additional setup after loading the view.
}


- (void)setRepresentedObject:(id)representedObject {
    [super setRepresentedObject:representedObject];

    // Update the view, if already loaded.
}

- (IBAction)imgSelectButtonClicked:(id)sender {
    [self.outputView setImage:[NSImage imageNamed:@"particle_fire.png"] size:CGSizeMake(128, 32)];
}

- (IBAction)fontTableGenButtonClicked:(id)sender {
}

@end
