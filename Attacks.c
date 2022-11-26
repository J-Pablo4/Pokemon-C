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
    int (*Damage) (Attack *, Pokemon *, Pokemon*);
};

int get_damage(Attack *attack, Pokemon *pokemon, Pokemon *pokemon1);


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

    new_attack->Damage = get_damage;

    return new_attack;
}

void apply_effect(Pokemon *pokemon, Attack *attack)
{
    time_t t;
    srand((unsigned) time(&t));
    int probability = (rand() % 100);

    if(probability <= attack->state_probability)
    {
        switch (attack->state_change)
        {
            case normal_state:
            {
                if(attack->affected_stat == attack_affected_stat)
                {
                    modify_pokemon_attack(get_pokemon_attack(pokemon) + attack->aggregated, pokemon);
                }
                else if(attack->affected_stat == defense_affected_stat)
                {
                    modify_pokemon_defense(get_pokemon_defense(pokemon) + attack->aggregated, pokemon);
                }
                else if(attack->affected_stat == S_attack_affected_stat)
                {
                    modify_pokemon_S_attack(get_pokemon_S_attack(pokemon) + attack->aggregated, pokemon);
                }
                else if(attack->affected_stat == S_defense_affected_stat)
                {
                    modify_pokemon_S_defense(get_pokemon_S_defense(pokemon) + attack->aggregated, pokemon);
                }
                else if(attack->affected_stat == speed_affected_stat)
                {
                    modify_pokemon_speed(get_pokemon_speed(pokemon) + attack->aggregated, pokemon);
                }
                else if(attack->affected_stat == hp_affected_stat)
                {
                    modify_pokemon_hp(get_pokemon_hp(pokemon) + attack->aggregated, pokemon);
                }
                else
                {
                    Attack *change_precision;
                    for(int i = 0; i < 4; i++)
                    {
                        change_precision = get_element(get_pokemon_list_attacks(pokemon), i);
                        if(change_precision->precision == -100)
                            continue;
                        change_precision->precision = change_precision->precision * attack->aggregated;
                    }
                }
            }
            case paralyzed_state:
            {
                if(get_pokemon_current_state(pokemon) != normal_state)
                {
                    if(probability <= attack->state_probability)
                    {
                        modify_pokemon_state(paralyzed_state, pokemon);
                        modify_pokemon_speed((double)get_pokemon_speed(pokemon) * .75, pokemon);
                    }
                }
            }
            case burned_state:
            {
                if(get_pokemon_current_state(pokemon) != normal_state)
                {
                    if(probability <= attack->state_probability)
                    {
                        modify_pokemon_state(burned_state, pokemon);
                    }
                }
            }
            case sleep_state:
            {
                if(get_pokemon_current_state(pokemon) != normal_state)
                {
                    if(probability <= attack->state_probability)
                    {
                        modify_pokemon_state(sleep_state, pokemon);
                    }
                }
            }
            case poisoned_state:
            {
                if(get_pokemon_current_state(pokemon) != normal_state)
                {
                    if(probability <= attack->state_probability)
                    {
                        modify_pokemon_state(poisoned_state, pokemon);
                    }
                }
            }
            case confused_state:
            {
                if(get_pokemon_current_state(pokemon) != normal_state)
                {
                    if(probability <= attack->state_probability)
                    {
                        modify_pokemon_state(confused_state, pokemon);
                    }
                }
            }
            case frozen_state:
            {
                if(get_pokemon_current_state(pokemon) != normal_state)
                {
                    if(probability <= attack->state_probability)
                    {
                        modify_pokemon_state(frozen_state, pokemon);
                    }
                }
            }
        }
    }
}

int get_damage(Attack *attack, Pokemon *pokemon_attacker, Pokemon *pokemon_receiver)
{
    double bonification = (get_pokemon_type1(pokemon_attacker) == attack->type || get_pokemon_type2(pokemon_attacker) == attack->type) ? 1.5 : 1;

    time_t t;
    srand((unsigned) time(&t));
    float variation = (rand() % 100);
    variation /= 100;
    variation *= 15;
    variation += 85;

    int damage = 0;

    if(attack->power == 0)
        return damage;
    
        //    Faltan returns
    else if(attack->attack == phisical)
    {
        damage = (int) ((.01 * bonification * (*(get_pokemon_weaknesses(pokemon_receiver)+attack->type) ) * variation) *
                ((((0.2 * get_pokemon_level(pokemon_attacker) + 1) * get_pokemon_attack(pokemon_attacker) * attack->power) / (25 *
                        get_pokemon_defense(pokemon_receiver))) + 2));
    }
    else if(attack->attack == special)
    {
        damage = (int) ((.01 * bonification * (*(get_pokemon_weaknesses(pokemon_receiver)+attack->type) ) * variation) *
                        ((((0.2 * get_pokemon_level(pokemon_attacker) + 1) * get_pokemon_S_attack(pokemon_attacker) * attack->power) / (25 *
                        get_pokemon_S_defense(pokemon_receiver))) + 2));
    }

    if(damage < 0)
        return 1;
    return damage;
}

int hit(Attack *attack, Pokemon *pokemon_attacker, Pokemon *pokemon_receiver)	//	metodo que asigna valores despues de un movimiento
{
    time_t t;
    srand((unsigned) time(&t));
    int precision = (rand() % 100);

    if(precision <= attack->precision || attack ->precision == -100)
    {

        modify_pokemon_hp(get_pokemon_hp(pokemon_receiver) - get_damage(attack, pokemon_attacker, pokemon_receiver),pokemon_receiver);
        if(attack->state_probability != -1)
        {
            if(attack->affected_stat == normal_state)
            {
                if(attack->direction != 0) // efecto a si mismo (pokemon que hace el movimiento)
                    if(attack->aggregated != -1000)
                        apply_effect(pokemon_attacker, attack);
                    //else
                    //    Estado.efecto(pokemon,this, movimiento); //	absorber autodestruccion y similar

                else	//	efecto al otro (pokemon contrario al que hace el movimiento
                    if(attack->aggregated != -1000)
                        apply_effect(pokemon_receiver, attack);
                    //else
                    //    Estado.efecto(this,pokemon, movimiento); //	absorber y similar
            }
            else if(attack->affected_stat == paralyzed_state)
            {
                apply_effect(pokemon_receiver, attack);
            }
        }
        //if (ps <= 0)
        //    debilitado = true;
        attack->pp --;
        return 0;	//	el golpe fue un exito
    }
    else
        attack->pp --;
    return -1;	// el golpe fallo
}

void attack_normalize(Attack *attack)
{
    attack->pp = attack->BASE_PP;
    attack->precision = attack->BASE_PRECISION;
    return;
}

char* attack_get_name(Attack *attack)
{
    return attack->name;
}

