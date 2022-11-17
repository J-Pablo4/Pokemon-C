//
// Created by jplop on 17/11/2022.
//

#ifndef POKEMON_PLAYER_H
#define POKEMON_PLAYER_H

#include "raylib.h"
#include <stdlib.h>
#define PLAYER_HOR_SPD 200.0f
typedef struct redPlayer RedPlayer;
// Rectangle mask;
void UpdatePlayer(float delta, RedPlayer *player);
RedPlayer* InitPlayer(int x, int y);
#endif //POKEMON_PLAYER_H
