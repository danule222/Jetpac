/**
 * @file player.cc
 * @author Juan S. Avilés
 * @brief Funciones de logica del Jugador
 *
 */

esat::SpriteHandle *g_sprites_jugador, *g_sprites_assets;
Jugador g_player, g_player_aux;
Asset *g_floor_pointer;
Asset *g_platform1, *g_platform2, *g_platform3;
int contadorFeetR = 3;
int contadorFeetL = 19;
int contadorRIGHT = 0;
int contadorLEFT = 0;
int contadorVivo = 0;
bool g_p1_playing = true;

int HOLAP;
// bool g_grav = true;

void StartPlayerAssets()
{
    int i = 0;
    int contador = 0;
    int contador2 = 0;
    int contador3 = 0;

    g_player.sprite = 18;
    g_player.pos.x = kWidth / 2;
    g_player.pos.y = kHeight - 100;
    g_player.alive = true;
    g_player.nivel = 0;
    g_player.score = 0;
    g_player.lifes = 3;

    g_player_aux.sprite = 18;
    g_player_aux.pos.x = kWidth / 2;
    g_player_aux.pos.y = kHeight - 100;
    g_player_aux.alive = false;
    g_player_aux.nivel = 0;
    g_player_aux.score = 0;
    g_player_aux.lifes = 3;

    g_floor_pointer = (Asset *)malloc(32 * sizeof(Asset));
    g_platform1 = (Asset *)malloc(6 * sizeof(Asset));
    g_platform2 = (Asset *)malloc(4 * sizeof(Asset));
    g_platform3 = (Asset *)malloc(6 * sizeof(Asset));

    // SUELOS
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

    // PLATAFORMAS 1

    for (int j = 96; j < 240; j += 24)
    {
        (g_platform1 + contador)->pos.x = j;
        ++contador;
    }
    for (int x = 0; x < 6; ++x)
    {
        (g_platform1 + x)->pos.y = 216;
        if (x > 0 && x < 5)
        {
            (g_platform1 + x)->sprite = 1;
        }
    }
    (g_platform1 + 0)->sprite = 0;
    (g_platform1 + 5)->sprite = 2;

    // PLATAFORMAS 2

    for (int j = 360; j < 456; j += 24)
    {
        (g_platform2 + contador2)->pos.x = j;
        ++contador2;
    }
    for (int x = 0; x < 4; ++x)
    {
        (g_platform2 + x)->pos.y = 288;
        if (x > 0 && x < 3)
        {
            (g_platform2 + x)->sprite = 1;
        }
    }
    (g_platform2 + 0)->sprite = 0;
    (g_platform2 + 3)->sprite = 2;

    // PLATAFORMAS 3

    for (int j = 576; j < 720; j += 24)
    {
        (g_platform3 + contador3)->pos.x = j;
        ++contador3;
    }
    for (int x = 0; x < 6; ++x)
    {
        (g_platform3 + x)->pos.y = 144;
        if (x > 0 && x < 5)
        {
            (g_platform3 + x)->sprite = 1;
        }
    }
    (g_platform3 + 0)->sprite = 0;
    (g_platform3 + 5)->sprite = 2;
}

