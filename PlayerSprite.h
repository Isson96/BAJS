//
// Created by AAR on 2020-02-17.
//

#ifndef CGAME_PLAYERSPRITE_H
#define CGAME_PLAYERSPRITE_H

#include "MovingSprite.h"

class Player: public MovingSprite{


//Supposed to respond to keycommands, Isabelle fix this!

public:
    Player(int xPos,int yPos, string path, SDL_Renderer* renderer): MovingSprite(xPos, yPos, path, renderer){}
private:
    void move(int collX, int collY){};

};

#endif //CGAME_PLAYERSPRITE_H
