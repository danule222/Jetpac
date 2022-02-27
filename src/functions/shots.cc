/**
 * @file shots.cc
 * @author Ignacio S. Avilés
 * @brief Funciones de logica del Disparo
 *
 */
 
esat::SpriteHandle *g_sprites_shots;
Shot *shots;

void InitShots()
{
	shots = (Shot *) malloc(sizeof(Shot) * 5);
	for(int i = 0; i < 5; i++) 
	{
		(shots + i)->pos.x = 0;
		(shots + i)->pos.y = 0;
		(shots + i)->alive = false;
		(shots + i)->sprite = 0;
		(shots + i)->frame_counter = 0;
		(shots + i)->facing_right = 0;
	}
}

void EndShots()
{
	free(shots);
	free(g_sprites_shots);
}

void InitSpritesShots()
{
    g_sprites_shots = (esat::SpriteHandle *) malloc(8 * sizeof(esat::SpriteHandle));
    for (int i = 0; i < 5; i++)
    {
		
        *(g_sprites_shots + i) = esat::SubSprite(g_spritesheet, 720 + (i * 48), 144, 24, 24);
    }
    for (int i = 5; i < 8; i++)
    {
        *(g_sprites_shots + i) = esat::SubSprite(g_spritesheet, (i - 5) * 48, 192, 24, 24);
    }
}

void DrawShotSprites()
{
	for(int i = 0; i < 5; i++)
	{
		Color backg;
		if((shots + i)->color == 0)
		{
			backg = c_magenta;
		}
		else if((shots + i)->color == 1)
		{
			backg = c_cyan;
		}
		else if((shots + i)->color == 2)
		{
			backg = c_red;
		}
		else 
		{
			backg = c_yellow;
		}
		if((shots + i)->alive)
		{
			if((shots + i)->facing_right)
			{
				for(int i = 0; i < (shots + i)->frame_counter; i++) 
				{
					esat::Vec2 pos_masc_shot = {(shots + i)->pos.x - (i * 24), (shots + i)->pos.y};
					DrawColorSquare(pos_masc_shot, backg, 24, 24);
					esat::DrawSprite(*(g_sprites_shots + i), (shots + i)->pos.x - (24 * i), (shots + i)->pos.y);
				}
			}
			
			else
			{
				for(int i = 0; i < (shots + i)->frame_counter; i++) 
				{
					esat::Vec2 pos_masc_shot = {(shots + i)->pos.x + (i * 24), (shots + i)->pos.y};
					DrawColorSquare(pos_masc_shot, backg, 24, 24);
					esat::DrawSprite(*(g_sprites_shots + i), (shots + i)->pos.x + (24 * i), (shots + i)->pos.y);
				}
			}
		}
	}
} 

void SpawnShot(float h, float v, bool face)
{
	int counter = 0;
	while((shots + counter)->alive)
	{
		counter++;
	}
	(shots + counter)->alive = true;
	(shots + counter)->pos.x = h;
	(shots + counter)->pos.y = v;
	(shots + counter)->facing_right = face;
	(shots + counter)->color = rand() % 4;
}

void MoveShots() {
	for(int i = 0; i < 5; i++)
	{
		if((shots + i)->alive)
		{
			if((shots + i)->facing_right)
			{
				(shots + i)->pos.x += 24;
				if((shots + i)->frame_counter < 14)
				{
					(shots + i)->frame_counter++;
				}
				else{
					(shots + i)->alive = false;
					(shots + i)->frame_counter = 0;
				}
			}
			
			else
			{
				(shots + i)->pos.x -= 24;
				if((shots + i)->frame_counter < 14)
				{
					(shots + i)->frame_counter++;
					
				}
				else{
					(shots + i)->alive = false;
					(shots + i)->frame_counter = 0;
				}
			}
		}
	}
}

void EnemyKill()
{
	for(int i = 0; i < 5; i++)
	{
		if(CollisionEnemyWihtShot((shots + i)->pos.x, (shots + i)->pos.y, (shots + i)->pos.x + 24, (shots + i)->pos.y + 3))
		{
			(shots + i)->alive = false;
			(shots + i)->pos.x = 0;
			(shots + i)->pos.y = 0;
		}
	}
}