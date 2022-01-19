#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>
#include "config_sdl.h"
#include <ctime>
using namespace std;
const int LARGEUR_ = 1000;
const int HAUTEUR_ = 500;
SDL_Color blanc = { 255, 255, 255 };
SDL_Color rouge = { 255, 0, 0 };
SDL_Color vert = { 0, 255, 0 };
SDL_Color bleu = { 0, 0, 255 };

const int LARGEUR = 1200;
const int HAUTEUR = 900;
const int N = 4;

void in(SDL_Renderer* co) {


}

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
void Aléatoire(Bamboo tab[][N], int taille) {
	srand(time(NULL));
	for (int i = 0; i < taille; i++) {
		for (int j = 0; j < taille; j++) {
			tab[i][j].croissance = rand() % 5 + 5;
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
void Reduce_Fastest(Bamboo tab[][N], int& a, int& b) {
	int j, H = 0, max = 0;
	for (int i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			H += tab[i][j].croissance;
		}
	}
	int x = 1 + 1 / sqrt(5);
	for (int i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if (tab[i][j].taille > x * H) {
				max = tab[i][j].taille;
				a = i;
				b = j;
			}
		}
	}
}
int Min(Bamboo tab[][N], int a, int b) {
	tab[a][b].taille = 200;
	int min = 200;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (tab[i][j].taille < min) {
				min = tab[i][j].taille;
			}
		}
	}
	tab[a][b].taille = 5;
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
	SDL_DestroyTexture(texture1);

	SDL_Texture* texture2 = loadText(rendu, "Return = Cut", blanc, font);
	SDL_QueryTexture(texture1, NULL, NULL, &ReturnUtility.w, &ReturnUtility.h);
	SDL_RenderCopy(rendu, texture2, NULL, &ReturnUtility);
	SDL_DestroyTexture(texture2);

	SDL_Rect MoyenneLeg;
	MoyenneLeg.x = 845;
	MoyenneLeg.y = 620;
	MoyenneLeg.w = 320;
	MoyenneLeg.h = 40;
	SDL_SetRenderDrawColor(rendu, 0, 0, 0, 255);
	SDL_RenderDrawRect(rendu, &MoyenneLeg);


	SDL_Rect quit;
	quit.x = 845;
	quit.y = 130;
	quit.w = 320;
	quit.h = 40;
	SDL_SetRenderDrawColor(rendu, 0, 0, 0, 255);
	SDL_RenderDrawRect(rendu, &quit);

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
	SDL_DestroyTexture(texture3);

	SDL_Texture* texture8 = loadText(rendu, "Exit = Escape", blanc, font);
	SDL_QueryTexture(texture8, NULL, NULL, &quit.w, &quit.h);
	SDL_RenderCopy(rendu, texture8, NULL, &quit);
	SDL_DestroyTexture(texture8);

	SDL_Texture* texture4 = loadText(rendu, "Maximum", vert, font);
	SDL_QueryTexture(texture4, NULL, NULL, &MaxLeg.w, &MaxLeg.h);
	SDL_RenderCopy(rendu, texture4, NULL, &MaxLeg);
	SDL_DestroyTexture(texture4);

	SDL_Texture* texture5 = loadText(rendu, "Minimum", bleu, font);
	SDL_QueryTexture(texture5, NULL, NULL, &MinLeg.w, &MinLeg.h);
	SDL_RenderCopy(rendu, texture5, NULL, &MinLeg);
	SDL_DestroyTexture(texture5);

	SDL_RenderPresent(rendu);

}
void legendeAuto(SDL_Renderer* rendu, TTF_Font* font) {


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
	SDL_DestroyTexture(texture3);

	SDL_Texture* texture4 = loadText(rendu, "Maximum", vert, font);
	SDL_QueryTexture(texture4, NULL, NULL, &MaxLeg.w, &MaxLeg.h);
	SDL_RenderCopy(rendu, texture4, NULL, &MaxLeg);
	SDL_DestroyTexture(texture4);

	SDL_Texture* texture5 = loadText(rendu, "Minimum", bleu, font);
	SDL_QueryTexture(texture5, NULL, NULL, &MinLeg.w, &MinLeg.h);
	SDL_RenderCopy(rendu, texture5, NULL, &MinLeg);
	SDL_DestroyTexture(texture5);

	SDL_Rect play;
	play.x = 845;
	play.y = 30;
	play.w = 320;
	play.h = 40;
	SDL_SetRenderDrawColor(rendu, 0, 0, 0, 255);
	SDL_RenderDrawRect(rendu, &play);

	SDL_Rect pause;
	pause.x = 845;
	pause.y = 80;
	pause.w = 320;
	pause.h = 40;
	SDL_SetRenderDrawColor(rendu, 0, 0, 0, 255);
	SDL_RenderDrawRect(rendu, &pause);

	SDL_Rect quit;
	quit.x = 845;
	quit.y = 130;
	quit.w = 320;
	quit.h = 40;
	SDL_SetRenderDrawColor(rendu, 0, 0, 0, 255);
	SDL_RenderDrawRect(rendu, &quit);

	SDL_Rect max;
	max.x = 845;
	max.y = 180;
	max.w = 320;
	max.h = 40;
	SDL_SetRenderDrawColor(rendu, 0, 0, 0, 255);
	SDL_RenderDrawRect(rendu, &max);

	SDL_Rect fast;
	fast.x = 845;
	fast.y = 230;
	fast.w = 320;
	fast.h = 40;
	SDL_SetRenderDrawColor(rendu, 0, 0, 0, 255);
	SDL_RenderDrawRect(rendu, &fast);

	SDL_Texture* texture6 = loadText(rendu, "PLAY = r", blanc, font);
	SDL_QueryTexture(texture6, NULL, NULL, &play.w, &play.h);
	SDL_RenderCopy(rendu, texture6, NULL, &play);
	SDL_DestroyTexture(texture6);

	SDL_Texture* texture7 = loadText(rendu, "Pause = t", blanc, font);
	SDL_QueryTexture(texture7, NULL, NULL, &pause.w, &pause.h);
	SDL_RenderCopy(rendu, texture7, NULL, &pause);
	SDL_DestroyTexture(texture7);

	SDL_Texture* texture8 = loadText(rendu, "Exit = Escape", blanc, font);
	SDL_QueryTexture(texture8, NULL, NULL, &quit.w, &quit.h);
	SDL_RenderCopy(rendu, texture8, NULL, &quit);
	SDL_DestroyTexture(texture8);

	SDL_Texture* texture9= loadText(rendu, "Reduce Max = M", blanc, font);
	SDL_QueryTexture(texture9, NULL, NULL, &max.w, &max.h);
	SDL_RenderCopy(rendu, texture9, NULL, &max);
	SDL_DestroyTexture(texture9);

	SDL_Texture* texture10 = loadText(rendu, "Reduce Fastest = P", blanc, font);
	SDL_QueryTexture(texture10, NULL, NULL, &fast.w, &fast.h);
	SDL_RenderCopy(rendu, texture10, NULL, &fast);
	SDL_DestroyTexture(texture10);



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
	for (int i = 0; i < 9; i++) {

		a = 856 + i * 30 ;
		SDL_SetRenderDrawColor(rendu, 255, 0, 0, 255);
		SDL_RenderDrawLine(rendu, a, 570 - TabMoy[i]/14, a + 30, 570 - TabMoy[(i + 1)]/14);

		SDL_SetRenderDrawColor(rendu, 0, 255, 0, 255);
		SDL_RenderDrawLine(rendu, a, 570 - TabMax[i], a + 30, 570 - TabMax[(i + 1)]);

		SDL_SetRenderDrawColor(rendu, 0, 0, 255, 255);
		SDL_RenderDrawLine(rendu, a, 570 - TabMin[i], a + 30, 570 - TabMin[(i + 1)]);

	}
	a = 856;
}
void Stats(Bamboo Tab[][N], int TabMoy[], int TabMin[], int TabMax[], int& c, int a, int b) {
	int e;
	int h;
	for (int i = 0; i < 9; i++) {
		TabMoy[i] = TabMoy[i+1];
		TabMin[i] = TabMin[i+1];
		TabMax[i] = TabMax[i+1];
	}
	TabMoy[9] = Moyenne(Tab);
	TabMin[9] = Min(Tab, a, b);
	TabMax[9] = Reduce_Max(Tab, e, h);
}
void AfficheRecharge(SDL_Renderer* rendu, int taille) {
	for (int i = 0; i < 7; i++) {
		SDL_Rect rg;
		rg.x = 845 + 40 * i;
		rg.y = 770;
		rg.w = 40;
		rg.h = 40;
		SDL_SetRenderDrawColor(rendu, 255, 255, 255, 255);
		SDL_RenderDrawRect(rendu, &rg);
		if (i < taille) {
			SDL_Rect rt;
			rt.x = 846 + 40 * i;
			rt.y = 771;
			rt.w = 38;
			rt.h = 38;
			SDL_SetRenderDrawColor(rendu, 0, 255, 0, 255);
			SDL_RenderFillRect(rendu, &rt);
		}if (i >= taille) {
			SDL_Rect rt;
			rt.x = 846 + 40 * i;
			rt.y = 771;
			rt.w = 38;
			rt.h = 38;
			SDL_SetRenderDrawColor(rendu, 0, 0, 0, 255);
			SDL_RenderFillRect(rendu, &rt);
		}
	}
}
int create_conf() {
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		std::cout << "Echec à l’ouverture";
		return 1;
	}
	TTF_Font* font = TTF_OpenFont("Snes.ttf", 25);
	SDL_Window* configuration = SDL_CreateWindow("Creer une configuration",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		LARGEUR / 4,
		HAUTEUR / 4,
		SDL_WINDOW_SHOWN
	);
	SDL_Renderer* co = SDL_CreateRenderer(
		configuration,
		-1,
		SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawBlendMode(co, SDL_BLENDMODE_BLEND);
	// premiere entrée
	SDL_Rect label_conf;
	label_conf.x = 20;
	label_conf.y = 30;
	label_conf.w = 70;
	label_conf.h = 30;
	SDL_Texture* label = loadText(co, "Nom Config:", blanc, font);
	SDL_QueryTexture(label, NULL, NULL, &label_conf.w, &label_conf.h);
	SDL_RenderCopy(co, label, NULL, &label_conf);
	SDL_DestroyTexture(label);

	SDL_Rect nom_conf;
	nom_conf.x = 135;
	nom_conf.y = 30;
	nom_conf.w = 140;
	nom_conf.h = 30;

	// deuxième entrée
	SDL_Rect label_conf2;
	label_conf2.x = 20;
	label_conf2.y = 80;
	label_conf2.w = 70;
	label_conf2.h = 30;
	SDL_Texture* label2 = loadText(co, "Nombre Bambous:", blanc, font);
	SDL_QueryTexture(label2, NULL, NULL, &label_conf2.w, &label_conf2.h);
	SDL_RenderCopy(co, label2, NULL, &label_conf2);
	SDL_DestroyTexture(label2);

	SDL_Rect nom_conf2;
	nom_conf2.x = 190;
	nom_conf2.y = 80;
	nom_conf2.w = 40;
	nom_conf2.h = 30;

	SDL_Rect end;
	end.x = 120;
	end.y = 140;
	end.w = 40;
	end.h = 30;
	SDL_Texture* label3 = loadText(co, "Create !", blanc, font);
	SDL_QueryTexture(label3, NULL, NULL, &end.w, &end.h);
	SDL_RenderCopy(co, label3, NULL, &end);
	SDL_DestroyTexture(label3);

	// Couleur et Render
	SDL_SetRenderDrawColor(co, 255, 255, 255, 255);
	SDL_RenderDrawRect(co, &nom_conf);
	SDL_RenderDrawRect(co, &label_conf);
	SDL_RenderDrawRect(co, &nom_conf2);
	SDL_RenderDrawRect(co, &label_conf2);
	SDL_RenderDrawRect(co, &end);
	SDL_RenderPresent(co);
	SDL_Delay(5000);
	SDL_DestroyWindow(configuration);

}
int import_conf() {
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		std::cout << "Echec à l’ouverture";
		return 1;
	}
	TTF_Font* font = TTF_OpenFont("Snes.ttf", 25);
	SDL_Window* configuration = SDL_CreateWindow("Importer une config",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		LARGEUR / 4,
		HAUTEUR / 6,
		SDL_WINDOW_SHOWN
	);
	SDL_Renderer* co = SDL_CreateRenderer(
		configuration,
		-1,
		SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawBlendMode(co, SDL_BLENDMODE_BLEND);
	// premiere entrée
	SDL_Rect label_conf;
	label_conf.x = 20;
	label_conf.y = 30;
	label_conf.w = 70;
	label_conf.h = 30;
	SDL_Texture* label = loadText(co, "Nom Config:", blanc, font);
	SDL_QueryTexture(label, NULL, NULL, &label_conf.w, &label_conf.h);
	SDL_RenderCopy(co, label, NULL, &label_conf);
	SDL_DestroyTexture(label);

	SDL_Rect nom_conf;
	nom_conf.x = 135;
	nom_conf.y = 30;
	nom_conf.w = 140;
	nom_conf.h = 30;

	SDL_Rect end;
	end.x = 120;
	end.y = 90;
	end.w = 40;
	end.h = 30;
	SDL_Texture* label3 = loadText(co, "Import !", blanc, font);
	SDL_QueryTexture(label3, NULL, NULL, &end.w, &end.h);
	SDL_RenderCopy(co, label3, NULL, &end);
	SDL_DestroyTexture(label3);




	// Couleur et Render
	SDL_SetRenderDrawColor(co, 255, 255, 255, 255);
	SDL_RenderDrawRect(co, &nom_conf);
	SDL_RenderDrawRect(co, &label_conf);
	SDL_RenderDrawRect(co, &end);
	SDL_RenderPresent(co);
	bool continuer = true;
	SDL_Event event;
	SDL_Event textinput;
	// Gestion des évenements
	while (continuer)
	{
		SDL_WaitEvent(&event);
		switch (event.type)
		{
		case SDL_QUIT:
			SDL_DestroyRenderer(co);
			SDL_DestroyWindow(configuration);
			continuer = false;
			break;

		case SDL_MOUSEBUTTONUP:
			if (event.button.x > LARGEUR_ - 103 && event.button.x < (LARGEUR_ - 103) + 64 && event.button.y>HAUTEUR_ - 96 && event.button.y < (HAUTEUR_ - 96) + 64) {
			}


		}
	}



	SDL_DestroyRenderer(co);
	SDL_DestroyWindow(configuration);
}
int jeuAuto(bool& menu) {
	Bamboo Tab[N][N];
	Aléatoire(Tab, N);
	int TabMoy[10] = { 0 };
	int TabMax[10] = { 0 };
	int TabMin[10] = { 0 };
	int positionx1 = 850;
	int recharge = 7;
	int c = 0;
	int a = 0;
	int b = 0;
	int x = 145;
	int y = 720;
	int a1 = 3;
	int b1 = 3;
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		std::cout << "Echec à l’ouverture mode auto";
		return 1;
	}

	SDL_Window* autowin = SDL_CreateWindow("Mode Automatique",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		LARGEUR,
		HAUTEUR,
		SDL_WINDOW_SHOWN
	);
	if (autowin == NULL)
		std::cout << "Erreur ouverture fenetre automatique";

	SDL_Renderer* autorend = SDL_CreateRenderer(
		autowin,
		-1,
		SDL_RENDERER_ACCELERATED);

	TTF_Init();
	TTF_Font* font = TTF_OpenFont("Snes.ttf", 30);
	TTF_Quit();
	interface_auto(autorend);
	legendeAuto(autorend, font);
	GraphStats(autorend);
	AfficheRecharge(autorend, recharge);
	bool continuer = true;
	SDL_Event event;
	bool TimePlay = true;
	bool Mode = true;
	SDL_EventState(SDL_MOUSEMOTION, false);
	while (continuer)
	{
		SDL_WaitEventTimeout(&event, 800);
		switch (event.type)
		{
		case SDL_QUIT:
			SDL_DestroyRenderer(autorend);
			SDL_DestroyWindow(autowin);
			continuer = false;
			menu = true;
			printf("Vous avez quitté le mode manuel\n----> Retour au Menu !\n");
			return(-1);
		case SDL_KEYDOWN:
			if (event.key.keysym.sym == SDLK_t) {
				TimePlay = false;
			}
			if (event.key.keysym.sym == SDLK_r) {
				TimePlay = true;
			
			}
			if (event.key.keysym.sym == SDLK_ESCAPE) {
				SDL_DestroyRenderer(autorend);
				SDL_DestroyWindow(autowin);
				continuer = false;
				menu = true;
				printf("Vous avez quitté le mode automatique\n----> Retour au Menu !\n");
				return-1;
			}
			if (event.key.keysym.sym == SDLK_p) {
				Mode = false;
				printf("\nMode Fastest actif ! \n");
				SDL_Rect active; //fastest
				active.w = 20;
				active.h = 20;
				active.x = 845+ 330;
				active.y = 180;
				SDL_SetRenderDrawColor(autorend, 0, 0, 0, 255);
				SDL_RenderFillRect(autorend, &active);
				SDL_RenderPresent(autorend);
				active.y = 230;
				SDL_SetRenderDrawColor(autorend, 0, 255, 0, 255);
				SDL_RenderFillRect(autorend, &active);
				SDL_RenderPresent(autorend);
			}
			if (event.key.keysym.sym == SDLK_m) {
				Mode = true; //autre
				printf("\nMode Max  actif ! \n");
				SDL_Rect active; 
				active.w = 20;
				active.h = 20;
				active.x = 845 + 330;
				active.y = 230;
				SDL_SetRenderDrawColor(autorend, 0, 0, 0, 255);
				SDL_RenderFillRect(autorend, &active);
				SDL_RenderPresent(autorend);
				active.y = 180;
				SDL_SetRenderDrawColor(autorend, 0, 255, 0, 255);
				SDL_RenderFillRect(autorend, &active);
				SDL_RenderPresent(autorend);
			}
		}
		if(Mode == false){
			Reduce_Fastest(Tab, a, b);
			if (Tab[a][b].taille < 170) {
				if (TimePlay == true) {
					SDL_Delay(200);
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
							SDL_SetRenderDrawColor(autorend, 0, 255, 0, 255);
							SDL_RenderFillRect(autorend, &bamboo);

							SDL_Rect bambooStep;
							bambooStep.x = j * 200 + 80;
							bambooStep.y = (i + 1) * 200 + 20 - Tab[i][j].taille;
							bambooStep.w = 16;
							bambooStep.h = 2;
							SDL_SetRenderDrawColor(autorend, 0, 128, 0, 255);
							SDL_RenderFillRect(autorend, &bambooStep);
						}
					}
					//if (a == a1 || b == b1) {
					SDL_Rect Cut;
					Cut.x = b * 200 + 73;
					Cut.y = (a + 1) * 200 - 155;
					Cut.w = 40;
					Cut.h = 169;
					SDL_SetRenderDrawColor(autorend, 0, 0, 0, 255);
					SDL_RenderFillRect(autorend, &Cut);
					Tab[a][b].taille = 5;
					panda(autorend, b * 200 + 147, (a + 1) * 200 - 76);
					SDL_Rect Cutpanda;
					Cutpanda.x = b1 * 200 + 146;
					Cutpanda.y = (a1 + 1) * 200 - 79;
					Cutpanda.w = 73;
					Cutpanda.h = 98;
					SDL_SetRenderDrawColor(autorend, 0, 0, 0, 255);
					SDL_RenderFillRect(autorend, &Cutpanda);
					a1 = a;
					b1 = b;
					//}
					/*else {
						panda(rendu, b * 200 + 147, (a1 + 1) * 200 - 76);
						SDL_Rect Cutpanda;
						Cutpanda.x = b1 * 200 + 146;
						Cutpanda.y = (a1 + 1) * 200 - 79;
						Cutpanda.w = 73;
						Cutpanda.h = 98;
						SDL_SetRenderDrawColor(rendu, 0, 0, 0, 255);
						SDL_RenderFillRect(rendu, &Cutpanda);
						SDL_RenderPresent(rendu);
						b1 = b;
					}*/
					Stats(Tab, TabMoy, TabMin, TabMax, c, a, b);
					AfficheStats(autorend, TabMoy, TabMin, TabMax, positionx1, c);
					recharge--;
					if (recharge == 0) {
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
								SDL_SetRenderDrawColor(autorend, 0, 255, 0, 255);
								SDL_RenderFillRect(autorend, &bamboo);

								SDL_Rect bambooStep;
								bambooStep.x = j * 200 + 80;
								bambooStep.y = (i + 1) * 200 + 20 - Tab[i][j].taille;
								bambooStep.w = 16;
								bambooStep.h = 2;
								SDL_SetRenderDrawColor(autorend, 0, 128, 0, 255);
								SDL_RenderFillRect(autorend, &bambooStep);
								recharge = 7;
							}
						}
					}
					AfficheRecharge(autorend, recharge);
					SDL_RenderPresent(autorend);

				}
			}
			else {
				break;
			}
		}
		else{
			if (Reduce_Max(Tab, a, b) < 170) {
				if (TimePlay == true) {
					SDL_Delay(200);
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
							SDL_SetRenderDrawColor(autorend, 0, 255, 0, 255);
							SDL_RenderFillRect(autorend, &bamboo);

							SDL_Rect bambooStep;
							bambooStep.x = j * 200 + 80;
							bambooStep.y = (i + 1) * 200 + 20 - Tab[i][j].taille;
							bambooStep.w = 16;
							bambooStep.h = 2;
							SDL_SetRenderDrawColor(autorend, 0, 128, 0, 255);
							SDL_RenderFillRect(autorend, &bambooStep);
						}
					}
					//if (a == a1 || b == b1) {
					SDL_Rect Cut;
					Cut.x = b * 200 + 73;
					Cut.y = (a + 1) * 200 - 155;
					Cut.w = 40;
					Cut.h = 169;
					SDL_SetRenderDrawColor(autorend, 0, 0, 0, 255);
					SDL_RenderFillRect(autorend, &Cut);
					Tab[a][b].taille = 5;
					panda(autorend, b * 200 + 147, (a + 1) * 200 - 76);
					SDL_Rect Cutpanda;
					Cutpanda.x = b1 * 200 + 146;
					Cutpanda.y = (a1 + 1) * 200 - 79;
					Cutpanda.w = 73;
					Cutpanda.h = 98;
					SDL_SetRenderDrawColor(autorend, 0, 0, 0, 255);
					SDL_RenderFillRect(autorend, &Cutpanda);
					a1 = a;
					b1 = b;
					//}
					/*else {
						panda(rendu, b * 200 + 147, (a1 + 1) * 200 - 76);
						SDL_Rect Cutpanda;
						Cutpanda.x = b1 * 200 + 146;
						Cutpanda.y = (a1 + 1) * 200 - 79;
						Cutpanda.w = 73;
						Cutpanda.h = 98;
						SDL_SetRenderDrawColor(rendu, 0, 0, 0, 255);
						SDL_RenderFillRect(rendu, &Cutpanda);
						SDL_RenderPresent(rendu);
						b1 = b;
					}*/
					Stats(Tab, TabMoy, TabMin, TabMax, c, a, b);
					AfficheStats(autorend, TabMoy, TabMin, TabMax, positionx1, c);
					recharge--;
					if (recharge == 0) {
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
								SDL_SetRenderDrawColor(autorend, 0, 255, 0, 255);
								SDL_RenderFillRect(autorend, &bamboo);

								SDL_Rect bambooStep;
								bambooStep.x = j * 200 + 80;
								bambooStep.y = (i + 1) * 200 + 20 - Tab[i][j].taille;
								bambooStep.w = 16;
								bambooStep.h = 2;
								SDL_SetRenderDrawColor(autorend, 0, 128, 0, 255);
								SDL_RenderFillRect(autorend, &bambooStep);
								recharge = 7;
							}
						}
					}
					AfficheRecharge(autorend, recharge);
					SDL_RenderPresent(autorend);
				}
			}
			else {
				break;
			}
		}
	}
	menu = true;
	SDL_DestroyRenderer(autorend);
	SDL_DestroyWindow(autowin);
	std::cout << "Mode Automatique : Perdu\n";
	return 0;
}
int jeuMan(bool& menu) {
	Bamboo Tab[N][N];
	Aléatoire(Tab, N);
	int TabMoy[10] = { 0 };
	int TabMax[10] = { 0 };
	int TabMin[10] = { 0 };
	int positionx1 = 850;
	int limCases = 3;
	int recharge = 7;
	int w = 0;
	int c = 0;
	int a = 0;
	int b = 0;
	int x = 145;
	int y = 720;
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		std::cout << "\nEchec à l’ouverture mode manuel\n";
		return 1;
	}

	SDL_Window* manwin = SDL_CreateWindow("Mode Manuel",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		LARGEUR,
		HAUTEUR,
		SDL_WINDOW_SHOWN
	);
	if (manwin == NULL)
		std::cout << "\nErreur ouverture fenetre mode manuel\n";

	SDL_Renderer* manrend = SDL_CreateRenderer(
		manwin,
		-1,
		SDL_RENDERER_ACCELERATED);

	TTF_Init();
	TTF_Font* font = TTF_OpenFont("Snes.ttf", 30);
	TTF_Quit();
	interface_auto(manrend);
	panda(manrend, x, y);
	//SDL_RenderPresent(manrend);
	legendeMan(manrend, font);
	GraphStats(manrend);
	AfficheRecharge(manrend, recharge);

	bool continuer = true;
	SDL_Event event;

	while (continuer && Reduce_Max(Tab, a, b) < 170)
	{
		SDL_WaitEvent(&event);
		switch (event.type)
		{
		case SDL_QUIT:
			SDL_DestroyRenderer(manrend);
			SDL_DestroyWindow(manwin);
			menu = true;
			continuer = false;
			printf("Vous avez quitté le mode manuel\n----> Retour au Menu !\n");
			return -1;
		case SDL_KEYDOWN:
			if (recharge == 0) {
				SDL_DestroyRenderer(manrend);
				SDL_DestroyWindow(manwin);
				menu = true;
				continuer = false;
				printf("Vous avez perdu le mode manuel car vous n'aviez plus d'énergie\n----> Retour au Menu !\n");
				return -1;
			}
			if (event.key.keysym.sym == SDLK_ESCAPE) {
				SDL_DestroyRenderer(manrend);
				SDL_DestroyWindow(manwin);
				menu = true;
				continuer = false;
				printf("Vous avez quitté le mode manuel\n----> Retour au Menu !\n");
				return -1;
			}
			if (event.key.keysym.sym == SDLK_LEFT && x > 145 && limCases != 0) {
				Left(manrend, x, y);
				SDL_RenderPresent(manrend);
				limCases--;
			}
			if (event.key.keysym.sym == SDLK_RIGHT && x < 660 && limCases != 0) {
				Right(manrend, x, y);
				SDL_RenderPresent(manrend);
				limCases--;
			}
			if (event.key.keysym.sym == SDLK_UP && y > 180 && limCases != 0) {
				Up(manrend, x, y);
				SDL_RenderPresent(manrend);
				limCases--;
			}
			if (event.key.keysym.sym == SDLK_DOWN && y < 720 && limCases != 0) {
				Down(manrend, x, y);
				SDL_RenderPresent(manrend);
				limCases--;
			}
			if (event.key.keysym.sym == SDLK_RETURN) {
				SDL_Rect Cut;
				Cut.x = x - 73;
				Cut.y = y - 75;
				Cut.w = 40;
				Cut.h = 169;
				Tab[(y - 20) / 200][(x - 20) / 200].taille = 5;
				SDL_SetRenderDrawColor(manrend, 0, 0, 0, 255);
				SDL_RenderFillRect(manrend, &Cut);
				SDL_RenderPresent(manrend);
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
						SDL_SetRenderDrawColor(manrend, 0, 255, 0, 255);
						SDL_RenderFillRect(manrend, &bamboo);

						SDL_Rect bambooStep;
						bambooStep.x = j * 200 + 80;
						bambooStep.y = (i + 1) * 200 + 20 - Tab[i][j].taille;
						bambooStep.w = 16;
						bambooStep.h = 2;
						SDL_SetRenderDrawColor(manrend, 0, 128, 0, 255);
						SDL_RenderFillRect(manrend, &bambooStep);
						SDL_RenderPresent(manrend);

					}
				}
				limCases = 3;
				recharge--;
				if (recharge == 0) {
					for (int i = 0; i < N; i++) {
						for (int j = 0; j < N; j++) {
							Tab[i][j].taille += Tab[i][j].croissance;
						}
					}
					SDL_Delay(1000);
				}
				if (w % 5 == 0) {
					Stats(Tab, TabMoy, TabMin, TabMax, c, a, b);
					AfficheStats(manrend, TabMoy, TabMin, TabMax, positionx1, c);
				}
				w++;
				AfficheRecharge(manrend, recharge);
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
						SDL_SetRenderDrawColor(manrend, 0, 255, 0, 255);
						SDL_RenderFillRect(manrend, &bamboo);

						SDL_Rect bambooStep;
						bambooStep.x = j * 200 + 80;
						bambooStep.y = (i + 1) * 200 + 20 - Tab[i][j].taille;
						bambooStep.w = 16;
						bambooStep.h = 2;
						SDL_SetRenderDrawColor(manrend, 0, 128, 0, 255);
						SDL_RenderFillRect(manrend, &bambooStep);
						SDL_RenderPresent(manrend);

					}
				}
				if (w % 5 == 0) {
					Stats(Tab, TabMoy, TabMin, TabMax, c, a, b);
					AfficheStats(manrend, TabMoy, TabMin, TabMax, positionx1, c);
				}
				w++;
				AfficheRecharge(manrend, recharge);
			}
			if (event.key.keysym.sym == SDLK_y && x == 145 && y == 720) {
				recharge = 7;
				AfficheRecharge(manrend, recharge);
			}
		}
	}
	SDL_DestroyRenderer(manrend);
	SDL_DestroyWindow(manwin);
	printf("\nVous avez perdu !\Retour au menu !");
	menu = true;
	return 0;
}
void menu_principal(SDL_Renderer* rendu, TTF_Font* font,TTF_Font* font2, SDL_Rect& sound) {
	SDL_RenderClear(rendu);
	SDL_Surface* image = SDL_LoadBMP("fond.bmp");
	SDL_Texture* background = SDL_CreateTextureFromSurface(rendu, image);
	SDL_FreeSurface(image);
	SDL_RenderCopy(rendu, background, NULL, NULL);
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

	SDL_Rect config;
	config.w = 200;
	config.h = 50;
	config.x = 40;
	config.y = HAUTEUR_ - 80;

	SDL_Rect import;
	import.w = 250;
	import.h = 50;
	import.x = 80 + config.w;
	import.y = HAUTEUR_ - 80;


	SDL_SetRenderDrawColor(rendu, 255, 255, 255, 255);
	SDL_RenderDrawRect(rendu, &config);
	SDL_RenderDrawRect(rendu, &import);
	SDL_Texture* new_conf = loadText(rendu, "Créer Config", blanc, font2);
	SDL_QueryTexture(new_conf, NULL, NULL, &config.w, &config.h);
	SDL_RenderCopy(rendu, new_conf, NULL, &config);
	SDL_DestroyTexture(new_conf);

	SDL_Texture* load = loadText(rendu, "Importer Config", blanc, font2);
	SDL_QueryTexture(load, NULL, NULL, &import.w, &import.h);
	SDL_RenderCopy(rendu, load, NULL, &import);
	SDL_DestroyTexture(load);


	SDL_Texture* texture1 = loadText(rendu, "Panda Garden", blanc, font);
	SDL_QueryTexture(texture1, NULL, NULL, &titre_.w, &titre_.h);
	SDL_RenderCopy(rendu, texture1, NULL, &titre_);
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
	SDL_DestroyTexture(texture2);

	SDL_Texture* texture3 = loadText(rendu, "Manuel", blanc, font);
	SDL_QueryTexture(texture3, NULL, NULL, &jeu_manuel_.w, &jeu_manuel_.h);
	SDL_RenderCopy(rendu, texture3, NULL, &jeu_manuel_);
	SDL_DestroyTexture(texture3);



	sound.w = 128;
	sound.h = 128;
	sound.x = LARGEUR_ - 135;
	sound.y = HAUTEUR_ - 128;

	SDL_Texture* audio = loadImage(rendu, "audio.png");
	SDL_RenderCopy(rendu, audio, NULL, &sound);
	SDL_RenderPresent(rendu);
	SDL_DestroyTexture(audio);


}
int main(int argn, char* argv[]) {
	SDL_Init(SDL_INIT_AUDIO);
	SDL_AudioSpec wavSpec;
	Uint32 wavLength;
	Uint8* wavBuffer;
	SDL_LoadWAV("music.wav", &wavSpec, &wavBuffer, &wavLength);
	SDL_AudioDeviceID deviceId = SDL_OpenAudioDevice(NULL, 0, &wavSpec, NULL, 0);
	bool music = true;
	SDL_Rect sound;
	sound.x = NULL;
	sound.y = NULL;
	sound.w = NULL;
	sound.h = NULL;

	bool in_menu = true;
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		std::cout << "Echec à l’ouverture";
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
		std::cout << "erreur ouverture fenetre";

	SDL_Surface* icon = IMG_Load("icon.png");
	SDL_SetWindowIcon(win, icon);

	SDL_Renderer* rendu = SDL_CreateRenderer(
		win,
		-1,
		SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawBlendMode(rendu, SDL_BLENDMODE_BLEND);


	TTF_Init();
	TTF_Font* font = TTF_OpenFont("Snes.ttf", 90);
	TTF_Font* font2 = TTF_OpenFont("Snes.ttf", 40);
	TTF_Quit();
	menu_principal(rendu, font,font2, sound);
	int success = SDL_QueueAudio(deviceId, wavBuffer, wavLength);
	SDL_PauseAudioDevice(deviceId, 0);


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
				if (event.button.x > LARGEUR_ - 103 && event.button.x < (LARGEUR_ - 103) + 64 && event.button.y>HAUTEUR_ - 96 && event.button.y < (HAUTEUR_ - 96) + 64) {
					if (music) {
						SDL_PauseAudioDevice(deviceId, 1);
						SDL_Texture* audio3 = loadImage(rendu, "audio3.png");
						SDL_RenderCopy(rendu, audio3, NULL, &sound);
						SDL_DestroyTexture(audio3);
						SDL_RenderPresent(rendu);
						SDL_Texture* audio = loadImage(rendu, "audio2.png");
						SDL_RenderCopy(rendu, audio, NULL, &sound);
						SDL_DestroyTexture(audio);
						SDL_RenderPresent(rendu);
						music = false;
					}
					else {
						SDL_PauseAudioDevice(deviceId, 0);
						SDL_Texture* audio3 = loadImage(rendu, "audio3.png");
						SDL_RenderCopy(rendu, audio3, NULL, &sound);
						SDL_DestroyTexture(audio3);
						SDL_RenderPresent(rendu);
						SDL_Texture* audio = loadImage(rendu, "audio.png");
						SDL_RenderCopy(rendu, audio, NULL, &sound);
						SDL_DestroyTexture(audio);
						SDL_RenderPresent(rendu);
						music = true;
					}


				}
				else if (event.button.x > 40 && event.button.x < 240 && event.button.y > HAUTEUR_ - 80 && event.button.y < HAUTEUR_ - 30) {
					create_conf();
				}
				else if (event.button.x > 280 && event.button.x < 280 + 250 && event.button.y > HAUTEUR_ - 80 && event.button.y < HAUTEUR_ - 30) {
					import_conf();
				}
				else if (event.button.x > 80 && event.button.x < LARGEUR_ / 2 - 80 && event.button.y>HAUTEUR_ / 2 - 100 && event.button.y < HAUTEUR_ / 2 + 100) {
					in_menu = false;
					jeuAuto(in_menu);
				}
				else if (event.button.x > LARGEUR_ / 2 + 80 && event.button.x < LARGEUR_ - 80 && event.button.y>HAUTEUR_ / 2 - 100 && event.button.y < HAUTEUR_ / 2 + 100) {
					in_menu = false;
					jeuMan(in_menu);
				}
			}
		}
	}
	SDL_CloseAudioDevice(deviceId);
	SDL_FreeWAV(wavBuffer);
	SDL_DestroyRenderer(rendu);
	SDL_DestroyWindow(win);
	SDL_Quit();
	return 0;
}


