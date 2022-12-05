//
// Created by jplop on 11/11/2022.
//

#ifndef POKEMON_POKEMON_H
#define POKEMON_POKEMON_H

#include <stdio.h>
#include <time.h>
#include "Lists.h"
#include "Attacks.h"
#include "Player.h"

typedef struct pokemon Pokemon;


Pokemon* new_pokemon(char *name, Type type1, Type type2, int hp,  int attack, int defense, int speed, int S_attack, int S_defense);
void define_attacks(char *name, Pokemon *pokemon, Type type, AttackType attack, int power, int precision, int pp, State state_change, int state_probability, Affected_stat affected_stat, int direction, int aggregated);
void set_level(int level, Pokemon *pokemon);
int get_pokemon_attack(Pokemon *pokemon);
int get_pokemon_defense(Pokemon *pokemon);
int get_pokemon_S_attack(Pokemon *pokemon);
int get_pokemon_S_defense(Pokemon *pokemon);
int get_pokemon_speed(Pokemon *pokemon);
int get_pokemon_hp(Pokemon *pokemon);
List* get_pokemon_list_attacks(Pokemon *pokemon);
State get_pokemon_current_state(Pokemon *pokemon);
Type get_pokemon_type1(Pokemon *pokemon);
Type get_pokemon_type2(Pokemon *pokemon);
double* get_pokemon_weaknesses(Pokemon *pokemon);
int get_pokemon_level(Pokemon *pokemon);
void pokemon_use_potion(Pokemon *pokemon, Potion potion);

void modify_pokemon_attack(int attack, Pokemon *pokemon);
void modify_pokemon_defense(int defense, Pokemon *pokemon);
void modify_pokemon_S_attack(int S_attack, Pokemon *pokemon);
void modify_pokemon_S_defense(int S_defense, Pokemon *pokemon);
void modify_pokemon_speed(double speed, Pokemon *pokemon);
void modify_pokemon_hp(int hp, Pokemon *pokemon);
void modify_pokemon_state(State state, Pokemon *pokemon);
void print_pokemon(Pokemon *pokemon);
char* type_to_string(Type type);
char* state_to_string(State state);
char* attack_type_to_string(AttackType attackType);
void pokemon_normalize(Pokemon *pokemon);
int hit(Attack *attack, Pokemon *pokemon_attacker, Pokemon *pokemon_receiver);
void init_pokemons();
void obtain_pokemons_from_file(RedPlayer *player);
void init_enemy_pokemons(Enemy *enemy);
char* get_pokemon_name(Pokemon *pokemon);
void set_player_potion_to_none(RedPlayer *player, int index);

#endif //POKEMON_POKEMON_H
