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
    Affected_stat affected_stat;
    int direction;
    int aggregated;
    State state_change;
    int state_probability;
    int BASE_PRESICION;
    int BASE_PP; //Power_Points
};

Attack* init_attack(Type type, AttackType attack, int power, int presicion, int pp, State state_change, int state_probability, Affected_stat affected_stat, int direction, int aggregated)
{
    Attack * new_attack = malloc(sizeof (Attack));
    new_attack->type = type;
    new_attack->attack = attack;
    new_attack->power = power;
    new_attack->presicion = presicion;
    new_attack->pp = pp;
    new_attack->state_change = state_change;
    new_attack->state_probability = state_probability;
    new_attack->affected_stat = affected_stat;
    new_attack->direction = direction;
    new_attack->BASE_PP = pp;
    new_attack->BASE_PRESICION = presicion;
    new_attack->aggregated =aggregated; //Nota> Era un float, si falla, regresar a float.

    return new_attack;
}

State get_attack_state_change(Attack *attack)
{
    return attack->state_change;
}

int get_attack_state_probability(Attack *attack)
{
    return attack->state_probability;
}

Affected_stat get_attack_affected_stat(Attack *attack)
{
    return attack->affected_stat;
}

int get_attack_aggregated(Attack *attack)
{
    return attack->aggregated;
}
