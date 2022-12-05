//
// Created by jplop on 05/12/2022.
//

#include "Battle.h"
#include "Pokemon.h"
#include <time.h>
#include <unistd.h>

#define JUMP printf("\n");

Pokemon* select_pokemon_for_battle(RedPlayer *player);

void battle(RedPlayer *player, Enemy *enemy)
{
    Pokemon *enemy_pokemon = NULL;
    Pokemon *player_pokemon = NULL;
    printf("you're gonna fight with %s\n", get_enemy_name(enemy));
    enemy_pokemon = get_element(get_enemy_pokemons(enemy), 5);
    JUMP
    printf("The enemy has chosen %s\n", get_pokemon_name(enemy_pokemon));
    JUMP
    system("pause");

    player_pokemon = select_pokemon_for_battle(player);
    printf("You have selected %s", get_pokemon_name(player_pokemon));

    sleep(1);

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
    choice = fgetc(stdin)
            ;
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