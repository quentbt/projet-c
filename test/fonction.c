#include <stdbool.h>
#define _CRT_SECURE_NO_WARNINGS

struct Question_Reponse {

	char listeTheme[9][20];
	bool valeurTheme[9];
};


char questionDonner[2][8][50] = { {"Quelle est la longueur d'un marathon ?", "42km" , "41km" , "56km" , "45km" , "42km" , "Sport" , "*"},
	{"Quel est l'actuel président français ?", "Macron", "Sarkozy", "Obama", "Macron", "Holland", "Culture g", ""} };

int jouer() {

	struct Question_Reponse jeu;

	bool questionTroll = true;

	char answer[1];
	char questionPoser[7][8][50];
	char questionEnlever[50][8][50];

	int nbrQuestion = 0;
	int argent = 10;
	int filtreQuestion = 0;

	//printf("%s \n",questionDonner[0][6]);

	while (questionTroll) {

		printf("Ce devoir merite-t-il un 20/20 ? \n A> NON \n B> OUI ");
		scanf("%s", &answer);

		if (strcmp(answer, "b") == 0) {

			questionTroll = false;
		}
	}


	//Filtre à faire plus tard
	printf("%d", jeu.valeurTheme[0]);

	while (filtreQuestion < sizeof(jeu.valeurTheme)) {

		if (jeu.valeurTheme[filtreQuestion]) {


		}
		filtreQuestion++;
	}

	/*printf("%s", questionPoser[0]);*/


	while (nbrQuestion < 5) {

		printf("%s\n A> %s \n B> %s \n C> %s \n D> %s", questionDonner[nbrQuestion][0], questionDonner[nbrQuestion][2], questionDonner[nbrQuestion][3], questionDonner[nbrQuestion][4], questionDonner[nbrQuestion][5]);
		scanf("%s", &answer);

		if (stricmp(answer, "a") == 0) {

			strcpy(answer, questionDonner[nbrQuestion][2]);
		}
		if (stricmp(answer, "b") == 0) {

			strcpy(answer, questionDonner[nbrQuestion][3]);
		}
		if (stricmp(answer, "c") == 0) {

			strcpy(answer, questionDonner[nbrQuestion][4]);
		}
		if (stricmp(answer, "d") == 0) {
			
			strcpy(answer, questionDonner[nbrQuestion][5]);
		}

		if (stricmp(answer, questionDonner[nbrQuestion][1]) == 0) {

			argent = argent * 10;
		}

		printf("Vous avez gagne %d euros \n", argent);
		nbrQuestion++;
	}

	// Faire une opération pour determine si on doit lui enlevé des gains
	printf("Vous avez gagne %d euros", argent);
	return argent;
}

bool Option() {

	int choix;
	int valid;

	// Thème pour filtrer les questions
	bool histoireTheme = true;
	bool mathsTheme = true;
	bool scienceTheme = true;
	bool langueTheme = true;
	bool musiqueTheme = true;
	bool cinemaTheme = true;
	bool jvTheme = true;
	bool cultureTheme = true;
	bool sportTheme = true;

	bool themeValide[9] = {histoireTheme, mathsTheme, scienceTheme, langueTheme, musiqueTheme, cinemaTheme, jvTheme, cultureTheme, sportTheme};

	// Boucle des paramètres
	bool settings = true;

	struct Question_Reponse jeu;
	char *theme[] = {"","Histoire", "Maths ","Science","Langues ","musique ","Cinema" ,"Jeux - videos ","Culture G ","Sport"};

	int i = 0;

	while (i < 10){

		strcpy(jeu.listeTheme[i], theme[i]);
		i++;
	}
	

	while (settings) {

		for (int i = 0; i < 10; i++) {

			if (i == 0) {
				i++;
			}
			printf("%d> %s\n",i, theme[i]);
		}
		printf("0> Retour \n");

		scanf("%d", &choix);


		switch (choix) {
		case 0:
			// Boucle pour retourner les thèmes.
			for (int mm = 0; mm < 9; mm++) {
				printf("%d\n", jeu.valeurTheme[mm]);
			}
			settings = false;
			break;
		default:
			if (choix >= 1 && choix <= 9) {
				printf("Activer le theme %s des questions ? \n 0> DESACTIVE \n 1> ACTIVE \n", jeu.listeTheme[choix]);
				scanf("%d", &valid);

				switch (valid) {
				case 1:
					themeValide[choix - 1] = true;
					break;
				case 0:
					themeValide[choix - 1] = false;
					break;
				default:
					printf("Sélectionner une valeur dans celle proposer\n");
					break;
				}
			}
			else {
				printf("Sélectionner une valeur dans celle proposer \n");
			}
			break;
		}

		for (int j = 0; j < 9; j++) {

			jeu.valeurTheme[j] = themeValide[j];
		}
	}
	return jeu.valeurTheme;
}

void Quit() {

	int menu;

	printf("Etes-vous sur de vouloir quitter ? \n 0> Quitter \n 1> Retour \n");
	scanf("%d", &menu);

	switch (menu)
	{
	case 0:
		exit();
	case 1:
		break;
	default:
		printf("Selectionner une des valeurs proposee");
	}
}