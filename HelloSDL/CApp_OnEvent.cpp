//
//  CApp_OnEvent.cpp
//  HelloSDL
//
//  Created by sasoh on 22.10.11.
//  Copyright (c) 2011 Student. All rights reserved.
//

#include "CApp.h"

void CApp::OnEvent(SDL_Event *Event) {
    CEvent::OnEvent(Event);
}

void CApp::OnExit() {
    Running = false;
}

void CApp::OnLButtonDown(int mX, int mY) {
    int ID = mX / 200;
    ID = ID + ((mY / 200) * 3);
    if (grid[ID] != GRID_TYPE_NONE) {
        return;
    }
    if (1 == current_player) {
        cout << 1;
        current_player = 2;
        grid[ID] = GRID_TYPE_X;
        return; // to prevent fall through
    }
    if (2 == current_player) {
        cout << 2;
        current_player = 1;
        grid[ID] = GRID_TYPE_0;
        return; // to prevent fall through
    }    
}