/**
 * @file structs.cc
 * @author Daniel Ramírez
 * @brief Estructuras usadas en el juego.
 */

#pragma region General

struct Game
{
  int hiScore;
  // @brief 0 - Cargando | 1 - Menú | 2 - Juego
  int state;
  int players;
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
  bool alive;
  bool explode;
  int explode_counter;
  int sprite;
  int animation_counter;
};

struct EnemNode
{
  Enemy enem;
  EnemNode *next;
};

#pragma endregion Enemigos

#pragma region Nave

struct PowerUp
{
  esat::Vec2 pos;
  float gravedad;
  float contador;
};

#pragma endregion Nave