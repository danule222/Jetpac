
const int TotalSpritesNaves = 12, PosicionNaveFija = 768;
int gravedadhola2 = 1, contadornave2, numerodegasofa;
bool empezarnivelnave = true, ocupadonave = false, bajarnave;

NaveJetpac *Nave;
esat::SpriteHandle *spritesNave;

// Inicializar los sprites de la nave
void InicializarSpritesNave()
{
	// Memoria
	spritesNave = (esat::SpriteHandle *)malloc(TotalSpritesNaves * sizeof(esat::SpriteHandle));

	spritefinal = esat::SpriteFromFile("../assets/spritesheet.png");

	// Asignar cada imagen a cada sprite
	int spritenum = 0;
	for (int i = 0; i < TotalSpritesNaves; i++)
	{
		*(spritesNave + i) = esat::SubSprite(spritefinal, spritenum, 0, 48, 48);
		spritenum += 48;
	}
}

void InicializarNaveJP()
{
	// Memoria
	Nave = (NaveJetpac *)malloc(TotalSpritesNaves * sizeof(NaveJetpac));
	int cada3 = 0;
	for (int i = 0; i < TotalSpritesNaves; i++)
	{
		(Nave + i)->estado = false;
		(Nave + i)->mantenernave = false;
		(Nave + i)->caidan = false;
		(Nave + i)->posicionfinal = false;
		cada3++;
		if (cada3 == 3)
		{
			(Nave + i)->posicionfinal = true;
			cada3 = 0;
		}
	}
}

void AparicionNave(int nivel)
{
	// Dependiendo del nivel, asigna una posición a la nave
	if (empezarnivelnave)
	{
		if (nivel % 4 == 0)
		{
			(Nave + 0 + ((nivel / 4) * 3))->pos.x = 168;
			(Nave + 0 + ((nivel / 4) * 3))->pos.y = 192;
			(Nave + 0 + ((nivel / 4) * 3))->estado = true;
			printf("%d ", (0 + ((nivel / 4) * 3)));
			(Nave + 1 + ((nivel / 4) * 3))->pos.x = 300;
			(Nave + 1 + ((nivel / 4) * 3))->pos.y = 300;
			(Nave + 1 + ((nivel / 4) * 3))->estado = true;
			printf("%d ", (1 + ((nivel / 4) * 3)));

			(Nave + 2 + ((nivel / 4) * 3))->pos.x = 504;
			(Nave + 2 + ((nivel / 4) * 3))->pos.y = 504;
			(Nave + 2 + ((nivel / 4) * 3))->estado = true;
			printf("%d \n", (2 + ((nivel / 4) * 3)));
		}
		empezarnivelnave = false;
	}
}

