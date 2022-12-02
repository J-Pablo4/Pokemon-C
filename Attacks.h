//
// Created by jplop on 18/11/2022.
//

#ifndef POKEMON_ATTACKS_H
#define POKEMON_ATTACKS_H

#include "Type.h"

typedef struct attack Attack;
typedef enum attack_type{phisical, special, stat} AttackType;
typedef enum state{normal_state, sleep_state, burned_state, paralyzed_state, confused_state, poisoned_state, frozen_state} State;
typedef enum affected_stat{attack_affected_stat, defense_affected_stat, S_attack_affected_stat, S_defense_affected_stat, speed_affected_stat, precision_affected_stat, hp_affected_stat} Affected_stat;

Attack* init_attack(Type type, AttackType attack, int power, int presicion, int pp, State state_change, int state_probability, Affected_stat affected_stat, int direction, int aggregated);



#endif //POKEMON_ATTACKS_H
