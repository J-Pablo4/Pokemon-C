//
// Created by jplop on 20/11/2022.
//

#ifndef POKEMON_LISTS_H
#define POKEMON_LISTS_H

#include <stdlib.h>
#include <stdio.h>

typedef struct list List;

List* list_new();
List* list_append(List *l, void *element);

//int list_contains(List *l, int value_to_find);
void* get_element(List *l, int index);
void delete_at(List *l, int index);

#endif //POKEMON_LISTS_H
