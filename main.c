#include "Pokemon.h"
#include "Player.h"
#include <unistd.h>

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
    system("pause");

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
            obtain_pokemons_from_file(red);
            set_player_potions(red);
            printf("NEW GAME!!!");
            JUMP
            sleep(1);
            printf("This are your pokemons. Take a look to them...");
            JUMP
            system("pause");
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