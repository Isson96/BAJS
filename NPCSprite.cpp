//
// Created by AAR on 2020-02-18.
//

#include "NPCSprite.h"
NPCSprite::NPCSprite(int xPos, int yPos, string path, SDL_Renderer *renderer,Direction direction)
        : MovingSprite(xPos, yPos, path, renderer) {
    this->direction = direction;
}

void NPCSprite::move(int collideX, int collideY){
    switch(direction){
        case(TOP):
            rect.y--;
            break;
        case(BOT):
            rect.y++;
            break;
        case(LEFT):
            rect.x--;
            break;
        case(RIGHT):
            rect.x++;
            break;
    }
}

void NPCSprite::tick(int collisionX, int collisionY){
    draw();
    move(collisionX,collisionY);
}

