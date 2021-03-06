/**
 * @file enemy.cc
 * @author Héctor Ochando
 * @brief Funciones necesarias para el
 * correcto funcionamiento de los enemigos.
 *
 */

esat::SpriteHandle *g_enemy_sprite_list = nullptr, *g_explosion_sprite_list = nullptr;
EnemNode *g_enemy_list = nullptr;
double g_last_spawn_time, g_current_spawn_time;
double g_enemy_spawn_time = 0.5;
int g_enemy_in_window = 6;

static int SelectEnemyType()
{
    int enemy_type = g_player.nivel % 8;
    switch (enemy_type)
    {
    case 0:
        return 0;
        break;
    case 1:
        return 2;
        break;
    case 2:
        return 4;
        break;
    case 6:
        if ((rand() % 2) == 0)
        {
            return 6;
        }
        else
        {
            return 7;
        }
        break;
    case 3:
        if ((rand() % 2) == 0)
        {
            return 8;
        }
        else
        {
            return 9;
        }
        break;
    case 7:
        return 10;
        break;
    case 5:
        return 11;
        break;
    case 4:
        return 12;
        break;
    }
    return 0;
}

static void ConstuctEnemy()
{
    Enemy aux_enemy;
    if (ListLength(g_enemy_list) < g_enemy_in_window)
    {
        int aux_i = rand() % 14;
        aux_enemy.sprite = SelectEnemyType();
        aux_enemy.speed = 1 + rand() % 5;
        aux_enemy.animation_counter = 0;
        aux_enemy.spawn = true;
        aux_enemy.explode = false;
        aux_enemy.explode_counter = 0;
        switch (aux_enemy.sprite)
        {
        case 0:
            aux_enemy.pos.x = 0.0f;
            aux_enemy.pos.y = rand() % (576 - esat::SpriteHeight(*(g_enemy_sprite_list + aux_enemy.sprite)));
            aux_enemy.dir.x = 5 + rand() % 15;
            aux_enemy.dir.y = rand() % 5;
            aux_enemy.dir = Vec2Normalize(&aux_enemy.dir);
            break;
        case 1:
            aux_enemy.pos.x = 0.0f;
            aux_enemy.pos.y = rand() % (576 - esat::SpriteHeight(*(g_enemy_sprite_list + aux_enemy.sprite)));
            aux_enemy.dir.x = 5 + rand() % 15;
            aux_enemy.dir.y = rand() % 5;
            aux_enemy.dir = Vec2Normalize(&aux_enemy.dir);
            break;
        case 2:
            aux_enemy.pos.x = 0.0f;
            aux_enemy.pos.y = rand() % (576 - esat::SpriteHeight(*(g_enemy_sprite_list + aux_enemy.sprite)));
            aux_enemy.dir.x = 1 + rand() % 5;
            aux_enemy.dir.y = rand() % 10;
            aux_enemy.dir = Vec2Normalize(&aux_enemy.dir);
            break;
        case 3:
            aux_enemy.pos.x = 0.0f;
            aux_enemy.pos.y = rand() % (576 - esat::SpriteHeight(*(g_enemy_sprite_list + aux_enemy.sprite)));
            aux_enemy.dir.x = 1 + rand() % 5;
            aux_enemy.dir.y = rand() % 10;
            aux_enemy.dir = Vec2Normalize(&aux_enemy.dir);
            break;
        case 4:
            aux_enemy.pos.x = 0.0f;
            aux_enemy.pos.y = rand() % (576 - esat::SpriteHeight(*(g_enemy_sprite_list + aux_enemy.sprite)));
            aux_enemy.dir.x = 1;
            aux_enemy.dir.y = 0;
            aux_enemy.speed = 3;
            aux_enemy.dir = Vec2Normalize(&aux_enemy.dir);
            break;
        case 5:
            aux_enemy.pos.x = 0.0f;
            aux_enemy.pos.y = rand() % (576 - esat::SpriteHeight(*(g_enemy_sprite_list + aux_enemy.sprite)));
            aux_enemy.dir.x = 1;
            aux_enemy.dir.y = 0;
            aux_enemy.speed = 3;
            aux_enemy.dir = Vec2Normalize(&aux_enemy.dir);
            break;
        case 6:
            aux_enemy.pos.x = 0.0f;
            aux_enemy.pos.y = rand() % (576 - esat::SpriteHeight(*(g_enemy_sprite_list + aux_enemy.sprite)));
            aux_enemy.dir.x = 5 + rand() % 15;
            aux_enemy.dir.y = rand() % 5;
            aux_enemy.speed = 3;
            aux_enemy.dir = Vec2Normalize(&aux_enemy.dir);
            break;
        case 7:
            aux_enemy.pos.x = (768.0f - 48.0f);
            aux_enemy.pos.y = rand() % (576 - esat::SpriteHeight(*(g_enemy_sprite_list + aux_enemy.sprite)));
            aux_enemy.dir.x = (5 + rand() % 15) * -1;
            aux_enemy.dir.y = rand() % 5;
            aux_enemy.speed = 3;
            aux_enemy.dir = Vec2Normalize(&aux_enemy.dir);
            break;
        case 8:
            aux_enemy.pos.x = 1.0f;
            aux_enemy.pos.y = rand() % (576 - esat::SpriteHeight(*(g_enemy_sprite_list + aux_enemy.sprite)) - 50);
            aux_enemy.dir.x = 1;
            aux_enemy.dir.y = 0;
            aux_enemy.speed = 3;
            aux_enemy.dir = Vec2Normalize(&aux_enemy.dir);
            break;
        case 9:
            aux_enemy.pos.x = 1.0f;
            aux_enemy.pos.y = rand() % (576 - esat::SpriteHeight(*(g_enemy_sprite_list + aux_enemy.sprite)) - 50);
            aux_enemy.dir.x = 1;
            aux_enemy.dir.y = 0;
            aux_enemy.speed = 3;
            aux_enemy.dir = Vec2Normalize(&aux_enemy.dir);
            break;
        case 10:
            aux_enemy.pos.x = 1.0f;
            aux_enemy.pos.y = rand() % (576 - esat::SpriteHeight(*(g_enemy_sprite_list + aux_enemy.sprite)) - 50);
            aux_enemy.dir.x = 1;
            aux_enemy.dir.y = 0;
            aux_enemy.speed = 3;
            aux_enemy.dir = Vec2Normalize(&aux_enemy.dir);
            break;
        case 11:
            aux_enemy.pos.x = 0.0f;
            aux_enemy.pos.y = rand() % (576 - esat::SpriteHeight(*(g_enemy_sprite_list + aux_enemy.sprite)));
            aux_enemy.dir.x = 1;
            aux_enemy.dir.y = 0;
            aux_enemy.speed = 3;
            aux_enemy.dir = Vec2Normalize(&aux_enemy.dir);
            break;
        case 12:
            aux_enemy.pos.x = 1.0f;
            aux_enemy.pos.y = rand() % (576 - esat::SpriteHeight(*(g_enemy_sprite_list + aux_enemy.sprite)) - 50);
            aux_enemy.dir.x = 1;
            aux_enemy.dir.y = 0;
            aux_enemy.speed = 3;
            aux_enemy.dir = Vec2Normalize(&aux_enemy.dir);
            break;
        }
        switch (aux_i)
        {
        case 0:
            aux_enemy.color = c_dark_blue;
            break;
        case 1:
            aux_enemy.color = c_blue;
            break;
        case 2:
            aux_enemy.color = c_dark_red;
            break;
        case 3:
            aux_enemy.color = c_red;
            break;
        case 4:
            aux_enemy.color = c_dark_magenta;
            break;
        case 5:
            aux_enemy.color = c_magenta;
            break;
        case 6:
            aux_enemy.color = c_dark_green;
            break;
        case 7:
            aux_enemy.color = c_green;
            break;
        case 8:
            aux_enemy.color = c_dark_cyan;
            break;
        case 9:
            aux_enemy.color = c_cyan;
            break;
        case 10:
            aux_enemy.color = c_dark_yellow;
            break;
        case 11:
            aux_enemy.color = c_yellow;
            break;
        case 12:
            aux_enemy.color = c_grey;
            break;
        case 13:
            aux_enemy.color = c_white;
            break;
        }

        InsertarList(&g_enemy_list, aux_enemy);
    }
}

