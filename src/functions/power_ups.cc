const int TotalSpritesPowerUps=6,TotalObjetos=6,TotalColores=12,pantallaxpowerups=768,posxnavep=500;
int caracteristicaspowerup,contadoraparicionpowerups,contadorfuel,contadorfuel2,aparicionYpowerups=120,totalcaidafuel=0,colorespunum,contadorcolorfuel;
float gravedadhola=1;
bool mantenerfuel=false,caidaf=false,aparicionfuelPU=false,activarvuelo=false,subirnave=false;
Color diamantepowerups;
powerups *objeto;
esat::SpriteHandle spritefinal;
esat::SpriteHandle *spritesPowerups;



//Inicializar los sprites de los Power Ups
void InicializarSpritesPowerUps(){
	//Memoria 
	spritesPowerups = (esat::SpriteHandle*)malloc( 6 * sizeof(esat::SpriteHandle));

	spritefinal = esat::SpriteFromFile("../assets/spritesheet.png");
	//Asignar cada imagen a cada sprite
	int spritenum=672;
	for(int i=0;i<TotalSpritesPowerUps;i++){
		*(spritesPowerups + i) = esat::SubSprite(spritefinal,spritenum,48,48,48);
		spritenum+=48;
	}
}


void ColoresPowerUps(){

	switch (colorespunum)
	{
	case 1:
		(objeto+1)->color={c_cyan};
		break;
	case 2:
		(objeto+1)->color={c_blue};
		break;
	case 3:
		(objeto+1)->color={c_dark_red};
		break;
	case 4:
		(objeto+1)->color={c_red};
		break;
	case 5:
		(objeto+1)->color={c_dark_magenta};
		break;
	case 6:
		(objeto+1)->color={c_magenta};
		break;
	case 7:
		(objeto+1)->color={c_dark_green};
		break;
	case 8:
		(objeto+1)->color={c_green};
		break;
	case 9:
		(objeto+1)->color={c_dark_cyan};
		break;
	case 10:
		(objeto+1)->color={c_cyan};
		break;
	case 11:
		(objeto+1)->color={c_dark_yellow};
		break;
	case 12:
		(objeto+1)->color={c_yellow};
		break;
	case 13:
		(objeto+1)->color={c_red};
		break;
	case 14:
		(objeto+1)->color={c_grey};
		break;
	case 15:
		(objeto+1)->color={c_white};
		break;	
	}
}



//Inicializar las características de los Power Ups
void InicializarPU(){
	//Memoria 
	objeto = (powerups*)malloc((TotalObjetos) * sizeof(powerups));

	//Asignarle a cada PowerUp su numero para posteriormente asignarle a cada uno una caracteristica diferente
	for(int i=0;i<TotalObjetos;i++){
		(objeto+i)->numero=i;
		(objeto+i)->estado=false;
	}

	//Caracterísiticas de cada objeto
	for(int i=0;i<TotalObjetos;i++){
	switch ((objeto+i)->numero)
	{
		//Fuel
		case 0:
			(objeto+i)->score=250;
      (objeto+i)->color=c_magenta;
			break;
		//Diamante
		case 1:
			(objeto+i)->score=250;
      (objeto+i)->color=c_dark_blue;
			break;
		//Slime raro
		case 2:
			(objeto+i)->score=250;
      (objeto+i)->color=c_green;
			break;
		//Nuclear
		case 3:
			(objeto+i)->score=250;
      (objeto+i)->color=c_cyan;
			break;
		//Tres Bolas Unidas Por Una Raya (???)
		case 4:
			(objeto+i)->score=250;
      (objeto+i)->color=c_cyan;
			break;
		//Bloque De Oro
		case 5:
			(objeto+i)->score=300;
      (objeto+i)->color=c_yellow;
			break;
		}
	}
}



void GravedadPowerUp(){
	//El PowerUp cae si no detecta colisiones
	for(int i=0;i<TotalObjetos;i++){
		if((objeto+i)->estado){
			if(!(CheckCollision((objeto+i)->pos.x,(objeto+i)->pos.y,48,48,0,552,768,24) ||
			 CheckCollision((objeto+i)->pos.x,(objeto+i)->pos.y,48,48,96,216,144,24) ||
				CheckCollision((objeto+i)->pos.x,(objeto+i)->pos.y,48,48,360,288,96,24) || 
				CheckCollision((objeto+i)->pos.x,(objeto+i)->pos.y,48,48,576,144,144,24))){
				(objeto+i)->pos.y+=gravedadhola;
			}
		}
	}
}




// {(objeto+i)->pos.x,(objeto+i)->pos.y}

