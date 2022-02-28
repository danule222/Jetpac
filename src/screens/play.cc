/**
 * @file play.cc
 * @author Daniel Ramírez
 * @brief Lógica encargada de controlar
 * la partida.
 */

void PlayInput()
{
  InputPlayer();

  ScreenCommonInput();
}

void PlayUpdate()
{
  EnemyUpdate();
  MovementsShip();
  PlayerCollision();
  MovementsPowerUps();
  CalculateCollision();

  ScreenCommonUpdate();
}

void PlayDraw()
{
  EnemyDraw();

  DrawAssets();
  ShipDraw();
  PowerUpsDraw();
  DrawPlayer();

  ScreenCommonDraw();
}

void PlayScreen()
{
  PlayInput();
  PlayUpdate();
  PlayDraw();
}