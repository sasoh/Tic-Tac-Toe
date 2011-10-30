//
//  CApp_OnCleanup.cpp
//  HelloSDL
//
//  Created by sasoh on 22.10.11.
//  Copyright (c) 2011 Student. All rights reserved.
//

#include "CApp.h"

void CApp::OnCleanup() {
    SDL_FreeSurface(X_Surface);
    SDL_FreeSurface(O_Surface);
    SDL_FreeSurface(Grid_Surface);
    SDL_FreeSurface(Display_Surface);
    SDL_Quit();
}