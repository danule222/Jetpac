/**
 * @file common.cc
 * @author Daniel Ramírez
 * @brief Lógica compartida entre
 * las diferentes pantallas.
 */

void StartScreenCommon()
{
}

void EndScreenCommon()
{
}

void ScreenCommonInput()
{
  SaveGameInput();
}

void ScreenCommonUpdate()
{
}

void ScreenCommonDraw()
{
  DrawText(75, 3, "1UP", 30, c_white);
  DrawText(363, 3, "HI", 30, c_cyan);
  DrawText(651, 3, "2UP", 30, c_white);
  DrawText(27, 27, "000000", 30, c_yellow);
  DrawText(315, 27, "000000", 30, c_yellow);
  DrawText(603, 27, "000000", 30, c_yellow);

  SaveGameDraw();
}