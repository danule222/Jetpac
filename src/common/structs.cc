/**
 * @file structs.cc
 * @author Daniel Ramírez
 * @brief Estructuras usadas en el juego.
 */

#pragma region Matematicas

struct Vec2
{
  float x, y;
};

struct Vec3
{
  float x, y, z;
};

#pragma endregion Matematicas

#pragma region Enemigos

struct Enemy
{
  Vec2 pos;
  Vec2 dir;
  Vec3 color;
  float speed;
  bool alive;
  bool explode;
  int explode_counter;
  int sprite;
  int animation_counter;
};

#pragma endregion Enemigos

#pragma region Nave

struct powerups
{
  Vec2 pos;
  float gravedad;
  float contador;
};

#pragma endregion Nave