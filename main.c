#include "Pokemon.h"
#include "raylib.h"
#include "Type.h"
#include "Player.h"

int main() {

    get_weakness(water, water);

    const int screenWidth = 368;
    const int screenHeight = 640;

    InitWindow(screenWidth, screenHeight, "Pokemon Memoria Dinamica");

    Texture2D redTxtr = LoadTexture("Assets/redPlayerWalking.png");
    Texture2D test = LoadTexture("Assets/redPlayerTEST.png");
    Texture2D blueTxtr = LoadTexture("Assets/blueRival.png");
    Texture2D route1Txtr = LoadTexture("Assets/route1.png");
    Texture2D lanceTxtr = LoadTexture("Assets/eliteFour");

    RedPlayer *red = InitPlayer(screenWidth, screenHeight);

    SetTargetFPS(24);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {

        float deltaTime = GetFrameTime();
        UpdatePlayer(deltaTime, red);
        updatePlayerTexture(redTxtr, red);

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(BLACK);
        DrawTexture(route1Txtr, 0, 0, WHITE);
        DrawTexture(redTxtr,getPlayerXPos(red),getPlayerYPos(red), WHITE);
        float playerXPos = getPlayerXPos(red);
        float playerYPos = getPlayerYPos(red);
        DrawRectangle(screenWidth/2,15,8,8,BLUE);
        DrawRectangle(0,0,30, screenHeight, WHITE);   //Pared izq map
        DrawRectangle(0,0, 156, 35, WHITE);           //Arboles izq campeon
        DrawRectangle(0,screenHeight-52, 185,52,WHITE); //Arboles izq entrada
        DrawRectangle(screenWidth-136, screenHeight-52, 50, 52, RED); //Arboles der entrada

        // DrawText(playerXPos, 0, 0, 8, BLACK);
        // DrawText(playerYPos, 0, 15, 8, BLACK);
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------




    return 0;

}