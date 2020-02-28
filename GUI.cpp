//
// Created by AAR on 2020-02-18.
//

#include "GUI.h"


GUI::GUI(string name, int height, int width){
    std::cout << "GameStart" << std::endl;
    int SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow(name.c_str(),
                                       SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,
                                       800,500,SDL_WINDOW_SHOWN);
    std::cout << "GameStart" << std::endl;
    if (window == nullptr) {
        cerr <<"Fel" <<SDL_GetError() <<endl;
        SDL_Quit();
        exit(-1);
    }

    renderer = SDL_CreateRenderer(window, -1, 0);
    if (renderer == nullptr) {
        cerr << "Fel:"  << SDL_GetError() << endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        exit(-1);
    }

}

GUI::~GUI(){
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
};

SDL_Window *GUI::getWin() const { return window; }

SDL_Renderer *GUI::getRen() const { return renderer; };