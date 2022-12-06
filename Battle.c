//
// Created by jplop on 05/12/2022.
//

#include "Battle.h"
#include "Pokemon.h"
#include <unistd.h>
#include "Attacks.h"

#define JUMP printf("\n");

/*Esta funcion actua como un controlador que manda a llamar las funciones que se ven en pantalla, las cuales
 * despliegan el menu de pokemones que tiene el jugador, así como el menu de posiones y el de ataques disponibles*/
Pokemon* select_pokemon_for_battle(RedPlayer *player);
char fight_menu(Pokemon *enemy_pokemon, Pokemon *player_pokemon);
void potions_menu(Pokemon *player_pokemon, RedPlayer *player);
int potion_exist(RedPlayer *player);
Attack* select_attack(Pokemon *player_pokemon);
Attack* getEnemyAttack(Pokemon* enemyPokemon);
int get_random();
void player_move(Pokemon *attacker, Pokemon *receiver, Attack* attack);
void after_hit(Pokemon *pokemon);

/*La siguiente funcion es la que maneja lo que ocurre en la batalla
 * primero a travez del getter get_enemy_pokemons y get_element saca al pokemon que el enemigo va a usar
 * y lo imprime, seguido de esto manda a llamar a la funcion select_pokemon_for_battle, con la cual
 * el jugador principal va a poder escoger un pokemon y si el jugador tiene pokemones vivos y el enemigo tambien
 * entonces por medio la velocidad de los pokemones es el que ataca primero por medio de la funcion player_move
 * que es la que controla el turno del jugador*/
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
    while (teamPlayerAlive(player) && teamEnemyAlive(enemy, i))
    {
        if(!get_pokemon_alive(enemy_pokemon))
        {

            printf("%s has fainted.\n", get_pokemon_name(enemy_pokemon));
            JUMP
            sleep(1);
            index--;
            enemy_pokemon = get_element(get_enemy_pokemons(enemy), index);
            printf("The enemy has chosen %s lv:%d <%d HP>\n", get_pokemon_name(enemy_pokemon), get_pokemon_level(enemy_pokemon), get_pokemon_hp(enemy_pokemon));
            JUMP
            sleep(1);
        }else if(!get_pokemon_alive(player_pokemon))
        {
            printf("%s has fainted.\n", get_pokemon_name(player_pokemon));
            JUMP
            sleep(1);
            player_pokemon = select_pokemon_for_battle(player);
            printf("You have selected %s lv:%d <%d HP>\n", get_pokemon_name(player_pokemon), get_pokemon_level(player_pokemon), get_pokemon_hp(player_pokemon));
            JUMP
            sleep(1);
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
        Attack *enemyAttack;

        do {
            enemyAttack = getEnemyAttack(enemy_pokemon);
        }
        while(get_attack_pp(enemyAttack) == 0);

        if(choice == 'a')
        {
            Attack *players_attack;
            do
            {
                players_attack = select_attack(player_pokemon);
                if(get_attack_pp(players_attack) == 0)
                {
                    printf("The movement is out of PP. Select another one!\n");
                    JUMP
                }
            }
            while(get_attack_pp(players_attack) == 0);

            if(get_pokemon_speed(player_pokemon) > get_pokemon_speed(enemy_pokemon))
            {
                player_move(player_pokemon, enemy_pokemon, players_attack);
                if(get_pokemon_alive(enemy_pokemon))
                {
                    player_move(enemy_pokemon, player_pokemon, enemyAttack);
                }
            } else
            {
                player_move(enemy_pokemon, player_pokemon, enemyAttack);
                if(get_pokemon_alive(player_pokemon))
                {
                    player_move(player_pokemon, enemy_pokemon, players_attack);
                }
            }
            after_hit(player_pokemon);
            after_hit(enemy_pokemon);
        } else
        {
            potions_menu(player_pokemon, player);
            player_move(enemy_pokemon, player_pokemon, enemyAttack);
            after_hit(player_pokemon);
            after_hit(enemy_pokemon);
        }
    }

    if(teamPlayerAlive(player))
    {
        player_normalize(player);
        player_set_level(player, get_pokemon_level(player_pokemon) + 5);
        printf("YOU WON!!!\n");
        JUMP
        sleep(1);
        printf("You have defeated %s", get_enemy_name(enemy));
        JUMP
        sleep(1);
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
        printf("Thanks for playing... See you next time.\n");
        JUMP
    }

}


/*mediante los getters get_pokemon_name, get_element y get_player_pokemon, accedemos a la lista de pokemones que el jugador tiene
 * despues de acuerdo a un switch case de los pokemones que tenemos, escoge al pokemon para pelear*/
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

/*Esta función revisa si el pokemon que se selecciono tiene vida para pelear, y si si la tiene
 * entonces despliega un menu para decidir si va a seguir peleando o tomara una posion */
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

