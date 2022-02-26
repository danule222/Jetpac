/**
 * @file save_game.cc
 * @author Daniel Ramírez
 * @brief Funciones encargadas del
 * guardado y carga de partida.
 */

double g_last_save_warning_time;

void StartSaveGame()
{
  g_last_save_warning_time = esat::Time();
}

void SaveGame()
{
  FILE *f;
  time_t tiempo;
  struct tm date;

  time(&tiempo);
  _localtime64_s(&date, &tiempo);

  TSaveGame save_game = {g_game_properties, date};

  f = fopen("save.dat", "ab");
  fwrite(&save_game, sizeof(save_game), 1, f);
  fclose(f);
}

void LoadGame()
{
}

void SaveGameInput()
{
  // Guardar partida
  if (esat::IsSpecialKeyDown(esat::kSpecialKey_F1))
  {
    SaveGame();
    g_last_save_warning_time = esat::Time();
  }
  // Menú de cargar partida
  if (esat::IsSpecialKeyDown(esat::kSpecialKey_F2))
  {
  }
  // Cargar última partida
  if (esat::IsSpecialKeyDown(esat::kSpecialKey_F3))
  {
    LoadGame();
  }
}

void SaveGameDraw()
{
  if (esat::Time() - g_last_save_warning_time <= 1000 * 3)
  {
    DrawColorSquare({261, 51}, c_white, 246, 30, false);
    DrawText(267, 57, "GAME SAVED", 30, c_black);
  }
}