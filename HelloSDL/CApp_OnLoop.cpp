//
//  CApp_OnLoop.cpp
//  HelloSDL
//
//  Created by sasoh on 22.10.11.
//  Copyright (c) 2011 Student. All rights reserved.
//

#include "CApp.h"

void CApp::OnLoop() {
    int gameWinner = CheckForFinishedGame();
    if (NOBODY != gameWinner) {
        if (DRAW == gameWinner) {
            cout << "Draw game\n";
        }
        else {
            cout << "Winner is Player " << gameWinner << endl;
        }
        Running = false;
    }
}