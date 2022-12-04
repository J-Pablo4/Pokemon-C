//
// Created by jplop on 18/11/2022.
//

#include "Attacks.h"
#include "Pokemon.h"
#include "Lists.h"

struct attack{
    char *name;
    AttackType attack;
    Type type;
    int power;
    int precision;
    int pp; //Power_Points
    Affected_stat affected_stat;
    int direction;
    int aggregated;
    State state_change;
    int state_probability;
    int BASE_PRECISION;
    int BASE_PP; //Power_Points
};

void modify_attack_precision(Attack *attack, int precision)
{
    attack->precision = precision;
}
void modify_attack_pp(Attack *attack, int pp)
{
    attack->pp = pp;
}

Type get_attack_type(Attack *attack)
{
    return attack->type;
}
int get_attack_state_probability(Attack *attack)
{
    return attack->state_probability;
}
AttackType get_attack_attack_type(Attack *attack)
{
    return attack->attack;
}
int get_attack_power(Attack *attack)
{
    return attack->power;
}
int get_attack_precision(Attack *attack)
{
    return attack->precision;
}
int get_attack_pp(Attack *attack)
{
    return attack->pp;
}
Affected_stat get_attack_affected_stat(Attack *attack)
{
    return attack->affected_stat;
}
int get_attack_direction(Attack *attack)
{
    return attack->direction;
}
int get_attack_aggregated(Attack *attack)
{
    return attack->aggregated;
}
State get_attack_state_change(Attack *attack)
{
    return attack->state_change;
}


Attack* init_attack(char *name, Type type, AttackType attack, int power, int precision, int pp, State state_change, int state_probability, Affected_stat affected_stat, int direction, int aggregated)
{
    Attack * new_attack = malloc(sizeof (Attack));
    new_attack->name = name;
    new_attack->type = type;
    new_attack->attack = attack;
    new_attack->power = power;
    new_attack->precision = precision;
    new_attack->pp = pp;
    new_attack->state_change = state_change;
    new_attack->state_probability = state_probability;
    new_attack->affected_stat = affected_stat;
    new_attack->direction = direction;
    new_attack->BASE_PP = pp;
    new_attack->BASE_PRECISION = precision;
    new_attack->aggregated =aggregated; //Nota> Era un float, si falla, regresar a float.

    return new_attack;
}

void attack_normalize(Attack *attack)
{
    attack->pp = attack->BASE_PP;
    attack->precision = attack->BASE_PRECISION;
}

char* attack_get_name(Attack *attack)
{
    return attack->name;
}

