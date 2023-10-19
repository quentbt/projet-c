#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "fonction.h"

extern struct question {

	char* question;
	char* bonneReponse;
	char* reponse[4];
	char* difficulte;
};

extern struct matiere {

	char nom[20];
	bool active;
	struct question* questionAll[100];
	struct question* questionPoser[100];
	int nbrQuestion;
	int nbrQuestionPoser;
};

extern struct Jeu {

	struct matiere* listeMatiere[9];
	struct matiere* listeMatiereActive[9];
	int nbrMatiereActive;
};

struct question question1 = { "En quel année à été découvert l'Amérique ?","1492",{"1598","1492","1678","1478"},"" };
struct question question2 = { "Combien font 2(2+4) ?", "12", {"18","22","8","12"}, "" };
struct question question3 = { "Quel est la célèbre formule d'équivalence entre la masse et l'énérgie ?","e=mc²",{"e=m6","e=mc²","m=ec²","Ec=1/2mv²"},"" };
struct question question4 = { "Quel est la traduction de la phrase suivante : \"The sun is yellow\" en français ?","Le soleil est jaune",{"Le soleil est beau","Le fils est jaune","La lune est blanche","Le soleil est jaune" },"" };
struct question question5 = { "Qui a chanté : \"J'suis dans la cuisine tu bouffes c'que je te prepare\"","Kaaris",{"Booba","Rohff","Kaaris","Jul" }, "" };
struct question question6 = { "Comment s'appelle le film où Andrew Garfield joue le role princpal ?","Spiderman",{"Superman","Spiderman","Aquaman","Le loup de wall street"},"" };
struct question question7 = { "Qui à un lampadaire dans lol ?", "Jax",{ "Sejuani", "Jax", "Milio","Sion"}, ""};
struct question question8 = { "Quel est l'actuel président français ?", "Macron", {"Sarkozy", "Obama", "Macron", "Holland"}, "" };
struct question question9 = { "Quelle est la longueur d'un marathon ?", "42km" , {"41km" , "56km" , "45km" , "42km" }, "" };

struct question listeQuestionPoser = { NULL };

struct matiere histoire = { "histoire" , true, {&question1}, {NULL}, 1, 0};
struct matiere maths = { "maths" , true, {&question2}, {NULL}, 1, 0};
struct matiere science = { "science" , true, {&question3}, {NULL}, 1, 0};
struct matiere langue = { "langue" , true,  {&question4}, {NULL}, 1, 0};
struct matiere musique = { "musique" , true, {&question5}, {NULL}, 1, 0};
struct matiere cinema = { "cinema" , true, {&question6}, {NULL}, 1, 0};
struct matiere jeux_videos = { "jeux_videos" , true, {&question7}, {NULL}, 1, 0};
struct matiere culture_g = { "culture_g" , true, {&question8}, {NULL}, 1, 0};
struct matiere sport = { "sport" , true , {&question9}, {NULL}, 1, 0};

struct Jeu jeu = { {&histoire, &maths, &science, &langue, &musique, &cinema, &jeux_videos, &culture_g, &sport},{NULL}, 0 };

