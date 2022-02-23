/**
 * @file play.cc
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-02-19
 *
 * @copyright Copyright (c) 2022
 *
 */

void PlayInput()
{
  InputPlayer();
}

void PlayUpdate()
{
  EnemyUpdate();
  PlayerCollision();
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