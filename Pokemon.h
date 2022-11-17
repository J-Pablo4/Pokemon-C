//
// Created by jplop on 11/11/2022.
//

#ifndef POKEMON_POKEMON_H
#define POKEMON_POKEMON_H

#include <stdio.h>
#include <time.h>

typedef struct pokemon Pokemon;

Pokemon* new_pokemon(char *name, int hp, int attack, int defense, int speed, int S_attack, int S_defense);

#endif //POKEMON_POKEMON_H
