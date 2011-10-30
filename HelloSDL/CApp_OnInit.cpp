//
//  CApp_OnInit.cpp
//  HelloSDL
//
//  Created by sasoh on 22.10.11.
//  Copyright (c) 2011 Student. All rights reserved.
//

#include "CApp.h"

bool CApp::OnInit() {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        return false;
    }
    if (NULL == (Display_Surface = SDL_SetVideoMode(display_width, display_height, 32, SDL_HWSURFACE | SDL_DOUBLEBUF))) {
        return false;
    }
    if (NULL == (Grid_Surface = CSurface::OnLoad((char *)"grid.bmp"))) {
        return false;
    }
    if (NULL == (X_Surface = CSurface::OnLoad((char *)"x.bmp"))) {
        return false;
    }
    if (NULL == (O_Surface = CSurface::OnLoad((char *)"o.bmp"))) {
        return false;
    }
    CSurface::Transparent(X_Surface, 255, 0, 255);
    CSurface::Transparent(O_Surface, 255, 0, 255);
    Reset();
    return true;
}