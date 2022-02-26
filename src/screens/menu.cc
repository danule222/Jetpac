/**
 * @file menu.cc
 * @author Daniel Ramírez
 * @brief Lógica encargada de controlar
 * el menú principal.
 */

double g_current_menu_time, g_last_menu_time;
bool g_text_is_highlighted;

void StartMenuScreen()
{
  g_text_is_highlighted = true;
  g_last_menu_time = esat::Time();
}

void MenuScreenInput()
{
  if (esat::IsKeyPressed('1'))
    g_game_properties.players = 1;
  if (esat::IsKeyPressed('2'))
    g_game_properties.players = 2;
  if (esat::IsKeyPressed('3'))
    g_game_properties.input_type = 0;
  if (esat::IsKeyPressed('4'))
    g_game_properties.input_type = 1;
  if (esat::IsKeyPressed('5'))
    g_game_properties.state = 2;
}

void MenuScreenUpdate()
{
  g_current_menu_time = esat::Time();

  if ((g_current_menu_time - g_last_menu_time) >= 1000.0 * 0.35)
  {
    g_last_menu_time = esat::Time();
    g_text_is_highlighted = !g_text_is_highlighted;
  }

  ScreenCommonUpdate();
}

void MenuScreenDraw()
{
  DrawText(147, 99, "JETPAC GAME SELECTION", 30, c_white);

  switch (g_game_properties.players)
  {
  case 1:
    if (g_text_is_highlighted)
    {
      DrawColorSquare({144, 168}, c_white, 408, 24, false);
      DrawText(147, 171, "1   1 PLAYER GAME", 30, c_black);
    }
    else
    {
      DrawText(147, 171, "1   1 PLAYER GAME", 30, c_white);
    }
    DrawText(147, 219, "2   2 PLAYER GAME", 30, c_white);

    break;
  case 2:
    if (g_text_is_highlighted)
    {
      DrawColorSquare({144, 216}, c_white, 408, 24, false);
      DrawText(147, 219, "2   2 PLAYER GAME", 30, c_black);
    }
    else
    {
      DrawText(147, 219, "2   2 PLAYER GAME", 30, c_white);
    }
    DrawText(147, 171, "1   1 PLAYER GAME", 30, c_white);

    break;
  }

  switch (g_game_properties.input_type)
  {
  case 0:
    if (g_text_is_highlighted)
    {
      DrawColorSquare({144, 264}, c_white, 288, 24, false);
      DrawText(147, 267, "3   KEYBOARD", 30, c_black);
    }
    else
    {
      DrawText(147, 267, "3   KEYBOARD", 30, c_white);
    }
    DrawText(147, 315, "4   KEMPSTON JOYSTICK", 30, c_white);

    break;
  case 1:
    if (g_text_is_highlighted)
    {
      DrawColorSquare({144, 312}, c_white, 504, 24, false);
      DrawText(147, 315, "4   KEMPSTON JOYSTICK", 30, c_black);
    }
    else
    {
      DrawText(147, 315, "4   KEMPSTON JOYSTICK", 30, c_white);
    }
    DrawText(147, 267, "3   KEYBOARD", 30, c_white);

    break;
  }

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