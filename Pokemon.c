//
// Created by jplop on 11/11/2022.
//
#include "Type.h"
#include "Pokemon.h"

int get_stat(int level, int base_stat, int variable_stat, int set_hp);

typedef struct stats
{
    int level;

    //    Base stats
    int base_hp;
    int base_attack;
    int base_defense;
    int base_speed;
    int base_S_attack;
    int base_S_defense;

    //    Variable stats
    int variable_hp;
    int variable_attack;
    int variable_defense;
    int variable_speed;
    int variable_S_attack;
    int variable_S_defense;

    //    Stats
    int fixed_hp;
    int hp;
    int attack;
    int defense;
    int speed;
    int S_attack;
    int S_defense;
}Stats;

struct pokemon
{
    Type type1;
    Type type2;
    double *weaknesses;
    Stats *stats;
    char *name;
    List *attacks;
    State current_state;
};



Pokemon* new_pokemon(char *name, Type type1, Type type2, int hp,  int attack, int defense, int speed, int S_attack, int S_defense)
{
//    Variables important for the rand function and srand
    time_t t;

    Pokemon *pokemon_new = malloc(sizeof (Pokemon));
    pokemon_new->stats = malloc(sizeof (Stats));
    pokemon_new->stats->level = 1;

    pokemon_new->type1 = type1;
    pokemon_new->type2 = type2;

//    Setting varible values
    srand((unsigned) time(&t));
    pokemon_new->stats->variable_hp = (rand() % 15) + 1;

    srand((unsigned) time(&t));
    pokemon_new->stats->variable_attack = (rand() % 15) + 1;

    srand((unsigned) time(&t));
    pokemon_new->stats->variable_defense = (rand() % 15) + 1;

    srand((unsigned) time(&t));
    pokemon_new->stats->variable_speed = (rand() % 15) + 1;

    srand((unsigned) time(&t));
    pokemon_new->stats->variable_S_attack = (rand() % 15) + 1;

    srand((unsigned) time(&t));
    pokemon_new->stats->variable_S_defense = (rand() % 15) + 1;


//    Set the base values
    pokemon_new->stats->base_hp = hp;
    pokemon_new->stats->base_attack = attack;
    pokemon_new->stats->base_defense = defense;
    pokemon_new->stats->base_speed = speed;
    pokemon_new->stats->base_S_attack = S_attack;
    pokemon_new->stats->base_S_defense = S_defense;

    //    Set the hp
    pokemon_new->stats->hp = get_stat(1, hp, pokemon_new->stats->variable_hp, 1);

    //    Set the attack
    pokemon_new->stats->attack = get_stat(1, attack, pokemon_new->stats->variable_attack, 0);

    //    Set the defense
    pokemon_new->stats->defense = get_stat(1, defense, pokemon_new->stats->variable_defense, 0);

    //    Set the speed
    pokemon_new->stats->speed = get_stat(1, speed, pokemon_new->stats->variable_speed, 0);

    //    Set the Special attack
    pokemon_new->stats->S_attack = get_stat(1, S_attack, pokemon_new->stats->variable_S_attack, 0);

    //    Set the Special defense
    pokemon_new->stats->S_defense = get_stat(1, S_defense, pokemon_new->stats->variable_S_defense, 0);

    pokemon_new->stats->fixed_hp = pokemon_new->stats->hp;

    pokemon_new->name = name;

    pokemon_new->current_state = normal_state;

    pokemon_new->attacks = list_new();

    pokemon_new->weaknesses = get_weakness(type1, type2);

    return pokemon_new;
}

void set_level(int level, Pokemon *pokemon)
{
    if (level >= 1 && level <= 1000)
    {
        pokemon->stats->level = level;
        pokemon->stats->hp = get_stat(level, pokemon->stats->base_hp, pokemon->stats->variable_hp, 1);
        pokemon->stats->attack = get_stat(level, pokemon->stats->base_attack, pokemon->stats->variable_attack, 0);
        pokemon->stats->defense = get_stat(level, pokemon->stats->base_defense, pokemon->stats->variable_defense, 0);
        pokemon->stats->speed = get_stat(level, pokemon->stats->base_speed, pokemon->stats->variable_speed, 0);
        pokemon->stats->S_attack = get_stat(level, pokemon->stats->base_S_attack, pokemon->stats->variable_S_attack, 0);
        pokemon->stats->S_defense = get_stat(level, pokemon->stats->base_S_defense, pokemon->stats->variable_S_defense, 0);
        pokemon->stats->fixed_hp = pokemon->stats->hp;
    }
}

