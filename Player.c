#include "Player.h"
#include "stdio.h"
#include "Lists.h"
#include "Pokemon.h"
int framesCounter = 0;

struct redPlayer{
    Vector2 position;
    float speed;
    Vector2 PlayerDirection;
    int right;
    int left;
    int up;
    int down;
    Texture2D playerTXTR;
    Rectangle mask;
};

RedPlayer* InitPlayer(int x, int y){
    RedPlayer *newRed = calloc(1, sizeof(RedPlayer));
    newRed->position.x = (float)x/2;
    newRed->position.y = (float)y/2;
    return newRed;
}

void UpdatePlayer(float delta, RedPlayer *player){
    int frameSpeed = 3;
    int currentFrame = 0;

    if(IsKeyDown(KEY_RIGHT)){
        player->position.x += PLAYER_HOR_SPD*delta;
        player->right = true;
        player->left = false;
        player->PlayerDirection.y = 3;
        player->PlayerDirection.x = 3;
        framesCounter++;

    }
    if(IsKeyDown(KEY_LEFT)){
        player->position.x -= PLAYER_HOR_SPD*delta;
        player->left = true;
        player->PlayerDirection.y = 2;
        player->PlayerDirection.x = 2;
        framesCounter++;
    }
    if(IsKeyDown(KEY_UP)){
        player->position.y -= PLAYER_HOR_SPD*delta;
        player->up = true;
        player->down = false;
        player->PlayerDirection.y = 1;
        player->PlayerDirection.x = 0;
        framesCounter++;
    }
    if(IsKeyDown(KEY_DOWN)){
        player->position.y += PLAYER_HOR_SPD*delta;
        player->down = true;
        player->up = false;
        player->PlayerDirection.y = 0;
        player->PlayerDirection.x = 0;
        framesCounter++;
    }


    if (framesCounter >= frameSpeed){                                  //ANIMATION
        framesCounter= 0;
            player->PlayerDirection.x++;
            currentFrame++;
        if(currentFrame > 5){
            currentFrame = 0;
            player->PlayerDirection.x++;
        } else {
            player->PlayerDirection.x = 1;
        }
    }
}


Vector2 getPlayerPos(RedPlayer *player){
    Vector2 pos;
    pos.x = player->position.x;
    pos.y = player->position.y;
    return pos;
}

void setPlayerTexture(Texture2D t, RedPlayer *player)
{
    player->playerTXTR = t;
}

void RenderPlayer(RedPlayer *player, int width)
{
    Rectangle mask;
    mask.y =player->PlayerDirection.y * (float)player->playerTXTR.height/4;
    mask.x =player->PlayerDirection.x * (float)player->playerTXTR.width/3;
    mask.height = player->playerTXTR.height/4;
    mask.width = player->playerTXTR.width/3;
    DrawTextureRec(player->playerTXTR, mask, getPlayerPos(player), WHITE);

}