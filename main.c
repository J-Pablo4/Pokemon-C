#include "Pokemon.h"
#include "raylib.h"
#include "Type.h"
#include "Player.h"
#include "mapBorders.h"

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
<<<<<<< HEAD
        DrawTexture(redTxtr, getPlayerPos(red).x, getPlayerPos(red).y, WHITE);
=======
        //DrawTexture(redTxtr,getPlayerXPos(red),getPlayerYPos(red), WHITE);
        float playerXPos = getPlayerXPos(red);
        float playerYPos = getPlayerYPos(red);
>>>>>>> 434bedafe37e572b3b2586aea0eb53af8f063394
        DrawRectangle(screenWidth/2,15,8,8,BLUE);
        drawMapCollisionBoxes(screenWidth,screenHeight);
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