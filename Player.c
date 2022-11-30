//
// Created by jplop on 17/11/2022.
//

#include "Player.h"
#include "stdio.h"

struct redPlayer{
    Vector2 position;
    float speed;
    int PlayerDirection;
    int right;
    int left;
    int up;
    int down;
    Texture2D playerTXTR;
};

RedPlayer* InitPlayer(int x, int y){
    RedPlayer *newRed = calloc(1, sizeof(RedPlayer));
    newRed->position.x = (float)x/2;
    newRed->position.y = (float)y/2;
    return newRed;
}

void UpdatePlayer(float delta, RedPlayer *player){

    if(IsKeyDown(KEY_RIGHT)){
        player->position.x += PLAYER_HOR_SPD*delta;
        player->right = true;
        player->PlayerDirection=1;

    }
    if(IsKeyDown(KEY_LEFT)){
        player->position.x -= PLAYER_HOR_SPD*delta;
        player->left = true;
        player->PlayerDirection=1;
    }
    if(IsKeyDown(KEY_UP)){
        player->position.y -= PLAYER_HOR_SPD*delta;
        player->up = true;
        player->PlayerDirection=1;
    }
    if(IsKeyDown(KEY_DOWN)){
        player->position.y += PLAYER_HOR_SPD*delta;
        player->down = true;
        player->PlayerDirection=1;
    }
}

Rectangle updatePlayerTexture(Texture2D playerTxtr, RedPlayer *player){

<<<<<<< Updated upstream
    Rectangle framesRed = {getPlayerPos(player).x, getPlayerPos(player).y, (float)playerTxtr.width, (float)playerTxtr.height};
=======
    Rectangle framesRed = {getPlayerPos(player).x, getPlayerPos(player).y, (float)playerTxtr.width/3, (float)playerTxtr.height/3};
>>>>>>> Stashed changes
    int currentFrame = 0;

    int framesCounter = 0;
    int framesSpeed = 8;

    framesCounter ++;
    if(currentFrame >= (60/framesSpeed))
    {
        framesCounter = 0;
        currentFrame ++;

        if(currentFrame > 2)
            framesRed.x = (float)currentFrame*(float)playerTxtr.width/3;

    }

    if(IsKeyDown(KEY_RIGHT))
        framesSpeed++;
    else if(IsKeyDown(KEY_LEFT))
        framesSpeed--;

    if(framesSpeed > MAX_FRAME_SPEED)
        framesSpeed = MAX_FRAME_SPEED;
    else if(framesSpeed < MIN_FRAME_SPEED)
        framesSpeed = MIN_FRAME_SPEED;

    return framesRed;
}

<<<<<<< Updated upstream
Vector2 getPlayerPos( RedPlayer *player)
{
    Vector2 XYPosition;
    XYPosition.x = player->position.x;
    XYPosition.y = player->position.y;
    return XYPosition;
}
=======
Vector2 getPlayerPos(RedPlayer *player){
    Vector2 pos;
    pos.x = player->position.x;
    pos.y = player->position.y;
    return pos;
}
>>>>>>> Stashed changes
