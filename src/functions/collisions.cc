/**
 * @file colisiones.cc
 * @author Héctor Ochando
 * @brief Funciones de colisiones del juego.
 */

double g_player_dead_time;
bool g_dead_player = false;

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
    /*
    if(CollisionEnemyWihtPlayer(g_player.pos.x, g_player.pos.y, 48, 72)) {
        g_player.alive = false;
    }
    */
    /*
    for(int i = 0; i < 5; i++)
    {
        if(CollisionEnemyWihtShot((shots + i)->pos.x, (shots + i)->pos.y, (shots + i)->pos.x + 24, (shots + i)->pos.y + 3))
        {
            (shots + i)->alive = false;
            (shots + i)->pos.x = 0;
            (shots + i)->pos.y = 0;
        }
    }
    */
    CollisionEnemyWihtShot(10, 10, 24, 3);
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

    for (int i = 0; i < 5; i++)
    {
        if (CollisionEnemyWihtShot((shots + i)->pos.x, (shots + i)->pos.y, 24, 3))
        {
            (shots + i)->alive = false;
            (shots + i)->pos.x = 0;
            (shots + i)->pos.y = 0;
        }
    }

    if (CollisionEnemyWihtPlayer(g_player.pos.x, g_player.pos.y, 50, 70) && g_player.alive)
    {
        Jugador aux;
        g_dead_player = true;
        g_player_dead_time = esat::Time();

        g_player.alive = false;
        g_player.lifes--;

        // Cambiar jugador
        if (g_game_properties.players == 2)
        {
            g_p1_playing = !g_p1_playing;

            aux.nivel = g_player.nivel;
            aux.score = g_player.score;
            aux.lifes = g_player.lifes;

            g_player.nivel = g_player_aux.nivel;
            g_player.score = g_player_aux.score;
            g_player.lifes = g_player_aux.lifes;

            g_player_aux.nivel = aux.nivel;
            g_player_aux.score = aux.score;
            g_player_aux.lifes = aux.lifes;
        }

        if (g_player.lifes == 0)
        {
            g_game_properties.state = 1;
            g_player.lifes = 3;
            g_player.score = 0;

            g_player_aux.lifes = 3;
            g_player_aux.score = 0;
            g_player_aux.pos.x = kWidth / 2;
            g_player_aux.pos.y = kHeight - 100;

            g_player.alive = true;
            g_player_aux.alive = true;
        }

        g_player.pos.x = kWidth / 2;
        g_player.pos.y = kHeight - 100;
    }

    if (g_dead_player)
    {
        printf("%lf\n", g_player_dead_time);
        if (esat::Time() - g_player_dead_time >= 1000 * 3)
        {
            printf("B");
            g_player.alive = true;
            g_dead_player = false;
        }
    }
}