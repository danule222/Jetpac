/**
 * @file player.cc
 * @author Juan S. Avilés
 * @brief Funciones de logica del Jugador
 *
 */

esat::SpriteHandle *g_sprites_jugador, *g_sprites_assets;
Jugador g_player;
Asset *g_floor_pointer;
// bool g_grav = true;

void StartPlayerAssets()
{
    int i = 0;
    g_player.sprite = 18;
    g_player.pos.x = kWidth / 2;
    g_player.pos.y = kHeight - 100;

    g_floor_pointer = (Asset *)malloc(32 * sizeof(Asset));
    for (int j = 0; j < 768; j += 24)
    {
        (g_floor_pointer + i)->pos.x = j;
        ++i;
    }
    for (int x = 0; x < 32; ++x)
    {
        (g_floor_pointer + x)->pos.y = 552;
        if (x > 0 && x < 31)
        {
            (g_floor_pointer + x)->sprite = 1;
        }
    }
    (g_floor_pointer + 0)->sprite = 0;
    (g_floor_pointer + 31)->sprite = 2;
}

void InitSpritesPlayerAssets()
{
    int sprite_count = 0;
    g_sprites_assets = (esat::SpriteHandle *)malloc(3 * sizeof(esat::SpriteHandle));
    g_sprites_jugador = (esat::SpriteHandle *)malloc(70 * sizeof(esat::SpriteHandle));
    for (int i = 0; i < 35; ++i)
    {
        *(g_sprites_jugador + sprite_count) = esat::SubSprite(g_spritesheet, i * 48, 96, 48, 48);
        ++sprite_count;
    }
    for (int j = 0; j < 35; ++j)
    {
        *(g_sprites_jugador + sprite_count) = esat::SubSprite(g_spritesheet, j * 48, 144, 48, 48);
        ++sprite_count;
    }
    *(g_sprites_assets + 0) = esat::SubSprite(g_spritesheet, 0, 48, 24, 24);
    *(g_sprites_assets + 1) = esat::SubSprite(g_spritesheet, 48, 48, 24, 24);
    *(g_sprites_assets + 2) = esat::SubSprite(g_spritesheet, 96, 48, 24, 24);
}

void InputPlayer()
{

    if (esat::IsSpecialKeyPressed(esat::kSpecialKey_Right))
    {
        g_player.pos.x += 5;
        g_player.sprite = 18;
    }
    if (esat::IsSpecialKeyPressed(esat::kSpecialKey_Left))
    {
        g_player.pos.x -= 5;
        g_player.sprite = 2;
    }
    if (esat::IsSpecialKeyPressed(esat::kSpecialKey_Space))
    {
        if (g_player.grav > -3)
        {
            g_player.grav -= 1.5;
        }
    }
    g_player.pos.y += g_player.grav;
}

void PlayerCollision()
{
    if (CheckCollision(0, 552, 768, 24, g_player.pos.x, g_player.pos.y, 48, 72))
    {
        g_player.grav = 0;
        g_player.pos.y = 480;
    }
    else
    {
        if (g_player.grav < 4.8)
        {
            g_player.grav += 0.5;
        }
    }
}

void DrawAssets()
{
    esat::Vec2 pos_floor_masc = {0, 552};
    DrawColorSquare(pos_floor_masc, c_yellow, 768, 24);
    for (int i = 0; i < 32; ++i)
    {
        esat::DrawSprite(*(g_sprites_assets + (g_floor_pointer + i)->sprite), (g_floor_pointer + i)->pos.x, (g_floor_pointer + i)->pos.y);
    }
}

void DrawPlayer()
{
    esat::Vec2 pos_masc_player = {g_player.pos.x, g_player.pos.y + 1};
    DrawColorSquare(pos_masc_player, c_white, 48, 69);
    esat::DrawSprite(*(g_sprites_jugador + g_player.sprite), g_player.pos.x, g_player.pos.y);
    esat::DrawSprite(*(g_sprites_jugador + g_player.sprite + 1), g_player.pos.x, g_player.pos.y + 47);
}

void EndPlayer()
{
    free(g_sprites_jugador);
    free(g_sprites_assets);
    free(g_floor_pointer);
}
