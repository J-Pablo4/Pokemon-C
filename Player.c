#include "Player.h"
#include <stdio.h>
#include "Pokemon.h"
#include "raylib.h"
int framesCounter = 0;
struct redPlayer{
    Vector2 position;
    float speed;
    Vector2 PlayerDirection;
    int right;
    int left;
    int up;
    int down;
    int widht;
    int height;
    Texture2D playerTXTR;
    Rectangle mask;
    List *pokemons;
    Potion potions[5];
};

struct npc{
    List *pokemon;
    Vector2 npcPosition;
    Texture2D txtr;
};

struct npc{
    List *pokemon;
    Vector2 npcPosition;
    Texture2D txtr;
};

RedPlayer* InitPlayer(int x, int y){
    RedPlayer *newRed = calloc(1, sizeof(RedPlayer));
    newRed->position.x = ((float)x/2)+10;
    newRed->position.y = 600;
    newRed->pokemons = list_new();
    return newRed;
}

NPC* initNPC(int x, int y, Texture2D txtr)
{
    NPC *newNPC = calloc(1, sizeof(NPC));
    newNPC->npcPosition.x = x;
    newNPC->npcPosition.y = y;
    newNPC->txtr = txtr;
    return newNPC;
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

void setPlayerPos(RedPlayer *player, int a, int b){
    player->position.x = a;
    player->position.y = b;
}

void setPlayerTexture(Texture2D txtr, RedPlayer *player)
{
    player->playerTXTR = txtr;
}

void RenderPlayer(RedPlayer *player, int width)
{
    Rectangle mask;
    mask.y =player->PlayerDirection.y * (float)player->playerTXTR.height/4;
    mask.x =player->PlayerDirection.x * (float)player->playerTXTR.width/3;
    mask.height = player->playerTXTR.height/4;
    mask.width = player->playerTXTR.width/3;
    player->mask = mask;
    DrawTextureRec(player->playerTXTR, mask, getPlayerPos(player), WHITE);
}

Rectangle getPlayerArea(RedPlayer *player, Texture2D playerTXTR)
{
    Rectangle playerArea = {player->position.x, player->position.y,(float)playerTXTR.width/3, (float)playerTXTR.height/4};
    return playerArea;
}

Rectangle getMask(RedPlayer *player){
    return player->mask;
}

Vector2 getNPCVector2(NPC *npc);
Vector2 getNpcVector2(NPC *npc) {
    return npc->npcPosition;
}

Texture2D getNPCTxtr(NPC *npc)
{
    return npc->txtr;
}

void setNPCTxtr(Texture2D npcTxtr, NPC npc)
{

}

void set_player_potions(RedPlayer *player)
{
    player->potions[0] = potion;
    player->potions[1] = potion;
    player->potions[2] = super_potion;
    player->potions[3] = hyper_potion;
    player->potions[4] = max_potion;
}

List* get_player_pokemons(RedPlayer *player)
{
    return player->pokemons;
}
