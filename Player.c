#include "Player.h"
#include "stdio.h"
#include "Lists.h"
#include "Pokemon.h"
int framesCounter = 0;

struct redPlayer{
    Vector2 position;
    float speed;
    Vector2 PlayerDirection;
    int right;
    int left;
    int up;
    int down;
    Texture2D playerTXTR;
    Rectangle mask;
    List *pokemons;
};

RedPlayer* InitPlayer(int x, int y){
    RedPlayer *newRed = calloc(1, sizeof(RedPlayer));
    newRed->position.x = (float)x/2;
    newRed->position.y = (float)y/2;
    return newRed;
}

void UpdatePlayer(float delta, RedPlayer *player){
    int frameSpeed = 3;
    int currentFrame = 0;

    if(IsKeyDown(KEY_RIGHT)){
        player->position.x += PLAYER_HOR_SPD*delta;
        player->right = true;
        player->left = false;
        player->PlayerDirection.y = 3;
        player->PlayerDirection.x = 3;
        framesCounter++;

    }
    if(IsKeyDown(KEY_LEFT)){
        player->position.x -= PLAYER_HOR_SPD*delta;
        player->left = true;
        player->PlayerDirection.y = 2;
        player->PlayerDirection.x = 2;
        framesCounter++;
    }
    if(IsKeyDown(KEY_UP)){
        player->position.y -= PLAYER_HOR_SPD*delta;
        player->up = true;
        player->down = false;
        player->PlayerDirection.y = 1;
        player->PlayerDirection.x = 0;
        framesCounter++;
    }
    if(IsKeyDown(KEY_DOWN)){
        player->position.y += PLAYER_HOR_SPD*delta;
        player->down = true;
        player->up = false;
        player->PlayerDirection.y = 0;
        player->PlayerDirection.x = 0;
        framesCounter++;
    }


    if (framesCounter >= frameSpeed){                                  //ANIMATION
        framesCounter= 0;
            player->PlayerDirection.x++;
            currentFrame++;
        if(currentFrame > 5){
            currentFrame = 0;
            player->PlayerDirection.x++;
        } else {
            player->PlayerDirection.x = 1;
        }
    }
}


Vector2 getPlayerPos(RedPlayer *player){
    Vector2 pos;
    pos.x = player->position.x;
    pos.y = player->position.y;
    return pos;
}

void setPlayerTexture(Texture2D t, RedPlayer *player)
{
    player->playerTXTR = t;
}

void RenderPlayer(RedPlayer *player, int width)
{
    Rectangle mask;
    mask.y =player->PlayerDirection.y * (float)player->playerTXTR.height/4;
    mask.x =player->PlayerDirection.x * (float)player->playerTXTR.width/3;
    mask.height = player->playerTXTR.height/4;
    mask.width = player->playerTXTR.width/3;
    DrawTextureRec(player->playerTXTR, mask, getPlayerPos(player), WHITE);

}

void init_pokemons(RedPlayer *player)
{
    FILE *file = fopen("../pokemon.txt", "a");

    if(file == NULL)
    {
        printf("No se abrio el archivo\n");
        return;
    }else
    {
        Pokemon *p1 = new_pokemon("name", type1, type2, hp, attack, defense, speed, S_attack, S_defense);
        set_level(50, p1);
        fwrite(p1, sizeof(Pokemon *), 1, file);

        Pokemon *p2;
        set_level(50, p2);
        fwrite(p2, sizeof(Pokemon *), 1, file);

        Pokemon *p3;
        set_level(50, p3);
        fwrite(p3, sizeof(Pokemon *), 1, file);

        Pokemon *p4;
        set_level(50, p4);
        fwrite(p4, sizeof(Pokemon *), 1, file);

        Pokemon *p5;
        set_level(50, p5);
        fwrite(p5, sizeof(Pokemon *), 1, file);

        Pokemon *p6;
        set_level(50, p6);
        fwrite(p6, sizeof(Pokemon *), 1, file);

        Pokemon *p7;
        set_level(50, p7);
        fwrite(p7, sizeof(Pokemon *), 1, file);

        Pokemon *p8;
        set_level(50, p8);
        fwrite(p8, sizeof(Pokemon *), 1, file);

        Pokemon *p9;
        set_level(50, p9);
        fwrite(p9, sizeof(Pokemon *), 1, file);

        Pokemon *p10;
        set_level(50, p10);
        fwrite(p10, sizeof(Pokemon *), 1, file);

        Pokemon *p11;
        set_level(50, p11);
        fwrite(p11, sizeof(Pokemon *), 1, file);

        Pokemon *p12;
        set_level(50, p12);
        fwrite(p12, sizeof(Pokemon *), 1, file);

        Pokemon *p13;
        set_level(50, p13);
        fwrite(p13, sizeof(Pokemon *), 1, file);

        Pokemon *p14;
        set_level(50, p14);
        fwrite(p14, sizeof(Pokemon *), 1, file);

        Pokemon *p15;
        set_level(50, p15);
        fwrite(p15, sizeof(Pokemon *), 1, file);

        Pokemon *p16;
        set_level(50, p16);
        fwrite(p16, sizeof(Pokemon *), 1, file);

        Pokemon *p17;
        set_level(50, p17);
        fwrite(p17, sizeof(Pokemon *), 1, file);

        Pokemon *p18;
        set_level(50, p18);
        fwrite(p18, sizeof(Pokemon *), 1, file);

        Pokemon *p19;
        set_level(50, p19);
        fwrite(p19, sizeof(Pokemon *), 1, file);

        Pokemon *p20;
        set_level(50, p20);
        fwrite(p20, sizeof(Pokemon *), 1, file);
    }
}