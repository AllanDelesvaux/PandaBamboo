#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>
#include "config_sdl.h"
using namespace std;

const int LARGEUR = 1000; //largeur fenetre
const int HAUTEUR = 700;  //hauteur fenetre
const int N = 6;
 
void Aléatoire(int Tab[][N]) {

}

void HauteurMax(int Tab[][N]) {

}

void DevMax(int ) {

}

void menu_principal(SDL_Renderer* rendu) {

	SDL_Rect titre;
	titre.x = 80;
	titre.y = 40;
	titre.w = LARGEUR - titre.x * 2;
	titre.h = 100;
	SDL_SetRenderDrawColor(rendu, 255, 255, 255, 255);
	SDL_RenderDrawRect(rendu, &titre);

	SDL_Rect jeu_auto;
	jeu_auto.x = 80;
	jeu_auto.y = 40;
	jeu_auto.w = LARGEUR - jeu_auto.x * 2;
	jeu_auto.h = 100;
	SDL_SetRenderDrawColor(rendu, 255, 255, 255, 255);
	SDL_RenderDrawRect(rendu, &titre);

}

void Left() {

}

void Right() {

}
void Up() {

}
void Down() {

}

int main(int argn, char* argv[]) {//entête imposée
								  //ouverture de la SDL
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		cout << "Echec à l’ouverture";
		return 1;
	}

	//on crée la fenêtre
	SDL_Window* win = SDL_CreateWindow("Ma fenetre",
		SDL_WINDOWPOS_CENTERED,     //pos. X: autre option: SDL_WINDOWPOS_UNDEFINED
		SDL_WINDOWPOS_CENTERED,     //pos. Y: autre option: SDL_WINDOWPOS_UNDEFINED 
		LARGEUR, 			//largeur en pixels			
		HAUTEUR, 			//hauteur en pixels
		SDL_WINDOW_SHOWN //d’autres options (plein ecran, resizable, sans bordure...)
	);
	if (win == NULL)
		cout << "erreur ouverture fenetre";

	//Création d’un dessin associé à la fenêtre (1 seul renderer par fenetre)
	SDL_Renderer* rendu = SDL_CreateRenderer(
		win,  //nom de la fenêtre
		-1, //par défaut
		SDL_RENDERER_ACCELERATED); //utilisation du GPU, valeur recommandée

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
		case SDL_KEYDOWN:
			if (event.key.keysym.sym == SDLK_LEFT) {
				Left();
			}
			if (event.key.keysym.sym == SDLK_RIGHT) {
				Right();
			}
			if (event.key.keysym.sym == SDLK_UP) {
				Up();
			}
			if (event.key.keysym.sym == SDLK_DOWN) {
				Down();
			}
		}
	}
	//destruction du renderer à la fin
	SDL_DestroyRenderer(rendu);

	//destruction à la fin
	SDL_DestroyWindow(win);   //equivalent du delete

	//fermeture
	SDL_Quit();
	return 0;
}