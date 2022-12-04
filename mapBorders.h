//
// Created by aarondev on 11/29/22.
//

#ifndef POKEMON_MAPBORDERS_H
#define POKEMON_MAPBORDERS_H
#include "raylib.h"
#include "Player.h"



void drawMapCollisionBoxes(int screenWidth, int screenHeight, RedPlayer *player);
void playerCollision(RedPlayer *player, Rectangle collisionBox);
void drawNPCTXTR(Texture2D npc1, Texture2D npc2, Texture2D npc3, Rectangle area);
void playerCollision2(RedPlayer *player);
void drawMapCollisionBoxes2(int screenWidth, int screenHeight, RedPlayer *player);


#endif //POKEMON_MAPBORDERS_H
