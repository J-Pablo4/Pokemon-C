//
// Created by jplop on 18/11/2022.
//

#ifndef POKEMON_ATTACKS_H
#define POKEMON_ATTACKS_H

#include "Type.h"

typedef struct attack Attack;
typedef enum attack_type{phisical, special, stat} AttackType;
typedef enum state{normal_state, sleep_state, burned_state, paralyzed_state, confused_state, poisoned_state, frozen_state, none_state} State;
typedef enum affected_stat{attack_affected_stat, defense_affected_stat, S_attack_affected_stat, S_defense_affected_stat, speed_affected_stat, precision_affected_stat, hp_affected_stat} Affected_stat;

Attack* init_attack(char *name, Type type, AttackType attack, int power, int precision, int pp, State state_change, int state_probability, Affected_stat affected_stat, int direction, int aggregated);
char* attack_get_name(Attack *attack);

void modify_attack_precision(Attack *attack, int precision);
void modify_attack_pp(Attack *attack, int pp);
Type get_attack_type(Attack *attack);
int get_attack_state_probability(Attack *attack);
AttackType get_attack_attack_type(Attack *attack);
int get_attack_power(Attack *attack);
int get_attack_precision(Attack *attack);
int get_attack_pp(Attack *attack);
Affected_stat get_attack_affected_stat(Attack *attack);
int get_attack_direction(Attack *attack);
int get_attack_aggregated(Attack *attack);
State get_attack_state_change(Attack *attack);
int get_attack_base_precision(Attack *attack);
int get_attack_base_pp(Attack *attack);

#endif //POKEMON_ATTACKS_H
