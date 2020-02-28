//
// Created by AAR on 2020-02-19.
//

#include "MovingSprite.h"

void MovingSprite::tick(int x, int y){

    move(x,y);
    draw();

}