void PowerUpsDraw(){
	//Dibujar
	for(int i=0;i<TotalObjetos;i++) {
    	if((objeto+i)->estado){
				if((objeto+i)->numero==1 || (objeto+i)->numero==5){
					if((objeto+i)->numero==1){
						contadorcolorfuel++;
						if(contadorcolorfuel>450)contadorcolorfuel=0;
						if(colorespunum>15)colorespunum=0;
						if(contadorcolorfuel%5==0)colorespunum++;
					DrawColorSquare((objeto+i)->pos,(objeto+i)->color,48,48,true);
					esat::DrawSprite(*(spritesPowerups+i),(objeto+i)->pos.x,(objeto+i)->pos.y);
					}
					if((objeto+i)->numero==5){
					DrawColorSquare((objeto+i)->pos,(objeto+i)->color,48,24,true);
					esat::DrawSprite(*(spritesPowerups+i),(objeto+i)->pos.x,(objeto+i)->pos.y);
					}
			}else{
					DrawColorSquare((objeto+i)->pos,(objeto+i)->color,48,48,true);
					esat::DrawSprite(*(spritesPowerups+i),(objeto+i)->pos.x,(objeto+i)->pos.y);
			}
		}
	}
}


void AparicionPowerUps(){
	//Comprueba el num de PowerUps en pantalla
	int vivo=0;
	for(int i=1;i<TotalObjetos;i++){
		if((objeto+i)->estado)vivo++;
	}
	
	//Si no hay ninguno en pantalla, hace spawnear a un PowerUp
	if(vivo<1 && totalcaidafuel<121){
		contadoraparicionpowerups++;

		if(contadoraparicionpowerups>(rand()%1000)+200){
			int aux=rand()%(TotalObjetos-1);
			(objeto+aux+1)->pos.x=rand()%(pantallaxpowerups-48);
			(objeto+aux+1)->pos.y=aparicionYpowerups;
			(objeto+aux+1)->estado=true;
			contadoraparicionpowerups=0;
		}

	}

	//Aparición del fuel por separado
	if(!(objeto)->estado){
		contadorfuel++;
		if(contadorfuel>121)contadorfuel=0;
		if(contadorfuel>120 && aparicionfuelPU && totalcaidafuel<121){
			(objeto)->estado=true;
			//Margen de aparición del powerup respecto a la x de la nave
			int div2=rand()%2;
			if(div2==1 || div2==2){
				(objeto)->pos.x=rand()%475;
			}else{
				(objeto)->pos.x=(700-(rand()%150));
			}
			(objeto)->pos.y=aparicionYpowerups;
		}
	}
}

void DesaparicionPowerups(float posjugx,float posjugy){
	//Hacer desaparecer los powerups al tener contacto con el jugador
	for(int i=1;i<TotalObjetos;i++){
		if((objeto+i)->estado){
			if(CheckCollision((objeto+i)->pos.x,(objeto+i)->pos.y,48,48,posjugx,posjugy,48,72)){
				g_player.score+=(objeto+i)->score;
				(objeto+i)->estado=false;
			}
		}
	}
}

bool RecogerFuel(float posjugx, float posjugy){
	if((objeto)->estado){
		if(CheckCollision((objeto)->pos.x,(objeto)->pos.y,48,48,posjugx,posjugy,48,72)){
				return true;
			}else{
				return false;
			}
	}else{
		return false;
	}
}

void MovimientoFuel(float posjugx,float posjugy){
	if(RecogerFuel(posjugx,posjugy)&&!caidaf)mantenerfuel=true;

	if(mantenerfuel){
		if(contadorfuel2>100)contadorfuel2=0;
		contadorfuel2++;	
		if(contadorfuel2%5==0){
			(objeto)->pos.x=posjugx-10;
			(objeto)->pos.y=posjugy+24;
		}
	}
}
	
	
void CaidaFuel(){
if((objeto)->pos.x>(486) && (objeto)->pos.x<(522)){
		caidaf=true;
		mantenerfuel=false;
		(objeto)->pos.x=504;
		(objeto)->pos.y+=gravedadhola;

		if((objeto)->pos.x==504 && (objeto)->pos.y>=504){
			if((objeto)->estado)totalcaidafuel+=24;
			(objeto)->estado=false;
			caidaf=false;
		}
	}
}

	void ShipVolandop(float posjugx, float posjugy){
		if(totalcaidafuel>120 && CheckCollision(504,504,48,144,posjugx,posjugy,48,72) && g_player.alive){
			g_player.alive=false;
			subirnave=true;
		}
	}
		



void MovementsPowerUps(){
	ColoresPowerUps();
	AparicionPowerUps();
	GravedadPowerUp();
	CaidaFuel();
	MovimientoFuel(g_player.pos.x, g_player.pos.y);
	DesaparicionPowerups(g_player.pos.x, g_player.pos.y);
	ShipVolandop(g_player.pos.x, g_player.pos.y);
}



void PowerUpsStart(){
	InicializarPU();
	InicializarSpritesPowerUps();
}

void PowerUpsEnd(){

	for(int i=0;i<TotalSpritesPowerUps;i++){
		esat::SpriteRelease(*(spritesPowerups+i));
	}
	free(objeto);
  free(spritesPowerups);
}