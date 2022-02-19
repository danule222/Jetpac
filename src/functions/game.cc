/**
 * @file game.cc
 * @author Daniel Ramírez
 * @brief Lógica relacionada con la estructura
 * principal del juego.
 */

void InitializeGame()
{
  g_game_properties = {0, 0, 1};
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