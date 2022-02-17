/**
 * @file enemy.cc
 * @author Héctor Ochando
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



// struct Vec2{
//     float x, y;
// };

// struct Vec3{
//     float x, y, z;
// };

// struct Enemy{
//     Vec2 pos;
//     Vec2 dir;
//     Vec3 color;
//     float speed;
//     bool alive;
//     bool explode;
//     int explode_counter;
//     int sprite;
//     int animation_counter;
// };

esat::SpriteHandle* g_enemy_sprite_list = nullptr;
Enemy* g_enemy_list = nullptr;
esat::SpriteHandle spritesheet;
double g_last_spawn_time, g_current_spawn_time;
double g_enemy_spawn_time = 1.0;
int g_enemy_in_window;

void ConstuctEnemy(Enemy* enemy){
    static int enemy_count;
    if(enemy_count < g_enemy_in_window){
        g_enemy_list->pos.x = rand() % 768;
        g_enemy_list->pos.y = rand() % 576;
    }
}

void SpawnEnemy(){
    g_current_spawn_time = esat::Time();
    if((g_current_spawn_time - g_last_spawn_time) >= 1000.0 * g_enemy_spawn_time){
        g_last_spawn_time = esat::Time();
        ConstuctEnemy(g_enemy_list);
    }
}

void EnemyStart(){
    int sprite_count = 0;
    g_last_spawn_time = esat::Time();
    spritesheet = esat::SpriteFromFile("C:\\Desarrollo\\PVG\\Jetpac\\assets\\spritesheet.png");
    g_enemy_list = (Enemy*) malloc(sizeof(Enemy));
    g_enemy_sprite_list = (esat::SpriteHandle*) malloc(sizeof(esat::SpriteHandle) * 13);
    g_enemy_list->sprite = 0;
    for(int i = 3; i <= 13; ++i){
        *(g_enemy_sprite_list + sprite_count) = esat::SubSprite(spritesheet, 48 * i, 48, 48, 48);
        ++sprite_count;
    }
    *(g_enemy_sprite_list + sprite_count) = esat::SubSprite(spritesheet, 0, 48 * 2, 48, 48);
    ++sprite_count;
    *(g_enemy_sprite_list + sprite_count) = esat::SubSprite(spritesheet, 48, 48 * 2, 48, 48);
}

void EnemyUpdate(){
    if(esat::IsKeyDown('P')){
        g_enemy_list->sprite++;
        g_enemy_list->sprite %= 13;
    }
    SpawnEnemy();
}

void EnemyDraw(){
    esat::DrawSprite(*(g_enemy_sprite_list + g_enemy_list->sprite), g_enemy_list->pos.x, 
                                                                   g_enemy_list->pos.y);
    
}

void EnemyEnd(){
    free(g_enemy_list);
    free(g_enemy_sprite_list);
}