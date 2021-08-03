//
//  AppDelegate.swift
//  Wonderland
//
//  Created by Admin on 02.08.2021.
//

#import "AppDelegate.h"
#import "WonderController.h"

@implementation AppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    WonderController* controller = [[WonderController alloc] init];
    _window = [[UIWindow alloc] initWithFrame:UIScreen.mainScreen.bounds];
    
    _window.rootViewController = controller;
    [_window makeKeyAndVisible];
    
    return YES;
}

@end
