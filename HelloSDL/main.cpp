//
//  main.cpp
//  HelloSDL
//
//  Created by Richard Carter on 5/30/11.
//  Copyright 2011 Richard Carter. All rights reserved.
//

#include <iostream>
#include <SDL/SDL.h>
#include "main.h"
#include "CApp.h"

using std::cout;
using std::cin;
using std::endl;

int SDL_main (int argc, char **argv) {
    CApp app(600, 600);
    return app.OnExecute();
}
