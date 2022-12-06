//
// Created by jplop on 05/12/2022.
//

#include "Battle.h"
#include "Pokemon.h"
#include <unistd.h>
#include "Attacks.h"

#define JUMP printf("\n");

Pokemon* select_pokemon_for_battle(RedPlayer *player);
char fight_menu(Pokemon *enemy_pokemon, Pokemon *player_pokemon);
void potions_menu(Pokemon *player_pokemon, RedPlayer *player);
int potion_exist(RedPlayer *player);
Attack* select_attack(Pokemon *player_pokemon);
Attack* getEnemyAttack(Pokemon* enemyPokemon);

void battle(RedPlayer *player, Enemy *enemy, int i)
{
    Pokemon *enemy_pokemon = NULL;
    Pokemon *player_pokemon = NULL;
    char choice;
    int index = i;
    printf("you're gonna fight with %s\n", get_enemy_name(enemy));
    enemy_pokemon = get_element(get_enemy_pokemons(enemy), index);
    JUMP
    printf("The enemy has chosen %s lv:%d <%d HP>\n", get_pokemon_name(enemy_pokemon), get_pokemon_level(enemy_pokemon), get_pokemon_hp(enemy_pokemon));
    JUMP
    sleep(2);

    player_pokemon = select_pokemon_for_battle(player);
    printf("You have selected %s lv:%d <%d HP>\n", get_pokemon_name(player_pokemon), get_pokemon_level(player_pokemon), get_pokemon_hp(player_pokemon));
    JUMP
    sleep(1);
    while (teamPlayerAlive(player) && teamEnemyAlive(enemy))
    {
        if(!get_pokemon_alive(enemy_pokemon))
        {
            printf("%s has fainted.\n", get_pokemon_name(enemy_pokemon));
            JUMP
            sleep(1);
            printf("The enemy has chosen %s lv:%d <%d HP>\n", get_pokemon_name(enemy_pokemon), get_pokemon_level(enemy_pokemon), get_pokemon_hp(enemy_pokemon));
            JUMP
            sleep(1);
            index--;
            enemy_pokemon = get_element(get_enemy_pokemons(enemy), index);
        }else if(!get_pokemon_alive(player_pokemon))
        {
            printf("%s has fainted.\n", get_pokemon_name(player_pokemon));
            JUMP
            sleep(1);
            printf("You have selected %s lv:%d <%d HP>\n", get_pokemon_name(player_pokemon), get_pokemon_level(player_pokemon), get_pokemon_hp(player_pokemon));
            JUMP
            sleep(1);
            player_pokemon = select_pokemon_for_battle(player);
            while (!get_pokemon_alive(player_pokemon))
            {
                printf("This pokemon is fainted... Select another one.\n");
                JUMP
                player_pokemon = select_pokemon_for_battle(player);
            }
        }
        printf("Enemy: %s lv:%d <%d HP>\n", get_pokemon_name(enemy_pokemon), get_pokemon_level(enemy_pokemon), get_pokemon_hp(enemy_pokemon));
        printf("You: %s lv:%d <%d HP>\n", get_pokemon_name(player_pokemon), get_pokemon_level(player_pokemon), get_pokemon_hp(player_pokemon));
        JUMP
        choice = fight_menu(enemy_pokemon, player_pokemon);
        Attack *enemyAttack = getEnemyAttack(enemy_pokemon);

        if(choice == 'a')
        {
            Attack *players_attack = select_attack(player_pokemon);
            if(get_pokemon_speed(player_pokemon) > get_pokemon_speed(enemy_pokemon))
            {
                hit(players_attack,player_pokemon,enemy_pokemon);
                if(get_pokemon_alive(enemy_pokemon))
                {
                    hit(enemyAttack,enemy_pokemon,player_pokemon);
                }
            } else
            {
                hit(enemyAttack,enemy_pokemon,player_pokemon);
                if(get_pokemon_alive(enemy_pokemon))
                {
                    hit(players_attack,player_pokemon,enemy_pokemon);
                }
            }
        } else
        {
            potions_menu(player_pokemon, player);
            hit(enemyAttack,enemy_pokemon,player_pokemon);
        }
    }

    if(teamPlayerAlive(player))
    {
        printf("YOU WIN!!!\n");
        JUMP
        sleep(1);
        printf("You have defeated %s", get_enemy_name(enemy));
    } else
    {
        printf(" _____                         ____                 \n");
        printf("/ ____|                       / __ \\                \n");
        printf("| |  __  __ _ _ __ ___   ___  | |  | |_   _____ _ __ \n");
        printf("| | |_ |/ _` | '_ ` _ \\ / _ \\ | |  | \\ \\ / / _ \\ '__|\n");
        printf("| |__| | (_| | | | | | |  __/ | |__| |\\ V /  __/ |   \n");
        printf(" \\_____|\\__,_|_| |_| |_|\\___|  \\____/  \\_/ \\___|_| \n");
        JUMP
        sleep(1);
        printf("Thanks for playing... See you next time\n");
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

Attack* select_attack(Pokemon *player_pokemon)
{
    Attack *at1 = get_element(get_pokemon_list_attacks(player_pokemon),0);
    Attack *at2 = get_element(get_pokemon_list_attacks(player_pokemon),1);
    Attack *at3 = get_element(get_pokemon_list_attacks(player_pokemon),2);
    Attack *at4 = get_element(get_pokemon_list_attacks(player_pokemon),3);
    char choice;

    printf("---Select an Attack ---\n");
    printf("[a] %s PP:%d/%d Type:%s", get_attack_name(at1), get_attack_pp(at1),get_attack_base_pp(at1), type_to_string(
            get_attack_type(at1)));
    JUMP
    printf("[b] %s PP:%d/%d Type:%s", get_attack_name(at2), get_attack_pp(at2),get_attack_base_pp(at2), type_to_string(
            get_attack_type(at2)));
    JUMP
    printf("[c] %s PP:%d/%d Type:%s", get_attack_name(at3), get_attack_pp(at3),get_attack_base_pp(at3), type_to_string(
            get_attack_type(at3)));
    JUMP
    if(at4 != NULL)
    {
        printf("[d] %s PP:%d/%d Type:%s", get_attack_name(at4), get_attack_pp(at4),get_attack_base_pp(at4), type_to_string(
                get_attack_type(at4)));
        JUMP
    }

    setbuf(stdin,NULL);
    printf("Choice > ");
    choice = fgetc(stdin);

    switch (choice) {
        case 'a':
        {
            return at1;
        }
        case 'b':
        {
            return at2;
        }
        case 'c':
        {
            return at3;
        }
        case 'd':
        {
            return at4;
        }
        default:
            return NULL;
    }
}

Attack* getEnemyAttack(Pokemon* enemyPokemon)
{
    int selectedAttack = true;
    while (selectedAttack)
    {
        time_t t;
        int index;
        srand((unsigned) time(&t));
        index = (rand() % 3);
        Attack *a = get_element(get_pokemon_list_attacks(enemyPokemon),index);

        if(get_attack_pp(a) > 0)
            return a;
    }
    return 0;
}
