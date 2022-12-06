#ifndef POKEMON_PLAYER_H
#define POKEMON_PLAYER_H

#include "raylib.h"
#include <stdlib.h>
#include <stdio.h>
#include "Lists.h"

typedef struct redPlayer RedPlayer;
typedef struct enemy Enemy;

typedef enum potion{potion = 20, super_potion = 50, hyper_potion = 200, max_potion = 100000, none_potion = -1} Potion;

RedPlayer* init_player();
List* get_player_pokemons(RedPlayer *player);
void set_player_potions(RedPlayer *player);
List* get_enemy_pokemons(Enemy *enemy);
Enemy* init_enemy(char *name);
char* get_enemy_name(Enemy *enemy);
Potion* get_player_potions(RedPlayer *player);
void player_normalize(RedPlayer *player);
void player_set_level(RedPlayer *player, int level);

#endif //POKEMON_PLAYER_H
