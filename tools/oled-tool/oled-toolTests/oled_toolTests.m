//
//  oled_toolTests.m
//  oled-toolTests
//
//  Created by wangyang on 2017/2/27.
//  Copyright © 2017年 wangyang. All rights reserved.
//

#import <XCTest/XCTest.h>
#import "OLEDView.h"

@interface oled_toolTests : XCTestCase

@end

@implementation oled_toolTests

- (void)setUp {
    [super setUp];
    // Put setup code here. This method is called before the invocation of each test method in the class.
}

- (void)tearDown {
    // Put teardown code here. This method is called after the invocation of each test method in the class.
    [super tearDown];
}

- (void)testExample {
    // This is an example of a functional test case.
    // Use XCTAssert and related functions to verify your tests produce the correct results.
    OLEDView *oledView = [[OLEDView alloc] init];
    [oledView extractImageFile:[NSImage imageNamed:@"particle_fire.png"]];
}

- (void)testPerformanceExample {
    // This is an example of a performance test case.
    [self measureBlock:^{
        // Put the code you want to measure the time of here.
    }];
}

@end
