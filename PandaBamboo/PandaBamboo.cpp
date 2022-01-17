#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>
#include "config_sdl.h"
using namespace std;

const int LARGEUR = 1200; 
const int HAUTEUR = 900;  
const int N = 6;
 
void Aléatoire(int Tab[][N]) {

}

void HauteurMax(int Tab[][N]) {

}

void DevMax(int ) {

}

void interface_auto(SDL_Renderer* rendu) {

	SDL_Rect Robot;
	Robot.x = 120;
	Robot.y = 740;
	Robot.w = 60;
	Robot.h = 80;
	SDL_SetRenderDrawColor(rendu, 0, 255, 255, 255);
	SDL_RenderFillRect(rendu, &Robot);

	for (int i = 20; i < 820; i+=160) {
		for (int j = 20; j < 820; j += 160) {
			SDL_Rect bambooPlace;
			bambooPlace.x = j;
			bambooPlace.y = i;
			bambooPlace.w = 160;
			bambooPlace.h = 160;
			SDL_SetRenderDrawColor(rendu, 255, 255, 255, 255);
			SDL_RenderDrawRect(rendu, &bambooPlace);

			SDL_Rect MaxHauteur;
			MaxHauteur.x = j+1;
			MaxHauteur.y = i+1;
			MaxHauteur.w = 158;
			MaxHauteur.h = 19;
			SDL_SetRenderDrawColor(rendu, 0, 0, 255, 255);
			SDL_RenderFillRect(rendu, &MaxHauteur);

			SDL_Rect bambooSeparation;
			bambooSeparation.x = j+100;
			bambooSeparation.y = i+80;
			bambooSeparation.w = 60;
			bambooSeparation.h = 80;
			SDL_SetRenderDrawColor(rendu, 255, 255, 255, 255);
			SDL_RenderDrawRect(rendu, &bambooSeparation);

			SDL_Rect bamboo;
			bambooSeparation.x = j+50;
			bambooSeparation.y = i+40;
			bambooSeparation.w = 10;
			bambooSeparation.h = 120;
			SDL_SetRenderDrawColor(rendu, 0, 255, 0, 255);
			SDL_RenderFillRect(rendu, &bambooSeparation);

			for (int k = i; k < i + 120; k += 30) {
				SDL_Rect bambooIncrease;
				bambooIncrease.x = j+47;
				bambooIncrease.y = k+40;
				bambooIncrease.w = 16;
				bambooIncrease.h = 3;
				SDL_SetRenderDrawColor(rendu,0, 128, 0, 255);
				SDL_RenderFillRect(rendu, &bambooIncrease);
			}
		}
	}
}

void panda(SDL_Renderer* rendu) {
	SDL_Surface img = IMG_Load(rendu, "");

}




void Left(SDL_Renderer* rendu,int &x, int &y) {
	SDL_Rect RobotLft;
	RobotLft.x = x+1;
	RobotLft.y = y+1;
	RobotLft.w = 58;
	RobotLft.h = 78;
	SDL_SetRenderDrawColor(rendu, 0, 0, 0, 255);
	SDL_RenderFillRect(rendu, &RobotLft);

	x -= 160;

	SDL_Rect RobotLft1;
	RobotLft1.x = x+1;
	RobotLft1.y = y+1;
	RobotLft1.w = 58;
	RobotLft1.h = 78;
	SDL_SetRenderDrawColor(rendu, 255, 255, 255, 255);
	SDL_RenderFillRect(rendu, &RobotLft1);
}

