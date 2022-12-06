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
            sleep(3);
            printf("This are your pokemons. Take a look to them...\n");
            JUMP
            sleep(3);
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

            printf("Blue: we face each other again Red... this time i'm going to win!!!\n");
            JUMP
            sleep(2);
            battle(red, blue, 3);
            printf("Blue: You are strong as ever, I'll have to keep training\n");
            JUMP
            printf("      for our next match, good luck in the rest of the tournament my eternal rival.\n");
            sleep(2);
            JUMP
            printf("(Red and Blue shake hands and Red goes down the hallway)\n");
            JUMP
            sleep(3);
            printf("Leaf: You finally are here, I'm not going to lose to you like Blue did\n");
            JUMP
            sleep(2);
            battle(red, leaf,4);
            printf("Leaf: You so damn strong, but I almost got you\n");
            JUMP
            printf("Leaf: I'm heading to mt. Silver to keep combat with some strong pokemon\n");
            JUMP
            printf("(Leaf goes running to the entry where she then gets on a taxi to mt. Silver)\n");
            JUMP
            sleep(2);
            printf("Lance: You must be pretty strong to get till this phase of the tournament\n");
            JUMP
            printf("       but I'm a Pokemon champion, I'm not losing to a kid\n");
            JUMP
            sleep(2);
            battle(red, lance, 5);
            printf("Lance: That's it! I hate to admit it, but you are a pokemon master!");
            JUMP
            printf("       If I had my Dragonites I would have won!\n");
            JUMP
            sleep(3);
            printf("At last, you were able to stand over all the participants\n");
            JUMP
            printf("and crown yourself as the best pokemon train!!!\n");
            JUMP
            sleep(2);
            printf("Finally, you received the tournament cup. Congratulations!!!\n");
            printf("  _______\n");
            printf(" |       |\n");
            printf("(|  RED  |)\n");
            printf(" |  #X   |\n");
            printf("  \\     /\n");
            printf("   `---'\n");
            printf("   _|_|_\n");
            JUMP
            sleep(2);
            printf("Thanks for playing... See you next time.\n");
            JUMP
            sleep(1);
            printf("       \\:.             .:/\n");
            printf("        \\``._________.''/ \n");
            printf("         \\             / \n");
            printf(" .--.--, / .':.   .':. \\\n");
            printf("/__:  /  | '::' . '::' |\n");
            printf("   / /   |`.   ._.   .'|\n");
            printf("  / /    |.'         '.|\n");
            printf(" /___-_-,|.\\  \\   /  /.|\n");
            printf("      // |''\\.;   ;,/ '|\n");
            printf("      `==|:=         =:|\n");
            printf("         `.          .'\n");
            printf("           :-._____.-:\n");
            printf("          `''       `''\n");
            JUMP
            printf("See you next time. :)\n");
            sleep(3);
            printf("Credits\n");
            printf("------------------------------------------\n");
            JUMP
            printf("Game developers:\n");
            printf("Juan Pablo Lopez Zuniga, GitHub: J-Pablo4\n");
            printf("Miguel Ignacio Hernandez Noriega, GitHub: MiguelHIteso\n");
            printf("Jose Antonio Mendoza Navarro, GitHub: josemenav\n");
            printf("Francisco Aaron Ortega Anguiano, GitHub: AaronOrtega1\n");
            sleep(3);
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