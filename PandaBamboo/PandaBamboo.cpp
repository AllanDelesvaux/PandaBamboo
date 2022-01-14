#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>
#include "config_sdl.h"
using namespace std;


const int LARGEUR = 1000; //largeur fenetre
const int HAUTEUR = 700;  //hauteur fenetre
const int N = 6;
const char image[] = "panda.png";
void menu_principal(SDL_Renderer* rendu) {

	SDL_Rect titre;
	titre.x = 80;
	titre.y = 40;
	titre.w = LARGEUR - titre.x*2;
	titre.h = 100;
	SDL_SetRenderDrawColor(rendu, 255, 255, 255,255);
	SDL_RenderDrawRect(rendu, &titre);
	
	SDL_Rect jeu_auto;
	jeu_auto.x = 80;
	jeu_auto.y = 40;
	jeu_auto.w = LARGEUR - jeu_auto.x * 2;
	jeu_auto.h = 100;
	SDL_SetRenderDrawColor(rendu, 255, 255, 255, 255);
	SDL_RenderDrawRect(rendu, &titre);

}


int main(int argn, char* argv[]) {
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		cout << "Echec � l�ouverture";
		return 1;
	}

	//on cr�e la fen�tre
	SDL_Window* win = SDL_CreateWindow("Menu Principal",
		SDL_WINDOWPOS_CENTERED,     
		SDL_WINDOWPOS_CENTERED,     
		LARGEUR, 					
		HAUTEUR, 			
		SDL_WINDOW_SHOWN 
	);
	
	if (win == NULL)
		cout << "erreur ouverture fenetre";

	//Cr�ation d�un dessin associ� � la fen�tre (1 seul renderer par fenetre)
	SDL_Renderer* rendu = SDL_CreateRenderer(
		win,  //nom de la fen�tre
		-1, //par d�faut
		SDL_RENDERER_ACCELERATED); //utilisation du GPU, valeur recommand�e
	menu_principal(rendu);
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
	
	SDL_DestroyRenderer(rendu);
	SDL_DestroyWindow(win);  
	SDL_Quit();
	return 0;
}