void Right(SDL_Renderer* rendu,int &x, int &y) {
	SDL_Rect RobotRght;
	RobotRght.x = x+1;
	RobotRght.y = y+1;
	RobotRght.w = 58;
	RobotRght.h = 78;
	SDL_SetRenderDrawColor(rendu, 0, 0, 0, 255);
	SDL_RenderFillRect(rendu, &RobotRght);

	x += 160;

	SDL_Rect RobotRght1;
	RobotRght1.x = x+1;
	RobotRght1.y = y+1;
	RobotRght1.w = 58;
	RobotRght1.h = 78;
	SDL_SetRenderDrawColor(rendu, 255, 255, 255, 255);
	SDL_RenderFillRect(rendu, &RobotRght1);
}
void Up(SDL_Renderer* rendu,int &x, int &y) {
	SDL_Rect RobotUp;
	RobotUp.x = x+1;
	RobotUp.y = y+1;
	RobotUp.w = 58;
	RobotUp.h = 78;
	SDL_SetRenderDrawColor(rendu, 0, 0, 0, 255);
	SDL_RenderFillRect(rendu, &RobotUp);

	y -= 160;

	SDL_Rect RobotUp1;
	RobotUp1.x = x+1;
	RobotUp1.y = y+1;
	RobotUp1.w = 58;
	RobotUp1.h = 78;
	SDL_SetRenderDrawColor(rendu, 255, 255, 255, 255);
	SDL_RenderFillRect(rendu, &RobotUp1);
}
void Down(SDL_Renderer* rendu,int &x, int &y) {
	SDL_Rect RobotDwn;
	RobotDwn.x = x+1;
	RobotDwn.y = y+1;
	RobotDwn.w = 58;
	RobotDwn.h = 78;
	SDL_SetRenderDrawColor(rendu, 0, 0, 0, 255);
	SDL_RenderFillRect(rendu, &RobotDwn);

	y += 160;

	SDL_Rect RobotDwn1;
	RobotDwn1.x = x+1;
	RobotDwn1.y = y+1;
	RobotDwn1.w = 58;
	RobotDwn1.h = 78;
	SDL_SetRenderDrawColor(rendu, 255, 255, 255, 255);
	SDL_RenderFillRect(rendu, &RobotDwn1);
}

int main(int argn, char* argv[]) {
	int x = 120;
	int y = 740;
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		cout << "Echec à l’ouverture";
		return 1;
	}

	SDL_Window* win = SDL_CreateWindow("Ma fenetre",
		SDL_WINDOWPOS_CENTERED,    
		SDL_WINDOWPOS_CENTERED,     
		LARGEUR, 					
		HAUTEUR, 			
		SDL_WINDOW_SHOWN 
	);
	if (win == NULL)
		cout << "erreur ouverture fenetre";

	SDL_Renderer* rendu = SDL_CreateRenderer(
		win,  
		-1, 
		SDL_RENDERER_ACCELERATED);
	
	interface_auto(rendu);
	SDL_RenderPresent(rendu);

	bool continuer = true; 
	SDL_Event event;
					
	while (continuer)
	{
		SDL_WaitEvent(&event);
		switch (event.type) 
		{
		case SDL_QUIT:
					   
			continuer = false;
			break;
		case SDL_KEYDOWN:
			if (event.key.keysym.sym == SDLK_LEFT && x > 140) {
				Left(rendu,x,y);
				SDL_RenderPresent(rendu);
			}
			if (event.key.keysym.sym == SDLK_RIGHT && x < 660) {
				Right(rendu, x, y);
				SDL_RenderPresent(rendu);
			}
			if (event.key.keysym.sym == SDLK_UP && y > 160) {
				Up(rendu, x, y);
				SDL_RenderPresent(rendu);
			}
			if (event.key.keysym.sym == SDLK_DOWN && y < 740) {
				Down(rendu, x, y);
				SDL_RenderPresent(rendu);
			}
			if (event.key.keysym.sym == SDLK_RETURN) {
				SDL_Rect Cut;
				Cut.x = x-53;
				Cut.y = y-60;
				Cut.w = 20;
				Cut.h = 134;
				SDL_SetRenderDrawColor(rendu, 0, 0, 0, 255);
				SDL_RenderFillRect(rendu, &Cut);
				SDL_RenderPresent(rendu);
			}
		}
	}
	SDL_DestroyRenderer(rendu);
	SDL_DestroyWindow(win);
	SDL_Quit();
	return 0;
}