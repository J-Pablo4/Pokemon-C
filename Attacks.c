//
// Created by jplop on 18/11/2022.
//

#include "Attacks.h"

struct attack{
    char *name;
    AttackType attack;
    Type type;
    int power;
    int presicion;
    int pp; //Power_Points
    int affected_stats;
    int direction;
    float agregated;
    State state_change;
    int state_probability;
    int BASE_PRESITION;
    int BASE_PP; //Power_Points
};

Attack* init_attack(Type type, AttackType attack, int power, int presicion, int pp, State state_change, int state_probability, int affected_stat, int direction, float aggregated)
{
    Attack * new_attack = malloc(sizeof (Attack));
    new_attack->type = type;
    new_attack->attack = attack;
    new_attack->power = power;
    new_attack->presicion = presicion;
    new_attack->pp = pp;
    new_attack->state_change = state_change;
    new_attack->state_probability = state_probability;
    new_attack->affected_stats = affected_stat;
    new_attack->direction = direction;
    new_attack->BASE_PP = pp;
    new_attack->BASE_PRESITION = presicion;

    return new_attack;
}
