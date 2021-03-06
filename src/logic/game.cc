/**
 * @file game.cc
 * @author Daniel Ramírez
 * @brief Lógica relacionada con la estructura
 * principal del juego.
 */

void InitializeGame()
{
  g_game_properties = {0, 0, 1, 0};
  g_spritesheet = esat::SpriteFromFile("../assets/spritesheet.png");
  esat::DrawSetTextFont("../assets/zx_spectrum-7.ttf");

  StartSound();
  StartPlayerAssets();
  InitSpritesPlayerAssets();
  InitShots();
  InitSpritesShots();
  StartScreenCommon();
  StartLoadingScreen();
  StartMenuScreen();
  EnemyStart();
  PowerUpsStart();
  ShipStart();
  StartSaveGame();
}

void FinalizeGame()
{
  EnemyEnd();
  PowerUpsEnd();
  EndLoadingScreen();
  EndScreenCommon();
  EndPlayer();
  ShipEnd();
  EndSound();
  EndShots();
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