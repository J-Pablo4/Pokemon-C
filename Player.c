#include "Player.h"
#include "Pokemon.h"

struct redPlayer{
    List *pokemons;
    Potion potions[5];
};

struct enemy{
    List *enemyPokemons;
    char *name;
};

/*Función inicializadora de la estructura del enemigo, primero asignamos memoria para la estructura
 * y despues le asignamos una lista para almacenar a sus pokemones y los demas datos correspondientes*/
Enemy* init_enemy(char *name)
{
    Enemy *npc = calloc(1, sizeof (Enemy));
    npc->enemyPokemons = list_new();
    npc->name = name;
    return npc;
}

/*Función inicializadora de la estructura del jugador, primero asignamos memoria para la estructura
 * y despues le asignamos una lista para almacenar a sus pokemones y los demas datos correspondientes*/
RedPlayer* init_player()
{
    RedPlayer *newRed = calloc(1, sizeof(RedPlayer));
    newRed->pokemons = list_new();
    return newRed;
}


void set_player_potions(RedPlayer *player)
{
    player->potions[0] = potion;
    player->potions[1] = potion;
    player->potions[2] = super_potion;
    player->potions[3] = hyper_potion;
    player->potions[4] = max_potion;
}

void set_player_potion_to_none(RedPlayer *player, int index)
{
    player->potions[index] = none_potion;
}

List* get_player_pokemons(RedPlayer *player)
{
    return player->pokemons;
}

List* get_enemy_pokemons(Enemy *enemy)
{
    return enemy->enemyPokemons;
}

char* get_enemy_name(Enemy *enemy)
{
    return enemy->name;
}

Potion* get_player_potions(RedPlayer *player)
{
    return player->potions;
}

void player_normalize(RedPlayer *player)
{
    Pokemon *pokemon;
    for(int i = 0; i < 6; i++)
    {
        pokemon = get_element(get_player_pokemons(player),i);
        pokemon_normalize(pokemon);
    }
}
void player_set_level(RedPlayer *player, int level)
{
    Pokemon *pokemon;
    for(int i = 0; i < 6; i++)
    {
        pokemon = get_element(get_player_pokemons(player),i);
        set_level(level, pokemon);
    }
}