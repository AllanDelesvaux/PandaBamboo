#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_mixer>
#include <stdio.h>
#include "config_sdl.h"
#include <ctime>
using namespace std;
const int LARGEUR_ = 1000;
const int HAUTEUR_ = 500;
SDL_Color blanc = { 255,255,255 };
SDL_Color rouge = { 255,0,0 };
SDL_Color vert = { 0,255,0 };
SDL_Color bleu = { 0,0,255 };

const int LARGEUR = 1200;
const int HAUTEUR = 900;
const int N = 4;

void interface_auto(SDL_Renderer* rendu) {

	for (int i = 20; i < 820; i += 200) {
		for (int j = 20; j < 820; j += 200) {
			SDL_Rect bambooPlace;
			bambooPlace.x = j;
			bambooPlace.y = i;
			bambooPlace.w = 200;
			bambooPlace.h = 200;
			SDL_SetRenderDrawColor(rendu, 255, 255, 255, 255);
			SDL_RenderDrawRect(rendu, &bambooPlace);

			SDL_Rect MaxHauteur;
			MaxHauteur.x = j + 1;
			MaxHauteur.y = i + 1;
			MaxHauteur.w = 198;
			MaxHauteur.h = 24;
			SDL_SetRenderDrawColor(rendu, 0, 0, 255, 255);
			SDL_RenderFillRect(rendu, &MaxHauteur);

		}
	}
}
struct Bamboo {
	int taille;
	int croissance;
};
void Al�atoire(Bamboo tab[][N], int taille) {
	srand(time(NULL));
	for (int i = 0; i < taille; i++) {
		for (int j = 0; j < taille; j++) {
			tab[i][j].croissance = rand() % 10 + 5;
			tab[i][j].taille = 5;
		}
	}
}
int Reduce_Max(Bamboo tab[][N], int& a, int& b) {
	int max = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (tab[i][j].taille > max) {
				max = tab[i][j].taille;
				a = i;
				b = j;
			}
		}
	}
	return max;
}
int Min(Bamboo tab[][N]) {
	int min = 200;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (tab[i][j].taille < min) {
				min = tab[i][j].taille;
			}
		}
	}
	return min;
}
int Moyenne(Bamboo Tab[][N]) {

	int somme = 0;
	for (int j = 0; j < N; j++) {
		for (int i = 0; i < N; i++) {
			somme = somme + Tab[j][i].taille;
		}
	}
	int moyenne;
	moyenne = somme / N * N;
	return moyenne;

}
int panda(SDL_Renderer* rendu, int x, int y) {
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
void Left(SDL_Renderer* rendu, int& x, int& y) {
	SDL_Rect RobotLft;
	RobotLft.x = x + 1;
	RobotLft.y = y + 1;
	RobotLft.w = 73;
	RobotLft.h = 98;
	SDL_SetRenderDrawColor(rendu, 0, 0, 0, 255);
	SDL_RenderFillRect(rendu, &RobotLft);

	x -= 200;

	panda(rendu, x, y);
}
void Right(SDL_Renderer* rendu, int& x, int& y) {
	SDL_Rect RobotRght;
	RobotRght.x = x + 1;
	RobotRght.y = y + 1;
	RobotRght.w = 73;
	RobotRght.h = 98;
	SDL_SetRenderDrawColor(rendu, 0, 0, 0, 255);
	SDL_RenderFillRect(rendu, &RobotRght);

	x += 200;

	panda(rendu, x, y);
}
void Up(SDL_Renderer* rendu, int& x, int& y) {
	SDL_Rect RobotUp;
	RobotUp.x = x + 1;
	RobotUp.y = y + 1;
	RobotUp.w = 73;
	RobotUp.h = 98;
	SDL_SetRenderDrawColor(rendu, 0, 0, 0, 255);
	SDL_RenderFillRect(rendu, &RobotUp);

	y -= 200;

	panda(rendu, x, y);
}
void Down(SDL_Renderer* rendu, int& x, int& y) {
	SDL_Rect RobotDwn;
	RobotDwn.x = x + 1;
	RobotDwn.y = y + 1;
	RobotDwn.w = 73;
	RobotDwn.h = 98;
	SDL_SetRenderDrawColor(rendu, 0, 0, 0, 255);
	SDL_RenderFillRect(rendu, &RobotDwn);

	y += 200;

	panda(rendu, x, y);
}
void legendeMan(SDL_Renderer* rendu, TTF_Font* font) {

	SDL_Rect spaceUtility;
	spaceUtility.x = 20;
	spaceUtility.y = 840;
	spaceUtility.w = 390;
	spaceUtility.h = 40;

	SDL_SetRenderDrawColor(rendu, 255, 0, 0, 255);
	SDL_RenderDrawRect(rendu, &spaceUtility);

	SDL_Rect ReturnUtility;
	ReturnUtility.x = 430;
	ReturnUtility.y = 840;
	ReturnUtility.w = 390;
	ReturnUtility.h = 40;

	SDL_SetRenderDrawColor(rendu, 255, 0, 0, 255);
	SDL_RenderDrawRect(rendu, &ReturnUtility);

	SDL_Texture* texture1 = loadText(rendu, "Space = 1 Day ", blanc, font);
	SDL_QueryTexture(texture1, NULL, NULL, &spaceUtility.w, &spaceUtility.h);
	SDL_RenderCopy(rendu, texture1, NULL, &spaceUtility);
	SDL_RenderPresent(rendu);
	SDL_DestroyTexture(texture1);

	SDL_Texture* texture2 = loadText(rendu, "Return = Cut", blanc, font);
	SDL_QueryTexture(texture1, NULL, NULL, &ReturnUtility.w, &ReturnUtility.h);
	SDL_RenderCopy(rendu, texture2, NULL, &ReturnUtility);
	SDL_RenderPresent(rendu);
	SDL_DestroyTexture(texture2);

	SDL_RenderPresent(rendu);

}
void legendeAuto(SDL_Renderer* rendu, TTF_Font* font) {

	SDL_Rect spaceUtility;
	spaceUtility.x = 20;
	spaceUtility.y = 840;
	spaceUtility.w = 390;
	spaceUtility.h = 40;

	SDL_SetRenderDrawColor(rendu, 255, 0, 0, 255);
	SDL_RenderDrawRect(rendu, &spaceUtility);

	SDL_Rect ReturnUtility;
	ReturnUtility.x = 430;
	ReturnUtility.y = 840;
	ReturnUtility.w = 390;
	ReturnUtility.h = 40;

	SDL_SetRenderDrawColor(rendu, 255, 0, 0, 255);
	SDL_RenderDrawRect(rendu, &ReturnUtility);

	SDL_Texture* texture1 = loadText(rendu, "Space = 1 Day ", blanc, font);
	SDL_QueryTexture(texture1, NULL, NULL, &spaceUtility.w, &spaceUtility.h);
	SDL_RenderCopy(rendu, texture1, NULL, &spaceUtility);
	SDL_RenderPresent(rendu);
	SDL_DestroyTexture(texture1);

	SDL_Texture* texture2 = loadText(rendu, "Return = Cut", blanc, font);
	SDL_QueryTexture(texture2, NULL, NULL, &ReturnUtility.w, &ReturnUtility.h);
	SDL_RenderCopy(rendu, texture2, NULL, &ReturnUtility);
	SDL_RenderPresent(rendu);
	SDL_DestroyTexture(texture2);

	SDL_Rect MoyenneLeg;
	MoyenneLeg.x = 845;
	MoyenneLeg.y = 620;
	MoyenneLeg.w = 320;
	MoyenneLeg.h = 40;
	SDL_SetRenderDrawColor(rendu, 0, 0, 0, 255);
	SDL_RenderDrawRect(rendu, &MoyenneLeg);

	SDL_Rect MaxLeg;
	MaxLeg.x = 845;
	MaxLeg.y = 670;
	MaxLeg.w = 320;
	MaxLeg.h = 40;
	SDL_SetRenderDrawColor(rendu, 0, 0, 0, 255);
	SDL_RenderDrawRect(rendu, &MaxLeg);

	SDL_Rect MinLeg;
	MinLeg.x = 845;
	MinLeg.y = 720;
	MinLeg.w = 320;
	MinLeg.h = 40;
	SDL_SetRenderDrawColor(rendu, 0, 0, 0, 255);
	SDL_RenderDrawRect(rendu, &MinLeg);

	SDL_Texture* texture3 = loadText(rendu, "Moyenne", rouge, font);
	SDL_QueryTexture(texture3, NULL, NULL, &MoyenneLeg.w, &MoyenneLeg.h);
	SDL_RenderCopy(rendu, texture3, NULL, &MoyenneLeg);
	SDL_RenderPresent(rendu);
	SDL_DestroyTexture(texture3);

	SDL_Texture* texture4 = loadText(rendu, "Maximum", vert, font);
	SDL_QueryTexture(texture4, NULL, NULL, &MaxLeg.w, &MaxLeg.h);
	SDL_RenderCopy(rendu, texture4, NULL, &MaxLeg);
	SDL_RenderPresent(rendu);
	SDL_DestroyTexture(texture4);

	SDL_Texture* texture5 = loadText(rendu, "Minimum", bleu, font);
	SDL_QueryTexture(texture5, NULL, NULL, &MinLeg.w, &MinLeg.h);
	SDL_RenderCopy(rendu, texture5, NULL, &MinLeg);
	SDL_RenderPresent(rendu);
	SDL_DestroyTexture(texture5);

	SDL_RenderPresent(rendu);

}
void GraphStats(SDL_Renderer* rendu) {

	SDL_Rect Graph;
	Graph.x = 835;
	Graph.y = 280;
	Graph.w = 355;
	Graph.h = 320;
	SDL_SetRenderDrawColor(rendu, 255, 255, 255, 255);
	SDL_RenderFillRect(rendu, &Graph);
	SDL_SetRenderDrawColor(rendu, 0, 0, 0, 255);
	SDL_RenderDrawLine(rendu, 845, 290, 845, 590);
	SDL_RenderDrawLine(rendu, 845, 590, 1175, 590);
	SDL_RenderDrawLine(rendu, 845, 290, 855, 300);
	SDL_RenderDrawLine(rendu, 845, 290, 835, 300);
	SDL_RenderDrawLine(rendu, 1175, 590, 1165, 580);
	SDL_RenderDrawLine(rendu, 1175, 590, 1165, 600);
	SDL_RenderPresent(rendu);
}
void AfficheStats(SDL_Renderer* rendu, int TabMoy[], int TabMin[], int TabMax[], int& a, int& c) {
	SDL_Rect Graph;
	Graph.x = 855;
	Graph.y = 280;
	Graph.w = 335;
	Graph.h = 300;
	SDL_SetRenderDrawColor(rendu, 255, 255, 255, 255);
	SDL_RenderFillRect(rendu, &Graph);
	for (int i = c; i < 100 + c; i++) {

		a = 856 + (i - c) * 3;
		SDL_SetRenderDrawColor(rendu, 255, 0, 0, 255);
		SDL_RenderDrawLine(rendu, a, 290 + TabMoy[(i) % 100] / 10, a + 3, 290 + TabMoy[(i + 1) % 100] / 10);
		SDL_RenderPresent(rendu);

		SDL_SetRenderDrawColor(rendu, 0, 255, 0, 255);
		SDL_RenderDrawLine(rendu, a, 390 + TabMax[(i) % 100], a + 3, 390 + TabMax[(i + 1) % 100]);
		SDL_RenderPresent(rendu);

		SDL_SetRenderDrawColor(rendu, 0, 0, 255, 255);
		SDL_RenderDrawLine(rendu, a, 490 + TabMin[(i) % 100], a + 3, 490 + TabMin[(i + 1) % 100]);
		SDL_RenderPresent(rendu);

	}
	a = 856;
}
void Stats(Bamboo Tab[][N], int TabMoy[], int TabMin[], int TabMax[], int& o, int& c) {
	int e;
	int h;
	if (o == 100) {
		o = 0;
		c++;
	}
	TabMoy[o] = Moyenne(Tab);
	TabMin[o] = Min(Tab);
	TabMax[o] = Reduce_Max(Tab, e, h);
	o++;
}
int jeuAuto() {
	Bamboo Tab[N][N];
	Al�atoire(Tab, N);
	int TabMoy[100] = { 0 };
	int TabMax[100] = { 0 };
	int TabMin[100] = { 0 };
	int positionx1 = 850;
	int c = 0;
	int o = 0;
	int a = 0;
	int b = 0;
	int x = 145;
	int y = 720;
	int a1 = 0;
	int b1 = 0;
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		std::cout << "Echec � l�ouverture";
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
		std::cout << "erreur ouverture fenetre";

	SDL_Renderer* rendu = SDL_CreateRenderer(
		win,
		-1,
		SDL_RENDERER_ACCELERATED);

	TTF_Init();
	TTF_Font* font = TTF_OpenFont("RobotoMono-Light.ttf", 30);
	TTF_Quit();
	interface_auto(rendu);
	legendeAuto(rendu, font);
	GraphStats(rendu);
	bool continuer = true;
	SDL_Event event;
	SDL_Delay(1000);
	while (continuer)
	{
		SDL_WaitEventTimeout(&event, 1000);
		switch (event.type)
		{
		case SDL_QUIT:

			continuer = false;
			break;
		case SDL_KEYDOWN:
			if (event.key.keysym.sym == SDLK_t) {
				while (Reduce_Max(Tab, a, b) < 170) {
					for (int i = 0; i < N; i++) {
						for (int j = 0; j < N; j++) {
							Tab[i][j].taille += Tab[i][j].croissance;
						}
					}
					for (int i = 0; i < N; i++) {
						for (int j = 0; j < N; j++) {
							SDL_Rect bamboo;
							bamboo.x = j * 200 + 83;
							bamboo.y = (i + 1) * 200 + 20 - Tab[i][j].taille;
							bamboo.w = 10;
							bamboo.h = Tab[i][j].taille;
							SDL_SetRenderDrawColor(rendu, 0, 255, 0, 255);
							SDL_RenderFillRect(rendu, &bamboo);

							SDL_Rect bambooStep;
							bambooStep.x = j * 200 + 80;
							bambooStep.y = (i + 1) * 200 + 20 - Tab[i][j].taille;
							bambooStep.w = 16;
							bambooStep.h = 2;
							SDL_SetRenderDrawColor(rendu, 0, 128, 0, 255);
							SDL_RenderFillRect(rendu, &bambooStep);
							SDL_RenderPresent(rendu);
						}
					}
					SDL_RenderPresent(rendu);
					SDL_Rect Cut;
					Cut.x = b * 200 + 73;
					Cut.y = (a + 1) * 200 - 155;
					Cut.w = 40;
					Cut.h = 169;
					SDL_SetRenderDrawColor(rendu, 0, 0, 0, 255);
					SDL_RenderFillRect(rendu, &Cut);
					SDL_RenderPresent(rendu);
					Tab[a][b].taille = 5;
					panda(rendu, b * 200 + 147, (a + 1) * 200 - 76);
					SDL_Rect Cutpanda;
					Cutpanda.x = b1 * 200 + 146;
					Cutpanda.y = (a1 + 1) * 200 - 79;
					Cutpanda.w = 73;
					Cutpanda.h = 98;
					SDL_SetRenderDrawColor(rendu, 0, 0, 0, 255);
					SDL_RenderFillRect(rendu, &Cutpanda);
					a1 = a;
					b1 = b;
					SDL_RenderPresent(rendu);
					SDL_Delay(100);
					Stats(Tab, TabMoy, TabMin, TabMax, o, c);
					AfficheStats(rendu, TabMoy, TabMin, TabMax, positionx1, c);
				}
			}
		}
	}
	SDL_DestroyRenderer(rendu);
	SDL_DestroyWindow(win);
	SDL_Quit();
	std::cout << "perdu";
	return 0;
}
int jeuMan() {
	Bamboo Tab[N][N];
	Al�atoire(Tab, N);
	int TabMoy[100] = { 0 };
	int TabMax[100] = { 0 };
	int TabMin[100] = { 0 };
	int positionx1 = 850;
	int w = 0;
	int c = 0;
	int o = 0;
	int a = 0;
	int b = 0;
	int x = 145;
	int y = 720;
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		std::cout << "Echec � l�ouverture";
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
		std::cout << "erreur ouverture fenetre";

	SDL_Renderer* rendu = SDL_CreateRenderer(
		win,
		-1,
		SDL_RENDERER_ACCELERATED);

	TTF_Init();
	TTF_Font* font = TTF_OpenFont("RobotoMono-Light.ttf", 30);
	TTF_Quit();
	interface_auto(rendu);
	panda(rendu, x, y);
	SDL_RenderPresent(rendu);
	legendeMan(rendu, font);
	GraphStats(rendu);

	bool continuer = true;
	SDL_Event event;

	while (continuer && Reduce_Max(Tab, a, b) < 175)
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
				Cut.y = y - 75;
				Cut.w = 40;
				Cut.h = 169;
				Tab[(y - 20) / 200][(x - 20) / 200].taille = 5;
				SDL_SetRenderDrawColor(rendu, 0, 0, 0, 255);
				SDL_RenderFillRect(rendu, &Cut);
				SDL_RenderPresent(rendu);
				for (int i = 0; i < N; i++) {
					for (int j = 0; j < N; j++) {
						Tab[i][j].taille += Tab[i][j].croissance;
					}
				}
				for (int i = 0; i < N; i++) {
					for (int j = 0; j < N; j++) {
						SDL_Rect bamboo;
						bamboo.x = j * 200 + 83;
						bamboo.y = (i + 1) * 200 + 20 - Tab[i][j].taille;
						bamboo.w = 10;
						bamboo.h = Tab[i][j].taille;
						SDL_SetRenderDrawColor(rendu, 0, 255, 0, 255);
						SDL_RenderFillRect(rendu, &bamboo);

						SDL_Rect bambooStep;
						bambooStep.x = j * 200 + 80;
						bambooStep.y = (i + 1) * 200 + 20 - Tab[i][j].taille;
						bambooStep.w = 16;
						bambooStep.h = 2;
						SDL_SetRenderDrawColor(rendu, 0, 128, 0, 255);
						SDL_RenderFillRect(rendu, &bambooStep);
						SDL_RenderPresent(rendu);

					}
				}
				if (w % 5 == 0) {
					Stats(Tab, TabMoy, TabMin, TabMax, o, c);
					AfficheStats(rendu, TabMoy, TabMin, TabMax, positionx1, c);
				}
				w++;
			}
			if (event.key.keysym.sym == SDLK_SPACE) {
				for (int i = 0; i < N; i++) {
					for (int j = 0; j < N; j++) {
						Tab[i][j].taille += Tab[i][j].croissance;
					}
				}
				for (int i = 0; i < N; i++) {
					for (int j = 0; j < N; j++) {
						SDL_Rect bamboo;
						bamboo.x = j * 200 + 83;
						bamboo.y = (i + 1) * 200 + 20 - Tab[i][j].taille;
						bamboo.w = 10;
						bamboo.h = Tab[i][j].taille;
						SDL_SetRenderDrawColor(rendu, 0, 255, 0, 255);
						SDL_RenderFillRect(rendu, &bamboo);

						SDL_Rect bambooStep;
						bambooStep.x = j * 200 + 80;
						bambooStep.y = (i + 1) * 200 + 20 - Tab[i][j].taille;
						bambooStep.w = 16;
						bambooStep.h = 2;
						SDL_SetRenderDrawColor(rendu, 0, 128, 0, 255);
						SDL_RenderFillRect(rendu, &bambooStep);
						SDL_RenderPresent(rendu);

					}
				}
				if (w % 5 == 0) {
					Stats(Tab, TabMoy, TabMin, TabMax, o, c);
					AfficheStats(rendu, TabMoy, TabMin, TabMax, positionx1, c);
				}
				w++;
			}
		}
	}
	SDL_DestroyRenderer(rendu);
	SDL_DestroyWindow(win);
	SDL_Quit();
	std::cout << "Vous avez perdu !";
	return 0;
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

	bool in_menu = true;
	if (SDL_Init(SDL_INIT_VIDEO |  SDL_INIT_AUDIO) != 0) {
		std::cout << "Echec � l�ouverture";
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

	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
		std::cout << "Error : " << Mix_GetError() << std::endl;

	Mix_Music* bgm = Mix_LoadMUS("panda_type_beat.wav");
	Mix_Chunk* soundEffect = Mix_LoadWav("panda_type_beat.wav");

	if (win == NULL)
		std::cout << "erreur ouverture fenetre";


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
		if (ev.type == SDL_KEYDOWN)
		{
			switch (ev.key.keysm.sym)
			{
			case SDLK_p:
				if (Mix_PlayingMusic())
					Mix_PlayMusic(bgm, -1);
				else if (Mix_PausedMusic())
					Mix_ResumeMusic();
				else(Mix_PauseMusic);
				break;
			case SDLK_s:
				Mix_HaltMusic();
				break;
			}
		}
		switch (event.type)
		{
		case SDL_QUIT:

			continuer = false;
			break;

		case SDL_MOUSEBUTTONUP:
			if (event.button.button == SDL_BUTTON_LEFT && in_menu) {
				if (event.button.x > 80 && event.button.x < LARGEUR_ / 2 - 80 && event.button.y>HAUTEUR_ / 2 - 100 && event.button.y < HAUTEUR_ / 2 + 100) {
					std::cout << "�a marche\n";
					in_menu = false;
					SDL_DestroyRenderer(rendu);
					SDL_DestroyWindow(win);
					jeuAuto();
				}
				else if (event.button.x > LARGEUR_ / 2 + 80 && event.button.x < LARGEUR_ - 80 && event.button.y>HAUTEUR_ / 2 - 100 && event.button.y < HAUTEUR_ / 2 + 100) {
					std::cout << "�a marche\n";
					in_menu = false;
					SDL_DestroyRenderer(rendu);
					SDL_DestroyWindow(win);
					jeuMan();
				}
			}
		}
	}

	SDL_DestroyRenderer(rendu);
	SDL_DestroyWindow(win);
	Mix_FreeChunk(soundEffect);
	Mix_FreeMusic(bgm);

	bgm = nullptr;
	soundEffect = nullptr;
	
	Mix_Quit();  
	SDL_Quit();
	return 0;
}
