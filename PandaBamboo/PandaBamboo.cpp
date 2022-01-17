#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>
#include "config_sdl.h"
using namespace std;
const int LARGEUR_ = 1000;
const int HAUTEUR_ = 500;
SDL_Color blanc = { 255,255,255 };

struct Bamboo {
	int taille;
	int croissance;
	int x;
	int y;
};

int Reduce_Max(Bamboo* tab,int taille) {
	int max = 0;
	for (int i = 0; i < taille;i++) {
		if (tab[i].taille > max) {
			max = i;
		}
	}
	tab[max].taille = 0;
	return (max);
}

void menu_principal(SDL_Renderer* rendu, TTF_Font* font) {
	SDL_Rect titre;
	titre.x = 80;
	titre.y = 40;
	titre.w = LARGEUR_ - titre.x * 2;
	titre.h = 100;

	SDL_Rect titre_;
	titre_.w = 450;
	titre_.h = titre.h;
	titre_.x = (titre.x + titre.w / 2) - titre_.w / 2;
	titre_.y = 40;

	SDL_SetRenderDrawColor(rendu, 0, 0, 0, 255);
	SDL_RenderDrawRect(rendu, &titre_);

	SDL_Texture* texture1 = loadText(rendu, "Panda Garden", blanc, font);
	SDL_QueryTexture(texture1, NULL, NULL, &titre_.w, &titre_.h);
	SDL_RenderCopy(rendu, texture1, NULL, &titre_);
	SDL_RenderPresent(rendu);
	SDL_DestroyTexture(texture1);

	SDL_Rect jeu_auto;
	jeu_auto.w = LARGEUR_ / 2 - 80 * 2;
	jeu_auto.h = 200;
	jeu_auto.x = 80;
	jeu_auto.y = HAUTEUR_ / 2 - jeu_auto.h / 2;


	SDL_Rect jeu_manuel;
	jeu_manuel.w = jeu_auto.w;
	jeu_manuel.h = 200;
	jeu_manuel.x = LARGEUR_ / 2 + 80;
	jeu_manuel.y = HAUTEUR_ / 2 - jeu_manuel.h / 2;



	SDL_Rect jeu_auto_;
	jeu_auto_.w = jeu_auto.w / 2;
	jeu_auto_.h = jeu_auto.h / 2;
	jeu_auto_.x = (jeu_auto.x + jeu_auto.w / 2) - jeu_auto_.w / 2;
	jeu_auto_.y = jeu_auto.y + jeu_auto_.h / 2;



	SDL_Rect jeu_manuel_;
	jeu_manuel_.w = jeu_manuel.w / 2;
	jeu_manuel_.h = jeu_manuel.h / 2;
	jeu_manuel_.x = (jeu_manuel.x + jeu_manuel.w / 2) - jeu_manuel_.w / 2;
	jeu_manuel_.y = jeu_manuel.y + jeu_manuel_.h / 2;



	SDL_Texture* texture2 = loadText(rendu, "Auto", blanc, font);
	SDL_QueryTexture(texture2, NULL, NULL, &jeu_auto_.w, &jeu_auto_.h);
	SDL_RenderCopy(rendu, texture2, NULL, &jeu_auto_);
	SDL_RenderPresent(rendu);
	SDL_DestroyTexture(texture2);

	SDL_Texture* texture3 = loadText(rendu, "Manuel", blanc, font);
	SDL_QueryTexture(texture3, NULL, NULL, &jeu_manuel_.w, &jeu_manuel_.h);
	SDL_RenderCopy(rendu, texture3, NULL, &jeu_manuel_);
	SDL_RenderPresent(rendu);
	SDL_DestroyTexture(texture3);

}


int main(int argn, char* argv[]) {
	const int nbr_bamboo = 5;

	Bamboo forest[nbr_bamboo];
	
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



	SDL_Window* win = SDL_CreateWindow("Menu Principal",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		LARGEUR_,
		HAUTEUR_,
		SDL_WINDOW_SHOWN
	);

	if (win == NULL)
		cout << "erreur ouverture fenetre";


	SDL_Renderer* rendu = SDL_CreateRenderer(
		win,
		-1,
		SDL_RENDERER_ACCELERATED);

	TTF_Init();
	TTF_Font* font = TTF_OpenFont("RobotoMono-Light.ttf", 60);
	TTF_Quit();
	menu_principal(rendu, font);
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

		case SDL_MOUSEBUTTONUP:
			if (event.button.button == SDL_BUTTON_LEFT && in_menu) {
				if (event.button.x > 80 && event.button.x < LARGEUR_ / 2 - 80 && event.button.y>HAUTEUR_ / 2 - 100 && event.button.y < HAUTEUR_ / 2 + 100) {
					cout << "ça marche\n";
					in_menu = false;
				}
				else if (event.button.x > LARGEUR_ / 2 + 80 && event.button.x < LARGEUR_ - 80 && event.button.y>HAUTEUR_ / 2 - 100 && event.button.y < HAUTEUR_ / 2 + 100) {
					cout << "ça marche\n";
					in_menu = false;
					jeu();
				}
			}
		}

	}

	SDL_DestroyRenderer(rendu);
	SDL_DestroyWindow(win);
	SDL_Quit();
	return 0;
}

