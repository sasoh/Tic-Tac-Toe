//
//  CApp.cpp
//  HelloSDL
//
//  Created by sasoh on 22.10.11.
//  Copyright (c) 2011 Student. All rights reserved.
//

#include "CApp.h"

CApp::CApp() {
    Running = true;
    display_width = 640;
    display_height = 480;
    Display_Surface = NULL;
    X_Surface = NULL;
    O_Surface = NULL;
    Grid_Surface = NULL;
    current_player = 1;
    memset(grid, 0, sizeof(grid));
}

CApp::CApp(int width, int height) {
    Running = true;
    Display_Surface = NULL;
    X_Surface = NULL;
    O_Surface = NULL;
    Grid_Surface = NULL;
    display_width = width;
    display_height = height;
    current_player = 1;
    memset(grid, 0, sizeof(grid));
}

int CApp::OnExecute() {
    if (false == OnInit()) {
        return -1;
    }
    SDL_Event Event;
    while (true == Running) {
        // game loop
        while (SDL_PollEvent(&Event)) {
            OnEvent(&Event);
        }
        OnLoop();
        OnRender();
    }
    OnCleanup();
    return 0;
}

void CApp::Reset() {
    for (int i = 0; i < 9; i++) {
        grid[i] = GRID_TYPE_NONE;
    }
}