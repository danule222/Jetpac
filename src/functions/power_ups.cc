const int TotalSpritesPowerUps=6,TotalObjetos=6,TotalColores=12,pantallaxpowerups=768,posxnavep=500;
int caracteristicaspowerup,contadoraparicionpowerups,contadorfuel,aparicionYpowerups=100;
float gravedadhola=1;


powerups *objeto;
esat::SpriteHandle spritefinal;
esat::SpriteHandle *spritesPowerups;



//Función de colisión para los Power Ups
bool Colision(int num, float x1, float y1, float x2, float y2){
		if((x1<(objeto+num)->pos.x+49)  &&  (x2>(objeto+num)->pos.x)  &&  (y1<(objeto+num)->pos.y)  &&  (y2>(objeto+num)->pos.y+49)) {
			return true;
		}else{
			return false;
		}
}



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
      (objeto+i)->color.r = 255;
      (objeto+i)->color.g = 255;
      (objeto+i)->color.b = 255;
			break;
		//Diamante
		case 1:
			(objeto+i)->score=250;
      (objeto+i)->color.r = 0;
      (objeto+i)->color.g = 0;
      (objeto+i)->color.b = 0;
			break;
		//Bloque De Oro
		case 2:
			(objeto+i)->score=250;
      (objeto+i)->color.r = 0;
      (objeto+i)->color.g = 0;
      (objeto+i)->color.b = 0;
			break;
		//Slime raro
		case 3:
			(objeto+i)->score=250;
      (objeto+i)->color.r = 0;
      (objeto+i)->color.g = 0;
      (objeto+i)->color.b = 0;
			break;
		//Tres Bolas Unidas Por Una Raya (???)
		case 4:
			(objeto+i)->score=250;
      (objeto+i)->color.r = 0;
      (objeto+i)->color.g = 0;
      (objeto+i)->color.b = 0;
			break;
		//Nuclear
		case 5:
			(objeto+i)->score=300;
      (objeto+i)->color.r = 0;
      (objeto+i)->color.g = 0;
      (objeto+i)->color.b = 0;
			break;
		}
	}
}

void GravedadPowerUp(){
	//El PowerUp cae si no detecta colisiones
	for(int i=0;i<TotalObjetos;i++){
		if((objeto+i)->estado){
			if(!Colision(i,0,500,800,600)){
				(objeto+i)->pos.y+=gravedadhola;
			}
		}
	}
}

void MovimientoPowerupJugador(int posjugx, int posjugy){
	//Función para cuando el Fuel toque al jugador para que se mueva con el jugador
	(objeto)->pos.x=posjugx;
	(objeto)->pos.y=posjugy;
}

// {(objeto+i)->pos.x,(objeto+i)->pos.y}

void PowerUpsDraw(){
	//Dibujar
	for(int i=0;i<TotalObjetos;i++) {
    	if((objeto+i)->estado){
        DrawColorSquare((objeto + i)->pos, (objeto+i)->color,48,48);
			esat::DrawSprite(*(spritesPowerups+i),(objeto+i)->pos.x,(objeto+i)->pos.y);
      
		}
	}
	DrawColorSquare((objeto + 0)->pos, (objeto+0)->color,48,48);
}

void AparicionPowerUps(){

	//Comprueba el num de PowerUps en pantalla
	int vivo=0;
	for(int i=1;i<TotalObjetos;i++){
		if((objeto+i)->estado)vivo++;
	}
	
	//Si no hay ninguno en pantalla, hace spawnear a un PowerUp
	if(vivo<1){
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
		if(contadorfuel>120){
			(objeto)->estado=true;
			//Margen de aparición del powerup respecto a la x de la nave
			int div2=rand()%2;
			if(div2==1){
				(objeto)->pos.x=rand()%(posxnavep-25);
			}else{
				(objeto)->pos.x=rand()%(posxnavep+((pantallaxpowerups-48)-(posxnavep+25)));
			}
			(objeto)->pos.y=aparicionYpowerups;
			contadorfuel=0;
		}
	}
}

void DesaparicionPowerups(){
	//Hacer desaparecer los powerups al tener contacto con el jugador
	for(int i=1;i<TotalObjetos;i++){
		if((objeto+i)->estado){
			if(Colision(i,0,500,800,600)){
				(objeto+i)->estado=false;
				
			}
		}
	}

if((objeto)->estado){
			if(Colision(0,0,500,800,600)){
				(objeto)->estado=false;
				
			}
		}

}

void MovementsPowerUps(){
	AparicionPowerUps();
	GravedadPowerUp();
	DesaparicionPowerups();
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