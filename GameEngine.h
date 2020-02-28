//
// Created by AAR on 2020-02-18.
//

#ifndef CGAME_GAMEENGINE_H
#define CGAME_GAMEENGINE_H

#include <vector>
#include "GUI.h"
#include "Sprite.h"

using namespace std;

class GameEngine {
public:
    vector<int> spritesToRemoveIndex;
    vector<Sprite*>  spritesToDelete;
    vector<Sprite*>  sprites;
    SDL_Renderer* renderer;
    GUI* gui;
    GameEngine(GUI* gui, SDL_Renderer* renderer, int windowHeight, int windowWidth);
    void gameLoop();
    void addSprites(std::vector<Sprite*> sprites);
private:
    int windowWidth;
    int windowHeight;
   void addSprite(Sprite* sprite);
   bool offScreen(Sprite* sprite);
};


#endif //CGAME_GAMEENGINE_H
