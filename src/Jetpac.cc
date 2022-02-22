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
#include "common/structs.cc"
#include "common/definitions.cc"
#include "common/lists_enems.cc"
#include "common/utils.cc"
// Functions
#include "functions/enemy.cc"
#include "functions/player.cc"
// Screens
#include "screens/common.cc"
#include "screens/loading.cc"
#include "screens/menu.cc"
#include "screens/play.cc"
// Logic
#include "logic/game.cc"

unsigned char fps = 60;
double current_time, last_time;

int esat::main(int argc, char **argv)
{
	srand(time(NULL));

	esat::WindowInit(kWidth, kHeight);
	WindowSetMouseVisibility(true);

	InitializeGame();

	while (esat::WindowIsOpened() &&
				 !esat::IsSpecialKeyDown(esat::kSpecialKey_Escape))
	{
		last_time = esat::Time();
		esat::DrawBegin();
		esat::DrawClear(0, 0, 0);

		Game();

		esat::DrawEnd();

		// Control FPS
		do
		{
			current_time = esat::Time();
		} while ((current_time - last_time) <= 1000.0 / fps);
		esat::WindowFrame();
	}

	FinalizeGame();

	esat::WindowDestroy();

	return 0;
}
