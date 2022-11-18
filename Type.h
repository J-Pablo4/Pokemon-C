//
// Created by jplop on 14/11/2022.
//

#ifndef POKEMON_TYPE_H
#define POKEMON_TYPE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef enum type{water_type ,bug_type ,dragon_type ,electric_type,ghost_type ,fire_type ,ice_type ,fighting_type ,normal_type ,grass_type ,psychic_type ,rock_type ,ground_type , poison_type, flying_type, none = -1} Type;

double* get_weakness(Type type1, Type type2);

#endif //POKEMON_TYPE_H