/*Esta funcion accede a las posiones que el jugador tiene por medio del getterget_player_potions, no sin antes hacer una
 * validacion sobre la existencia de las posiones en el arsenal del jugador, por medio de la funcion potion_exist
 * despues por medio de un switch casedependiendo de la pision que el jugador haya escogido, manda a llamar la funcion
 * pokemon_use_potion y por medio del setter set_player_potion_to_none elimina esa posion del arsenal del jugador*/
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

/*Esta funcion accede a las posiones que el jugador tiene por medio de get_player_potions y
 * las recorre por medio de un ciclo for para revisar que al menos haya una*/
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


/*La siguiente funcion accede a la lista en la que los pokemones y sus ataques se encuentran almacenados y los asigna
 * a los 4 ataques definidos, despues imprime un menu donde accede a los atributos de los atauqes por medio de getters
 * y dependiendo de la eleccion que se realice un switch escoge el ataque a retronar */
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

/*Hace exactamente lo mismo que la funcion anterior pero escoge el ataque de manera aleatoria*/
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

int get_random()
{
    time_t t;
    int random;
    srand((unsigned) time(&t));
    random = (rand() % 100);
    return random;
}

/*Esta funcion define si un pokemon esta paralizado o no y con base a esto define si su ataque puede o no proceder
 */
void is_paralysed(Pokemon *attacker, Pokemon *receiver, Attack *attack)
{
    if (get_random() <= 75) {
        hit(attack, attacker, receiver);

    } else {
        printf("%s is paralyzed and is unable to move.\n", get_pokemon_name(attacker));
        JUMP
        sleep(1);
    }
}

/*Esta funcion define si un pokemon esta dormido o no y con base a esto define si su ataque puede o no proceder
 */
void is_sleep(Pokemon *attacker, Pokemon *receiver, Attack *attack)
{
    if (get_random() <= 50) {
        printf("%s woke up.\n", get_pokemon_name(attacker));
        JUMP
        sleep(1);
        modify_pokemon_state(normal_state, attacker);
        hit(attack, attacker, receiver);
    } else {
        printf("%s is fast asleep.\n", get_pokemon_name(attacker));
        JUMP
        sleep(1);
    }
}
/*Esta funcion define si un pokemon esta congelado o no y con base a esto define si su ataque puede o no proceder
 */
void is_frozen(Pokemon *attacker, Pokemon *receiver, Attack *attack)
{
    if (get_random() <= 50) {
        printf("%s has warmed up.\n", get_pokemon_name(attacker));
        JUMP
        sleep(1);
        modify_pokemon_state(normal_state, attacker);
        hit(attack, attacker, receiver);
    } else {
        printf("%s is frozen solid.\n", get_pokemon_name(attacker));
        JUMP
        sleep(1);
    }
}

//Esto aun no

void is_burned(Pokemon *pokemon)
{
    modify_pokemon_hp(get_pokemon_hp(pokemon)-(get_pokemon_fixed_hp(pokemon)/16), pokemon);
    modify_pokemon_attack(get_pokemon_attack(pokemon)/2,pokemon);
    printf("%s is hurt by its burned.\n", get_pokemon_name(pokemon));
    JUMP
    sleep(1);
}
void is_poisoned(Pokemon *pokemon)
{
    modify_pokemon_hp(get_pokemon_hp(pokemon)-(get_pokemon_fixed_hp(pokemon)/16), pokemon);
    printf("%s is hurt by poison.\n", get_pokemon_name(pokemon));
    JUMP
    sleep(1);
}

void after_hit(Pokemon *pokemon)
{
    if(get_pokemon_current_state(pokemon) == burned_state)
    {
        is_burned(pokemon);
    } else if(get_pokemon_current_state(pokemon) == poisoned_state)
    {
        is_poisoned(pokemon);
    }
}

/*La funcion player_move determina de acuerdo con el estado del pokemon actual
 * si este tiene o puede atacar o no, esto lo hace por medio de estructuras selectivas que
 * mandan llamar el getter get_pokemon_current_state, el cual accede al estado actual del pokemon
 * y en dado caso de no estar ni congelado, paralizado o recibiendo un ataque, te deja atacar */
void player_move(Pokemon *attacker, Pokemon *receiver, Attack* attack)
{
    if(get_pokemon_current_state(attacker) == paralyzed_state)
    {
        is_paralysed(attacker, receiver, attack);
    } else if(get_pokemon_current_state(attacker) == sleep_state)
    {
        is_sleep(attacker, receiver, attack);
    }else if(get_pokemon_current_state(attacker) == frozen_state)
    {
        is_frozen(attacker, receiver, attack);
    }else
    {
        hit(attack, attacker, receiver);
    }
}
