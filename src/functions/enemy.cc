/**
 * @file enemy.cc
 * @author Héctor Ochando Casañ
 * @brief 
 * 
 * 
 */

#include <esat/window.h>
#include <esat/draw.h>
#include <esat/input.h>
#include <esat/sprite.h>
#include <esat/time.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>



struct Vec2{
    float x, y;
};

struct Vec3{
    float x, y, z;
};

struct Enemy{
    Vec2 pos;
    Vec2 dir;
    Vec3 color;
    float speed;
    bool alive;
    bool explode;
    int explode_counter;
    int sprite;
    int animation_counter;
};

esat::SpriteHandle* g_enemy_sprite_list = nullptr;
Enemy* g_enemy_list = nullptr;
esat::SpriteHandle spritesheet;

void EnemyStart(){
    spritesheet = esat::SpriteFromFile("C:\\Desarrollo\\PVG\\Jetpac\\assets\\spritesheet.png");
    g_enemy_list = (Enemy*) malloc(sizeof(Enemy));
    g_enemy_sprite_list = (esat::SpriteHandle*) malloc(sizeof(esat::SpriteHandle));
    g_enemy_list->sprite = 0;
    *g_enemy_sprite_list = esat::SubSprite(spritesheet, 48 * 3, 48, 48, 48);
}

void EnemyUpdate(){
    if(esat::IsKeyDown('O')){
        g_enemy_list->pos.x = 0.0f;
        g_enemy_list->pos.y = rand() % 576;
    }
}

void EnemyDraw(){
    esat::DrawSprite(*(g_enemy_sprite_list + g_enemy_list->sprite), g_enemy_list->pos.x, 
                                                                   g_enemy_list->pos.y);
    
}

void EnemyEnd(){
    free(g_enemy_list);
}