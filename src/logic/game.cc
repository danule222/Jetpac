/**
 * @file game.cc
 * @author Daniel Ramírez
 * @brief Lógica relacionada con la estructura
 * principal del juego.
 */

void InitializeGame()
{
  g_game_properties = {0, 2, 1, 0};
  g_spritesheet = esat::SpriteFromFile("../assets/spritesheet.png");
  esat::DrawSetTextFont("../assets/zx_spectrum-7.ttf");

  StartScreenCommon();
  StartLoadingScreen();
  StartMenuScreen();
  EnemyStart();
  PowerUpsStart();
}

void FinalizeGame()
{
  EnemyEnd();
  PowerUpsEnd();
  EndLoadingScreen();
  EndScreenCommon();

  esat::SpriteRelease(g_spritesheet);
}

void Game()
{
  switch (g_game_properties.state)
  {
  case 0:
    LoadingScreen();
    break;
  case 1:
    MenuScreen();
    break;
  case 2:
    PlayScreen();
    break;
  }
}