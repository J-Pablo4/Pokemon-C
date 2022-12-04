//
// Created by aarondev on 11/29/22.
//

#include "mapBorders.h"

void drawMapCollisionBoxes(int screenWidth, int screenHeight, RedPlayer *player)
{
    Rectangle leftWall = {0,0,30,screenHeight};
    DrawRectangleRec(leftWall, BLANK);
    playerCollision(player ,leftWall);
    Rectangle treesLeftChamp = {0,0,156,35};
    DrawRectangleRec(treesLeftChamp,BLANK);
    playerCollision(player,treesLeftChamp);
    Rectangle treesLeftEntry = {0, screenHeight-52, 185, 52};
    DrawRectangleRec(treesLeftEntry,BLANK);
    playerCollision(player,treesLeftEntry);
    Rectangle treesRightEntry = {screenWidth-140,screenHeight-52,140,52};
    DrawRectangleRec(treesRightEntry,BLANK);
    playerCollision(player, treesRightEntry);
    Rectangle rightWall = {screenWidth-30, 0, 30,screenHeight};
    DrawRectangleRec(rightWall, BLANK);
    playerCollision(player,rightWall);
    Rectangle treesRightChamp = {screenWidth-150,0,150,35};
    DrawRectangleRec(treesRightChamp,BLANK);
    playerCollision(player, treesRightChamp);
    Rectangle inferiorLineSquare = {0,170,130,4};
    DrawRectangleRec(inferiorLineSquare,BLANK);
    playerCollision(player, inferiorLineSquare);
    Rectangle superiorLineSquare = {0, 90, 250,4};
    DrawRectangleRec(superiorLineSquare,BLANK);
    playerCollision(player,superiorLineSquare);
    Rectangle treesSquare = {130,70,30,115};
    DrawRectangleRec(treesSquare,BLANK);
    playerCollision(player,treesSquare);
    Rectangle thirdLine1 = {0,330,65,4};
    DrawRectangleRec(thirdLine1,BLANK);
    playerCollision(player, thirdLine1);
    Rectangle thirdLine2 = {85,330,55,4};
    DrawRectangleRec(thirdLine2,BLANK);
    playerCollision(player,thirdLine2);
    Rectangle thirdLine3 = {175,330,600,4};
    DrawRectangleRec(thirdLine3,BLANK);
    playerCollision(player,thirdLine3);
    Rectangle fourthLine = {0,250,240,4};
    DrawRectangleRec(fourthLine,BLANK);
    playerCollision(player,fourthLine);
    Rectangle treesFourthWall = {0,224,65,40};
    DrawRectangleRec(treesFourthWall,BLANK);
    playerCollision(player,treesFourthWall);
    Rectangle treesFourthMid = {164,224,90,40};
    DrawRectangleRec(treesFourthMid,BLANK);
    playerCollision(player, treesFourthMid);
    Rectangle treesSecondLine = {0,385,190,40};
    DrawRectangleRec(treesSecondLine,BLANK);
    playerCollision(player,treesSecondLine);
    Rectangle secondLine = {screenWidth-80,425,80,4};
    DrawRectangleRec(secondLine,BLANK);
    playerCollision(player,secondLine);
    Rectangle  firstLineRight = {screenWidth-220,505,200,5};
    DrawRectangleRec(firstLineRight,BLANK);
    playerCollision(player, firstLineRight);
    Rectangle firstLineLeft = {0,505,90,5};
    DrawRectangleRec(firstLineLeft,BLANK);
    playerCollision(player, firstLineLeft);
}


void drawNPCTXTR(Texture2D npc1, Texture2D npc2, Texture2D npc3, Rectangle area)
{
    DrawTexture(npc1,125,300,BLANK);
    DrawTexture(npc3, 174, 12,BLANK);
    DrawTexture(npc2, 80, 474,BLANK);
}

void playerCollision(RedPlayer *player, Rectangle collisionBox)
{

   float playerRightEdge = getMask(player).width + getPlayerPos(player).x;
    float playerLeftEdge = getPlayerPos(player).x;
    float playerTopEdge = getPlayerPos(player).y + getMask(player).height;
    float playerBottomEdge = getPlayerPos(player).y;
    float boxRightEdge = collisionBox.x +collisionBox.width;
    float boxLeftEdge = collisionBox.x;
    float boxTopEdge = collisionBox.y+collisionBox.height;
    float boxBottomEdge = collisionBox.y;

    if(playerRightEdge >= boxLeftEdge &&
       playerLeftEdge <= boxRightEdge &&
       playerTopEdge >= boxBottomEdge &&
       playerBottomEdge <= boxTopEdge)
    {

        if(playerTopEdge >= boxBottomEdge){
            setPlayerPos(player,getPlayerPos(player).x, getPlayerPos(player).y - getMask(player).height);
        }
        if(playerTopEdge >= boxTopEdge){
            setPlayerPos(player,getPlayerPos(player).x, getMask(player).y + collisionBox.y);
        }
        /*if(playerLeftEdge >= boxLeftEdge && !(playerTopEdge >= boxTopEdge)){
            DrawText("collisio333", 184, 300, 16, BLACK);
            setPlayerPos(player,getPlayerPos(player).x - getMask(player).width, getPlayerPos(player).y);
        }*/
    }
}

