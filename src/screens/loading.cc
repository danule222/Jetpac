/**
 * @file loading.cc
 * @author Daniel Ramírez
 * @brief Lógica encargada de controlar
 * la pantalla de carga.
 */

esat::SpriteHandle g_ls_sprite_0;
esat::SpriteHandle g_ls_sprite_1;
double g_initial_loading_screen_time,
    g_current_loading_screen_time, g_last_loading_screen_time;
int loading_screen_sprite;

void StartLoadingScreen()
{
  g_initial_loading_screen_time = esat::Time();
  g_last_loading_screen_time = esat::Time();
  loading_screen_sprite = 0;

  g_ls_sprite_0 = esat::SubSprite(g_spritesheet, 0, 624, 768, 528);
  g_ls_sprite_1 = esat::SubSprite(g_spritesheet, 0, 1152, 768, 528);
}

void EndLoadingScreen()
{
  esat::SpriteRelease(g_ls_sprite_0);
  esat::SpriteRelease(g_ls_sprite_1);
}

void LoadingScreenUpdate()
{
  g_current_loading_screen_time = esat::Time();

  // Parpadear "Jetpac is loading"
  if ((g_current_loading_screen_time - g_last_loading_screen_time) >=
      1000.0 * 0.35)
  {
    g_last_loading_screen_time = esat::Time();
    loading_screen_sprite = loading_screen_sprite == 0 ? 1 : 0;
  }

  // Tiempo que la pantalla de carga será visible
  if ((g_current_loading_screen_time - g_initial_loading_screen_time) >=
      1000.0 * 7)
  {
    g_last_loading_screen_time = esat::Time();
    g_game_properties.state = 1;
  }
}

void LoadingScreenDraw()
{
  switch (loading_screen_sprite)
  {
  case 0:
    esat::DrawSprite(g_ls_sprite_0, 0, 0);
    break;
  case 1:
    esat::DrawSprite(g_ls_sprite_1, 0, 0);
    break;
  }
}

void LoadingScreen()
{
  LoadingScreenUpdate();
  LoadingScreenDraw();
}