#include "Pokemon.h"
#include "raylib.h"
#include "Player.h"
#include "mapBorders.h"

int main() {
    init_pokemons();

    const int screenWidth = 368;
    const int screenHeight = 640;

    InitWindow(screenWidth, screenHeight, "Pokemon Memoria Dinamica");

    Texture2D redTxtr = LoadTexture("Assets/redPlayerWalking.png");
    Texture2D leafTxtr = LoadTexture("Assets/leafCrop.png");
    Texture2D blueTxtr = LoadTexture("Assets/blueRivalCrop.png");
    Texture2D route1Txtr = LoadTexture("Assets/route1.png");
    Texture2D lanceTxtr = LoadTexture("Assets/lanceCrop.png");

    RedPlayer *red = InitPlayer(screenWidth, screenHeight);
    Rectangle redArea = getPlayerArea(red, redTxtr);
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
        drawMapCollisionBoxes(screenWidth,screenHeight,redArea);
        drawNPCTXTR(blueTxtr,leafTxtr,lanceTxtr, redArea);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}