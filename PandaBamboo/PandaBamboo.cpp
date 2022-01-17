#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>
#include "config_sdl.h"
using namespace std;
const int LARGEUR = 1000; //largeur fenetre
const int HAUTEUR = 700;  //hauteur fenetre
const int N = 6;
const char image[] = "panda.png";
SDL_Color blanc = {255,255,255};

void menu_principal(SDL_Renderer* rendu,TTF_Font* font) {
	SDL_Rect titre;
	titre.x = 80;
	titre.y = 40;
	titre.w = LARGEUR - titre.x*2;
	titre.h = 100;
	SDL_SetRenderDrawColor(rendu, 255, 255, 255,255);
	SDL_RenderDrawRect(rendu, &titre);

	SDL_Texture* texture1 = loadText(rendu, "Panda Garden", blanc, font);
	SDL_QueryTexture(texture1, NULL, NULL, &titre.w, &titre.h);
	SDL_RenderCopy(rendu, texture1, NULL, &titre);
	SDL_RenderPresent(rendu);
	SDL_DestroyTexture(texture1);

	SDL_Rect jeu_auto;
	jeu_auto.w = LARGEUR/2-80*2;
	jeu_auto.h = 200;
	jeu_auto.x = 80;
	jeu_auto.y = HAUTEUR/2-jeu_auto.h/2;
	SDL_RenderDrawRect(rendu, &jeu_auto);

	SDL_Rect jeu_manuel;
	jeu_manuel.w = jeu_auto.w;
	jeu_manuel.h = 200;
	jeu_manuel.x = LARGEUR/2+80;
	jeu_manuel.y = HAUTEUR / 2 - jeu_manuel.h / 2;
	SDL_RenderDrawRect(rendu, &jeu_manuel);
	SDL_RenderDrawLine(rendu,LARGEUR/2,60+titre.h,LARGEUR/2,HAUTEUR);
	SDL_RenderDrawLine(rendu, 0,HAUTEUR/2 ,LARGEUR, HAUTEUR/2);

}


int main(int argn, char* argv[]) {

	bool in_menu = true;
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		cout << "Echec à l’ouverture";
		return 1;
	}
	else if (TTF_Init() == -1)
	{
		printf("TTF_Init: %s\n", TTF_GetError());
		exit(2);
	}


	//on crée la fenêtre
	SDL_Window* win = SDL_CreateWindow("Menu Principal",
		SDL_WINDOWPOS_CENTERED,     
		SDL_WINDOWPOS_CENTERED,     
		LARGEUR, 					
		HAUTEUR, 			
		SDL_WINDOW_SHOWN 
	);
	
	if (win == NULL)
		cout << "erreur ouverture fenetre";

	//Création d’un dessin associé à la fenêtre (1 seul renderer par fenetre)
	SDL_Renderer* rendu = SDL_CreateRenderer(
		win,  //nom de la fenêtre
		-1, //par défaut
		SDL_RENDERER_ACCELERATED); //utilisation du GPU, valeur recommandée
	
	TTF_Init();
	TTF_Font* font = TTF_OpenFont("RobotoMono-Light.ttf", 60);
	TTF_Quit();
	menu_principal(rendu,font);
	SDL_RenderPresent(rendu);
	
	bool continuer = true;   //booléen fin de programme
	SDL_Event event;//gestion des évènements souris/clavier, 
					//SDL_Event est de type struct
	while (continuer)
	{
		SDL_WaitEvent(&event);//attente d’un évènement
		switch (event.type) //test du type d’évènement
		{
		case SDL_QUIT: //clic sur la croix de fermeture
					   
			continuer = false;
			break;

		case SDL_MOUSEBUTTONUP:
			if (event.button.button == SDL_BUTTON_LEFT && in_menu) {
				if (event.button.x > 80 && event.button.x < LARGEUR/2 - 80 && event.button.y>HAUTEUR / 2 - 100 && event.button.y < HAUTEUR/2+100) {
					cout << "ça marche\n";
					in_menu = false;
				}
				else if (event.button.x > LARGEUR/2+80 && event.button.x < LARGEUR  - 80 && event.button.y>HAUTEUR / 2 - 100 && event.button.y < HAUTEUR / 2 + 100) {
					cout << "ça marche\n";
					in_menu = false;
				}
			}
		}

	}
	
	SDL_DestroyRenderer(rendu);
	SDL_DestroyWindow(win);  
	SDL_Quit();
	return 0;
}

