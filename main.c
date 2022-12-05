#include "Pokemon.h"
#include "Player.h"
#include <unistd.h>
#include "Battle.h"

#define JUMP printf("\n");

int main() {
    char choice;

    printf("Welcome to...");
    sleep(2);
    JUMP
    printf("                                  ,'\\\n");
    printf("    _.----.        ____         ,'  _\\   ___    ___     ____\n");
    printf("_,-'       `.     |    |  /`.   \\,-'    |   \\  /   |   |    \\  |`.\n");
    printf("\\      __    \\    '-.  | /   `.  ___    |    \\/    |   '-.   \\ |  |\n");
    printf(" \\.    \\ \\   |  __  |  |/    ,','_  `.  |          | __  |    \\|  |\n");
    printf("   \\    \\/   /,' _`.|      ,' / / / /   |          ,' _`.|     |  |\n");
    printf("    \\     ,-'/  /   \\    ,'   | \\/ / ,`.|         /  /   \\  |     |\n");
    printf("     \\    \\ |   \\_/  |   `-.  \\    `'  /|  |    ||   \\_/  | |\\    |\n");
    printf("      \\    \\ \\      /       `-.`.___,-' |  |\\  /| \\      /  | |   |\n");
    printf("       \\    \\ `.__,'|  |`-._    `|      |__| \\/ |  `.__,'|  | |   |\n");
    printf("        \\_.-'       |__|    `-._ |              '-.|     '-.| |   |\n");
    printf("                                `'                            '-._|\n");

    sleep(1);
    JUMP
    printf("A command line experience!!!\n");
    JUMP
    sleep(2);

    printf("-----MENU-----\n");
    JUMP
    printf("[a] New Game");
    JUMP
    printf("[b] Load");
    JUMP
    printf("Choice > ");
    choice = fgetc(stdin);

    switch (choice)
    {
        case 'a':
        {
            init_pokemons();
            RedPlayer *red = init_player();
            Enemy *blue = init_enemy("Blue");
            Enemy *leaf = init_enemy("Leaf");
            Enemy *lance = init_enemy("Lance");

            obtain_pokemons_from_file(red);
            set_player_potions(red);

            init_enemy_pokemons(blue,0);
            init_enemy_pokemons(leaf,1);
            init_enemy_pokemons(lance,2);

            printf("NEW GAME!!!");
            JUMP
            sleep(1);
            JUMP
            printf("You are Red... The best Pokemon trainer in the world.\n");
            JUMP
            sleep(2);
            printf("You are always proud of yourself, and always wish\n");
            printf("to prove to others what you are capable of.\n");
            JUMP
            sleep(2);
            printf("Recently, you became aware of a Pokemon tournament, \n");
            printf("where you, obviously, needed to participate.\n");
            JUMP
            sleep(2);
            printf("So, you grabbed the best Pokemons you have, 5 dollars to register for the tournament,\n");
            printf("a sandwich for lunch, and directed yourself towards the tournament.\n");
            JUMP
            sleep(2);
            printf("This are your pokemons. Take a look to them...");
            JUMP
            sleep(2);
            print_pokemon(get_element(get_player_pokemons(red),0));
            sleep(2);
            JUMP
            print_pokemon(get_element(get_player_pokemons(red),1));
            sleep(2);
            JUMP
            print_pokemon(get_element(get_player_pokemons(red),2));
            sleep(2);
            JUMP
            print_pokemon(get_element(get_player_pokemons(red),3));
            sleep(2);
            JUMP
            print_pokemon(get_element(get_player_pokemons(red),4));
            sleep(2);
            JUMP
            print_pokemon(get_element(get_player_pokemons(red),5));
            sleep(2);
            JUMP

            battle(red, blue, 3);
            battle(red, leaf,4);
            battle(red, lance, 5);
            break;
        }
        case 'b':
        {
            printf("LOADED GAME!!!");
            break;
        }
        default:
            break;
    }
    return 0;
}