int jouer() {

	int solde = 10;
	int reponseJoueur;
	char* reponseDonnee;
	
	for (int i = 0; i < (sizeof(jeu.listeMatiere) / sizeof(jeu.listeMatiere[0])); i++) {
		
		if (jeu.listeMatiere[i]) {

			if (jeu.listeMatiere[i]->active) {

				jeu.listeMatiereActive[jeu.nbrMatiereActive] = jeu.listeMatiere[i];
				jeu.nbrMatiereActive++;
			}
		}
	}

	for (int nombreQuestion = 0; nombreQuestion < 5; nombreQuestion++) {

		int nbrAleatoireMatiere; 
		int nbrALeatoireQuestion;

		while (1) {

			nbrAleatoireMatiere = Random(0, jeu.nbrMatiereActive - 1);
			nbrALeatoireQuestion = Random(0, jeu.listeMatiereActive[nbrAleatoireMatiere]->nbrQuestion - 1);

			if (jeu.listeMatiere[nbrAleatoireMatiere]->questionAll[nbrALeatoireQuestion]) {

				printf(" %s\n", jeu.listeMatiere[nbrAleatoireMatiere]->questionAll[nbrALeatoireQuestion]->question);

				for (int boucleReponse = 0; boucleReponse < sizeof(jeu.listeMatiere[nbrAleatoireMatiere]->questionAll[nbrALeatoireQuestion]->reponse) / sizeof(jeu.listeMatiere[nbrAleatoireMatiere]->questionAll[nbrALeatoireQuestion]->reponse[0]); boucleReponse++) {

					printf("Reponse %d > %s\n", boucleReponse + 1, jeu.listeMatiere[nbrAleatoireMatiere]->questionAll[nbrALeatoireQuestion]->reponse[boucleReponse]);
				}

				while (1) {

					if (scanf_s("%d", &reponseJoueur) == 1) {

						if (reponseJoueur >= 1 && reponseJoueur <= 4) {

							reponseDonnee = jeu.listeMatiere[nbrAleatoireMatiere]->questionAll[nbrALeatoireQuestion]->reponse[reponseJoueur - 1];
							break;
						}
						else
							printf("Repondez a la question avec 1, 2 ,3, 4 \n Votre reponse : ");
					}
				}

				if (reponseDonnee == jeu.listeMatiere[nbrAleatoireMatiere]->questionAll[nbrALeatoireQuestion]->bonneReponse) {

					solde = solde * 10;
				}

				jeu.listeMatiere[nbrAleatoireMatiere]->questionPoser[jeu.listeMatiere[nbrAleatoireMatiere]->nbrQuestionPoser] = jeu.listeMatiere[nbrAleatoireMatiere]->questionAll[nbrALeatoireQuestion];
				jeu.listeMatiere[nbrAleatoireMatiere]->questionAll[nbrALeatoireQuestion] = NULL;
				jeu.listeMatiere[nbrAleatoireMatiere]->nbrQuestionPoser++;
				break;
			}
		}

		printf("Votre solde est de :%d \n", solde);
		Sleep(1000);
		ClearScreen();
	}

	printf("Vous avez gagné %d euros", solde);
	return solde;
}

void Option() {

	int playerInput;

	while (1) {

		ClearScreen();
		for (int i = 0; i < sizeof(jeu.listeMatiere) / sizeof(jeu.listeMatiere[0]); i++) {
	
			printf("%d > %s\n",i+1, jeu.listeMatiere[i]->nom);
		}
		printf("\n0 > Retour");

		printf("\n\nSelectionnez votre choix : ");

		if (scanf_s("%d", &playerInput) == 1) {

			if (playerInput >= 0 && playerInput <= 9) {

				if (playerInput == 0) {

					ClearScreen();
					break;
				}

				ActiveDesactive(playerInput - 1);
			}
		}
		while (getchar() != '\n');
	}
}


void ActiveDesactive(int numeroMatiere) {

	ClearScreen();
	printf("Voulez vous activer le theme %s : \n ", jeu.listeMatiere[numeroMatiere]->nom);
	if (jeu.listeMatiere[numeroMatiere]->active) {

		printf("1> ACTIVE (Choix Actuel)\n 2> DESACTIVE \n \n");
	}
	else {

		printf("1> ACTIVE \n 2> DESACTIVE (Choix Actuel) \n \n");
	}
	printf("Selectionnez une des deux options : ");

	int playerInput;

	while (1) {

		if (scanf_s("%d", &playerInput) == 1) {

			if (playerInput == 1 || playerInput == 2) {

				switch (playerInput)
				{
				case 1:

					jeu.listeMatiere[numeroMatiere]->active = true;
					break;
				case 2:

					jeu.listeMatiere[numeroMatiere]->active = false;
					break;
				
				}
				break;
			}
		}
		while (getchar() != '\n');
	}
	
}

void ClearScreen() {

	system("cls");
}

void Quit() {

	int menu;

	printf("Etes - vous sur de vouloir quitter ? \n 0> Quitter \n 1> Retour \n");
	scanf_s("%d", &menu);

	switch (menu)
	{
	case 0:
		exit(0);
	case 1:
		break;
	default:
		printf("Selectionner une des valeurs proposee");
	}
}

int Random(int minimum, int maximum) {

	int NumberModulo = (maximum - minimum) + 1;
	int numRandom = rand() % NumberModulo;
	return numRandom + minimum;
}