void InitSpritesPlayerAssets()
{
    int sprite_count = 0;
    g_sprites_assets = (esat::SpriteHandle *)malloc(3 * sizeof(esat::SpriteHandle));
    g_sprites_jugador = (esat::SpriteHandle *)malloc(70 * sizeof(esat::SpriteHandle));
    for (int i = 0; i < 20; ++i)
    {
        *(g_sprites_jugador + sprite_count) = esat::SubSprite(g_spritesheet, i * 48, 96, 48, 48);
        ++sprite_count;
    }
    for (int j = 0; j < 20; ++j)
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
    if (esat::IsSpecialKeyPressed(esat::kSpecialKey_Right) && CheckCollision(0, 552, 768, 24, g_player.pos.x, g_player.pos.y, 48, 72) && g_player.alive ||
        esat::IsSpecialKeyPressed(esat::kSpecialKey_Right) && CheckCollision(96, 216, 144, 24, g_player.pos.x, g_player.pos.y, 48, 72) &&
            g_player.pos.y < 150 && g_player.alive ||
        esat::IsSpecialKeyPressed(esat::kSpecialKey_Right) && CheckCollision(360, 288, 96, 24, g_player.pos.x, g_player.pos.y, 48, 72) &&
            g_player.pos.y < 225 && g_player.alive)
    {
        g_player.pos.x += 3;
        g_player.sprite = 18;
        contadorRIGHT++;
        if (contadorRIGHT >= 5)
        {
            if (contadorFeetR >= 25)
            {
                contadorFeetR = 19;
            }
            contadorFeetR += 2;
            contadorRIGHT = 0;
        }
    }
    if (esat::IsSpecialKeyPressed(esat::kSpecialKey_Right) && !CheckCollision(0, 552, 768, 24, g_player.pos.x, g_player.pos.y, 48, 72) &&
            !CheckCollision(96, 216, 144, 24, g_player.pos.x, g_player.pos.y, 48, 72) && g_player.alive ||
        esat::IsSpecialKeyPressed(esat::kSpecialKey_Right) &&
            !CheckCollision(360, 288, 96, 24, g_player.pos.x, g_player.pos.y, 48, 72) && g_player.alive)
    {
        g_player.pos.x += 5;
        g_player.sprite = 26;
    }
    if (esat::IsSpecialKeyPressed(esat::kSpecialKey_Left) && CheckCollision(0, 552, 768, 24, g_player.pos.x, g_player.pos.y, 48, 72) && g_player.alive ||
        esat::IsSpecialKeyPressed(esat::kSpecialKey_Left) && CheckCollision(96, 216, 144, 24, g_player.pos.x, g_player.pos.y, 48, 72) &&
            g_player.pos.y < 150 && g_player.alive ||
        esat::IsSpecialKeyPressed(esat::kSpecialKey_Left) && CheckCollision(360, 288, 96, 24, g_player.pos.x, g_player.pos.y, 48, 72) &&
            g_player.pos.y < 225 && g_player.alive)
    {
        g_player.pos.x -= 3;
        g_player.sprite = 2;
        contadorLEFT++;
        if (contadorLEFT >= 5)
        {
            if (contadorFeetL >= 9)
            {
                contadorFeetL = 3;
            }
            contadorFeetL += 2;
            contadorLEFT = 0;
        }
    }
    if (esat::IsSpecialKeyPressed(esat::kSpecialKey_Left) && !CheckCollision(0, 552, 768, 24, g_player.pos.x, g_player.pos.y, 48, 72) &&
            !CheckCollision(96, 216, 144, 24, g_player.pos.x, g_player.pos.y, 48, 72) && g_player.alive ||
        esat::IsSpecialKeyPressed(esat::kSpecialKey_Left) &&
            !CheckCollision(360, 288, 96, 24, g_player.pos.x, g_player.pos.y, 48, 72) && g_player.alive)
    {
        g_player.pos.x -= 5;
        g_player.sprite = 10;
    }

    if (esat::IsSpecialKeyPressed(esat::kSpecialKey_Up) && !CheckCollision(96, 216, 144, 40, g_player.pos.x, g_player.pos.y, 48, 72) &&
            g_player.pos.y > 55 && g_player.alive ||
        esat::IsSpecialKeyPressed(esat::kSpecialKey_Left) && CheckCollision(96, 216, 144, 24, g_player.pos.x, g_player.pos.y, 48, 72) &&
            g_player.pos.y < 150 && g_player.alive)
    {
        if (g_player.grav > -3)
        {
            g_player.grav -= 1.5;
        }
    }
    if (esat::IsSpecialKeyPressed(esat::kSpecialKey_Space))
    {
        // AQUI EL DISPARO PERO NO ESTA
    }
    g_player.pos.y += g_player.grav;
}

void PlayerCollision()
{
    //  && subirnave && bajarnave
    /*
    if(!g_player.alive) {
        contadorVivo++;
    }
    */
    if (CheckCollision(0, 552, 768, 24, g_player.pos.x, g_player.pos.y, 48, 72))
    {
        g_player.grav = 0;
        g_player.pos.y = 480;
    }
    if (CheckCollision(96, 216, 144, 24, g_player.pos.x, g_player.pos.y, 48, 72))
    {
        if (g_player.pos.y < 150 && g_player.pos.x > 95 && g_player.pos.x < 240)
        {
            g_player.grav = 0;
            g_player.pos.y = 144;
        }
    }
    if (CheckCollision(360, 288, 96, 24, g_player.pos.x, g_player.pos.y, 48, 72))
    {
        if (g_player.pos.y < 225 && g_player.pos.x > 360 && g_player.pos.x < 460)
        {
            g_player.grav = 0;
            g_player.pos.y = 218;
        }
    }
    if (CheckCollision(576, 144, 144, 24, g_player.pos.x, g_player.pos.y, 48, 72))
    {
        if (g_player.pos.y < 72 && g_player.pos.x > 576 && g_player.pos.x < 720)
        {
            g_player.grav = 0;
            g_player.pos.y = 70;
        }
    }
    else
    {
        if (g_player.grav < 4.8)
        {
            g_player.grav += 0.5;
        }
    }
    /*
    if(contadorVivo >= 300) {
        g_player.alive = true;
        contadorVivo = 0;
        g_player.pos.x = kWidth / 2;
        g_player.pos.y = kHeight - 100;
    }
    */
    /*
    if(CollisionEnemyWihtPlayer(g_player.pos.x, g_player.pos.y, 48, 72)) {
        g_player.alive = false;
    }
    */
}

