//
//  CApp_CheckForFinishedGame.cpp
//  HelloSDL
//
//  Created by sasoh on 30.10.11.
//  Copyright (c) 2011 Student. All rights reserved.
//

#include "CApp.h"

int CApp::GetElementFromArray(int row, int col) {
    return grid[row * 3 + col];
}

int CApp::CheckForFinishedGame() {
    int winner = DRAW;
    
    // check horizontal lines
    for (int i = 0; i < 3; i++) {
        if ((GetElementFromArray(i, 0) == GetElementFromArray(i, 1)) &&
            (GetElementFromArray(i, 1) == GetElementFromArray(i, 2)) &&
            (GetElementFromArray(i, 0) == GetElementFromArray(i, 2)) &&            
            (GetElementFromArray(i, 0) != GRID_TYPE_NONE)) {
            return (winner = GetElementFromArray(i, 0) == PLAYER_1? PLAYER_1: PLAYER_2);
        }
    }
    
    // check vertical lines
    for (int i = 0; i < 3; i++) {
        if ((GetElementFromArray(0, i) == GetElementFromArray(1, i)) &&
            (GetElementFromArray(1, i) == GetElementFromArray(2, i)) &&
            (GetElementFromArray(0, i) == GetElementFromArray(2, i)) &&            
            (GetElementFromArray(0, i) != GRID_TYPE_NONE)) {
            return (winner = GetElementFromArray(0, i) == PLAYER_1? PLAYER_1: PLAYER_2);
        }
    }
    
    // check first diagonal
    if ((GetElementFromArray(0, 0) == GetElementFromArray(1, 1)) &&
        (GetElementFromArray(1, 1) == GetElementFromArray(2, 2)) &&
        (GetElementFromArray(0, 0) == GetElementFromArray(2, 2)) &&            
        (GetElementFromArray(0, 0) != GRID_TYPE_NONE)) {
        return (winner = GetElementFromArray(0, 0) == PLAYER_1? PLAYER_1: PLAYER_2);
    }
    
    // check second diagonal
    if ((GetElementFromArray(0, 2) == GetElementFromArray(1, 1)) &&
        (GetElementFromArray(1, 1) == GetElementFromArray(2, 0)) &&
        (GetElementFromArray(0, 2) == GetElementFromArray(2, 0)) &&            
        (GetElementFromArray(0, 2) != GRID_TYPE_NONE)) {
        return (winner = GetElementFromArray(0, 2) == PLAYER_1? PLAYER_1: PLAYER_2);
    }

    // check for draw game
    for (int i = 0; i < 9; i++) {
        if (grid[i] == GRID_TYPE_NONE) {
            winner = NOBODY;
            break;
        }
    }
    return winner;
}