bool RecogerNave(int numnave, float posjugx, float posjugy)
{
	if (CheckCollision((Nave + numnave)->pos.x, (Nave + numnave)->pos.y, 48, 48, posjugx, posjugy, 48, 72))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void ShipDraw()
{
	for (int i = 0; i < TotalSpritesNaves; i++)
	{
		if ((Nave + i)->estado)
		{
			DrawColorSquare((Nave + i)->pos, c_white, 48, 48, true);
			if (i == 2 || i == 5 || i == 8 || i == 11)
			{
				esat::Vec2 naveposxy = {504, (Nave + i)->pos.y + 48};
				DrawColorSquare(naveposxy, c_magenta, 48, -totalcaidafuel);
			}
		}
	}
	for (int i = 0; i < TotalSpritesNaves; i++)
	{
		if ((Nave + i)->estado)
		{
			esat::DrawSprite(*(spritesNave + i), (Nave + i)->pos.x, (Nave + i)->pos.y);
		}
	}
}

void MovimientoNave(float posjugx, float posjugy)
{
	for (int i = 0; i < TotalSpritesNaves; i++)
	{
		// Revisa si esta vivo
		if ((Nave + i)->estado && !(Nave + i)->posicionfinal && (Nave + i + 1)->posicionfinal)
		{
			// Revisa si hay colision y si no hay ninguna nave cayendo
			if (RecogerNave(i, posjugx, posjugy) && !(Nave + i)->caidan)
				(Nave + i)->mantenernave = true;
			if ((Nave + i)->mantenernave)
			{
				// Contador para darle efecto de retraso mientras sigue al jugador la nave
				if (contadornave2 > 100)
					contadornave2 = 0;
				contadornave2++;
				if (contadornave2 % 5 == 0)
				{
					(Nave + i)->pos.x = posjugx;
					(Nave + i)->pos.y = posjugy + 24;
				}
			}
		}
	}
}

void NaveCayendo()
{
	for (int i = 0; i < TotalSpritesNaves; i++)
	{
		if ((Nave + i)->pos.x > (486) && (Nave + i)->pos.x < (522) && !(Nave + i)->posicionfinal && (Nave + i)->pos.y < 408)
		{
			(Nave + i)->caidan = true;
			(Nave + i)->mantenernave = false;
			(Nave + i)->pos.x = 504;
		}
		if ((Nave + i)->pos.x == 504 && (Nave + i)->posicionfinal)
		{
			(Nave + i)->caidan = false;
		}
		if ((Nave + i)->caidan)
			(Nave + i)->pos.y += gravedadhola2;
	}
}

void PosFinalNave(int nivel)
{
	float posy = 408;
	float posy2 = 407;
	for (int i = 0; i < 2; i++)
	{
		if ((Nave + i + ((nivel / 4) * 3))->pos.y >= posy2 && (Nave + i + ((nivel / 4) * 3))->pos.y <= posy && (Nave + i + ((nivel / 4) * 3))->pos.x == 504)
		{
			(Nave + i + ((nivel / 4) * 3))->posicionfinal = true;
		}
		posy += 48;
		posy2 += 48;
	}
	if ((Nave + ((nivel / 4) * 3))->posicionfinal)
	{
		aparicionfuelPU = true;
	}
}

void NaveDespegandop()
{
	if (subirnave)
	{
		for (int i = 0; i < 12; i++)
		{
			if ((Nave + i)->estado)
				(Nave + i)->pos.y--;
			if ((Nave + i)->pos.y < -20 && (Nave + i)->estado)
			{
				bajarnave = true;
				if (g_player.nivel == 3)
				{
					(Nave + 0)->estado = false;
					(Nave + 1)->estado = false;
					(Nave + 2)->estado = false;
					g_player.alive = true;
					empezarnivelnave = true;
					bajarnave = false;
				}
				if (g_player.nivel == 7)
				{
					(Nave + 3)->estado = false;
					(Nave + 4)->estado = false;
					(Nave + 5)->estado = false;
					g_player.alive = true;
					empezarnivelnave = true;
					bajarnave = false;
				}
				if (g_player.nivel == 11)
				{
					(Nave + 6)->estado = false;
					(Nave + 7)->estado = false;
					(Nave + 8)->estado = false;
					g_player.alive = true;
					empezarnivelnave = true;
					bajarnave = false;
				}
				g_player.nivel++;
				totalcaidafuel = 0;
				subirnave = false;
			}
		}
	}

	if (bajarnave)
	{
		for (int i = 0; i < 12; i++)
		{
			if ((Nave + i)->estado)
				(Nave + i)->pos.y++;
			if ((Nave + i)->pos.y > 504)
			{
				g_player.alive = true;
				empezarnivelnave = true;
				bajarnave = false;
			}
		}
	}
}

void ControlarNiveles()
{
}

void ShipStart()
{
	InicializarNaveJP();
	InicializarSpritesNave();
}

void MovementsShip()
{
	AparicionNave(g_player.nivel);
	MovimientoNave(g_player.pos.x, g_player.pos.y);
	NaveCayendo();
	NaveDespegandop();
	PosFinalNave(g_player.nivel);
	ControlarNiveles();
}

void ShipEnd()
{
	for (int i = 0; i < TotalSpritesNaves; i++)
	{
		esat::SpriteRelease(*(spritesNave + i));
	}
	free(Nave);
	free(spritesNave);
}