void define_attacks(char *name, Pokemon *pokemon, Type type, AttackType attack, int power, int precision, int pp, State state_change, int state_probability, Affected_stat affected_stat, int direction, int aggregated)
{
    Attack *new_attack = init_attack(name,type, attack, power, precision, pp, state_change, state_probability, affected_stat, direction, aggregated);
    list_append(pokemon->attacks, new_attack);
}

int get_stat(int level, int base_stat, int variable_stat, int set_hp)
{
    int stat;
    if(set_hp == 0)
    {
        stat = (((((base_stat + variable_stat) * 2) + 4) * level)/ 100) + 5;
        return stat;
    } else
    {
        stat = (((((base_stat + variable_stat) * 2) + 4) * level)/ 100) + 10 + level;
        return stat;
    }
}

int get_pokemon_attack(Pokemon *pokemon)
{
    return pokemon->stats->attack;
}
int get_pokemon_defense(Pokemon *pokemon)
{
    return pokemon->stats->defense;
}
int get_pokemon_S_attack(Pokemon *pokemon)
{
    return pokemon->stats->S_attack;
}
int get_pokemon_S_defense(Pokemon *pokemon)
{
    return pokemon->stats->S_defense;
}
int get_pokemon_speed(Pokemon *pokemon)
{
    return pokemon->stats->speed;
}
int get_pokemon_hp(Pokemon *pokemon)
{
    return pokemon->stats->hp;
}
List* get_pokemon_list_attacks(Pokemon *pokemon)
{
    return pokemon->attacks;
}
State get_pokemon_current_state(Pokemon *pokemon)
{
    return pokemon->current_state;
}
Type get_pokemon_type1(Pokemon *pokemon)
{
    return pokemon->type1;
}
Type get_pokemon_type2(Pokemon *pokemon)
{
    return pokemon->type2;
}
double* get_pokemon_weaknesses(Pokemon *pokemon)
{
    return pokemon->weaknesses;
}
int get_pokemon_level(Pokemon *pokemon)
{
    return pokemon->stats->level;
}

