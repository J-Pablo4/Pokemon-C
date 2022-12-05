//
// Created by jplop on 11/11/2022.
//
#include "Type.h"
#include "Pokemon.h"
#include "Player.h"

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
    int alive;
};



Pokemon* new_pokemon(char *name, Type type1, Type type2, int hp,  int attack, int defense, int speed, int S_attack, int S_defense)
{
//    Variables important for the rand function and srand
    time_t t;

    Pokemon *pokemon_new = malloc(sizeof (Pokemon));
    pokemon_new->stats = malloc(sizeof (Stats));
    pokemon_new->stats->level = 1;
    pokemon_new->alive = 1;
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

char* get_pokemon_name(Pokemon *pokemon)
{
    return pokemon->name;
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
int get_pokemon_alive(Pokemon *pokemon)
{
    return pokemon->alive;
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
    if(hp <= 0)
    {
        pokemon->alive = 0;
        pokemon->stats->hp = 0;
    }
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
        switch(get_attack_state_change(attack))
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
                    int i = 0;
                    while (get_element(get_pokemon_list_attacks(pokemon), i) != NULL)
                    {
                        change_precision = get_element(get_pokemon_list_attacks(pokemon), i);
                        if(get_attack_precision(change_precision) == -100)
                        {
                            i++;
                            continue;
                        }
                        modify_attack_precision(change_precision, get_attack_precision(change_precision)+
                                get_attack_aggregated(attack));
                        i++;
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
    printf("State: %s\n", state_to_string(pokemon->current_state));
    printf("Type: %s\n", type_to_string(pokemon->type1));
    printf("Type: %s\n", type_to_string(pokemon->type2));
    printf("Level: %d\n", pokemon->stats->level);
    printf("HP: %d\n", pokemon->stats->hp);
    printf("Attack: %d\n", pokemon->stats->attack);
    printf("Defense: %d\n", pokemon->stats->defense);
    printf("Special Attack: %d\n", pokemon->stats->S_attack);
    printf("Special Defense: %d\n", pokemon->stats->variable_S_defense);
    printf("Speed: %d\n", pokemon->stats->speed);
    printf("Movements:\n");
    Attack *attack = NULL;
    int i = 0;
    while (get_element(get_pokemon_list_attacks(pokemon), i) != NULL)
    {
        attack = get_element(get_pokemon_list_attacks(pokemon), i);
        printf("Attack: %s, ", attack_get_name(attack));
        printf("Attack Type: %s, ", attack_type_to_string(get_attack_attack_type(attack)));
        printf("Type: %s, ", type_to_string(get_attack_type(attack)));
        printf("Power: %d, ", get_attack_power(attack));
        printf("Precision: %d/%d ", get_attack_precision(attack), get_attack_base_precision(attack));
        printf("PP: %d/%d, ", get_attack_pp(attack),get_attack_base_pp(attack));
        printf("Affected Stat: %s, ", affected_stat_to_string(get_attack_affected_stat(attack)));
        printf("Direction: %d, ", get_attack_direction(attack));
        printf("Aggregated: %d, ", get_attack_aggregated(attack));
        printf("State Change: %s, ", state_to_string(get_attack_state_change(attack)));
        printf("State Probability: %d\n", get_attack_state_probability(attack));
        printf("\n");
        i++;
    }
}

char* type_to_string(Type type)
{
    char* types[] = {"Water", "Bug", "Dragon", "Electric", "Ghost", "Fire", "Ice", "Fighting", "Normal", "Grass",
                     "Psychic", "Rock", "Ground", "Poison", "Flying", "none"};
    return types[type];
}

char* state_to_string(State state)
{
    char* states[] = {"Normal", "Sleep", "Burned", "Paralyzed", "Confused", "Poisoned", "Frozen","none"};
    return states[state];
}
char* attack_type_to_string(AttackType attackType)
{
    char* attack_types[] = {"Physical", "Special", "Stat"};
    return attack_types[attackType];
}
char* affected_stat_to_string(Affected_stat affectedStat)
{
    char* stats[] = {"Attack", "Defense", "S Attack", "S Defense", "Speed", "Precision", "HP"};
    return stats[affectedStat];
}


void init_pokemons()
{
    FILE *file;
    file = fopen("../pokemon.txt", "w");

    Pokemon *p1 = new_pokemon("Bulbasaur",grass_type,poison_type,45,49,49,45,65,65);
    define_attacks("Razor Leaf", p1,grass_type,phisical,55,95,25,none_state,0,0,0,0);
    define_attacks("Growth",p1,normal_type,stat,0,-100,40,normal_state,100,S_attack_affected_stat,1,1);
    define_attacks("Body slam",p1,normal_type,phisical,85,100,15,paralyzed_state,30,0,0,0);
    define_attacks("Stun spore", p1,grass_type,stat,0,75,30,paralyzed_state,100,0,0,0);

    set_level(50, p1);
    fwrite(p1, sizeof(Pokemon), 1, file);
    fclose(file);


    file = fopen("../pokemon.txt", "a");
    Pokemon *p2 = new_pokemon("Ivysaur",grass_type,poison_type,60,62,63,60,80,80);
    define_attacks("Razor Leaf", p2,grass_type,phisical,55,95,25,none_state,0,0,0,0);
    define_attacks("Growth", p2,normal_type,stat,0,-100,40,normal_state,100,S_attack_affected_stat,1,1);
    define_attacks("Stun spore",p2, grass_type,stat,0,75,30,paralyzed_state,100,0,0,0);
    define_attacks("Body slam",p2,normal_type,phisical,85,100,15,paralyzed_state,30,0,0,0);

    set_level(50, p2);
    fwrite(p2, sizeof(Pokemon), 1, file);
    fclose(file);


    file = fopen("../pokemon.txt", "a");
    Pokemon *p3 = new_pokemon("Venusaur",grass_type,poison_type,80,82,83,80,100,100);
    define_attacks("Razor Leaf",p3, grass_type,phisical,55,95,25,none_state,0,0,0,0);
    define_attacks("Growth",p3, normal_type,stat,0,-100,40,normal_state,100,S_attack_affected_stat,1,1);
    define_attacks("Sleep Powder",p3,grass_type,stat,0,75,15,sleep_state,100,0,0,0);
    define_attacks("Body slam",p3,normal_type,phisical,85,100,15,paralyzed_state,30,0,0,0);

    set_level(50, p3);
    fwrite(p3, sizeof(Pokemon), 1, file);
    fclose(file);


    file = fopen("../pokemon.txt", "a");
    Pokemon *p4 = new_pokemon("Charmander",fire_type,none,39,52,43,65,60,50);
    define_attacks("Ember",p4,fire_type,special,40,100,25,burned_state,10,0,0,0);
    define_attacks("Body slam",p4,normal_type,phisical,85,100,15,paralyzed_state,30,0,0,0);
    define_attacks("Flamethrower",p4,fire_type,special,90,100,15,burned_state,10,0,0,0);
    define_attacks("Submission",p4,fighting_type,phisical,80,80,25,none_state,0,0,0,0);

    set_level(50, p4);
    fwrite(p4, sizeof(Pokemon), 1, file);
    fclose(file);


    file = fopen("../pokemon.txt", "a");
    Pokemon *p5 = new_pokemon("Charmeleon",fire_type,none,58,64,58,80,80,65);
    define_attacks("Slash",p5,normal_type,phisical,70,100,20,none_state,0,0,0,0);
    define_attacks("Flamethrower",p5,fire_type,special,90,100,15,burned_state,10,0,0,0);
    define_attacks("Submission",p5,fighting_type,phisical,80,80,25,none_state,0,0,0,0);
    define_attacks("Earthquake",p5,ground_type,phisical,100,100,10,none_state,0,0,0,0);

    set_level(50, p5);
    fwrite(p5, sizeof(Pokemon), 1, file);
    fclose(file);


    file = fopen("../pokemon.txt", "a");
    Pokemon *p6 = new_pokemon("Charizard",fire_type,flying_type,78,84,78,100,109,85);
    define_attacks("Fire blast",p6,fire_type,special,120,85,5,burned_state,30,0,0,0);
    define_attacks("Wing Attack",p6,flying_type,phisical,60,100,35,none_state,0,0,0,0);
    define_attacks("Swords Dance",p6,normal_type,stat,0,-100,30,normal_state,100,attack_affected_stat,1,2);
    define_attacks("Slash",p6,normal_type,phisical,70,100,20,none_state,0,0,0,0);

    set_level(50, p6);
    fwrite(p6, sizeof(Pokemon), 1, file);
    fclose(file);


    file = fopen("../pokemon.txt", "a");
    Pokemon *p7 = new_pokemon("Squirtle",water_type,none,44,48,65,43,50,64);
    define_attacks("Surf",p7,water_type,special,90,100,15,0,0,0,0,0);
    define_attacks("Body slam",p7,normal_type,phisical,85,100,15,paralyzed_state,30,0,0,0);
    define_attacks("Blizzard",p7,ice_type,stat,120,70,5,frozen_state,10,0,0,0);
    define_attacks("Earthquake",p7,ground_type,phisical,100,100,10,none_state,0,0,0,0);

    set_level(50, p7);
    fwrite(p7, sizeof(Pokemon), 1, file);
    fclose(file);


    file = fopen("../pokemon.txt", "a");
    Pokemon *p8 = new_pokemon("Wartortle",water_type,none,59,63,80,58,65,80);
    define_attacks("Toxic",p8,poison_type,stat,0,85,10,poisoned_state,100,0,0,0);
    define_attacks("Submission",p8,fighting_type,phisical,80,80,25,none_state,0,0,0,0);
    define_attacks("Earthquake",p8,ground_type,phisical,100,100,10,none_state,0,0,0,0);
    define_attacks("Surf",p8,water_type,special,90,100,15,none_state,0,0,0,0);

    set_level(50, p8);
    fwrite(p8, sizeof(Pokemon), 1, file);
    fclose(file);


    file = fopen("../pokemon.txt", "a");
    Pokemon *p9 = new_pokemon("Blastoise",water_type,none,79,83,100,78,85,105);
    define_attacks("Headbutt",p9,normal_type,phisical,70,100,15,none_state,0,0,0,0);
    define_attacks("Hydro pump",p9,water_type,special,120,80,5,none_state,0,0,0,0);
    define_attacks("Tail whip",p9,normal_type,stat,0,100,30,normal_state,100,defense_affected_stat,0,-1);
    define_attacks("Surf",p9,water_type,special,90,100,15,none_state,0,0,0,0);

    set_level(50, p9);
    fwrite(p9, sizeof(Pokemon), 1, file);
    fclose(file);


    file = fopen("../pokemon.txt", "a");
    Pokemon *p10 = new_pokemon("Caterpie",bug_type,none,45,30,35,45,20,20);
    define_attacks("String Shot",p10,bug_type,stat,0,95,40,normal_state,100,speed_affected_stat,0,-1);
    define_attacks("Tackle",p10,normal_type,phisical,35,95,35,none_state,0,0,0,0);
    define_attacks("Harden",p10,normal_type,stat,0,-100,30,normal_state,100,defense_affected_stat,1,1);

    set_level(50, p10);
    fwrite(p10, sizeof(Pokemon), 1, file);
    fclose(file);


    file = fopen("../pokemon.txt", "a");
    Pokemon *p11 = new_pokemon("Metapod",bug_type,none,50,20,55,30,25,25);     define_attacks("String Shot",p11,bug_type,stat,0,95,40,normal_state,100,speed_affected_stat,0,-1);
    define_attacks("String Shot",p10,bug_type,stat,0,95,40,normal_state,100,speed_affected_stat,0,-1);
    define_attacks("Tackle",p11,normal_type,phisical,35,95,35,none_state,0,0,0,0);
    define_attacks("Harden",p11,normal_type,stat,0,-100,30,normal_state,100,defense_affected_stat,1,1);

    set_level(50, p11);
    fwrite(p11, sizeof(Pokemon), 1, file);
    fclose(file);


    file = fopen("../pokemon.txt", "a");
    Pokemon *p12 = new_pokemon("Butterfree", bug_type, flying_type, 60, 45, 50, 70, 90, 80);
    define_attacks("Stun spore", p12, grass_type, stat, 0, 75, 30, paralyzed_state, 100, 0, 0, 0);
    define_attacks("Swift", p12, normal_type, special, 60, 0, 20, none_state, 0, 0, 0, 0);
    define_attacks("Psychic", p12, psychic_type, special, 90, 100, 10, normal_state, 33, S_defense_affected_stat, 0,
                   -1);
    define_attacks("Wing Attack", p12, flying_type, phisical, 60, 100, 35, none_state, 0, 0, 0, 0);

    set_level(50, p12);
    fwrite(p12, sizeof(Pokemon), 1, file);
    fclose(file);


    file = fopen("../pokemon.txt", "a");
    Pokemon *p13 = new_pokemon("Weedle", bug_type, poison_type, 40, 35, 30, 50, 20, 20);
    define_attacks("Poison sting", p13, poison_type, phisical, 15, 100, 35, poisoned_state, 20, 0, 0, 0);
    define_attacks("Tackle", p13, normal_type, phisical, 35, 95, 35, none_state, 0, 0, 0, 0);
    define_attacks("Harden", p13, normal_type, stat, 0, -100, 30, normal_state, 100, defense_affected_stat, 1, 1);

    set_level(50, p13);
    fwrite(p13, sizeof(Pokemon), 1, file);
    fclose(file);


    file = fopen("../pokemon.txt", "a");
    Pokemon *p14 = new_pokemon("Kakuna", bug_type, poison_type, 45, 25, 50, 35, 25, 25);
    define_attacks("Poison sting", p14, poison_type, phisical, 15, 100, 35, poisoned_state, 20, 0, 0, 0);
    define_attacks("Tackle", p14, normal_type, phisical, 35, 95, 35, none_state, 0, 0, 0, 0);
    define_attacks("Harden", p14, normal_type, stat, 0, -100, 30, normal_state, 100, defense_affected_stat, 1, 1);

    set_level(50, p14);
    fwrite(p14, sizeof(Pokemon), 1, file);
    fclose(file);


    file = fopen("../pokemon.txt", "a");
    Pokemon *p15 = new_pokemon("Beedrill", bug_type, poison_type, 65, 80, 40, 75, 45, 80);
    define_attacks("Twineedle", p15, bug_type, phisical, 50, 100, 20, none_state, 0, 0, 0, 0);
    define_attacks("Toxic", p15, poison_type, stat, 0, 85, 10, poisoned_state, 100, 0, 0, 0);
    define_attacks("Razor wind", p15, normal_type, special, 80, 100, 10, none_state, 0, 0, 0, 0);
    define_attacks("Harden", p15, normal_type, stat, 0, -100, 30, normal_state, 100, defense_affected_stat, 1, 1);

    set_level(50, p15);
    fwrite(p15, sizeof(Pokemon), 1, file);
    fclose(file);


    file = fopen("../pokemon.txt", "a");
    Pokemon *p16 = new_pokemon("Pidgey", normal_type, flying_type, 40, 45, 40, 56, 35, 35);
    define_attacks("Sand Attack", p16, normal_type, stat, 0, 100, 15, normal_state, 100, precision_affected_stat, 0,
                   -6);
    define_attacks("Wing Attack", p16, flying_type, phisical, 60, 100, 35, none_state, 0, 0, 0, 0);
    define_attacks("Swift", p16, normal_type, special, 60, 0, 20, none_state, 0, 0, 0, 0);
    define_attacks("Drill peck", p16, flying_type, phisical, 80, 100, 20, none_state, 0, 0, 0, 0);

    set_level(50, p16);
    fwrite(p16, sizeof(Pokemon), 1, file);
    fclose(file);


    file = fopen("../pokemon.txt", "a");
    Pokemon *p17 = new_pokemon("Pidgeotto", normal_type, flying_type, 63, 60, 55, 71, 50, 50);
    define_attacks("Sand Attack", p17, normal_type, stat, 0, 100, 15, normal_state, 100, precision_affected_stat, 0,
                   -6);
    define_attacks("Wing Attack", p17, flying_type, phisical, 60, 100, 35, none_state, 0, 0, 0, 0);
    define_attacks("Swift", p17, normal_type, special, 60, 0, 20, 0, none_state, 0, 0, 0);
    define_attacks("Toxic", p17, poison_type, stat, 0, 85, 10, poisoned_state, 100, 0, 0, 0);

    set_level(50, p17);
    fwrite(p17, sizeof(Pokemon), 1, file);
    fclose(file);


    file = fopen("../pokemon.txt", "a");
    Pokemon *p18 = new_pokemon("Pidgeot", normal_type, flying_type, 83, 80, 75, 101, 70, 70);
    define_attacks("Swift", p18, normal_type, special, 60, 0, 20, none_state, 0, 0, 0, 0);
    define_attacks("Gust", p18, normal_type, special, 40, 100, 35, none_state, 0, 0, 0, 0);
    define_attacks("Sand Attack", p18, normal_type, stat, 0, 100, 15, normal_state, 100, precision_affected_stat, 0,
                   -6);
    define_attacks("Wing Attack", p18, flying_type, phisical, 60, 100, 35, none_state, 0, 0, 0, 0);

    set_level(50, p18);
    fwrite(p18, sizeof(Pokemon), 1, file);
    fclose(file);


    file = fopen("../pokemon.txt", "a");
    Pokemon *p19 = new_pokemon("Rattata", normal_type, none, 30, 56, 35, 72, 25, 35);
    define_attacks("Hyper Fang", p19, normal_type, phisical, 80, 90, 15, none_state, 0, 0, 0, 0);
    define_attacks("Toxic", p19, poison_type, stat, 0, 85, 10, poisoned_state, 100, 0, 0, 0);
    define_attacks("Body slam", p19, normal_type, phisical, 85, 100, 15, paralyzed_state, 30, 0, 0, 0);
    define_attacks("Earthquake", p19, ground_type, phisical, 100, 100, 10, none_state, 0, 0, 0, 0);

    set_level(50, p19);
    fwrite(p19, sizeof(Pokemon), 1, file);
    fclose(file);


    file = fopen("../pokemon.txt", "a");
    Pokemon *p20 = new_pokemon("Raticate", normal_type, none, 55, 81, 60, 97, 50, 70);
    define_attacks("Hyper Fang", p20, normal_type, phisical, 80, 90, 15, none_state, 0, 0, 0, 0);
    define_attacks("Toxic", p20, poison_type, stat, 0, 85, 10, poisoned_state, 100, 0, 0, 0);
    define_attacks("Body slam", p20, normal_type, phisical, 85, 100, 15, paralyzed_state, 30, 0, 0, 0);
    define_attacks("Sand Attack", p20, normal_type, stat, 0, 100, 15, normal_state, 100, precision_affected_stat, 0,
                   -6);

    set_level(50, p20);
    fwrite(p20, sizeof(Pokemon), 1, file);
    fclose(file);
}

int is_index_in_array(int *indexes, int index)
{
    for (int i = 0; i < 6; ++i) {
        if(indexes[i] == index)
        {
            return 1;
        }
    }
    return 0;
}

void set_pokemons_to_player(RedPlayer *player, Pokemon pokemon_array[], int index_array, int *indexes)
{
    time_t t;
    int index;

    srand((unsigned) time(&t));
    index = (rand() % 20);
    while(is_index_in_array(indexes, index))
    {
        index = (rand() % 20);
    }
    indexes[index_array] = index;
    list_append(get_player_pokemons(player), &(pokemon_array[index]));
}

void obtain_pokemons_from_file(RedPlayer *player)
{
    FILE *file = fopen("../pokemon.txt", "r");
    Pokemon *pokemon_array = calloc(20,sizeof (Pokemon));

    if(file == NULL)
    {
        printf("No se abrio el archivo\n");
        return;
    }else
    {
        rewind(file);
        fread(pokemon_array, sizeof (Pokemon), 20, file);
        fclose(file);
        int indexes[6] = {21,21,21,21,21,21};

        set_pokemons_to_player(player, pokemon_array, 0, indexes);
        set_pokemons_to_player(player, pokemon_array, 1, indexes);
        set_pokemons_to_player(player, pokemon_array, 2, indexes);
        set_pokemons_to_player(player, pokemon_array, 3, indexes);
        set_pokemons_to_player(player, pokemon_array, 4, indexes);
        set_pokemons_to_player(player, pokemon_array, 5, indexes);
    }
}

void init_enemy_pokemons(Enemy *enemy, int flag)
{
    if(flag == 0)
    {
        Pokemon *p5 = new_pokemon("Charmeleon",fire_type,none,58,64,58,80,80,65);
        define_attacks("Slash",p5,normal_type,phisical,70,100,20,none_state,0,0,0,0);
        define_attacks("Flamethrower",p5,fire_type,special,90,100,15,burned_state,10,0,0,0);
        define_attacks("Submission",p5,fighting_type,phisical,80,80,25,none_state,0,0,0,0);
        define_attacks("Earthquake",p5,ground_type,phisical,100,100,10,none_state,0,0,0,0);

        set_level(55, p5);
        list_append(get_enemy_pokemons(enemy), p5);

        Pokemon *p10 = new_pokemon("Caterpie",bug_type,none,45,30,35,45,20,20);
        define_attacks("String Shot",p10,bug_type,stat,0,95,40,normal_state,100,speed_affected_stat,0,-1);
        define_attacks("Tackle",p10,normal_type,phisical,35,95,35,none_state,0,0,0,0);
        define_attacks("Harden",p10,normal_type,stat,0,-100,30,normal_state,100,defense_affected_stat,1,1);

        set_level(50, p10);
        list_append(get_enemy_pokemons(enemy), p10);

        Pokemon *p15 = new_pokemon("Beedrill", bug_type, poison_type, 65, 80, 40, 75, 45, 80);
        define_attacks("Twineedle", p15, bug_type, phisical, 50, 100, 20, none_state, 0, 0, 0, 0);
        define_attacks("Toxic", p15, poison_type, stat, 0, 85, 10, poisoned_state, 100, 0, 0, 0);
        define_attacks("Razor wind", p15, normal_type, special, 80, 100, 10, none_state, 0, 0, 0, 0);
        define_attacks("Harden", p15, normal_type, stat, 0, -100, 30, normal_state, 100, defense_affected_stat, 1, 1);

        set_level(50, p15);
        list_append(get_enemy_pokemons(enemy), p15);

        Pokemon *p20 = new_pokemon("Raticate", normal_type, none, 55, 81, 60, 97, 50, 70);
        define_attacks("Hyper Fang", p20, normal_type, phisical, 80, 90, 15, none_state, 0, 0, 0, 0);
        define_attacks("Toxic", p20, poison_type, stat, 0, 85, 10, poisoned_state, 100, 0, 0, 0);
        define_attacks("Body Slam", p20, normal_type, phisical, 85, 100, 15, paralyzed_state, 30, 0, 0, 0);
        define_attacks("Sand Attack", p20, normal_type, stat, 0, 100, 15, normal_state, 100, precision_affected_stat, 0,
                       -6);

        set_level(50, p20);
        list_append(get_enemy_pokemons(enemy), p20);
    } else if(flag == 1)
    {
        Pokemon *p8 = new_pokemon("Wartortle",water_type,none,59,63,80,58,65,80);
        define_attacks("Toxic",p8,poison_type,stat,0,85,10,poisoned_state,100,0,0,0);
        define_attacks("Submission",p8,fighting_type,phisical,80,80,25,none_state,0,0,0,0);
        define_attacks("Earthquake",p8,ground_type,phisical,100,100,10,none_state,0,0,0,0);
        define_attacks("Surf",p8,water_type,special,90,100,15,none_state,0,0,0,0);

        set_level(60, p8);
        list_append(get_enemy_pokemons(enemy), p8);

        Pokemon *p17 = new_pokemon("Pidgeotto", normal_type, flying_type, 63, 60, 55, 71, 50, 50);
        define_attacks("Sand Attack", p17, normal_type, stat, 0, 100, 15, normal_state, 100, precision_affected_stat, 0,
                       -6);
        define_attacks("Wing Attack", p17, flying_type, phisical, 60, 100, 35, none_state, 0, 0, 0, 0);
        define_attacks("Swift", p17, normal_type, special, 60, 0, 20, 0, none_state, 0, 0, 0);
        define_attacks("Toxic", p17, poison_type, stat, 0, 85, 10, poisoned_state, 100, 0, 0, 0);

        set_level(55, p17);
        list_append(get_enemy_pokemons(enemy), p17);

        Pokemon *p19 = new_pokemon("Rattata", normal_type, none, 30, 56, 35, 72, 25, 35);
        define_attacks("Hyper Fang", p19, normal_type, phisical, 80, 90, 15, none_state, 0, 0, 0, 0);
        define_attacks("Toxic", p19, poison_type, stat, 0, 85, 10, poisoned_state, 100, 0, 0, 0);
        define_attacks("Body slam", p19, normal_type, phisical, 85, 100, 15, paralyzed_state, 30, 0, 0, 0);
        define_attacks("Earthquake", p19, ground_type, phisical, 100, 100, 10, none_state, 0, 0, 0, 0);

        set_level(55, p19);
        list_append(get_enemy_pokemons(enemy), p19);

        Pokemon *p12 = new_pokemon("Butterfree", bug_type, flying_type, 60, 45, 50, 70, 90, 80);
        define_attacks("Stun spore", p12, grass_type, stat, 0, 75, 30, paralyzed_state, 100, 0, 0, 0);
        define_attacks("Swift", p12, normal_type, special, 60, 0, 20, none_state, 0, 0, 0, 0);
        define_attacks("Psychic", p12, psychic_type, special, 90, 100, 10, normal_state, 33, S_defense_affected_stat, 0,
                       -1);
        define_attacks("Wing Attack", p12, flying_type, phisical, 60, 100, 35, none_state, 0, 0, 0, 0);

        set_level(55, p12);
        list_append(get_enemy_pokemons(enemy), p12);

        Pokemon *p15 = new_pokemon("Beedrill", bug_type, poison_type, 65, 80, 40, 75, 45, 80);
        define_attacks("Twineedle", p15, bug_type, phisical, 50, 100, 20, none_state, 0, 0, 0, 0);
        define_attacks("Toxic", p15, poison_type, stat, 0, 85, 10, poisoned_state, 100, 0, 0, 0);
        define_attacks("Razor wind", p15, normal_type, special, 80, 100, 10, none_state, 0, 0, 0, 0);
        define_attacks("Harden", p15, normal_type, stat, 0, -100, 30, normal_state, 100, defense_affected_stat, 1, 1);

        set_level(55, p15);
        list_append(get_enemy_pokemons(enemy), p15);
    } else
    {
        Pokemon *p3 = new_pokemon("Venusaur",grass_type,poison_type,80,82,83,80,100,100);
        define_attacks("Razor Leaf",p3, grass_type,phisical,55,95,25,none_state,0,0,0,0);
        define_attacks("Growth",p3, normal_type,stat,0,-100,40,normal_state,100,S_attack_affected_stat,1,1);
        define_attacks("Sleep Powder",p3,grass_type,stat,0,75,15,sleep_state,100,0,0,0);
        define_attacks("Body slam",p3,normal_type,phisical,85,100,15,paralyzed_state,30,0,0,0);

        set_level(65, p3);
        list_append(get_enemy_pokemons(enemy), p3);

        Pokemon *p6 = new_pokemon("Charizard",fire_type,flying_type,78,84,78,100,109,85);
        define_attacks("Fire blast",p6,fire_type,special,120,85,5,burned_state,30,0,0,0);
        define_attacks("Wing Attack",p6,flying_type,phisical,60,100,35,none_state,0,0,0,0);
        define_attacks("Swords Dance",p6,normal_type,stat,0,-100,30,normal_state,100,attack_affected_stat,1,2);
        define_attacks("Slash",p6,normal_type,phisical,70,100,20,none_state,0,0,0,0);

        set_level(60, p6);
        list_append(get_enemy_pokemons(enemy), p6);

        Pokemon *p9 = new_pokemon("Blastoise",water_type,none,79,83,100,78,85,105);
        define_attacks("Headbutt",p9,normal_type,phisical,70,100,15,none_state,0,0,0,0);
        define_attacks("Hydro pump",p9,water_type,special,120,80,5,none_state,0,0,0,0);
        define_attacks("Tail whip",p9,normal_type,stat,0,100,30,normal_state,100,defense_affected_stat,0,-1);
        define_attacks("Surf",p9,water_type,special,90,100,15,none_state,0,0,0,0);

        set_level(60, p9);
        list_append(get_enemy_pokemons(enemy), p9);

        Pokemon *p12 = new_pokemon("Butterfree", bug_type, flying_type, 60, 45, 50, 70, 90, 80);
        define_attacks("Stun spore", p12, grass_type, stat, 0, 75, 30, paralyzed_state, 100, 0, 0, 0);
        define_attacks("Swift", p12, normal_type, special, 60, 0, 20, none_state, 0, 0, 0, 0);
        define_attacks("Psychic", p12, psychic_type, special, 90, 100, 10, normal_state, 33, S_defense_affected_stat, 0,
                       -1);
        define_attacks("Wing Attack", p12, flying_type, phisical, 60, 100, 35, none_state, 0, 0, 0, 0);

        set_level(60, p12);
        list_append(get_enemy_pokemons(enemy), p12);

        Pokemon *p18 = new_pokemon("Pidgeot", normal_type, flying_type, 83, 80, 75, 101, 70, 70);
        define_attacks("Swift", p18, normal_type, special, 60, 0, 20, none_state, 0, 0, 0, 0);
        define_attacks("Gust", p18, normal_type, special, 40, 100, 35, none_state, 0, 0, 0, 0);
        define_attacks("Sand Attack", p18, normal_type, stat, 0, 100, 15, normal_state, 100, precision_affected_stat, 0,
                       -6);
        define_attacks("Wing Attack", p18, flying_type, phisical, 60, 100, 35, none_state, 0, 0, 0, 0);

        set_level(60, p18);
        list_append(get_enemy_pokemons(enemy), p18);

        Pokemon *p20 = new_pokemon("Raticate", normal_type, none, 55, 81, 60, 97, 50, 70);
        define_attacks("Hyper Fang", p20, normal_type, phisical, 80, 90, 15, none_state, 0, 0, 0, 0);
        define_attacks("Toxic", p20, poison_type, stat, 0, 85, 10, poisoned_state, 100, 0, 0, 0);
        define_attacks("Body slam", p20, normal_type, phisical, 85, 100, 15, paralyzed_state, 30, 0, 0, 0);
        define_attacks("Sand Attack", p20, normal_type, stat, 0, 100, 15, normal_state, 100, precision_affected_stat, 0,
                       -6);

        set_level(60, p20);
        list_append(get_enemy_pokemons(enemy), p20);
    }
}

int teamPlayerAlive(RedPlayer *player)
{

    for (int i = 0; i < 5; ++i) {
        Pokemon *pk = get_element(get_player_pokemons(player),i);
        if(pk->alive == 1)
        {
            return 1;
        }
    }
    return 0;
}

int teamEnemyAlive(Enemy *enemy)
{

    for (int i = 0; i < 5; ++i) {
        Pokemon *pk = get_element(get_enemy_pokemons(enemy),i);
        if(pk->alive == 1)
        {
            return 1;
        }
    }
    return 0;

}
