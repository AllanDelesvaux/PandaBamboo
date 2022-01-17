#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>
#include "config_sdl.h"
using namespace std;

const int LARGEUR = 1200; 
const int HAUTEUR = 900;  
const int N = 6;

void interface_auto(SDL_Renderer* rendu) {

	for (int i = 20; i < 820; i+=200) {
		for (int j = 20; j < 820; j += 200) {
			SDL_Rect bambooPlace;
			bambooPlace.x = j;
			bambooPlace.y = i;
			bambooPlace.w = 200;
			bambooPlace.h = 200;
			SDL_SetRenderDrawColor(rendu, 255, 255, 255, 255);
			SDL_RenderDrawRect(rendu, &bambooPlace);

			SDL_Rect MaxHauteur;
			MaxHauteur.x = j+1;
			MaxHauteur.y = i+1;
			MaxHauteur.w = 198;
			MaxHauteur.h = 24;
			SDL_SetRenderDrawColor(rendu, 0, 0, 255, 255);
			SDL_RenderFillRect(rendu, &MaxHauteur);

			SDL_Rect bambooSeparation;
			bambooSeparation.x = j+125;
			bambooSeparation.y = i+100;
			bambooSeparation.w = 75;
			bambooSeparation.h = 100;
			SDL_SetRenderDrawColor(rendu, 255, 255, 255, 255);
			SDL_RenderDrawRect(rendu, &bambooSeparation);

			SDL_Rect bamboo;
			bamboo.x = j+63;
			bamboo.y = i+60;
			bamboo.w = 10;
			bamboo.h = 139;
			SDL_SetRenderDrawColor(rendu, 0, 255, 0, 255);
			SDL_RenderFillRect(rendu, &bamboo);

			for (int k = i; k < i + 139; k += 30) {
				SDL_Rect bambooIncrease;
				bambooIncrease.x = j+60;
				bambooIncrease.y = k+60;
				bambooIncrease.w = 16;
				bambooIncrease.h = 3;
				SDL_SetRenderDrawColor(rendu,0, 128, 0, 255);
				SDL_RenderFillRect(rendu, &bambooIncrease);
			}
		}
	}
}
int panda(SDL_Renderer* rendu,int x, int y) {
	SDL_Surface* image = IMG_Load("panda1.PNG");
	if (!image)
	{
		printf("Erreur de chargement de l'image : %s", SDL_GetError());
		return -1;
	}

	SDL_Texture* monImage = SDL_CreateTextureFromSurface(rendu, image);
	SDL_FreeSurface(image);

	SDL_Rect posImg;
	posImg.x = x;
	posImg.y = y;
	
	SDL_QueryTexture(monImage, NULL, NULL, &posImg.w, &posImg.h);
	SDL_RenderCopy(rendu, monImage, NULL, &posImg);
	SDL_RenderPresent(rendu);
}
void Left(SDL_Renderer* rendu,int &x, int &y) {
	SDL_Rect RobotLft;
	RobotLft.x = x+1;
	RobotLft.y = y+1;
	RobotLft.w = 73;
	RobotLft.h = 98;
	SDL_SetRenderDrawColor(rendu, 0, 0, 0, 255);
	SDL_RenderFillRect(rendu, &RobotLft);

	x -= 200;

	panda(rendu, x, y);
}
void Right(SDL_Renderer* rendu,int &x, int &y) {
	SDL_Rect RobotRght;
	RobotRght.x = x+1;
	RobotRght.y = y+1;
	RobotRght.w = 73;
	RobotRght.h = 98;
	SDL_SetRenderDrawColor(rendu, 0, 0, 0, 255);
	SDL_RenderFillRect(rendu, &RobotRght);

	x += 200;

	panda(rendu, x, y);
}
void Up(SDL_Renderer* rendu,int &x, int &y) {
	SDL_Rect RobotUp;
	RobotUp.x = x+1;
	RobotUp.y = y+1;
	RobotUp.w = 73;
	RobotUp.h = 98;
	SDL_SetRenderDrawColor(rendu, 0, 0, 0, 255);
	SDL_RenderFillRect(rendu, &RobotUp);

	y -= 200;

	panda(rendu, x, y);
}
void Down(SDL_Renderer* rendu,int &x, int &y) {
	SDL_Rect RobotDwn;
	RobotDwn.x = x+1;
	RobotDwn.y = y+1;
	RobotDwn.w = 73;
	RobotDwn.h = 98;
	SDL_SetRenderDrawColor(rendu, 0, 0, 0, 255);
	SDL_RenderFillRect(rendu, &RobotDwn);

	y += 200;

	panda(rendu, x, y);
}
int jeu(int argn, char* argv[]) {
	int x = 145;
	int y = 720;
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
	panda(rendu, x, y);
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
			if (event.key.keysym.sym == SDLK_LEFT && x > 145) {
				Left(rendu, x, y);
				SDL_RenderPresent(rendu);
			}
			if (event.key.keysym.sym == SDLK_RIGHT && x < 660) {
				Right(rendu, x, y);
				SDL_RenderPresent(rendu);
			}
			if (event.key.keysym.sym == SDLK_UP && y > 180) {
				Up(rendu, x, y);
				SDL_RenderPresent(rendu);
			}
			if (event.key.keysym.sym == SDLK_DOWN && y < 720) {
				Down(rendu, x, y);
				SDL_RenderPresent(rendu);
			}
			if (event.key.keysym.sym == SDLK_RETURN) {
				SDL_Rect Cut;
				Cut.x = x - 73;
				Cut.y = y - 60;
				Cut.w = 40;
				Cut.h = 154;
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

