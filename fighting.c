//
// Created by aarondev on 12/3/22.
//

#include "fighting.h"


Rectangle getNpcArea(Vector2 npcVector, Texture2D npcTxtr)
{
    Rectangle npcArea = {npcVector.x,npcVector.y,npcTxtr.width,npcTxtr.height};
    return npcArea;
}