static void SpawnEnemy()
{
    g_current_spawn_time = esat::Time();
    if ((g_current_spawn_time - g_last_spawn_time) >= 1000.0 * g_enemy_spawn_time)
    {
        g_last_spawn_time = esat::Time();
        ConstuctEnemy();
    }
}

static void MovementRules(Enemy *enemy)
{
    esat::Vec2 aux_vec;
    switch (enemy->sprite)
    {
    case 0:
        if (enemy->dir.x > 0 && enemy->pos.x > 768)
        {
            enemy->pos.x = 0.0f;
        }
        if (CheckCollision(enemy->pos.x, enemy->pos.y,
                           esat::SpriteWidth(*(g_enemy_sprite_list + enemy->sprite)),
                           esat::SpriteHeight(*(g_enemy_sprite_list + enemy->sprite)),
                           96, 216, 144, 24))
        {
            enemy->explode = true;
            enemy->sprite = 0;
        }
        if (CheckCollision(enemy->pos.x, enemy->pos.y,
                           esat::SpriteWidth(*(g_enemy_sprite_list + enemy->sprite)),
                           esat::SpriteHeight(*(g_enemy_sprite_list + enemy->sprite)),
                           576, 144, 144, 24))
        {
            enemy->sprite = 0;
            enemy->explode = true;
        }
        if (CheckCollision(enemy->pos.x, enemy->pos.y,
                           esat::SpriteWidth(*(g_enemy_sprite_list + enemy->sprite)),
                           esat::SpriteHeight(*(g_enemy_sprite_list + enemy->sprite)),
                           360, 288, 96, 24))
        {
            enemy->sprite = 0;
            enemy->explode = true;
        }
        if ((enemy->pos.y + 30) >= (576 - 30))
        {
            enemy->sprite = 0;
            enemy->explode = true;
        }
        break;
    case 1:
        if (enemy->dir.x > 0 && enemy->pos.x > 768)
        {
            enemy->pos.x = 0.0f;
        }
        if (CheckCollision(enemy->pos.x, enemy->pos.y,
                           esat::SpriteWidth(*(g_enemy_sprite_list + enemy->sprite)),
                           esat::SpriteHeight(*(g_enemy_sprite_list + enemy->sprite)),
                           96, 216, 144, 24))
        {
            enemy->sprite = 0;
            enemy->explode = true;
        }
        if (CheckCollision(enemy->pos.x, enemy->pos.y,
                           esat::SpriteWidth(*(g_enemy_sprite_list + enemy->sprite)),
                           esat::SpriteHeight(*(g_enemy_sprite_list + enemy->sprite)),
                           576, 144, 144, 24))
        {
            enemy->sprite = 0;
            enemy->explode = true;
        }
        if (CheckCollision(enemy->pos.x, enemy->pos.y,
                           esat::SpriteWidth(*(g_enemy_sprite_list + enemy->sprite)),
                           esat::SpriteHeight(*(g_enemy_sprite_list + enemy->sprite)),
                           360, 288, 96, 24))
        {
            enemy->sprite = 0;
            enemy->explode = true;
        }
        if ((enemy->pos.y + 30) >= (576 - 30))
        {
            enemy->explode = true;
            enemy->sprite = 0;
        }
        break;
    case 2:
        if (enemy->dir.y > 0 && enemy->pos.y >= (576 - esat::SpriteHeight(*(g_enemy_sprite_list + enemy->sprite)) - 24))
        {
            enemy->dir.y *= -1;
        }
        if (enemy->dir.y < 0 && enemy->pos.y <= 45)
        {
            enemy->dir.y *= -1;
        }
        if (enemy->dir.x > 0 && enemy->pos.x > 768)
        {
            enemy->pos.x = 0.0f;
        }
        if (enemy->dir.x < 0 && enemy->pos.x < 0 - 48)
        {
            enemy->pos.x = 768.0f - 48.0f;
        }
        if (CheckCollision(enemy->pos.x, enemy->pos.y,
                           esat::SpriteWidth(*(g_enemy_sprite_list + enemy->sprite)),
                           esat::SpriteHeight(*(g_enemy_sprite_list + enemy->sprite)),
                           96, 216, 144, 24))
        {
            if (enemy->pos.x < 96 && (enemy->pos.y + 48) > 216 && enemy->pos.y < (216 + 24))
            {
                enemy->dir.x *= -1;
            }
            else if ((enemy->pos.x + 48) > (96 + 144) && (enemy->pos.y + 48) > 216 && enemy->pos.y < (216 + 24))
            {
                enemy->dir.x *= -1;
            }
            else if (enemy->pos.y < 216 && enemy->pos.x < (96 + 144) && (enemy->pos.x + 48) > 96)
            {
                enemy->dir.y *= -1;
            }
            else if ((enemy->pos.y + 48) > (216 + 24) && enemy->pos.x < (96 + 144) && (enemy->pos.x + 48) > 96)
            {
                enemy->dir.y *= -1;
            }
        }
        if (CheckCollision(enemy->pos.x, enemy->pos.y,
                           esat::SpriteWidth(*(g_enemy_sprite_list + enemy->sprite)),
                           esat::SpriteHeight(*(g_enemy_sprite_list + enemy->sprite)),
                           576, 144, 144, 24))
        {
            if (enemy->pos.x < 576 && (enemy->pos.y + 48) > 144 && enemy->pos.y < (144 + 24))
            {
                enemy->dir.x *= -1;
            }
            else if ((enemy->pos.x + 48) > (576 + 144) && (enemy->pos.y + 48) > 144 && enemy->pos.y < (144 + 24))
            {
                enemy->dir.x *= -1;
            }
            else if (enemy->pos.y < 144 && enemy->pos.x < (576 + 144) && (enemy->pos.x + 48) > 576)
            {
                enemy->dir.y *= -1;
            }
            else if ((enemy->pos.y + 48) > (144 + 24) && enemy->pos.x < (576 + 144) && (enemy->pos.x + 48) > 576)
            {
                enemy->dir.y *= -1;
            }
        }
        if (CheckCollision(enemy->pos.x, enemy->pos.y,
                           esat::SpriteWidth(*(g_enemy_sprite_list + enemy->sprite)),
                           esat::SpriteHeight(*(g_enemy_sprite_list + enemy->sprite)),
                           360, 288, 96, 24))
        {
            if (enemy->pos.x < 360 && (enemy->pos.y + 48) > 288 && enemy->pos.y < (288 + 24))
            {
                enemy->dir.x *= -1;
            }
            else if ((enemy->pos.x + 48) > (360 + 96) && (enemy->pos.y + 48) > 288 && enemy->pos.y < (288 + 24))
            {
                enemy->dir.x *= -1;
            }
            else if (enemy->pos.y < 288 && enemy->pos.x < (360 + 96) && (enemy->pos.x + 48) > 360)
            {
                enemy->dir.y *= -1;
            }
            else if ((enemy->pos.y + 48) > (288 + 24) && enemy->pos.x < (360 + 96) && (enemy->pos.x + 48) > 360)
            {
                enemy->dir.y *= -1;
            }
        }
        break;
    case 3:
        if (enemy->dir.y > 0 && enemy->pos.y >= (576 - esat::SpriteHeight(*(g_enemy_sprite_list + enemy->sprite)) - 24))
        {
            enemy->dir.y *= -1;
        }
        if (enemy->dir.y < 0 && enemy->pos.y <= 45)
        {
            enemy->dir.y *= -1;
        }
        if (enemy->dir.x > 0 && enemy->pos.x > 768)
        {
            enemy->pos.x = 0.0f;
        }
        if (enemy->dir.x < 0 && enemy->pos.x < 0 - 48)
        {
            enemy->pos.x = 768.0f - 48.0f;
        }
        if (CheckCollision(enemy->pos.x, enemy->pos.y,
                           esat::SpriteWidth(*(g_enemy_sprite_list + enemy->sprite)),
                           esat::SpriteHeight(*(g_enemy_sprite_list + enemy->sprite)),
                           96, 216, 144, 24))
        {
            if (enemy->pos.x < 96 && (enemy->pos.y + 48) > 216)
            {
                enemy->dir.x *= -1;
            }
            else if ((enemy->pos.x + 48) >= (96 + 144))
            {
                enemy->dir.x *= -1;
            }
            else if (enemy->pos.y < 216 && enemy->pos.x > 96)
            {
                enemy->dir.y *= -1;
            }
            else if ((enemy->pos.y + 48) > (216 + 24) && enemy->pos.x > 96)
            {
                enemy->dir.y *= -1;
            }
        }
        if (CheckCollision(enemy->pos.x, enemy->pos.y,
                           esat::SpriteWidth(*(g_enemy_sprite_list + enemy->sprite)),
                           esat::SpriteHeight(*(g_enemy_sprite_list + enemy->sprite)),
                           576, 144, 144, 24))
        {
            if (enemy->pos.x <= 576)
            {
                enemy->dir.x *= -1;
            }
            else if ((enemy->pos.x + 48) >= (576 + 144))
            {
                enemy->dir.x *= -1;
            }
            else if (enemy->pos.y < 144)
            {
                enemy->dir.y *= -1;
            }
            else if ((enemy->pos.y + 48) > (144 + 24))
            {
                enemy->dir.y *= -1;
            }
        }
        if (CheckCollision(enemy->pos.x, enemy->pos.y,
                           esat::SpriteWidth(*(g_enemy_sprite_list + enemy->sprite)),
                           esat::SpriteHeight(*(g_enemy_sprite_list + enemy->sprite)),
                           360, 288, 96, 24))
        {
            if (enemy->pos.x <= 360)
            {
                enemy->dir.x *= -1;
            }
            else if ((enemy->pos.x + 48) >= (360 + 144))
            {
                enemy->dir.x *= -1;
            }
            else if (enemy->pos.y < 288)
            {
                enemy->dir.y *= -1;
            }
            else if ((enemy->pos.y + 48) > (288 + 24))
            {
                enemy->dir.y *= -1;
            }
        }
        break;
    case 4:
        if (enemy->dir.y > 0 && enemy->pos.y >= (576 - esat::SpriteHeight(*(g_enemy_sprite_list + enemy->sprite)) - 24))
        {
            enemy->dir.y *= -1;
        }
        if (enemy->dir.y < 0 && enemy->pos.y <= 45)
        {
            enemy->dir.y *= -1;
        }
        if (enemy->dir.x > 0 && enemy->pos.x > 768)
        {
            enemy->pos.x = 0.0f;
        }
        if (enemy->dir.x < 0 && enemy->pos.x < 0 - 48)
        {
            enemy->pos.x = 768.0f - 48.0f;
        }
        if ((rand() % 60) == 0)
        {
            if ((rand() % 2) == 0)
            {
                enemy->dir = {enemy->dir.x, 1};
                enemy->dir = Vec2Normalize(&enemy->dir);
            }
            else
            {
                enemy->dir = {enemy->dir.x, -1};
                enemy->dir = Vec2Normalize(&enemy->dir);
            }
        }
        else if ((rand() % 30) == 0)
        {
            enemy->dir.y = 0;
            enemy->dir = Vec2Normalize(&enemy->dir);
        }
        if (CheckCollision(enemy->pos.x, enemy->pos.y,
                           esat::SpriteWidth(*(g_enemy_sprite_list + enemy->sprite)),
                           esat::SpriteHeight(*(g_enemy_sprite_list + enemy->sprite)),
                           96, 216, 144, 24))
        {
            if (enemy->pos.x < 96 && (enemy->pos.y + 48) > 216)
            {
                enemy->dir.x *= -1;
            }
            else if ((enemy->pos.x + 48) >= (96 + 144))
            {
                enemy->dir.x *= -1;
            }
            else if (enemy->pos.y < 216 && enemy->pos.x > 96)
            {
                enemy->dir.y *= -1;
            }
            else if ((enemy->pos.y + 48) > (216 + 24) && enemy->pos.x > 96)
            {
                enemy->dir.y *= -1;
            }
        }
        if (CheckCollision(enemy->pos.x, enemy->pos.y,
                           esat::SpriteWidth(*(g_enemy_sprite_list + enemy->sprite)),
                           esat::SpriteHeight(*(g_enemy_sprite_list + enemy->sprite)),
                           576, 144, 144, 24))
        {
            if (enemy->pos.x <= 576)
            {
                enemy->dir.x *= -1;
            }
            else if ((enemy->pos.x + 48) >= (576 + 144))
            {
                enemy->dir.x *= -1;
            }
            else if (enemy->pos.y < 144)
            {
                enemy->dir.y *= -1;
            }
            else if ((enemy->pos.y + 48) > (144 + 24))
            {
                enemy->dir.y *= -1;
            }
        }
        if (CheckCollision(enemy->pos.x, enemy->pos.y,
                           esat::SpriteWidth(*(g_enemy_sprite_list + enemy->sprite)),
                           esat::SpriteHeight(*(g_enemy_sprite_list + enemy->sprite)),
                           360, 288, 96, 24))
        {
            if (enemy->pos.x <= 360)
            {
                enemy->dir.x *= -1;
            }
            else if ((enemy->pos.x + 48) >= (360 + 144))
            {
                enemy->dir.x *= -1;
            }
            else if (enemy->pos.y < 288)
            {
                enemy->dir.y *= -1;
            }
            else if ((enemy->pos.y + 48) > (288 + 24))
            {
                enemy->dir.y *= -1;
            }
        }
        break;
    case 5:
        if (enemy->dir.y > 0 && enemy->pos.y >= (576 - esat::SpriteHeight(*(g_enemy_sprite_list + enemy->sprite)) - 24))
        {
            enemy->dir.y *= -1;
        }
        if (enemy->dir.y < 0 && enemy->pos.y <= 45)
        {
            enemy->dir.y *= -1;
        }
        if (enemy->dir.x > 0 && enemy->pos.x > 768)
        {
            enemy->pos.x = 0.0f;
        }
        if (enemy->dir.x < 0 && enemy->pos.x < 0 - 48)
        {
            enemy->pos.x = 768.0f - 48.0f;
        }
        if ((rand() % 60) == 0)
        {
            if ((rand() % 2) == 0)
            {
                enemy->dir = {enemy->dir.x, 1};
                enemy->dir = Vec2Normalize(&enemy->dir);
            }
            else
            {
                enemy->dir = {enemy->dir.x, -1};
                enemy->dir = Vec2Normalize(&enemy->dir);
            }
        }
        else if ((rand() % 30) == 0)
        {
            enemy->dir.y = 0;
            enemy->dir = Vec2Normalize(&enemy->dir);
        }
        if (CheckCollision(enemy->pos.x, enemy->pos.y,
                           esat::SpriteWidth(*(g_enemy_sprite_list + enemy->sprite)),
                           esat::SpriteHeight(*(g_enemy_sprite_list + enemy->sprite)),
                           96, 216, 144, 24))
        {
            if (enemy->pos.x < 96 && (enemy->pos.y + 48) > 216)
            {
                enemy->dir.x *= -1;
            }
            else if ((enemy->pos.x + 48) >= (96 + 144))
            {
                enemy->dir.x *= -1;
            }
            else if (enemy->pos.y < 216 && enemy->pos.x > 96)
            {
                enemy->dir.y *= -1;
            }
            else if ((enemy->pos.y + 48) > (216 + 24) && enemy->pos.x > 96)
            {
                enemy->dir.y *= -1;
            }
        }
        if (CheckCollision(enemy->pos.x, enemy->pos.y,
                           esat::SpriteWidth(*(g_enemy_sprite_list + enemy->sprite)),
                           esat::SpriteHeight(*(g_enemy_sprite_list + enemy->sprite)),
                           576, 144, 144, 24))
        {
            if (enemy->pos.x <= 576)
            {
                enemy->dir.x *= -1;
            }
            else if ((enemy->pos.x + 48) >= (576 + 144))
            {
                enemy->dir.x *= -1;
            }
            else if (enemy->pos.y < 144)
            {
                enemy->dir.y *= -1;
            }
            else if ((enemy->pos.y + 48) > (144 + 24))
            {
                enemy->dir.y *= -1;
            }
        }
        if (CheckCollision(enemy->pos.x, enemy->pos.y,
                           esat::SpriteWidth(*(g_enemy_sprite_list + enemy->sprite)),
                           esat::SpriteHeight(*(g_enemy_sprite_list + enemy->sprite)),
                           360, 288, 96, 24))
        {
            if (enemy->pos.x <= 360)
            {
                enemy->dir.x *= -1;
            }
            else if ((enemy->pos.x + 48) >= (360 + 144))
            {
                enemy->dir.x *= -1;
            }
            else if (enemy->pos.y < 288)
            {
                enemy->dir.y *= -1;
            }
            else if ((enemy->pos.y + 48) > (288 + 24))
            {
                enemy->dir.y *= -1;
            }
        }
        break;
    case 6:
        if (enemy->dir.x > 0 && enemy->pos.x > 768)
        {
            enemy->pos.x = 0.0f;
        }
        if (CheckCollision(enemy->pos.x, enemy->pos.y,
                           esat::SpriteWidth(*(g_enemy_sprite_list + enemy->sprite)),
                           esat::SpriteHeight(*(g_enemy_sprite_list + enemy->sprite)),
                           96, 216, 144, 24))
        {
            enemy->explode = true;
            enemy->sprite = 0;
        }
        if (CheckCollision(enemy->pos.x, enemy->pos.y,
                           esat::SpriteWidth(*(g_enemy_sprite_list + enemy->sprite)),
                           esat::SpriteHeight(*(g_enemy_sprite_list + enemy->sprite)),
                           576, 144, 144, 24))
        {
            enemy->explode = true;
            enemy->sprite = 0;
        }
        if (CheckCollision(enemy->pos.x, enemy->pos.y,
                           esat::SpriteWidth(*(g_enemy_sprite_list + enemy->sprite)),
                           esat::SpriteHeight(*(g_enemy_sprite_list + enemy->sprite)),
                           360, 288, 96, 24))
        {
            enemy->explode = true;
            enemy->sprite = 0;
        }
        if ((enemy->pos.y + 30) >= (576 - 30))
        {
            enemy->explode = true;
            enemy->sprite = 0;
        }
        break;
    case 7:
        if (enemy->dir.x < 0 && enemy->pos.x < 0 - 48)
        {
            enemy->pos.x = 768.0f - 48.0f;
        }
        if (CheckCollision(enemy->pos.x, enemy->pos.y,
                           esat::SpriteWidth(*(g_enemy_sprite_list + enemy->sprite)),
                           esat::SpriteHeight(*(g_enemy_sprite_list + enemy->sprite)),
                           96, 216, 144, 24))
        {
            enemy->explode = true;
            enemy->sprite = 0;
        }
        if (CheckCollision(enemy->pos.x, enemy->pos.y,
                           esat::SpriteWidth(*(g_enemy_sprite_list + enemy->sprite)),
                           esat::SpriteHeight(*(g_enemy_sprite_list + enemy->sprite)),
                           576, 144, 144, 24))
        {
            enemy->explode = true;
            enemy->sprite = 0;
        }
        if (CheckCollision(enemy->pos.x, enemy->pos.y,
                           esat::SpriteWidth(*(g_enemy_sprite_list + enemy->sprite)),
                           esat::SpriteHeight(*(g_enemy_sprite_list + enemy->sprite)),
                           360, 288, 96, 24))
        {
            enemy->explode = true;
            enemy->sprite = 0;
        }
        if ((enemy->pos.y + 30) >= (576 - 30))
        {
            enemy->explode = true;
            enemy->sprite = 0;
        }
        break;
    case 8:
        if (enemy->dir.x > 0 && enemy->pos.x > 768)
        {
            enemy->pos.x = 0.0f;
        }
        if (enemy->dir.x < 0 && enemy->pos.x < 0 - 48)
        {
            enemy->pos.x = 768.0f - 48.0f;
        }
        if (enemy->spawn)
        {
            enemy->dir.x = 0;
            enemy->dir.y = (g_player.pos.y + (72 / 2)) - enemy->pos.y;
            enemy->dir = Vec2Normalize(&enemy->dir);
            if ((rand() % 60) == 0)
            {
                enemy->spawn = false;
                enemy->pos.x = 0;
            }
        }
        else
        {
            esat::Vec2 aux_vec;
            aux_vec.y = (g_player.pos.y + (72 / 2)) - enemy->pos.y;
            aux_vec.x = (g_player.pos.x + (48 / 2)) - enemy->pos.x;
            aux_vec = Vec2Normalize(&aux_vec);
            if ((g_player.pos.x + (72 / 2)) > enemy->pos.x + 48)
            {
                if ((g_player.pos.y + (72 / 2)) > enemy->pos.y)
                {
                    if (aux_vec.y > 0.707)
                    {
                        enemy->dir.y = 0.707;
                        enemy->dir.x = 0.707f;
                    }
                    else
                    {
                        enemy->dir.y = aux_vec.y;
                        enemy->dir.x = aux_vec.x;
                    }
                }
                if ((g_player.pos.y + (72 / 2)) < enemy->pos.y)
                {
                    if (aux_vec.y < -0.707)
                    {
                        enemy->dir.y = -0.707;
                        enemy->dir.x = 0.707f;
                    }
                    else
                    {
                        enemy->dir.y = aux_vec.y;
                        enemy->dir.x = aux_vec.x;
                    }
                }
            }
            enemy->dir = Vec2Normalize(&enemy->dir);
        }
        if (CheckCollision(enemy->pos.x, enemy->pos.y,
                           esat::SpriteWidth(*(g_enemy_sprite_list + enemy->sprite)),
                           esat::SpriteHeight(*(g_enemy_sprite_list + enemy->sprite)),
                           96, 216, 144, 24))
        {
            enemy->explode = true;
            enemy->sprite = 0;
        }
        if (CheckCollision(enemy->pos.x, enemy->pos.y,
                           esat::SpriteWidth(*(g_enemy_sprite_list + enemy->sprite)),
                           esat::SpriteHeight(*(g_enemy_sprite_list + enemy->sprite)),
                           576, 144, 144, 24))
        {
            enemy->explode = true;
            enemy->sprite = 0;
        }
        if (CheckCollision(enemy->pos.x, enemy->pos.y,
                           esat::SpriteWidth(*(g_enemy_sprite_list + enemy->sprite)),
                           esat::SpriteHeight(*(g_enemy_sprite_list + enemy->sprite)),
                           360, 288, 96, 24))
        {
            enemy->explode = true;
            enemy->sprite = 0;
        }
        break;
    case 9:
        if (enemy->dir.x > 0 && enemy->pos.x > 768)
        {
            enemy->pos.x = 0.0f;
        }
        if (enemy->dir.x < 0 && enemy->pos.x < 0 - 48)
        {
            enemy->pos.x = 768.0f - 48.0f;
        }
        if (enemy->spawn)
        {
            enemy->dir.x = 0;
            enemy->dir.y = (g_player.pos.y + (72 / 2)) - enemy->pos.y;
            enemy->dir = Vec2Normalize(&enemy->dir);
            if ((rand() % 60) == 0)
            {
                enemy->spawn = false;
                enemy->pos.x = (768 - 24);
                enemy->dir.x = -1;
                enemy->dir.y = (g_player.pos.y + (72 / 2)) - enemy->pos.y;
                enemy->dir = Vec2Normalize(&enemy->dir);
            }
        }
        else
        {
            aux_vec.y = (g_player.pos.y + (72 / 2)) - enemy->pos.y;
            aux_vec.x = (g_player.pos.x + (48 / 2)) - enemy->pos.x;
            aux_vec = Vec2Normalize(&aux_vec);
            if ((g_player.pos.x + (72 / 2)) < enemy->pos.x)
            {
                if ((g_player.pos.y + (72 / 2)) > enemy->pos.y)
                {
                    if (aux_vec.y > 0.707)
                    {
                        enemy->dir.y = 0.707;
                        enemy->dir.x = -0.707f;
                    }
                    else
                    {
                        enemy->dir.y = aux_vec.y;
                        enemy->dir.x = aux_vec.x;
                    }
                }
                if ((g_player.pos.y + (72 / 2)) < enemy->pos.y)
                {
                    if (aux_vec.y < -0.707)
                    {
                        enemy->dir.y = -0.707;
                        enemy->dir.x = -0.707f;
                    }
                    else
                    {
                        enemy->dir.y = aux_vec.y;
                        enemy->dir.x = aux_vec.x;
                    }
                }
            }
            enemy->dir = Vec2Normalize(&enemy->dir);
        }
        break;
    case 10:
        aux_vec.y = (g_player.pos.y + (72 / 2)) - enemy->pos.y;
        aux_vec.x = (g_player.pos.x + (48 / 2)) - enemy->pos.x;
        aux_vec = Vec2Normalize(&aux_vec);
        if (enemy->dir.y > 0 && enemy->pos.y >= (576 - esat::SpriteHeight(*(g_enemy_sprite_list + enemy->sprite))))
        {
            enemy->dir.y *= -1;
        }
        if (enemy->dir.y < 0 && enemy->pos.y <= 45)
        {
            enemy->dir.y *= -1;
        }
        if (enemy->dir.x > 0 && enemy->pos.x > 768)
        {
            enemy->pos.x = 0.0f;
        }
        if (enemy->dir.x < 0 && enemy->pos.x < 0 - 48)
        {
            enemy->pos.x = 768.0f - 48.0f;
        }
        enemy->dir.y += aux_vec.y;
        enemy->dir.x += aux_vec.x;
        enemy->dir = Vec2Normalize(&enemy->dir);
        if (CheckCollision(enemy->pos.x, enemy->pos.y,
                           esat::SpriteWidth(*(g_enemy_sprite_list + enemy->sprite)),
                           esat::SpriteHeight(*(g_enemy_sprite_list + enemy->sprite)),
                           96, 216, 144, 24))
        {
            if (enemy->pos.x <= 96)
            {
                enemy->dir.x *= -15;
            }
            else if ((enemy->pos.x + 48) >= (96 + 144))
            {
                enemy->dir.x *= -15;
            }
            else if (enemy->pos.y < 216)
            {
                enemy->dir.y *= -15;
            }
            else if ((enemy->pos.y + 48) > (216 + 24))
            {
                enemy->dir.y *= -15;
            }
        }
        if (CheckCollision(enemy->pos.x, enemy->pos.y,
                           esat::SpriteWidth(*(g_enemy_sprite_list + enemy->sprite)),
                           esat::SpriteHeight(*(g_enemy_sprite_list + enemy->sprite)),
                           576, 144, 144, 24))
        {
            if (enemy->pos.x <= 576)
            {
                enemy->dir.x *= -15;
            }
            else if ((enemy->pos.x + 48) >= (576 + 144))
            {
                enemy->dir.x *= -15;
            }
            else if (enemy->pos.y < 144)
            {
                enemy->dir.y *= -15;
            }
            else if ((enemy->pos.y + 48) > (144 + 24))
            {
                enemy->dir.y *= -15;
            }
        }
        if (CheckCollision(enemy->pos.x, enemy->pos.y,
                           esat::SpriteWidth(*(g_enemy_sprite_list + enemy->sprite)),
                           esat::SpriteHeight(*(g_enemy_sprite_list + enemy->sprite)),
                           360, 288, 96, 24))
        {
            if (enemy->pos.x <= 360)
            {
                enemy->dir.x *= -15;
            }
            else if ((enemy->pos.x + 48) >= (360 + 144))
            {
                enemy->dir.x *= -15;
            }
            else if (enemy->pos.y < 288)
            {
                enemy->dir.y *= -15;
            }
            else if ((enemy->pos.y + 48) > (288 + 24))
            {
                enemy->dir.y *= -15;
            }
        }
        break;
    case 11:
        if (enemy->dir.y > 0 && enemy->pos.y >= (576 - esat::SpriteHeight(*(g_enemy_sprite_list + enemy->sprite)) - 24))
        {
            enemy->dir.y *= -1;
        }
        if (enemy->dir.y < 0 && enemy->pos.y <= 45)
        {
            enemy->dir.y *= -1;
        }
        if (enemy->dir.x > 0 && enemy->pos.x > 768)
        {
            enemy->pos.x = 0.0f;
        }
        if (enemy->dir.x < 0 && enemy->pos.x < 0 - 48)
        {
            enemy->pos.x = 768.0f - 48.0f;
        }
        if ((rand() % 60) == 0)
        {
            if ((rand() % 2) == 0)
            {
                enemy->dir = {enemy->dir.x, 1};
                enemy->dir = Vec2Normalize(&enemy->dir);
            }
            else
            {
                enemy->dir = {enemy->dir.x, -1};
                enemy->dir = Vec2Normalize(&enemy->dir);
            }
        }
        else if ((rand() % 30) == 0)
        {
            enemy->dir.y = 0;
            enemy->dir = Vec2Normalize(&enemy->dir);
        }
        if (CheckCollision(enemy->pos.x, enemy->pos.y,
                           esat::SpriteWidth(*(g_enemy_sprite_list + enemy->sprite)),
                           esat::SpriteHeight(*(g_enemy_sprite_list + enemy->sprite)),
                           96, 216, 144, 24))
        {
            if (enemy->pos.x < 96 && (enemy->pos.y + 48) > 216)
            {
                enemy->dir.x *= -1;
            }
            else if ((enemy->pos.x + 48) >= (96 + 144))
            {
                enemy->dir.x *= -1;
            }
            else if (enemy->pos.y < 216 && enemy->pos.x > 96)
            {
                enemy->dir.y *= -1;
            }
            else if ((enemy->pos.y + 48) > (216 + 24) && enemy->pos.x > 96)
            {
                enemy->dir.y *= -1;
            }
        }
        if (CheckCollision(enemy->pos.x, enemy->pos.y,
                           esat::SpriteWidth(*(g_enemy_sprite_list + enemy->sprite)),
                           esat::SpriteHeight(*(g_enemy_sprite_list + enemy->sprite)),
                           576, 144, 144, 24))
        {
            if (enemy->pos.x <= 576)
            {
                enemy->dir.x *= -1;
            }
            else if ((enemy->pos.x + 48) >= (576 + 144))
            {
                enemy->dir.x *= -1;
            }
            else if (enemy->pos.y < 144)
            {
                enemy->dir.y *= -1;
            }
            else if ((enemy->pos.y + 48) > (144 + 24))
            {
                enemy->dir.y *= -1;
            }
        }
        if (CheckCollision(enemy->pos.x, enemy->pos.y,
                           esat::SpriteWidth(*(g_enemy_sprite_list + enemy->sprite)),
                           esat::SpriteHeight(*(g_enemy_sprite_list + enemy->sprite)),
                           360, 288, 96, 24))
        {
            if (enemy->pos.x <= 360)
            {
                enemy->dir.x *= -1;
            }
            else if ((enemy->pos.x + 48) >= (360 + 144))
            {
                enemy->dir.x *= -1;
            }
            else if (enemy->pos.y < 288)
            {
                enemy->dir.y *= -1;
            }
            else if ((enemy->pos.y + 48) > (288 + 24))
            {
                enemy->dir.y *= -1;
            }
        }
        break;
    case 12:
        aux_vec.y = (g_player.pos.y + (72 / 2)) - enemy->pos.y;
        aux_vec.x = (g_player.pos.x + (48 / 2)) - enemy->pos.x;
        aux_vec = Vec2Normalize(&aux_vec);
        if (enemy->dir.y > 0 && enemy->pos.y >= (576 - esat::SpriteHeight(*(g_enemy_sprite_list + enemy->sprite))))
        {
            enemy->dir.y *= -1;
        }
        if (enemy->dir.y < 0 && enemy->pos.y <= 45)
        {
            enemy->dir.y *= -1;
        }
        if (enemy->dir.x > 0 && enemy->pos.x > 768)
        {
            enemy->pos.x = 0.0f;
        }
        if (enemy->dir.x < 0 && enemy->pos.x < 0 - 48)
        {
            enemy->pos.x = 768.0f - 48.0f;
        }
        enemy->dir.y += aux_vec.y;
        enemy->dir.x += aux_vec.x;
        enemy->dir = Vec2Normalize(&enemy->dir);
        if (CheckCollision(enemy->pos.x, enemy->pos.y,
                           esat::SpriteWidth(*(g_enemy_sprite_list + enemy->sprite)),
                           esat::SpriteHeight(*(g_enemy_sprite_list + enemy->sprite)),
                           96, 216, 144, 24))
        {
            if (enemy->pos.x <= 96)
            {
                enemy->dir.x *= -15;
            }
            else if ((enemy->pos.x + 48) >= (96 + 144))
            {
                enemy->dir.x *= -15;
            }
            else if (enemy->pos.y < 216)
            {
                enemy->dir.y *= -15;
            }
            else if ((enemy->pos.y + 48) > (216 + 24))
            {
                enemy->dir.y *= -15;
            }
        }
        if (CheckCollision(enemy->pos.x, enemy->pos.y,
                           esat::SpriteWidth(*(g_enemy_sprite_list + enemy->sprite)),
                           esat::SpriteHeight(*(g_enemy_sprite_list + enemy->sprite)),
                           576, 144, 144, 24))
        {
            if (enemy->pos.x <= 576)
            {
                enemy->dir.x *= -15;
            }
            else if ((enemy->pos.x + 48) >= (576 + 144))
            {
                enemy->dir.x *= -15;
            }
            else if (enemy->pos.y < 144)
            {
                enemy->dir.y *= -15;
            }
            else if ((enemy->pos.y + 48) > (144 + 24))
            {
                enemy->dir.y *= -15;
            }
        }
        if (CheckCollision(enemy->pos.x, enemy->pos.y,
                           esat::SpriteWidth(*(g_enemy_sprite_list + enemy->sprite)),
                           esat::SpriteHeight(*(g_enemy_sprite_list + enemy->sprite)),
                           360, 288, 96, 24))
        {
            if (enemy->pos.x <= 360)
            {
                enemy->dir.x *= -15;
            }
            else if ((enemy->pos.x + 48) >= (360 + 144))
            {
                enemy->dir.x *= -15;
            }
            else if (enemy->pos.y < 288)
            {
                enemy->dir.y *= -15;
            }
            else if ((enemy->pos.y + 48) > (288 + 24))
            {
                enemy->dir.y *= -15;
            }
        }
        break;
    }
}

