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
                        if(change_precision->presicion == -100)
                            continue;
                        change_precision->presicion = change_precision->presicion * attack->aggregated;
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
