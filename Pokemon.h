//
// Created by jplop on 11/11/2022.
//

#ifndef POKEMON_POKEMON_H
#define POKEMON_POKEMON_H

#include <stdio.h>
#include <time.h>

typedef struct pokemon Pokemon;

Pokemon* new_pokemon(char *name, int hp, int attack, int defense, int speed, int S_attack, int S_defense);
int get_pokemon_attack(Pokemon *pokemon);
int get_pokemon_defense(Pokemon *pokemon);
int get_pokemon_S_attack(Pokemon *pokemon);
int get_pokemon_S_defense(Pokemon *pokemon);

void modify_pokemon_attack(int attack, Pokemon *pokemon);
void modify_pokemon_defense(int defense, Pokemon *pokemon);
void modify_pokemon_S_attack(int S_attack, Pokemon *pokemon);
void modify_pokemon_S_defense(int S_defense, Pokemon *pokemon);
void modify_pokemon_speed(int speed, Pokemon *pokemon);

#endif //POKEMON_POKEMON_H
