#ifndef POKEMON_PLAYER_H
#define POKEMON_PLAYER_H

#include "raylib.h"
#include <stdlib.h>
#include <stdio.h>

#define MAX_FRAME_SPEED 10
#define MIN_FRAME_SPEED 1
#define PLAYER_HOR_SPD 100.0f
#define G 450
#define PLAYER_JUMP_SPD 410.0f \

typedef struct redPlayer RedPlayer;
void UpdatePlayer(float delta, RedPlayer *player);
RedPlayer* InitPlayer(int x, int y);
Rectangle updatePlayerTexture(Texture2D playerTxtr, RedPlayer *player);
Vector2 getPlayerPos(RedPlayer *player);
void RenderPlayer(RedPlayer *player, int width);
void setPlayerTexture(Texture2D t, RedPlayer *player);
void get_player_pokemons(RedPlayer *player);
void set_player_potions(RedPlayer *player);
#endif //POKEMON_PLAYER_H
