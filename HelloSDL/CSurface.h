//
//  CSurface.h
//  HelloSDL
//
//  Created by sasoh on 22.10.11.
//  Copyright (c) 2011 Student. All rights reserved.
//

#ifndef HelloSDL_CSurface_h
#define HelloSDL_CSurface_h

#include <SDL/SDL.h>
#include <iostream>

class CSurface {
    public:
        CSurface();
        static SDL_Surface *OnLoad(char *Filename);
        static bool OnDraw(SDL_Surface *Destination_Surface, SDL_Surface *Source_Surface, int x, int y);
        static bool OnDraw(SDL_Surface *Destination_Surface, SDL_Surface *Source_Surface, int x, int y, int x2, int y2, int width, int height);
        static bool Transparent(SDL_Surface *Destination_Surface, int R, int G, int B);
};

#endif
