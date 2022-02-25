/**
 * @file colisiones.cc
 * @author Héctor Ochando
 * @brief Funciones de colisiones del juego.
 */

bool CollisionEnemyWihtShot(float x, float y, float w, float h)
{
    EnemNode *aux_enemy;
    bool collision;
    for (int i = 0; i < ListLength(g_enemy_list); ++i)
    {
        aux_enemy = IndexList(g_enemy_list, i);
        collision = CheckCollision(aux_enemy->enem.pos.x, aux_enemy->enem.pos.y,
                                   esat::SpriteWidth(*(g_enemy_sprite_list + aux_enemy->enem.sprite)),
                                   esat::SpriteHeight(*(g_enemy_sprite_list + aux_enemy->enem.sprite)),
                                   x, y, w, h);
        if (collision)
        {
            aux_enemy->enem.sprite = 0;
            aux_enemy->enem.explode = true;
            return true;
        }
    }
    return false;
}

bool CollisionEnemyWihtPlayer(float x, float y, float w, float h)
{
    EnemNode *aux_enemy;
    bool collision;
    for (int i = 0; i < ListLength(g_enemy_list); ++i)
    {
        aux_enemy = IndexList(g_enemy_list, i);
        collision = CheckCollision(aux_enemy->enem.pos.x, aux_enemy->enem.pos.y,
                                   esat::SpriteWidth(*(g_enemy_sprite_list + aux_enemy->enem.sprite)),
                                   esat::SpriteHeight(*(g_enemy_sprite_list + aux_enemy->enem.sprite)),
                                   x, y, w, h);
        if (collision)
        {
            return true;
        }
    }
    return false;
}

void CalculateCollision()
{
    /**
     * Example of collision wiht a shot,
     * this shot now is the mouse but it
     * can be replaced by the real shot.
     *
     * In this example the width and height
     * is 1 because the mouse is a point but
     * if the shot is a square or similar you
     * must put the width and height of the
     * square or rectangle.
     *
     */
    // if(esat::MouseButtonDown(0)){
    //     CollisionEnemyWihtShot(esat::MousePositionX(), esat::MousePositionY(), 1, 1);
    // }
}