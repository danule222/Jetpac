/**
 * @file play.cc
 * @author Daniel Ramírez
 * @brief Lógica encargada de controlar
 * la partida.
 */

void PlayInput()
{
  InputPlayer();
}

void PlayUpdate()
{
  EnemyUpdate();
  PlayerCollision();
  CalculateCollision();

  ScreenCommonUpdate();
}

void PlayDraw()
{
  EnemyDraw();
  DrawAssets();
  DrawPlayer();

  ScreenCommonDraw();
}

void PlayScreen()
{
  PlayInput();
  PlayUpdate();
  PlayDraw();
}