/**
 * @file colisiones.cc
 * @author your name (you@domain.com)
 * @brief 
 * 
 * 
 */

bool CollisionEnemyWihtShot(float x, float y, float w, float h){
    EnemNode *aux_enemy;
    bool collision;
    for (int i = 0; i < ListLength(g_enemy_list); ++i)
    {
        aux_enemy = IndexList(g_enemy_list, i);
        collision = CheckCollision(enemy->pos.x, enemy->pos.y,
                           esat::SpriteWidth(*(g_enemy_sprite_list + enemy->sprite)),
                           esat::SpriteHeight(*(g_enemy_sprite_list + enemy->sprite)),
                           x, y, w, h);
        if(collision){
            return true;
        }
    }
    return false;
}

bool CollisionEnemyWihtPlayer(float x, float y, float w, float h){
    EnemNode *aux_enemy;
    bool collision;
    for (int i = 0; i < ListLength(g_enemy_list); ++i)
    {
        aux_enemy = IndexList(g_enemy_list, i);
        collision = CheckCollision(enemy->pos.x, enemy->pos.y,
                           esat::SpriteWidth(*(g_enemy_sprite_list + enemy->sprite)),
                           esat::SpriteHeight(*(g_enemy_sprite_list + enemy->sprite)),
                           x, y, w, h);
        if(collision){
            return true;
        }
    }
    return false;
}