//
// Created by jplop on 17/11/2022.
//

#ifndef POKEMON_PLAYER_H
#define POKEMON_PLAYER_H

#include "raylib.h"
#include <stdlib.h>
#include <stdio.h>

#define MAX_FRAME_SPEED 10
#define MIN_FRAME_SPEED 1
#define PLAYER_HOR_SPD 100.0f

typedef struct redPlayer RedPlayer;
void UpdatePlayer(float delta, RedPlayer *player);
RedPlayer* InitPlayer(int x, int y);
Rectangle updatePlayerTexture(Texture2D playerTxtr, RedPlayer *player);
Vector2 getPlayerPos(RedPlayer *player);
Rectangle getPlayerArea(RedPlayer *player, Texture2D playerTXTR);
#endif //POKEMON_PLAYER_H
