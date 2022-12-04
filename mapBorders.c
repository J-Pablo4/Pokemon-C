//
// Created by aarondev on 11/29/22.
//

#include "mapBorders.h"

void drawMapCollisionBoxes(int screenWidth, int screenHeight, Rectangle area)
{
    Rectangle leftWall = {0,0,30,screenHeight};
    DrawRectangleRec(leftWall, WHITE);
    playerCollision(area,leftWall);
    Rectangle treesLeftChamp = {0,0,156,35};
    DrawRectangleRec(treesLeftChamp,WHITE);
    Rectangle treesLeftEntry = {0, screenHeight-52, 185, 52};
    DrawRectangleRec(treesLeftEntry,WHITE);
    Rectangle treesRightEntry = {screenWidth-140,screenHeight-52,140,52};
    DrawRectangleRec(treesRightEntry,WHITE);
    Rectangle rightWall = {screenWidth-30, 0, 30,screenHeight};
    DrawRectangleRec(rightWall, WHITE);
    Rectangle treesRightChamp = {screenWidth-150,0,150,35};
    DrawRectangleRec(treesRightChamp,WHITE);
    Rectangle inferiorLineSquare = {0,170,130,4};
    DrawRectangleRec(inferiorLineSquare,WHITE);
    Rectangle superiorLineSquare = {0, 90, 250,4};
    DrawRectangleRec(superiorLineSquare,WHITE);
    Rectangle treesSquare = {130,70,30,115};
    DrawRectangleRec(treesSquare,WHITE);
    Rectangle thirdLine1 = {0,330,65,4};
    DrawRectangleRec(thirdLine1,WHITE);
    Rectangle thirdLine2 = {85,330,55,4};
    DrawRectangleRec(thirdLine2,WHITE);
    Rectangle thirdLine3 = {175,330,600,4};
    DrawRectangleRec(thirdLine3,WHITE);
    Rectangle fourthLine = {0,250,240,4};
    DrawRectangleRec(fourthLine,WHITE);
    Rectangle treesFourthWall = {0,224,65,40};
    DrawRectangleRec(treesFourthWall,WHITE);
    Rectangle treesFourthMid = {164,224,90,40};
    DrawRectangleRec(treesFourthMid,WHITE);
    Rectangle treesSecondLine = {0,385,190,40};
    DrawRectangleRec(treesSecondLine,WHITE);
    Rectangle secondLine = {screenWidth-80,425,80,4};
    DrawRectangleRec(secondLine,WHITE);
    Rectangle  firstLineRight = {screenWidth-220,505,200,5};
    DrawRectangleRec(firstLineRight,WHITE);
    Rectangle firstLineLeft = {0,505,90,5};
    DrawRectangleRec(firstLineLeft,WHITE);
}

void drawNPCTXTR(Texture2D npc1, Texture2D npc2, Texture2D npc3, Rectangle area)
{
    DrawTexture(npc1,125,300,WHITE);
    DrawTexture(npc3, 174, 12,WHITE);
    DrawTexture(npc2, 80, 474,WHITE);
}

void playerCollision(Rectangle area, Rectangle collisionBox)
{
    if(CheckCollisionRecs(area,collisionBox)){
        DrawText("collision",184,320,14,BLACK);
    }
    if(area.x < (collisionBox.width+collisionBox.x) && (area.x+area.width) > (collisionBox.x+collisionBox.width)){
        // Right border detection
        area.x = collisionBox.x+collisionBox.width;
    }
    else if((area.x+area.width) > collisionBox.x && area.x < collisionBox.x){
        // Left border detection
        area.x = collisionBox.x+collisionBox.width;
    }
}