void PlayerShot()
{
    if (esat::IsSpecialKeyPressed(esat::kSpecialKey_Space) && g_player.puedeDisp)
    {
        if (g_player.sprite < 18)
        {
            g_player.puedeDisp = false;
            SpawnShot(g_player.pos.x - 24, g_player.pos.y + 30, false);
        }

        else
        {
            g_player.puedeDisp = false;
            SpawnShot(g_player.pos.x + 48, g_player.pos.y + 30, true);
        }
    }
}

void IncreaseCounter()
{
    if (!g_player.puedeDisp)
    {
        g_player.contDisp++;
    }

    if (g_player.contDisp > 12)
    {
        g_player.puedeDisp = true;
        g_player.contDisp = 0;
    }
}

void DrawAssets()
{
    esat::Vec2 pos_floor_masc = {0, 552};
    esat::Vec2 pos_plat1 = {96, 216};
    esat::Vec2 pos_plat2 = {360, 288};
    esat::Vec2 pos_plat3 = {576, 144};
    DrawColorSquare(pos_floor_masc, c_yellow, 768, 24);
    DrawColorSquare(pos_plat1, c_green, 144, 24);
    DrawColorSquare(pos_plat2, c_green, 96, 24);
    DrawColorSquare(pos_plat3, c_green, 144, 24);
    for (int i = 0; i < 32; ++i)
    {
        esat::DrawSprite(*(g_sprites_assets + (g_floor_pointer + i)->sprite), (g_floor_pointer + i)->pos.x, (g_floor_pointer + i)->pos.y);
    }
    for (int i = 0; i < 6; ++i)
    {
        esat::DrawSprite(*(g_sprites_assets + (g_platform1 + i)->sprite), (g_platform1 + i)->pos.x, (g_platform1 + i)->pos.y);
    }
    for (int i = 0; i < 4; ++i)
    {
        esat::DrawSprite(*(g_sprites_assets + (g_platform2 + i)->sprite), (g_platform2 + i)->pos.x, (g_platform2 + i)->pos.y);
    }
    for (int i = 0; i < 6; ++i)
    {
        esat::DrawSprite(*(g_sprites_assets + (g_platform3 + i)->sprite), (g_platform3 + i)->pos.x, (g_platform3 + i)->pos.y);
    }
}

void DrawPlayer()
{
    if (g_player.alive)
    {
        esat::Vec2 pos_masc_player = {g_player.pos.x, g_player.pos.y};
        DrawColorSquare(pos_masc_player, c_white, 48, 69);

        if (!CheckCollision(0, 552, 768, 24, g_player.pos.x, g_player.pos.y, 48, 72))
        {
            esat::DrawSprite(*(g_sprites_jugador + g_player.sprite), g_player.pos.x, g_player.pos.y);
            esat::DrawSprite(*(g_sprites_jugador + g_player.sprite + 1), g_player.pos.x, g_player.pos.y + 47);
        }
        if (CheckCollision(0, 552, 768, 24, g_player.pos.x, g_player.pos.y, 48, 72) && g_player.sprite < 18)
        {
            esat::DrawSprite(*(g_sprites_jugador + g_player.sprite), g_player.pos.x, g_player.pos.y);
            esat::DrawSprite(*(g_sprites_jugador + contadorFeetL), g_player.pos.x, g_player.pos.y + 47);
        }
        if (CheckCollision(0, 552, 768, 24, g_player.pos.x, g_player.pos.y, 48, 72) && g_player.sprite >= 18)
        {
            esat::DrawSprite(*(g_sprites_jugador + g_player.sprite), g_player.pos.x, g_player.pos.y);
            esat::DrawSprite(*(g_sprites_jugador + contadorFeetR), g_player.pos.x, g_player.pos.y + 47);
        }
    }
}

//  || !CheckCollision(96,216,144,24, g_player.pos.x, g_player.pos.y, 48, 72) && g_player.sprite <= 18
//   || !CheckCollision(96,216,144,24, g_player.pos.x, g_player.pos.y, 48, 72) && g_player.sprite >= 18

void EndPlayer()
{
    free(g_sprites_jugador);
    free(g_sprites_assets);
    free(g_floor_pointer);
    free(g_platform1);
    free(g_platform2);
    free(g_platform3);
}
