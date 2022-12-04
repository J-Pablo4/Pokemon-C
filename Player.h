#ifndef POKEMON_PLAYER_H
#define POKEMON_PLAYER_H

#include "raylib.h"
#include <stdlib.h>
#include <stdio.h>
//#include "Pokemon.h"
#include "Lists.h"
#include "raylib.h"
#define MAX_FRAME_SPEED 10
#define MIN_FRAME_SPEED 1
#define PLAYER_HOR_SPD 100.0f
#define G 450
#define PLAYER_JUMP_SPD 410.0f \




typedef struct redPlayer RedPlayer;
typedef struct npc NPC;
void UpdatePlayer(float delta, RedPlayer *player);
RedPlayer* InitPlayer(int x, int y);
NPC* initNPC(int x, int y, Texture2D txtr);
Rectangle updatePlayerTexture(Texture2D playerTxtr, RedPlayer *player);
Vector2 getPlayerPos(RedPlayer *player);
void RenderPlayer(RedPlayer *player, int width);
void setPlayerTexture(Texture2D txtr, RedPlayer *player);
Rectangle getPlayerArea(RedPlayer *player, Texture2D playerTXTR);
Rectangle getMask(RedPlayer *player);
Vector2 getPlayerPos(RedPlayer *player);
Vector2 getNPCVector2(NPC *npc);
Texture2D getNPCTxtr(NPC *npc);
#endif //POKEMON_PLAYER_H
