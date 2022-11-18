//
// Created by jplop on 18/11/2022.
//

#ifndef POKEMON_ATTACKS_H
#define POKEMON_ATTACKS_H

#include "Type.h"

typedef struct attck Attack;
typedef enum attack_type{phisical, special, stat} AttackType;

Attack* init_attack(Type type, AttackType attack, int power, int presicion, int pp, State state_change, int state_probability, int affected_stat, int direction, float aggregated);

#endif //POKEMON_ATTACKS_H
