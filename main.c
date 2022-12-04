#include "Pokemon.h"
#include "raylib.h"
#include "Type.h"
#include "Player.h"
#include "Attacks.h"
#include "mapBorders.h"
#include "fighting.h"

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
    NPC *leafNPC = initNPC(145,300, leafTxtr);
    NPC *blueNPC = initNPC(174,12,blueTxtr);
    NPC *lanceNPC = initNPC(80,474,lanceTxtr);
    Rectangle redArea = getPlayerArea(red, redTxtr);
    setPlayerTexture(redTxtr, red);
    Rectangle redMask = getMask(red);
    Vector2 playerPos = getPlayerPos(red);
    Vector2 npcVectorBlue = getNPCVector2(blueNPC);
    //Vector2 npcVectorLeaf = getNPCVector2(leafNPC);
    //Vector2 npcVectorLance = getNPCVector2(lanceNPC);
    Texture2D txtrBlue = getNPCTxtr(blueNPC);
    Texture2D txtrLeaf = getNPCTxtr(leafNPC);
    Texture2D txtrLance = getNPCTxtr(lanceNPC);

    SetTargetFPS(24);

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
        drawMapCollisionBoxes(screenWidth,screenHeight,redMask, getPlayerPos(red));
        EndDrawing();
    }

    CloseWindow();
    return 0;

}