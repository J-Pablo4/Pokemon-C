//
// Created by jplop on 17/11/2022.
//

#include "Player.h"

struct redPlayer{
    Vector2 position;
    float speed;
    int PlayerDirection;
    int right;
    int left;
    int up;
    int down;
};

RedPlayer* InitPlayer(int x, int y){
    RedPlayer *newRed = calloc(1, sizeof(RedPlayer));
    newRed->position.x = x/2;
    newRed->position.y = y/2;
    return newRed;
}

void UpdatePlayer(float delta, RedPlayer *player){

    if(IsKeyDown(KEY_RIGHT)){
        player->position.x += PLAYER_HOR_SPD*delta;
        player->right = true;
        player->left = false;
        player->down = false;
        player->up = false;
        player->PlayerDirection=1;
    }
    if(IsKeyDown(KEY_LEFT)){
        player->position.x -= PLAYER_HOR_SPD*delta;
        player->right = false;
        player->left = true;
        player->down = false;
        player->up = false;
        player->PlayerDirection=1;
    }
    if(IsKeyDown(KEY_UP)){
        player->position.y += PLAYER_HOR_SPD*delta;
        player->right = false;
        player->left = false;
        player->down = false;
        player->up = true;
        player->PlayerDirection=1;
    }
    if(IsKeyDown(KEY_DOWN)){
        player->position.y -= PLAYER_HOR_SPD*delta;
        player->right = false;
        player->left = false;
        player->down = true;
        player->up = false;
        player->PlayerDirection=1;
    }
}
