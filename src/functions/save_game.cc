/**
 * @file save_game.cc
 * @author Daniel Ramírez
 * @brief Funciones encargadas del
 * guardado y carga de partida.
 */

double g_last_save_warning_time;
// 0 - Save | 1 - Load
int g_warning_type = 0;

void StartSaveGame()
{
  g_last_save_warning_time = esat::Time();
}

bool SaveGame()
{
  FILE *f;
  time_t tiempo;
  struct tm date;

  time(&tiempo);
  _localtime64_s(&date, &tiempo);

  // TODO: Guardar puntuación del J1 y J2
  TSaveGame save_game = {g_game_properties, date, 0, 0};

  f = fopen("save.dat", "wb");
  fwrite(&save_game, sizeof(save_game), 1, f);
  fclose(f);

  return true;
}

bool LoadGame()
{
  FILE *f;
  TSaveGame save_game;

  if ((f = fopen("save.dat", "rb")) == NULL)
  {
    return false;
  }
  else
  {
    while (fread(&save_game, sizeof(save_game), 1, f))
    {
      g_game_properties = save_game.game_state;
    }
    fclose(f);
  }

  return true;
}

void SaveGameInput()
{
  // Guardar partida
  if (esat::IsSpecialKeyDown(esat::kSpecialKey_F1))
  {
    if (SaveGame())
    {
      g_warning_type = 0;
    }
    else
    {
      g_warning_type = -1;
    }
    g_last_save_warning_time = esat::Time();
  }
  // Cargar última partida
  if (esat::IsSpecialKeyDown(esat::kSpecialKey_F2))
  {
    if (LoadGame())
    {
      g_warning_type = 1;
    }
    else
    {
      g_warning_type = -1;
    }
    g_last_save_warning_time = esat::Time();
  }
}

void SaveGameDraw()
{
  if (esat::Time() - g_last_save_warning_time <= 1000 * 3)
  {
    switch (g_warning_type)
    {
    case 0:
      DrawColorSquare({261, 51}, c_white, 246, 30, false);
      DrawText(267, 57, "GAME SAVED", 30, c_black);
      break;
    case 1:
      DrawColorSquare({261, 51}, c_white, 270, 30, false);
      DrawText(267, 57, "GAME LOADED", 30, c_black);
      break;
    case -1:
      DrawColorSquare({309, 51}, c_red, 126, 30, false);
      DrawText(315, 57, "ERROR", 30, c_white);
      break;
    }
  }
}