/**
 * @file definitions.cc
 * @brief Archivo que contiene todas
 * las constantes y variables usadas
 * por el juego.
 */

// Screen resolution
// ZX Spectrum res.: 256×192 pixels
const int kWidth = 768, kHeight = 576;

// Game Properties
Game g_game_properties;

// Sprite Sheet
esat::SpriteHandle g_spritesheet;

// COLORS

Color c_dark_blue = {0, 0, 224};
Color c_blue = {0, 0, 255};
Color c_dark_red = {224, 0, 0};
Color c_red = {0, 0, 255};
Color c_dark_magenta = {224, 0, 224};
Color c_magenta = {255, 0, 255};
Color c_dark_green = {0, 224, 0};
Color c_green = {0, 255, 0};
Color c_dark_cyan = {0, 224, 224};
Color c_cyan = {0, 255, 255};
Color c_dark_yellow = {224, 224, 0};
Color c_yellow = {255, 255, 0};
Color c_black = {0, 0, 0};
Color c_grey = {224, 224, 224};
Color c_white = {255, 255, 255};