#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool gagner_million = true;
bool option = true;
bool questionTroll = true;


int mise_depart = 0;
int argent = 10;
int nbrQuestion = 0;

int menu;
int optionTheme;
int optionSuppr;

char answer[1];

int main() {


	while (gagner_million) {

		printf("Bienvenue dans \"Qui veut gagner des pepettes\" ! \n 1> JOUER \n 2> OPTION\n 3> QUITTER \n");
		scanf("%d", &menu);

		printf("%d\n", menu);

		switch (menu)
		{
		case 1:

			printf("Repondez aux questions en mettant la lettre de la reponse. \n Bien, commencons avec la 1ere question.");

			while (questionTroll) {
				
				printf("Ce devoir merite-t-il un 20/20 ? \n A> NON \n B> OUI ");
				scanf("%s", answer);

				if (strcmp(answer, "b") == 0) {

					questionTroll = false;
				}
			}

			while (nbrQuestion < 5) {

				// mettre 2 themes au hasard parmis les sélectionner.

				printf("coucou \n");

				if (/*mettre la bonne réponse*/true) {

					argent = argent * 10;
				}
				nbrQuestion++;
			}

			break;

		case 2:

			printf("Ici, vous pouvez choisir les themes que vous voulez voir dans les questions. Cependant, chaque theme en moins enleve 10% à votre gain total \n \n");

			while (option) {

				printf(" 1> Histoire \n 2> Maths \n 3> Science \n 4>Langues \n 5> musique \n 6> Cinema \n 7> Jeux-videos \n 8> Culture G \n 9> Sport \n 0> retour");
				scanf("%d", &optionTheme);


				switch (optionTheme)
				{

				case 1:

					printf("souhaitez-vous supprimer le theme suivant : Histoire ? \n 1> NON \n 0> OUI");
					scanf("%d", &optionSuppr);

					switch (optionSuppr)
					{
					case 1:
						printf("\n \n");
						break;

					case 0:

						// Code pour retirer le theme

						printf("Le theme \"histoire\" a ete retire des questions \n \n");
						break;
					}
					break;

				case 0:

					option = false;
					break;
				}
			}
			break;

		case 3:


			printf("Etes-vous sur de vouloir quitter ? \n 0> Quitter \n 1> Retour");
			scanf("%d", &menu);

			switch (menu)
			{
			case 0:
				gagner_million = false;
				break;
			case 1:
				break;
			}
		}
	}

	return 0;
}