//
// Created by jplop on 14/11/2022.
//

#ifndef POKEMON_TYPE_H
#define POKEMON_TYPE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef enum type{water,bug,dragon,electric,ghost,fire,ice,fighting,normal,grass,psychic,rock,ground, poison, flying, none} Type;

double* get_weakness(Type type1, Type type2);

#endif //POKEMON_TYPE_H
