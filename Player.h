//
// Created by aarondev on 11/16/22.
//

#ifndef POKEMON_C_PLAYER_H
#define POKEMON_C_PLAYER_H

#include "raylib.h"
#define PLAYER_HOR_SPD 200.0f
typedef struct redPlayer RedPlayer;
// Rectangle mask;
void UpdatePlayer(float delta, RedPlayer player);

#endif //POKEMON_C_PLAYER_H
