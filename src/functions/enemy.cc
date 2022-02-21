/**
 * @file enemy.cc
 * @author Héctor Ochando
 * @brief
 *
 *
 */
// #include "../common/structs.cc"

esat::SpriteHandle *g_enemy_sprite_list = nullptr;
EnemNode *g_enemy_list = nullptr;
esat::SpriteHandle spritesheet;
double g_last_spawn_time, g_current_spawn_time;
double g_enemy_spawn_time = 1.0;
int g_enemy_in_window = 500;

static void ConstuctEnemy()
{
    Enemy aux_enemy;
    if (ListLength(g_enemy_list) < g_enemy_in_window)
    {   
        int aux_i = rand() % 14;
        aux_enemy.sprite = 0;
        aux_enemy.pos.x = rand() % 768;
        aux_enemy.pos.y = rand() % (576 - esat::SpriteHeight(*(g_enemy_sprite_list + aux_enemy.sprite)));
        aux_enemy.speed = 5;
        switch (aux_enemy.sprite)
        {
            case 0:
                aux_enemy.pos.x = -75.0f;
                aux_enemy.pos.y = rand() % (576 - esat::SpriteHeight(*(g_enemy_sprite_list + aux_enemy.sprite)));
                aux_enemy.dir.x = rand() % 10;
                aux_enemy.dir.y = rand() % 5;
                Vec2Normalize(&aux_enemy.dir);
                break;
            case 1:
                aux_enemy.pos.x = -75.0f;
                aux_enemy.pos.y = rand() % (576 - esat::SpriteHeight(*(g_enemy_sprite_list + aux_enemy.sprite)));
                aux_enemy.dir.x = rand() % 10;
                aux_enemy.dir.y = rand() % 5;
                Vec2Normalize(&aux_enemy.dir);
                break;
            case 2:
                
                break;
            case 3:
                
                break;
            case 4:
                
                break;
            case 5:
                
                break;
            case 6:
                
                break;
            case 7:
                
                break;
            case 8:
                
                break;
            case 9:
                
                break;
            case 10:
                
                break;
            case 11:
                
                break;
            case 12:
                
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

static void MoveEnemy(Enemy* enemy){
    enemy->pos.x += enemy->dir.x * enemy->speed;
    enemy->pos.y += enemy->dir.y * enemy->speed;
}

static void MovementRules(Enemy* enemy){
    switch (enemy->sprite)
    {
    case 0:
        if(enemy->dir.x > 0 && enemy->pos.x > 768){
            enemy->pos.x = -75.0f;
        }
        break;
    case 1:
        
        break;
    case 2:
        
        break;
    case 3:
        
        break;
    case 4:
        
        break;
    case 5:
        
        break;
    case 6:
        
        break;
    case 7:
        
        break;
    case 8:
        
        break;
    case 9:
        
        break;
    case 10:
        
        break;
    case 11:
        
        break;
    case 12:
        
        break;
    }
}

void EnemyStart()
{
    int sprite_count = 0;
    g_last_spawn_time = esat::Time();
    g_enemy_sprite_list = (esat::SpriteHandle *)malloc(sizeof(esat::SpriteHandle) * 13);
    CrearList(&g_enemy_list);
    for (int i = 3; i <= 13; ++i)
    {
        *(g_enemy_sprite_list + sprite_count) = esat::SubSprite(g_spritesheet, 48 * i, 48, 48, 48);
        ++sprite_count;
    }
    *(g_enemy_sprite_list + sprite_count) = esat::SubSprite(g_spritesheet, 0, 48 * 2, 48, 48);
    ++sprite_count;
    *(g_enemy_sprite_list + sprite_count) = esat::SubSprite(g_spritesheet, 48, 48 * 2, 48, 24);
}

void EnemyUpdate()
{
    EnemNode *aux_enemy;
    SpawnEnemy();
    for(int i = 0; i < ListLength(g_enemy_list); ++i){
        aux_enemy = IndexList(g_enemy_list, i);
        // aux_enemy->enem.pos.x += aux_enemy->enem.dir.x * aux_enemy->enem.speed;
        // aux_enemy->enem.pos.y += aux_enemy->enem.dir.y * aux_enemy->enem.speed;
        // UpdateMovement();
        MovementRules(&aux_enemy->enem);
        MoveEnemy(&aux_enemy->enem);
        
    }
    if (esat::IsKeyDown('P'))
    {
        // g_enemy_list->sprite++;
        // g_enemy_list->sprite %= 13;
    }
}

void EnemyDraw()
{
    EnemNode *aux_enemy;
    for (int i = 0; i < ListLength(g_enemy_list); ++i)
    {
        aux_enemy = IndexList(g_enemy_list, i);
        DrawColorSquare({aux_enemy->enem.pos.x + 1, aux_enemy->enem.pos.y + 1}, aux_enemy->enem.color,
                        esat::SpriteWidth(*(g_enemy_sprite_list + aux_enemy->enem.sprite)) - 2,
                        esat::SpriteHeight(*(g_enemy_sprite_list + aux_enemy->enem.sprite)) - 2);
        esat::DrawSprite(*(g_enemy_sprite_list + aux_enemy->enem.sprite),
                         aux_enemy->enem.pos.x,
                         aux_enemy->enem.pos.y);
    }
}

void EnemyEnd()
{
    DelWholeList(&g_enemy_list);
    free(g_enemy_sprite_list);
}