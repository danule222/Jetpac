/**
 * @file enemy.cc
 * @author Héctor Ochando
 * @brief 
 * 
 * 
 */

esat::SpriteHandle* g_enemy_sprite_list = nullptr;
EnemNode* g_enemy_list = nullptr;
esat::SpriteHandle spritesheet;
double g_last_spawn_time, g_current_spawn_time;
double g_enemy_spawn_time = 1.0;
int g_enemy_in_window = 5;

void ConstuctEnemy(){
    Enemy aux_enemy;
    if(ListLength(g_enemy_list) < g_enemy_in_window){
        aux_enemy.sprite = 0;  
        aux_enemy.pos.x = rand() % 768;
        aux_enemy.pos.y = rand() % 576 - esat::SpriteHeight(*(g_enemy_sprite_list + aux_enemy.sprite));
        aux_enemy.color.r = rand() % 255;
        aux_enemy.color.g = rand() % 255;
        aux_enemy.color.b = rand() % 255;
        InsertarList(&g_enemy_list, aux_enemy);
    }
}

void SpawnEnemy(){
    g_current_spawn_time = esat::Time();
    if((g_current_spawn_time - g_last_spawn_time) >= 1000.0 * g_enemy_spawn_time){
        g_last_spawn_time = esat::Time();
        ConstuctEnemy();
    }
}

void EnemyStart(){
    int sprite_count = 0;
    g_last_spawn_time = esat::Time();
    printf("1");
    spritesheet = esat::SpriteFromFile("E:\\Desarrollo\\PVG\\Jetpac\\assets\\spritesheet.png");
    printf("2");
    g_enemy_sprite_list = (esat::SpriteHandle*) malloc(sizeof(esat::SpriteHandle) * 13);
    CrearList(&g_enemy_list);
    for(int i = 3; i <= 13; ++i){
        *(g_enemy_sprite_list + sprite_count) = esat::SubSprite(spritesheet, 48 * i, 48, 48, 48);
        ++sprite_count;
    }
    *(g_enemy_sprite_list + sprite_count) = esat::SubSprite(spritesheet, 0, 48 * 2, 48, 48);
    ++sprite_count;
    *(g_enemy_sprite_list + sprite_count) = esat::SubSprite(spritesheet, 48, 48 * 2, 48, 24);
}

void EnemyUpdate(){
    SpawnEnemy();
    if(esat::IsKeyDown('P')){
        // g_enemy_list->sprite++;
        // g_enemy_list->sprite %= 13;
    }
}

void EnemyDraw(){
    EnemNode* aux_enemy;
    for(int i = 0; i < ListLength(g_enemy_list); ++i){
        aux_enemy = IndexList(g_enemy_list, i);
        DrawColorSquare({aux_enemy->enem.pos.x, aux_enemy->enem.pos.y}, aux_enemy->enem.color, 
                            esat::SpriteWidth(*(g_enemy_sprite_list + aux_enemy->enem.sprite)), 
                            esat::SpriteHeight(*(g_enemy_sprite_list + aux_enemy->enem.sprite)));
        esat::DrawSprite(*(g_enemy_sprite_list + aux_enemy->enem.sprite), 
                                                aux_enemy->enem.pos.x, 
                                                aux_enemy->enem.pos.y);
    }
    
}

void EnemyEnd(){
    DelWholeList(&g_enemy_list);
    free(g_enemy_sprite_list);
}