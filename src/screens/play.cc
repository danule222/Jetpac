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
  PlayerShot();
}

void PlayUpdate()
{
  EnemyUpdate();
  MovementsShip();
  PlayerCollision();
  MovementsPowerUps();
  CalculateCollision();
  IncreaseCounter();
  ScreenCommonUpdate();
  MoveShots();
}

void PlayDraw()
{
  EnemyDraw();
  DrawAssets();
  ShipDraw();
  PowerUpsDraw();
  DrawPlayer();
  DrawShotSprites();
  
  ScreenCommonDraw();
}

void PlayScreen()
{
  PlayInput();
  PlayUpdate();
  PlayDraw();
}