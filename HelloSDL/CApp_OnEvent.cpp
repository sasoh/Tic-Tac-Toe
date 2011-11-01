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
    if (PLAYER_1 == current_player) {
        current_player = PLAYER_2;
        grid[ID] = GRID_TYPE_X;
        return; // to prevent fall through
    }
    if (PLAYER_2 == current_player) {
        current_player = PLAYER_1;
        grid[ID] = GRID_TYPE_0;
        return; // to prevent fall through
    }
}