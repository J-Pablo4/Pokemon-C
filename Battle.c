//
// Created by jplop on 05/12/2022.
//

#include "Battle.h"
#include "Pokemon.h"
#include <unistd.h>

#define JUMP printf("\n");

Pokemon* select_pokemon_for_battle(RedPlayer *player);
char fight_menu(Pokemon *enemy_pokemon, Pokemon *player_pokemon);
void potions_menu(Pokemon *player_pokemon, RedPlayer *player);
int potion_exist(RedPlayer *player);

void battle(RedPlayer *player, Enemy *enemy)
{
    Pokemon *enemy_pokemon = NULL;
    Pokemon *player_pokemon = NULL;
    char choice;
    printf("you're gonna fight with %s\n", get_enemy_name(enemy));
    enemy_pokemon = get_element(get_enemy_pokemons(enemy), 5);
    JUMP
    printf("The enemy has chosen %s\n", get_pokemon_name(enemy_pokemon));
    JUMP
    system("pause");

    player_pokemon = select_pokemon_for_battle(player);
    printf("You have selected %s\n", get_pokemon_name(player_pokemon));

    sleep(1);
    choice = fight_menu(enemy_pokemon, player_pokemon);
    
    if(choice == 'a')
    {
        printf("hola");
    } else
    {
        potions_menu(player_pokemon, player);
    }
}

Pokemon* select_pokemon_for_battle(RedPlayer *player)
{
    char choice;
    printf("---Select a pokemon---\n");
    printf("[a] %s", get_pokemon_name(get_element(get_player_pokemons(player),0)));
    JUMP
    printf("[b] %s", get_pokemon_name(get_element(get_player_pokemons(player),1)));
    JUMP
    printf("[c] %s", get_pokemon_name(get_element(get_player_pokemons(player),2)));
    JUMP
    printf("[d] %s", get_pokemon_name(get_element(get_player_pokemons(player),3)));
    JUMP
    printf("[e] %s", get_pokemon_name(get_element(get_player_pokemons(player),4)));
    JUMP
    printf("[f] %s", get_pokemon_name(get_element(get_player_pokemons(player),5)));
    JUMP
    JUMP
    setbuf(stdin,NULL);
    printf("Choice > ");
    choice = fgetc(stdin);
    switch (choice)
    {
        case 'a':
        {
            return get_element(get_player_pokemons(player),0);
        }
        case 'b':
        {
            return get_element(get_player_pokemons(player),1);
        }
        case 'c':
        {
            return get_element(get_player_pokemons(player),2);
        }
        case 'd':
        {
            return get_element(get_player_pokemons(player),3);
        }
        case 'e':
        {
            return get_element(get_player_pokemons(player),4);
        }
        case 'f':
        {
            return get_element(get_player_pokemons(player),5);
        }
        default:
            return NULL;
    }
}

char fight_menu(Pokemon *enemy_pokemon, Pokemon *player_pokemon)
{
    char choice = 'a';
    if(get_pokemon_hp(enemy_pokemon) > 0 && get_pokemon_hp(player_pokemon) > 0)
    {
        printf("---Select an Action ---\n");
        printf("[a] Attack");
        JUMP
        printf("[b] Potions");
        JUMP
        setbuf(stdin,NULL);
        printf("Choice > ");
        choice = fgetc(stdin);
    }
    return choice;
}

void potions_menu(Pokemon *player_pokemon, RedPlayer *player)
{
    char choice;
    if(potion_exist(player))
    {
        printf("---Select a Potion ---\n");
        if(get_player_potions(player)[0] == potion)
        {
            printf("[a] Potion <%d hp>", potion);
            JUMP
        }
        if(get_player_potions(player)[1] == potion)
        {
            printf("[b] Potion <%d hp>", potion);
            JUMP
        }
        if(get_player_potions(player)[2] == super_potion)
        {
            printf("[c] Super Potion <%d hp>", super_potion);
            JUMP
        }
        if(get_player_potions(player)[3] == hyper_potion)
        {
            printf("[d] Hyper Potion <%d hp>", hyper_potion);
            JUMP
        }
        if(get_player_potions(player)[4] == max_potion)
        {
            printf("[e] Max Potion <%d hp>", max_potion);
            JUMP
        }
        setbuf(stdin,NULL);
        printf("Choice > ");
        choice = fgetc(stdin);

        switch (choice)
        {
            case 'a':
            {
                pokemon_use_potion(player_pokemon, get_player_potions(player)[0]);
                set_player_potion_to_none(player, 0);
                break;
            }
            case 'b':
            {
                pokemon_use_potion(player_pokemon, get_player_potions(player)[1]);
                set_player_potion_to_none(player, 1);
                break;
            }
            case 'c':
            {
                pokemon_use_potion(player_pokemon, get_player_potions(player)[2]);
                set_player_potion_to_none(player, 2);
                break;
            }
            case 'd':
            {
                pokemon_use_potion(player_pokemon, get_player_potions(player)[3]);
                set_player_potion_to_none(player, 3);
                break;
            }
            case 'e':
            {
                pokemon_use_potion(player_pokemon, get_player_potions(player)[4]);
                set_player_potion_to_none(player, 4);
                break;
            }
            default:
                break;
        }
    } else
    {
        JUMP
        printf("You don't have any potion to use");
    }
}

int potion_exist(RedPlayer *player)
{
    for (int i = 0; i < 5; ++i)
    {
        if(get_player_potions(player)[i] != none_potion)
        {
            return 1;
        }
    }
    return 0;
}