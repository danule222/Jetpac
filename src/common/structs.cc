/**
 * @file structs.cc
 * @author Daniel Ramírez
 * @brief Estructuras usadas en el juego.
 */

#pragma region General

struct Color
{
  unsigned char r, g, b, alpha = 255;
};

struct EnemNode
{
  int index;
  Enemy enem;
  EnemNode *next;
};

#pragma endregion General

#pragma region Enemigos

struct Enemy
{
  esat::Vec2 pos;
  esat::Vec2 dir;
  esat::Vec3 color;
  float speed;
  bool alive;
  bool explode;
  int explode_counter;
  int sprite;
  int animation_counter;
};

struct EnemNode
{
  int index;
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