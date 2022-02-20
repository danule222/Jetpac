/**
 * @file utils.cc
 * @author Daniel Ramírez
 * @brief Funciones genéricas usadas en el
 * juego.
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

/**
 * @brief Draws text on screen.
 *
 * @param x X Coord where the text will appear.
 * @param y Y Coord where the text will appear.
 * @param text The text that's going to appear on screen.
 * @param size The size of the font.
 * @param color Color of the text defined by the Color struct.
 */
void DrawText(float x, float y, const char *text, float size, Color color)
{
  esat::DrawSetFillColor(color.r, color.g, color.b, color.alpha);
  esat::DrawSetTextSize(size);
  esat::DrawText(x - 3, y + 18, text);
}