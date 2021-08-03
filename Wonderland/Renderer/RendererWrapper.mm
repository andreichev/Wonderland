//
//  CounterWrapper.mm
//  Wonderland
//
//  Created by Admin on 02.08.2021.
//

#import "RendererWrapper.h"
#import "OpenGLRenderer.hpp"

@implementation RendererWrapper {
    OpenGLRenderer* renderer;
}

- (instancetype)init {
    self = [super init];
    NSString* path = NSBundle.mainBundle.resourcePath;
    renderer = new OpenGLRenderer(path.UTF8String);
    return self;
}

- (void) updateScreenSize:(float)width height:(float) height {
    renderer->updateScreenSize(width, height);
}

- (void) render: (float) time {
    renderer->render(time);
}

@end

