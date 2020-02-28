//
// Created by AAR on 2020-02-15.
//

#include "Sprite.h"
#include <string>
#include <iostream>

Sprite::Sprite(int xPos,int yPos, string path, SDL_Renderer* renderer){

    image = IMG_Load(path.c_str());
    this->texture = SDL_CreateTextureFromSurface(renderer,image);
    rect = {xPos,yPos, image->w,image->h};
    this->renderer = renderer;

};

void Sprite::draw(){

   SDL_RenderCopy(renderer,texture,NULL,&rect);

}






