//
//  CApp_OnRender.cpp
//  HelloSDL
//
//  Created by sasoh on 22.10.11.
//  Copyright (c) 2011 Student. All rights reserved.
//

#include "CApp.h"

void CApp::OnRender() {
    CSurface::OnDraw(Display_Surface, Grid_Surface, 0, 0);
    for (int i = 0; i < 9; i++) {
        int X = (i % 3) * 200;
        int Y = (i / 3) * 200;
        if (grid[i] == GRID_TYPE_0) {
            CSurface::OnDraw(Display_Surface, O_Surface, X, Y);
        }
        if (grid[i] == GRID_TYPE_X) {
            CSurface::OnDraw(Display_Surface, X_Surface, X, Y);
        }
    }
    SDL_Flip(Display_Surface);
}