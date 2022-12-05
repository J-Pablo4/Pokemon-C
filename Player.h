#ifndef POKEMON_PLAYER_H
#define POKEMON_PLAYER_H

#include "raylib.h"
#include <stdlib.h>
#include <stdio.h>
#include "Lists.h"

typedef struct redPlayer RedPlayer;

RedPlayer* init_player();
List* get_player_pokemons(RedPlayer *player);
void set_player_potions(RedPlayer *player);

#endif //POKEMON_PLAYER_H
