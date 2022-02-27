/**
 * @file utils.cc
 * @author Daniel Ramírez
 * @brief Funciones genéricas usadas en el
 * juego.
 */

void DrawColorSquare(esat::Vec2 pos, Color color, int width,
                     int height, bool stroke = true)
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

  esat::DrawSetStrokeColor(0, 0, 0);
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

/**
 * @brief Returns true if there is a collision.
 *
 * @param x1 Position X of the first sprite.
 * @param y1 Position Y of the first sprite.
 * @param w1 Width of the first sprite.
 * @param h1 Height of the  first sprite.
 * @param x2 Position X of the second sprite.
 * @param y2 Position Y of the second sprite.
 * @param w2 Width of the second sprite.
 * @param h2 Height of the  second sprite.
 * @return true There is collision.
 * @return false There is no collision.
 */
bool CheckCollision(int x1, int y1, int w1, int h1,
                    int x2, int y2, int w2, int h2)
{
  for (int i = y1; i <= h1 + y1; i++)
  {
    for (int j = x1; j <= w1 + x1; j++)
    {
      if (j >= x2 && j <= x2 + w2 && i >= y2 && i <= y2 + h2)
        return true;
    }
  }

  return false;
}