/**
 * @file menu.cc
 * @author Daniel Ramírez
 * @brief Lógica encargada de controlar
 * el menú principal.
 */

void StartMenuScreen()
{
}

void EndMenuScreen()
{
}

void MenuScreenInput()
{
}

void MenuScreenUpdate()
{
  ScreenCommonUpdate();
}

void MenuScreenDraw()
{
  DrawText(147, 99, "JETPAC GAME SELECTION", 30, c_white);
  DrawText(147, 171, "1   1 PLAYER GAME", 30, c_white);
  DrawText(147, 219, "2   2 PLAYER GAME", 30, c_white);
  DrawText(147, 267, "3   KEYBOARD", 30, c_white);
  DrawText(147, 315, "4   KEMPSTON JOYSTICK", 30, c_white);
  DrawText(147, 459, "5   START GAME", 30, c_white);
  DrawText(3, 555, "©1983 A.C.G. ALL RIGHTS RESERVED", 30, c_white);

  ScreenCommonDraw();
}

void MenuScreen()
{
  MenuScreenInput();
  MenuScreenUpdate();
  MenuScreenDraw();
}