/**
 * @file utils.cc
 * @author Daniel Ramírez
 * @brief Estructuras usadas en el juego.
 */

void DrawColorSquare(esat::Vec2 pos, Color color, int width,
                     int height, bool stroke = false)
{
  float *vertices = nullptr;

  vertices = (float *)malloc(sizeof(float) * 10);

  *(vertices + 0) = pos.x;
  *(vertices + 1) = pos.y;

  *(vertices + 2) = pos.x + width;
  *(vertices + 3) = pos.y;

  *(vertices + 4) = pos.x + width;
  *(vertices + 5) = pos.y + height;

  *(vertices + 6) = pos.x;
  *(vertices + 7) = pos.y + height;

  *(vertices + 8) = pos.x;
  *(vertices + 9) = pos.y;

  esat::DrawSetFillColor(color.r, color.g, color.b, color.alpha);
  esat::DrawSolidPath(vertices, 5, stroke);

  free(vertices);
  vertices = nullptr;
}