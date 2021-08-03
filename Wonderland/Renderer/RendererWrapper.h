//
//  CounterWrapper.h
//  Wonderland
//
//  Created by Admin on 02.08.2021.
//

#import <Foundation/Foundation.h>

@interface RendererWrapper : NSObject

- (void) render:(float) time;
- (void) updateScreenSize:(float)width height:(float) height;

@end
