//
// Created by AAR on 2020-02-18.
//

/*
 * Creates window and renderer.
 *
 *
 *
 */

#ifndef CGAME_WINDOW_H
#define CGAME_WINDOW_H

#include <SDL_video.h>
#include <SDL_image.h>
#include "stdio.h"
#include <iostream>


using namespace std;

class GUI{

public:
//Constructor takes size of window
    GUI(string name, int height, int width);
    SDL_Window *getWin() const;
    SDL_Renderer *getRen() const;
    ~GUI();

    //Renderer mainly used by GameEngine and Sprites
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
};


#endif //CGAME_WINDOW_H
