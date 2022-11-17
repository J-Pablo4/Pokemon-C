//
// Created by aarondev on 11/16/22.
//

#include "Player.h"

typedef struct redPlayer{
    Vector2 position;
    float speed;
    int PlayerDirection;
    bool right;
    bool left;
    bool up;
    bool down;
}RedPlayer;

void UpdatePlayer(float delta, RedPlayer player){

    if(IsKeyDown(KEY_RIGHT)){
        player.position.x += PLAYER_HOR_SPD*delta;
        player.right = true;
        player.left = false;
        player.down = false;
        player.up = false;
        player.PlayerDirection=3;
    }
    if(IsKeyDown(KEY_LEFT)){
        player.position.x -= PLAYER_HOR_SPD*delta;
        player.left = true;
        player.right = false;
        player.up = false;
        player.down = false;
        player.PlayerDirection=1;
    }
    if(IsKeyDown(KEY_UP)){
        player.position.y += PLAYER_HOR_SPD*delta;
        player.up = true;
        player.down = false;
        player.left = false;
        player.right = false;
        player.PlayerDirection=1;
    }
    if(IsKeyDown(KEY_DOWN)){
        player.position.y -= PLAYER_HOR_SPD*delta;
        player.up = false;
        player.down = true;
        player.left = false;
        player.right = false;
        player.PlayerDirection=1;
    }

}
