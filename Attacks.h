//
// Created by jplop on 18/11/2022.
//

#ifndef POKEMON_ATTACKS_H
#define POKEMON_ATTACKS_H

#include "Type.h"
#include "State.h"

typedef struct attack Attack;
typedef enum attack_type{phisical, special, stat} AttackType;

Attack* init_attack(Type type, AttackType attack, int power, int presicion, int pp, State state_change, int state_probability, Affected_stat affected_stat, int direction, int aggregated);

State get_attack_state_change(Attack *attack);
int get_attack_state_probability(Attack *attack);
Affected_stat get_attack_affected_stat(Attack *attack);
int get_attack_aggregated(Attack *attack);

#endif //POKEMON_ATTACKS_H