static void MoveEnemy(Enemy *enemy)
{
    if (!enemy->explode)
    {
        MovementRules(enemy);
        enemy->pos.x += enemy->dir.x * enemy->speed;
        enemy->pos.y += enemy->dir.y * enemy->speed;
    }
}

static void AnimationEnemy(Enemy *enemy)
{
    if (!enemy->explode)
    {
        enemy->animation_counter++;
        enemy->animation_counter %= 30;
        if (enemy->animation_counter == 0)
        {
            switch (enemy->sprite)
            {
            case 0:
                enemy->sprite = 1;
                break;
            case 1:
                enemy->sprite = 0;
                break;
            case 2:
                enemy->sprite = 3;
                break;
            case 3:
                enemy->sprite = 2;
                break;
            case 4:
                enemy->sprite = 5;
                break;
            case 5:
                enemy->sprite = 4;
                break;
            }
        }
    }
}

static void EnemyExplosion(Enemy *enemy)
{
    if (enemy->explode)
    {
        enemy->explode_counter++;
        enemy->explode_counter %= 15;
        if (enemy->explode_counter == 0)
        {
            enemy->sprite++;
        }
    }
}

void EnemyStart()
{
    int sprite_count = 0;
    g_last_spawn_time = esat::Time();
    g_enemy_sprite_list = (esat::SpriteHandle *)malloc(sizeof(esat::SpriteHandle) * 13);
    g_explosion_sprite_list = (esat::SpriteHandle *)malloc(sizeof(esat::SpriteHandle) * 3);
    // g_player.nivel = 0;
    CrearList(&g_enemy_list);
    for (int i = 3; i <= 13; ++i)
    {
        if (sprite_count == 8 || sprite_count == 9)
        {
            *(g_enemy_sprite_list + sprite_count) = esat::SubSprite(g_spritesheet, 48 * i, 48, 48, 24);
            ++sprite_count;
        }
        else
        {
            *(g_enemy_sprite_list + sprite_count) = esat::SubSprite(g_spritesheet, 48 * i, 48, 48, 48);
            ++sprite_count;
        }
    }
    *(g_enemy_sprite_list + sprite_count) = esat::SubSprite(g_spritesheet, 0, 48 * 2, 48, 48);
    ++sprite_count;
    *(g_enemy_sprite_list + sprite_count) = esat::SubSprite(g_spritesheet, 48, 48 * 2, 48, 24);
    *(g_explosion_sprite_list + 0) = esat::SubSprite(g_spritesheet, 48 * 12, 0, 93, 48);
    *(g_explosion_sprite_list + 1) = esat::SubSprite(g_spritesheet, 665, 0, 66, 34);
    *(g_explosion_sprite_list + 2) = esat::SubSprite(g_spritesheet, 765, 0, 50, 32);
}

