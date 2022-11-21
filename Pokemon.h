//
// Created by jplop on 11/11/2022.
//

#ifndef POKEMON_POKEMON_H
#define POKEMON_POKEMON_H

#include <stdio.h>
#include <time.h>
#include "Lists.h"
#include "Attacks.h"

typedef struct pokemon Pokemon;

Pokemon* new_pokemon(char *name, int hp, int attack, int defense, int speed, int S_attack, int S_defense, Type type1, Type type2);
int get_pokemon_attack(Pokemon *pokemon);
int get_pokemon_defense(Pokemon *pokemon);
int get_pokemon_S_attack(Pokemon *pokemon);
int get_pokemon_S_defense(Pokemon *pokemon);
int get_pokemon_speed(Pokemon *pokemon);
int get_pokemon_hp(Pokemon *pokemon);
List* get_pokemon_list_attacks(Pokemon *pokemon);
State get_pokemon_current_state(Pokemon *pokemon);

void modify_pokemon_attack(int attack, Pokemon *pokemon);
void modify_pokemon_defense(int defense, Pokemon *pokemon);
void modify_pokemon_S_attack(int S_attack, Pokemon *pokemon);
void modify_pokemon_S_defense(int S_defense, Pokemon *pokemon);
void modify_pokemon_speed(double speed, Pokemon *pokemon);
void modify_pokemon_hp(int hp, Pokemon *pokemon);
void modify_pokemon_state(State state, Pokemon *pokemon);

#endif //POKEMON_POKEMON_H
