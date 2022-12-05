#ifndef POKEMON_PLAYER_H
#define POKEMON_PLAYER_H

#include "raylib.h"
#include <stdlib.h>
#include <stdio.h>
#include "Lists.h"

typedef struct redPlayer RedPlayer;
typedef struct enemy Enemy;

RedPlayer* init_player();
List* get_player_pokemons(RedPlayer *player);
void set_player_potions(RedPlayer *player);
List* get_enemy_pokemons(Enemy *enemy);
Enemy* init_enemy(char *name);
char* get_enemy_name(Enemy *enemy);

#endif //POKEMON_PLAYER_H
