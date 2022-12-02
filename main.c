#include "Pokemon.h"
#include "raylib.h"
#include "Type.h"
#include "Player.h"
#include "Attacks.h"
#include "mapBorders.h"

int main() {

//    get_weakness(water, water);

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

        Rectangle mask;
        mask.x = getPlayerPos(red).x;
        mask.y = getPlayerPos(red).y * (redTxtr.height/4);
        mask.width = redTxtr.width/3;
        mask.height = redTxtr.height/3.6;
        //DrawTexture(redTxtr, getPlayerPos(red).x, getPlayerPos(red).y, WHITE);
        DrawTextureRec(redTxtr,mask, getPlayerPos(red), WHITE);
        float playerXPos = getPlayerPos(red).x;
        float playerYPos = getPlayerPos(red).y;
        drawMapCollisionBoxes(screenWidth,screenHeight, redArea);
        drawNPCTXTR(blueTxtr, leafTxtr,lanceTxtr, redArea);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------




    return 0;

}