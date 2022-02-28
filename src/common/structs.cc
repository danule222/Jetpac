/**
 * @file structs.cc
 * @author Daniel Ramírez
 * @brief Estructuras usadas en el juego.
 */

#pragma region General

struct Game
{
  int hiScore;
  // 0 - Cargando | 1 - Menú | 2 - Juego
  int state;
  int players;
  // 0 - Teclado | 1 - Joystick
  int input_type;
};

struct Color
{
  unsigned char r, g, b, alpha = 255;
};

#pragma endregion General

#pragma region Enemigos

struct Enemy
{
  esat::Vec2 pos;
  esat::Vec2 dir;
  Color color;
  float speed;
  bool explode;
  bool spawn;
  int explode_counter;
  int sprite;
  int animation_counter;
};

struct EnemNode
{
  Enemy enem;
  EnemNode *next;
};

struct Shot
{
  esat::Vec2 pos;
  bool alive;
  int sprite;
  int frame_counter;
  int facing_right;
  int color;
};

#pragma endregion Enemigos

#pragma region Nave

struct powerups
{
  esat::Vec2 pos;
  Color color;
  float gravedad = 1;
  float contador;
  bool estado = false;
  int score;
  int numero;
};

struct NaveJetpac
{
  esat::Vec2 pos;
  float contador;
  bool posicionfinal;
  bool estado;
  bool recoger = false;
  bool mantenernave;
  bool caidan;
};

#pragma endregion Nave

#pragma region Jugador

struct Jugador
{
  esat::Vec2 pos;
  Color color;
  // float speed;
  float grav = 4.8;
  bool alive;
  bool explode;
  int sprite;
  int feet; // int
  int score;
  int nivel;
  int contDisp;
  bool puedeDisp;
  int lifes;
};

#pragma endregion Jugador

#pragma region asset

struct Asset
{
  esat::Vec2 pos;
  int sprite;
  bool dibujar;
};

#pragma endregion asset

#pragma region SaveGame

struct TSaveGame
{
  Game game_state;
  struct tm date;
  int p1_score, p2_score;
};

#pragma endregion SaveGame
