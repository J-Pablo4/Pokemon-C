//
// Created by jplop on 18/11/2022.
//

#ifndef POKEMON_STATE_H
#define POKEMON_STATE_H

#include "Pokemon.h"
#include "Attacks.h"

typedef enum state{normal_state, sleep_state, burned_state, paralyzed_state, confused_state, poisoned_state, frozen_state, critical_state, retro_state} State;
typedef enum affected_stat{attack_affected, defense_affected, S_attack_affected, S_defense_affected, speed_affected, precision_affected, hp_affected} Affected_stat;

#endif //POKEMON_STATE_H
