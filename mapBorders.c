//
// Created by aarondev on 11/29/22.
//

#include "mapBorders.h"
void drawMapCollisionBoxes(int screenWidth, int screenHeight){
    DrawRectangle(0,0,30, screenHeight, CLITERAL(Color){255,255,255,128});   //Pared izq map
    DrawRectangle(0,0, 156, 35, WHITE);           //Arboles izq campeon
    DrawRectangle(0,screenHeight-52, 185,52,WHITE); //Arboles izq entrada
    DrawRectangle(screenWidth-140, screenHeight-52, 140, 52, WHITE); //Arboles der entrada
    DrawRectangle(screenWidth-30, 0, 30, screenHeight, WHITE); //Pared derecha
    DrawRectangle(screenWidth-150, 0, 150, 35, WHITE);
    DrawRectangle(0, 170, 130, 4, WHITE); //Linea inferior cuadrado
    DrawRectangle(0, 90, 250, 4, WHITE); //Linea Superior cuadrado
    DrawRectangle(130, 70, 30, 115, WHITE); //Arboles Cuadradoi
    DrawRectangle(0, 330, 65, 4, WHITE); //Linea 3era de abajo para arriba inicio
    DrawRectangle(85, 330, 55,4,WHITE); //Linea 3era de abajo 2da
    DrawRectangle(175, 330, 600,4, WHITE); //Linea 3era de abajo 3era
    DrawRectangle(0, 250, 240, 4, WHITE); //Linea 4ta de abajo para arriba
    DrawRectangle(0, 224, 65, 40, WHITE); //Arboles 4ta linea pegados a la pared
    DrawRectangle(164, 224, 90, 40, WHITE); //Arboles 4ta linea en medio
    DrawRectangle(0, 385, 190, 40,WHITE); //Arboles 2da linea
    DrawRectangle(screenWidth-80, 425, 80, 4, WHITE); //Linea 2da linea
    DrawRectangle(screenWidth-220, 505, 200, 5, WHITE); //1era linea pared derecha
    DrawRectangle(0, 505, 90, 4, WHITE); //1era linea pared izq
    DrawRectangle(screenWidth/2,15,12,12,RED);
    DrawRectangle(120, 315, 12, 12, BLUE);
    DrawRectangle(80, 490, 12, 12, GREEN);
}