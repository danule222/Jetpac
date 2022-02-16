/**
 * @file Jetpac.cc
 *
 * @brief Primary file of the game where the main function is.
 */

// Generic includes
#include <esat/window.h>
#include <esat/draw.h>
#include <esat/input.h>
#include <esat/sprite.h>
#include <esat/time.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// Personal includes
// Common

// Screens

// Functions
#include "./functions/enemy.cc"
// ZX Spectrum res.: 256×192 pixels
int WIDTH = 768, HEIGHT = 576;

unsigned char fps = 60;
double current_time, last_time;

int esat::main(int argc, char **argv)
{
	srand(time(NULL));

	esat::WindowInit(WIDTH, HEIGHT);
	WindowSetMouseVisibility(true);
	EnemyStart();
	while (esat::WindowIsOpened() &&
				 !esat::IsSpecialKeyDown(esat::kSpecialKey_Escape))
	{
		last_time = esat::Time();
		esat::DrawBegin();
		esat::DrawClear(255, 255, 255);
		EnemyUpdate();
		EnemyDraw();
		esat::DrawEnd();

		// Control FPS
		do
		{
			current_time = esat::Time();
		} while ((current_time - last_time) <= 1000.0 / fps);
		esat::WindowFrame();
	}

	esat::WindowDestroy();
	EnemyEnd();
	return 0;
}
