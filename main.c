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
    // Texture2D Gym = LoadTexture("Assets/1erGymCrop.png");
    // Texture2D  viriadianTownTxtr = LoadTexture("Assets/viridianTown.png");
    RedPlayer red = {{(screenWidth/2), (screenHeight/2)},0,0,0,0,1,0};


    //SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {

        float deltaTime = GetFrameTime();
//        UpdatePlayer(deltaTime, red);

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(BLACK);
        // DrawTexture(route1Txtr, 0, 0,WHITE);
        // DrawTexture(Gym, 0,0,WHITE);
        DrawTexture(route1Txtr, 0, 0, WHITE);
        DrawTexture(test,(screenWidth/2),(screenHeight/2), WHITE);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------




    return 0;

}