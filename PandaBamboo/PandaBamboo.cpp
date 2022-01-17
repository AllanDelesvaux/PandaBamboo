#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>
#include "config_sdl.h"
#include <ctime>
 
using namespace std;

const int LARGEUR = 800; //largeur fenetre
const int HAUTEUR = 600;  //hauteur fenetre
const int N = 100;

struct bambou {

	int posx;
	int posy;
	int croissance;
	int hauteur = NULL;

};

void Al�atoire(bambou tablo[]) {
	srand(time(NULL));
	for (int i = 0; i < N; i++) {
		tablo[i].croissance = rand() % 20;

	}
}

int HauteurMax(int Tab[][N]) {

	int HauteurMax = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {

			if (Tab[i][j] > HauteurMax) {
				HauteurMax = Tab[i][j];
			}
		}
	}
	return HauteurMax;
}

int Moyenne(int Tab[][N]) {

	int somme;
	for (int i = 0; i < N; i++) {
		somme = Tab[N][N] + Tab[N+1][N + 1];
	}
	int moyenne;
	moyenne = somme / N;
	return moyenne;

}

void abcisse(SDL_Renderer* rendu, int x1, int y1, int x2, int y2) {

	SDL_SetRenderDrawColor(rendu, 255, 0, 0, 255);
	SDL_SetRenderDrawLine(255, 0, Largeur / 2, 255);
	SDL_RenderPresent(rendu);

}

int main(int argn, char* argv[]) {//ent�te impos�e
							  //ouverture de la SDL*
	struct bambou {
		int posx;
		int posy;
		int croissance;
		int hauteur = NULL;
	};

	bambou tab[N];
	

	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		cout << "Echec � l�ouverture";
		return 1;
	}

	//on cr�e la fen�tre
	SDL_Window* win = SDL_CreateWindow("Ma fenetre",
		SDL_WINDOWPOS_CENTERED,     //pos. X: autre option: SDL_WINDOWPOS_UNDEFINED
		SDL_WINDOWPOS_CENTERED,     //pos. Y: autre option: SDL_WINDOWPOS_UNDEFINED 
		LARGEUR, 			//largeur en pixels			
		HAUTEUR, 			//hauteur en pixels
		SDL_WINDOW_SHOWN //d�autres options (plein ecran, resizable, sans bordure...)
	);
	if (win == NULL)
		cout << "erreur ouverture fenetre";

	//Cr�ation d�un dessin associ� � la fen�tre (1 seul renderer par fenetre)
	SDL_Renderer* rendu = SDL_CreateRenderer(
		win,  //nom de la fen�tre
		-1, //par d�faut
		SDL_RENDERER_ACCELERATED); //utilisation du GPU, valeur recommand�e

	SDL_RenderPresent(rendu);

	bool continuer = true;   //bool�en fin de programme
	SDL_Event event;//gestion des �v�nements souris/clavier, 
					//SDL_Event est de type struct
	while (continuer)
	{
		SDL_WaitEvent(&event);//attente d�un �v�nement
		switch (event.type) //test du type d��v�nement
		{
		case SDL_QUIT: //clic sur la croix de fermeture
					   
			continuer = false;
			break;
		}
	}
	//destruction du renderer � la fin
	SDL_DestroyRenderer(rendu);

	//destruction � la fin
	SDL_DestroyWindow(win);   //equivalent du delete

	//fermeture
	SDL_Quit();

	return 0;
}