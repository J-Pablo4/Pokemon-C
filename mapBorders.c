//
// Created by aarondev on 11/29/22.
//

#include "mapBorders.h"

void drawMapCollisionBoxes(int screenWidth, int screenHeight, Rectangle mask, Vector2 positionPlayer)
{
    Rectangle leftWall = {0,0,30,screenHeight};
    DrawRectangleRec(leftWall, WHITE);
    playerCollision(mask,positionPlayer,leftWall);
    Rectangle treesLeftChamp = {0,0,156,35};
    DrawRectangleRec(treesLeftChamp,WHITE);
    playerCollision(mask,positionPlayer,treesLeftChamp);
    Rectangle treesLeftEntry = {0, screenHeight-52, 185, 52};
    DrawRectangleRec(treesLeftEntry,WHITE);
    playerCollision(mask, positionPlayer,treesLeftEntry);
    Rectangle treesRightEntry = {screenWidth-140,screenHeight-52,140,52};
    DrawRectangleRec(treesRightEntry,WHITE);
    playerCollision(mask, positionPlayer, treesRightEntry);
    Rectangle rightWall = {screenWidth-30, 0, 30,screenHeight};
    DrawRectangleRec(rightWall, WHITE);
    playerCollision(mask,positionPlayer,rightWall);
    Rectangle treesRightChamp = {screenWidth-150,0,150,35};
    DrawRectangleRec(treesRightChamp,WHITE);
    playerCollision(mask, positionPlayer, treesRightChamp);
    Rectangle inferiorLineSquare = {0,170,130,4};
    DrawRectangleRec(inferiorLineSquare,WHITE);
    playerCollision(mask, positionPlayer, inferiorLineSquare);
    Rectangle superiorLineSquare = {0, 90, 250,4};
    DrawRectangleRec(superiorLineSquare,WHITE);
    playerCollision(mask,positionPlayer,superiorLineSquare);
    Rectangle treesSquare = {130,70,30,115};
    DrawRectangleRec(treesSquare,WHITE);
    playerCollision(mask,positionPlayer,treesSquare);
    Rectangle thirdLine1 = {0,330,65,4};
    DrawRectangleRec(thirdLine1,WHITE);
    playerCollision(mask, positionPlayer, thirdLine1);
    Rectangle thirdLine2 = {85,330,55,4};
    DrawRectangleRec(thirdLine2,WHITE);
    playerCollision(mask,positionPlayer,thirdLine2);
    Rectangle thirdLine3 = {175,330,600,4};
    DrawRectangleRec(thirdLine3,WHITE);
    playerCollision(mask,positionPlayer,thirdLine3);
    Rectangle fourthLine = {0,250,240,4};
    DrawRectangleRec(fourthLine,WHITE);
    playerCollision(mask,positionPlayer,fourthLine);
    Rectangle treesFourthWall = {0,224,65,40};
    DrawRectangleRec(treesFourthWall,WHITE);
    playerCollision(mask, positionPlayer,treesFourthWall);
    Rectangle treesFourthMid = {164,224,90,40};
    DrawRectangleRec(treesFourthMid,WHITE);
    playerCollision(mask, positionPlayer, treesFourthMid);
    Rectangle treesSecondLine = {0,385,190,40};
    DrawRectangleRec(treesSecondLine,WHITE);
    playerCollision(mask,positionPlayer,treesSecondLine);
    Rectangle secondLine = {screenWidth-80,425,80,4};
    DrawRectangleRec(secondLine,WHITE);
    playerCollision(mask, positionPlayer,secondLine);
    Rectangle  firstLineRight = {screenWidth-220,505,200,5};
    DrawRectangleRec(firstLineRight,WHITE);
    playerCollision(mask, positionPlayer, firstLineRight);
    Rectangle firstLineLeft = {0,505,90,5};
    DrawRectangleRec(firstLineLeft,WHITE);
    playerCollision(mask,positionPlayer, firstLineLeft);
}

void drawNPCTXTR(Texture2D npc1, Texture2D npc2, Texture2D npc3, Rectangle area)
{
    DrawTexture(npc1,125,300,WHITE);
    DrawTexture(npc3, 174, 12,WHITE);
    DrawTexture(npc2, 80, 474,WHITE);
}

void playerCollision(Rectangle mask, Vector2 position, Rectangle collisionBox)
{
    // Declaration of variables for more human understanding
    float playerRightEdge = mask.width+position.x;//area.x+area.width;
    float playerLeftEdge = position.x;//area.x;
    float playerTopEdge = position.y+mask.height;//area.y+area.height;
    float playerBottomEdge = position.y;//area.y;
    float boxRightEdge = collisionBox.x+collisionBox.width;
    float boxLeftEdge = collisionBox.x;
    float boxTopEdge = collisionBox.y+collisionBox.height;
    float boxBottomEdge = collisionBox.y;

    if(playerRightEdge >= boxLeftEdge &&
       playerLeftEdge <= boxRightEdge &&
       playerTopEdge >= boxBottomEdge &&
       playerBottomEdge <= boxTopEdge) //Detects if there is a collision
    {
        DrawText("collision", 184, 320, 16, BLACK);
        if(playerBottomEdge < boxBottomEdge) //If the collision is vertically
        {
            position.y = boxBottomEdge - playerBottomEdge;
        }
        if(playerLeftEdge < boxLeftEdge) //If the collision horizontally
        {
            position.x = boxLeftEdge - playerLeftEdge;
        }
    }
}