void modify_pokemon_attack(int attack, Pokemon *pokemon)
{
    pokemon->stats->attack = attack;
}
void modify_pokemon_defense(int defense, Pokemon *pokemon)
{
    pokemon->stats->defense = defense;
}
void modify_pokemon_S_attack(int S_attack, Pokemon *pokemon)
{
    pokemon->stats->S_attack = S_attack;
}
void modify_pokemon_S_defense(int S_defense, Pokemon *pokemon)
{
    pokemon->stats->S_defense = S_defense;
}
void modify_pokemon_speed(double speed, Pokemon *pokemon)
{
    pokemon->stats->speed = (int)speed;
}
void modify_pokemon_hp(int hp, Pokemon *pokemon)
{
    pokemon->stats->hp = hp;
}
void modify_pokemon_state(State state, Pokemon *pokemon)
{
    pokemon->current_state = state;
}
void pokemon_normalize(Pokemon *pokemon)
{
    pokemon->stats->hp = get_stat(pokemon->stats->level, pokemon->stats->base_hp, pokemon->stats->variable_hp, 1);
    pokemon->stats->attack = get_stat(pokemon->stats->level, pokemon->stats->base_attack, pokemon->stats->variable_attack, 0);
    pokemon->stats->defense = get_stat(pokemon->stats->level, pokemon->stats->base_defense, pokemon->stats->variable_defense, 0);
    pokemon->stats->speed = get_stat(pokemon->stats->level, pokemon->stats->base_speed, pokemon->stats->variable_speed, 0);
    pokemon->stats->S_attack = get_stat(pokemon->stats->level, pokemon->stats->base_S_attack, pokemon->stats->variable_S_attack, 0);
    pokemon->stats->S_defense = get_stat(pokemon->stats->level, pokemon->stats->base_S_defense, pokemon->stats->variable_S_defense, 0);
}
void pokemon_use_potion(Pokemon *pokemon, Potion potion)
{
    pokemon->stats->hp += potion;
    if (pokemon->stats->hp > pokemon->stats->fixed_hp)
    {
        pokemon->stats->hp = pokemon->stats->fixed_hp;
    }
}
void apply_effect(Pokemon *pokemon, Attack *attack)
{
    time_t t;
    srand((unsigned) time(&t));
    int probability = (rand() % 100);

    if(probability <= get_attack_state_probability(attack))
    {
        switch (get_attack_state_change(attack))
        {
            case normal_state:
            {
                if(get_attack_affected_stat(attack) == attack_affected_stat)
                {
                    modify_pokemon_attack(get_pokemon_attack(pokemon) + get_attack_aggregated(attack), pokemon);
                }
                else if(get_attack_affected_stat(attack) == defense_affected_stat)
                {
                    modify_pokemon_defense(get_pokemon_defense(pokemon) + get_attack_aggregated(attack), pokemon);
                }
                else if(get_attack_affected_stat(attack) == S_attack_affected_stat)
                {
                    modify_pokemon_S_attack(get_pokemon_S_attack(pokemon) + get_attack_aggregated(attack), pokemon);
                }
                else if(get_attack_affected_stat(attack) == S_defense_affected_stat)
                {
                    modify_pokemon_S_defense(get_pokemon_S_defense(pokemon) + get_attack_aggregated(attack), pokemon);
                }
                else if(get_attack_affected_stat(attack) == speed_affected_stat)
                {
                    modify_pokemon_speed(get_pokemon_speed(pokemon) + get_attack_aggregated(attack), pokemon);
                }
                else if(get_attack_affected_stat(attack) == hp_affected_stat)
                {
                    modify_pokemon_hp(get_pokemon_hp(pokemon) + get_attack_aggregated(attack), pokemon);
                }
                else
                {
                    Attack *change_precision;
                    for(int i = 0; i < 4; i++)
                    {
                        change_precision = get_element(get_pokemon_list_attacks(pokemon), i);
                        if(get_attack_precision(change_precision) == -100)
                            continue;
                        modify_attack_precision(change_precision, get_attack_precision(change_precision)*
                                get_attack_aggregated(attack));
                    }
                }
            }
            case paralyzed_state:
            {
                if(get_pokemon_current_state(pokemon) == normal_state)
                {
                    if(probability <= get_attack_state_probability(attack))
                    {
                        modify_pokemon_state(paralyzed_state, pokemon);
                        modify_pokemon_speed((double)get_pokemon_speed(pokemon) * .75, pokemon);
                    }
                }
            }
            case burned_state:
            {
                if(get_pokemon_current_state(pokemon) == normal_state)
                {
                    if(probability <= get_attack_state_probability(attack))
                    {
                        modify_pokemon_state(burned_state, pokemon);
                    }
                }
            }
            case sleep_state:
            {
                if(get_pokemon_current_state(pokemon) == normal_state)
                {
                    if(probability <= get_attack_state_probability(attack))
                    {
                        modify_pokemon_state(sleep_state, pokemon);
                    }
                }
            }
            case poisoned_state:
            {
                if(get_pokemon_current_state(pokemon) == normal_state)
                {
                    if(probability <= get_attack_state_probability(attack))
                    {
                        modify_pokemon_state(poisoned_state, pokemon);
                    }
                }
            }
            case confused_state:
            {
                if(get_pokemon_current_state(pokemon) == normal_state)
                {
                    if(probability <= get_attack_state_probability(attack))
                    {
                        modify_pokemon_state(confused_state, pokemon);
                    }
                }
            }
            case frozen_state:
            {
                if(get_pokemon_current_state(pokemon) == normal_state)
                {
                    if(probability <= get_attack_state_probability(attack))
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
    double bonification = (get_pokemon_type1(pokemon_attacker) == get_attack_type(attack) || get_pokemon_type2(pokemon_attacker) == get_attack_type(attack)) ? 1.5 : 1;

    time_t t;
    srand((unsigned) time(&t));
    float variation = (rand() % 100);
    variation /= 100;
    variation *= 15;
    variation += 85;

    int damage = 0;

    if(get_attack_power(attack) == 0)
        return damage;

        //    Faltan returns
    if(get_attack_attack_type(attack) == phisical)
    {
        damage = (int) ((.01 * bonification * (*(get_pokemon_weaknesses(pokemon_receiver) + get_attack_type(attack)) ) * variation) *
                        ((((0.2 * get_pokemon_level(pokemon_attacker) + 1) * get_pokemon_attack(pokemon_attacker) * get_attack_power(attack)) / (25 *
                        get_pokemon_defense(pokemon_receiver))) + 2));

    }
    else if(get_attack_attack_type(attack) == special)
    {
        damage = (int) ((.01 * bonification * (*(get_pokemon_weaknesses(pokemon_receiver) + get_attack_type(attack)) ) * variation) *
                        ((((0.2 * get_pokemon_level(pokemon_attacker) + 1) * get_pokemon_S_attack(pokemon_attacker) * get_attack_power(attack)) / (25 *
                        get_pokemon_S_defense(pokemon_receiver))) + 2));
    }

    if(damage <= 0)
        return 1;
    return damage;
}

int hit(Attack *attack, Pokemon *pokemon_attacker, Pokemon *pokemon_receiver)	//	metodo que asigna valores despues de un movimiento
{
    time_t t;
    srand((unsigned) time(&t));
    int precision = (rand() % 100);

    if(precision <= get_attack_precision(attack) || get_attack_precision(attack) == -100)
    {

        modify_pokemon_hp(get_pokemon_hp(pokemon_receiver) - get_damage(attack, pokemon_attacker, pokemon_receiver),pokemon_receiver);


        if(get_attack_state_change(attack) == normal_state)
        {
            if(get_attack_direction(attack)) // efecto a si mismo
            {
                apply_effect(pokemon_attacker, attack);
            }
            else
            {
                apply_effect(pokemon_receiver, attack);
            }

        }
        else if(get_attack_state_change(attack) == paralyzed_state)
        {
            apply_effect(pokemon_receiver, attack);
        }
        else if(get_attack_state_change(attack) == burned_state)
        {
            apply_effect(pokemon_receiver, attack);
        }
        else if(get_attack_state_change(attack) == frozen_state)
        {
            apply_effect(pokemon_receiver, attack);
        }
        else if(get_attack_state_change(attack) == poisoned_state)
        {
            apply_effect(pokemon_receiver, attack);
        }
        else if(get_attack_state_change(attack) == sleep_state)
        {
            apply_effect(pokemon_receiver, attack);
        }
        else if(get_attack_state_change(attack) == confused_state)
        {
            apply_effect(pokemon_receiver, attack);
        }

        modify_attack_pp(attack,get_attack_pp(attack)-1);
        return 0;	//	el golpe fue un exito
    }
    else
        modify_attack_pp(attack,get_attack_pp(attack)-1);
    return -1;	// el golpe fallo
}

void print_pokemon(Pokemon *pokemon)
{
    printf("Pokemon: %s\n", pokemon->name);
    printf("State: %d\n", pokemon->current_state);
    printf("Type: %d\n", pokemon->type1);
    printf("Type: %d\n", pokemon->type2);
    printf("Level: %d\n", pokemon->stats->level);
    printf("HP: %d\n", pokemon->stats->hp);
    printf("Attack: %d\n", pokemon->stats->attack);
    printf("Defense: %d\n", pokemon->stats->defense);
    printf("Special Attack: %d\n", pokemon->stats->S_attack);
    printf("Special Defense: %d\n", pokemon->stats->variable_S_defense);
    printf("Speed: %d\n", pokemon->stats->speed);
    printf("Movements:\n");
    Attack *attack;
    for(int i = 0; i < 4; i++)
    {
        attack = get_element(get_pokemon_list_attacks(pokemon), i);
        printf("%s\n", attack_get_name(attack));
    }
}