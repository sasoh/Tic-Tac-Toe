//
//  CSurface.cpp
//  HelloSDL
//
//  Created by sasoh on 22.10.11.
//  Copyright (c) 2011 Student. All rights reserved.
//

#include "CSurface.h"

CSurface::CSurface() {

}

SDL_Surface *CSurface::OnLoad(char *Filename) {
    SDL_Surface *Temp_Surface = NULL;
    SDL_Surface *Result_Surface = NULL;
    
    char source[512] = {""};
    strcat(source, "HelloSDL.app/Contents/Resources/"); // mac compatability
    strcat(source, Filename);
    if (NULL == (Temp_Surface = SDL_LoadBMP(source))) {
        std::cout << "ERR" << std::endl;
        return NULL;
    }
    Result_Surface = SDL_DisplayFormat(Temp_Surface);
    SDL_FreeSurface(Temp_Surface);
    return Result_Surface;
}

bool CSurface::OnDraw(SDL_Surface *Destination_Surface, SDL_Surface *Source_Surface, int x, int y) {
    if (NULL == Destination_Surface || NULL == Source_Surface) {
        return false;   
    }
    SDL_Rect DestinationRect;
    DestinationRect.x = x;
    DestinationRect.y = y;
    SDL_BlitSurface(Source_Surface, NULL, Destination_Surface, &DestinationRect);
    return true;
}

bool CSurface::OnDraw(SDL_Surface *Destination_Surface, SDL_Surface *Source_Surface, int x, int y, int x2, int y2, int width, int height) {
    if (NULL == Destination_Surface || NULL == Source_Surface) {
        return false;   
    }
    SDL_Rect DestinationRect;
    DestinationRect.x = x;
    DestinationRect.y = y;
    SDL_Rect FrameRect;
    FrameRect.x = x2;
    FrameRect.y = y2;
    FrameRect.w = width;
    FrameRect.h = height;
    SDL_BlitSurface(Source_Surface, &FrameRect, Destination_Surface, &DestinationRect);
    return true;
}

bool CSurface::Transparent(SDL_Surface *Destination_Surface, int R, int G, int B) {
    if (Destination_Surface == NULL) {
        return false;
    }
    SDL_SetColorKey(Destination_Surface, SDL_SRCCOLORKEY | SDL_RLEACCEL, SDL_MapRGB(Destination_Surface->format, R, G, B));
    return true;
}
