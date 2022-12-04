#include "Pokemon.h"
#include "raylib.h"
#include "Type.h"
#include "Player.h"
#include "Attacks.h"
#include "mapBorders.h"
#include <stdio.h>

int main() {
    init_pokemons();
//    get_weakness(water, water);

    const int screenWidth = 368;
    const int screenHeight = 640;

    InitWindow(screenWidth, screenHeight, "Pokemon Memoria Dinamica");

    Texture2D redTxtr = LoadTexture("Assets/redPlayerWalking.png");
    Texture2D test = LoadTexture("Assets/redPlayerTEST.png");
    Texture2D blueTxtr = LoadTexture("Assets/blueRival.png");
    Texture2D route1Txtr = LoadTexture("Assets/route1.png");

    RedPlayer *red = InitPlayer(screenWidth, screenHeight);
    setPlayerTexture(redTxtr, red);

    SetTargetFPS(24);

    obtain_pokemons_from_file(red);
    set_player_potions(red);

    while (!WindowShouldClose())
    {
        float deltaTime = GetFrameTime();
        UpdatePlayer(deltaTime, red);
        BeginDrawing();
        ClearBackground(BLACK);
        DrawTexture(route1Txtr, 0, 0, WHITE);
        RenderPlayer(red, 3);
        float playerXPos = getPlayerPos(red).x;
        float playerYPos = getPlayerPos(red).y;
        DrawRectangle(screenWidth/2,15,8,8,BLUE);
        drawMapCollisionBoxes(screenWidth,screenHeight);
        EndDrawing();
    }

    CloseWindow();
    return 0;

}