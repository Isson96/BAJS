//
// Created by AAR on 2020-02-18.
//

#include "GameEngine.h"
#include "Sprite.h"
#include "NPCSprite.h"

void GameEngine::addSprite(Sprite* sprite){
    GameEngine::sprites.push_back(sprite);
}

void GameEngine::gameLoop() {

    string bPath = SDL_GetBasePath();
    bool runOn = true;
    Sprite * bulMove = new NPCSprite(150, 0, bPath + "Resources/Protagonist.png", renderer, RIGHT);
    sprites.push_back(bulMove);
    // vector<Sprite*> sprites =  {bulMove};


    //insert game specific spawning and destruction "EngineTick"
    int spawnCounter = 0;

    while (runOn) {

        // Put in separate functionset later on
        spawnCounter++;
        if (spawnCounter % 500 == 0) {
            int randomPos = rand() % windowHeight - 100;
            if (randomPos > windowHeight - 200)
                randomPos -= 300;
            if (randomPos < 200)
                randomPos += 300;
            addSprite(new NPCSprite(0, randomPos, bPath + "Resources/Protagonist.png", renderer, RIGHT));
        }

        SDL_Event eve;
        while (SDL_PollEvent(&eve)) {
            switch (eve.type) {
                case SDL_QUIT:
                    runOn = false;
                    break;
                case SDL_KEYDOWN:
                    if (eve.key.keysym.sym == SDLK_DOWN)
                        runOn = false;
                    break;
            } // switch
        } // inre while
        SDL_RenderClear(renderer);
        for (int i = 0; i < sprites.size(); i++) {
            //insert collisioncheck
            if(offScreen(sprites[i])){
                cout<<"time to remove"<<i<<endl;
                GameEngine::spritesToRemoveIndex.push_back(i);
                spritesToDelete.push_back(sprites[i]);
            }else{
                sprites[i]->tick(NULL, NULL);
            }
         }
         for(int i = 0; i < spritesToRemoveIndex.size(); i++){
            GameEngine::sprites.erase(sprites.begin());
         }
         for(int i = 0; i < spritesToDelete.size();i++){
             cout<<"trying to delete"<<spritesToRemoveIndex[i]<<endl;
             delete spritesToDelete[i];
        }
        spritesToRemoveIndex.clear();
        spritesToDelete.clear();
        SDL_RenderPresent(renderer);
    }

    SDL_Quit();

} // yttre while


bool GameEngine::offScreen(Sprite* sprite){

    if(sprite->getRect().x > windowWidth+200){
        return true;
    }
    return false;
}





GameEngine::GameEngine(GUI *gui, SDL_Renderer *renderer,int windowHeight, int windowWidth) {
    this->renderer = renderer;
    this->gui = gui;
    this->windowWidth= windowWidth;
    this->windowHeight = windowHeight;
}


