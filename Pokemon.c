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
    float *debilidades;
    Stats *stats;
    char *name;
};

Pokemon* new_pokemon(char *name, int hp,  int attack, int defense, int speed, int S_attack, int S_defense)
{
//    Variables important for the rand function and srand
    time_t t;

    Pokemon *pokemon_new = malloc(sizeof (Pokemon));
    pokemon_new->stats->level = 1;

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
    pokemon_new->stats->S_attack = S_attack;
    pokemon_new->stats->S_defense = S_defense;

    //    Set the hp
    pokemon_new->stats->S_defense = get_stat(1, hp, pokemon_new->stats->variable_hp, 1);

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


//    pokemon_new->type1 = NULL;
//    pokemon_new->type2 = NULL;
    pokemon_new->name = name;

    return pokemon_new;
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
