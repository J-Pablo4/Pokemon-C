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
        // DrawTexture(route1Txtr, 0, 0,WHITE);
        // DrawTexture(Gym, 0,0,WHITE);
        DrawTexture(route1Txtr, 0, 0, WHITE);
        DrawTexture(test,get_x(red),get_y(red), WHITE);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------




    return 0;

}