void EnemyUpdate()
{
    EnemNode *aux_enemy;
    SpawnEnemy();
    for (int i = 0; i < ListLength(g_enemy_list); ++i)
    {
        aux_enemy = IndexList(g_enemy_list, i);
        MoveEnemy(&aux_enemy->enem);
        EnemyExplosion(&aux_enemy->enem);
        AnimationEnemy(&aux_enemy->enem);
    }
    // if (esat::IsKeyDown('P'))
    // {
    //     g_player.nivel++;
    //     DelWholeList(&g_enemy_list);
    // }
}

void EnemyDraw()
{
    EnemNode *aux_enemy;
    float aux_pos;
    for (int i = 0; i < ListLength(g_enemy_list); ++i)
    {
        aux_enemy = IndexList(g_enemy_list, i);
        if (aux_enemy->enem.explode)
        {
            if (aux_enemy->enem.sprite >= 3)
            {
                DelFromList(&g_enemy_list, i);
            }
            else
            {
                DrawColorSquare({aux_enemy->enem.pos.x, aux_enemy->enem.pos.y}, aux_enemy->enem.color,
                                esat::SpriteWidth(*(g_explosion_sprite_list + aux_enemy->enem.sprite)),
                                esat::SpriteHeight(*(g_explosion_sprite_list + aux_enemy->enem.sprite)));
                esat::DrawSprite(*(g_explosion_sprite_list + aux_enemy->enem.sprite),
                                 aux_enemy->enem.pos.x,
                                 aux_enemy->enem.pos.y); //*(g_explosion_sprite_list + 2)
            }
        }
        else
        {
            if (aux_enemy->enem.pos.x + 48 > 768 && aux_enemy->enem.dir.x > 0)
            {
                aux_pos = aux_enemy->enem.pos.x - 768.0f;
                DrawColorSquare({aux_pos, aux_enemy->enem.pos.y}, aux_enemy->enem.color,
                                esat::SpriteWidth(*(g_enemy_sprite_list + aux_enemy->enem.sprite)),
                                esat::SpriteHeight(*(g_enemy_sprite_list + aux_enemy->enem.sprite)));
                esat::DrawSprite(*(g_enemy_sprite_list + aux_enemy->enem.sprite),
                                 aux_pos,
                                 aux_enemy->enem.pos.y);
            }
            if (aux_enemy->enem.pos.x < 0)
            {
                aux_pos = 768.0f + aux_enemy->enem.pos.x;
                DrawColorSquare({aux_pos, aux_enemy->enem.pos.y}, aux_enemy->enem.color,
                                esat::SpriteWidth(*(g_enemy_sprite_list + aux_enemy->enem.sprite)),
                                esat::SpriteHeight(*(g_enemy_sprite_list + aux_enemy->enem.sprite)));
                esat::DrawSprite(*(g_enemy_sprite_list + aux_enemy->enem.sprite),
                                 aux_pos,
                                 aux_enemy->enem.pos.y);
            }
            DrawColorSquare({aux_enemy->enem.pos.x, aux_enemy->enem.pos.y}, aux_enemy->enem.color,
                            esat::SpriteWidth(*(g_enemy_sprite_list + aux_enemy->enem.sprite)),
                            esat::SpriteHeight(*(g_enemy_sprite_list + aux_enemy->enem.sprite)));
            esat::DrawSprite(*(g_enemy_sprite_list + aux_enemy->enem.sprite),
                             aux_enemy->enem.pos.x,
                             aux_enemy->enem.pos.y);
        }
    }
}

void EnemyEnd()
{
    DelWholeList(&g_enemy_list);
    free(g_enemy_sprite_list);
}