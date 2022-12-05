#include "Player.h"
#include "Pokemon.h"

struct redPlayer{
    List *pokemons;
    Potion potions[5];
};

struct enemy{
    List *enemyPokemons;
    int defeated;
};

Enemy* init_enemy()
{
    Enemy *npc = calloc(1, sizeof (Enemy));
    npc->enemyPokemons = list_new();
    return npc;
}

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

List* get_player_pokemons(RedPlayer *player)
{
    return player->pokemons;
}

List* get_enemy_pokemons(Enemy *enemy)
{
    return enemy->enemyPokemons;
}
