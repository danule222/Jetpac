/**
 * @file common.cc
 * @author Daniel Ramírez
 * @brief Lógica compartida entre
 * las diferentes pantallas.
 */

bool g_p1_playing = true;
char g_score_1[] = {"000000\0"};
char g_score_2[] = {"000000\0"};
char g_hiScore[] = {"000000\0"};

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
  if (g_game_properties.hiScore < g_player.score)
    g_game_properties.hiScore = g_player.score;

  if (g_p1_playing)
  {
    sprintf(g_score_1, "%06d\n", g_player.score);
  }
  else
  {
    sprintf(g_score_2, "%06d\n", g_player.score);
  }

  sprintf(g_hiScore, "%06d\n", g_game_properties.hiScore);
}

void ScreenCommonDraw()
{
  DrawText(75, 3, "1UP", 30, c_white);
  DrawText(363, 3, "HI", 30, c_cyan);
  DrawText(651, 3, "2UP", 30, c_white);
  DrawText(27, 27, g_score_1, 30, c_yellow);
  DrawText(315, 27, g_hiScore, 30, c_yellow);
  DrawText(603, 27, g_score_2, 30, c_yellow);

  SaveGameDraw();
}