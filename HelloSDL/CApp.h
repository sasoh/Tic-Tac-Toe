//
//  CApp.h
//  HelloSDL
//
//  Created by sasoh on 22.10.11.
//  Copyright (c) 2011 Student. All rights reserved.
//

#ifndef HelloSDL_CApp_h
#define HelloSDL_CApp_h

#include <iostream>
#include <SDL/SDL.h>
#include "CSurface.h"
#include "CEvent.h"

using std::cout;
using std::cin;
using std::endl;

class CApp: public CEvent {
    public:
        CApp();
        CApp(int width, int height);
        int OnExecute();
        void Reset();
        bool OnInit();
        void OnEvent(SDL_Event *Event);
        virtual void OnLButtonDown(int mX, int mY);
        void OnLoop();
        void OnRender();
        void OnCleanup();
        void OnExit();
    private:
        bool Running;
        int display_width;
        int display_height;
        int current_player;
        enum {
            GRID_TYPE_NONE,
            GRID_TYPE_X,
            GRID_TYPE_0,
        };
        int grid[9];
        SDL_Surface *Display_Surface;
        SDL_Surface *Grid_Surface;
        SDL_Surface *X_Surface;
        SDL_Surface *O_Surface;
};

#endif
