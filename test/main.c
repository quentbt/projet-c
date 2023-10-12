#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

bool game = true;
int menu;
int theme;
int alea;
int bonneReponse = 0;
int tour = 0;

char answer[1];

//Question à poser 

char questionHistoire[][100] = {"Quand a eu lieu la Révolution française ? ","Qui était le fondateur de l'Empire romain ?","Quelle était la principale cause de la Première Guerre mondiale ?", "Qui était Mahatma Gandhi ?","Qu'est-ce que la Renaissance ?","Qui étaient les principaux leaders de la lutte pour les droits civiques aux États-Unis","Quelles sont les principales caractéristiques de l'Empire mongol ?", "Quand a commence la révolution industrielle ?"};
char questionMaths[][100] = {"combien font 25 + 37 ?","Trouve la valeur de 8 x 4","Combien font 15 - 42 ?", "Combien font 56/7 ?","Combien font 3/5 + 1/4 ? ","Combien font 9x3-7","Quel est la moitié de 50 ?", "Combien font 1/4 + 2/3 ? "};
//char questionScience[][100] = {" ","Qui était le fondateur de l'Empire romain ?","Quelle était la principale cause de la Première Guerre mondiale ?", "Qui était Mahatma Gandhi ?","Qu'est-ce que la Renaissance ?","Qui étaient les principaux leaders de la lutte pour les droits civiques aux États-Unis","Quelles sont les principales caractéristiques de l'Empire mongol ?", "Quand a commence la révolution industrielle ?"};
//char questionCinema[][100] = {"","Qui était le fondateur de l'Empire romain ?","Quelle était la principale cause de la Première Guerre mondiale ?", "Qui était Mahatma Gandhi ?","Qu'est-ce que la Renaissance ?","Qui étaient les principaux leaders de la lutte pour les droits civiques aux États-Unis","Quelles sont les principales caractéristiques de l'Empire mongol ?", "Quand a commence la révolution industrielle ?"};
//char questionjeuxVideo[][100] = {" ","Qui était le fondateur de l'Empire romain ?","Quelle était la principale cause de la Première Guerre mondiale ?", "Qui était Mahatma Gandhi ?","Qu'est-ce que la Renaissance ?","Qui étaient les principaux leaders de la lutte pour les droits civiques aux États-Unis","Quelles sont les principales caractéristiques de l'Empire mongol ?", "Quand a commence la révolution industrielle ?"};

int main() {

	setlocale(LC_ALL, "C");

	while (game) {

		printf("Vous souhaitez jouer ou quitter ? 1 pour joeur, 0 pour quitté \n");
		scanf("%d", &menu);

		switch (menu)
		{
		case 0:

			game = false;
			break;

		case 1:

			printf("choisissez un thème parmis les suivants : \n 1> Maths \n 2> Histoire \n 3> Science \n 4> Langues \n 5> Musique \n 6> Sport \n 7> Jeux-vidéos \n 8> Cinema \n 9> Culture G \n 10> Multitheme \n");
			scanf("%d", &theme);

			switch (theme)
			{
			case 1 :		//Theme maths

				printf("Question 1 + reponse");
				scanf("%s", &answer);

				if (strcmp(answer, "Lettre réponse")) {

					bonneReponse++;
					printf("Nbr de point > %d", bonneReponse);
				}

				printf("Question 2 + reponse");
				scanf("%s", &answer);

				if (strcmp(answer, "Lettre réponse")) {

					bonneReponse++;
					printf("Nbr de point > %d", bonneReponse);
				}

				printf("Question 2 + reponse");
				scanf("%s", &answer);

				if (strcmp(answer, "Lettre réponse")) {

					bonneReponse++;
					printf("Nbr de point > %d", bonneReponse);
				}

				printf("Question 4 + reponse");
				scanf("%s", &answer);

				if (strcmp(answer, "Lettre réponse")) {

					bonneReponse++;
					printf("Nbr de point > %d", bonneReponse);
				}

				printf("Question 5 + reponse");
				scanf("%s", &answer);

				if (strcmp(answer, "Lettre réponse")) {

					bonneReponse++;
					printf("Nbr de point > %d", bonneReponse);
				}

			case 2 :		//Theme Histoire

				while (tour < 5){

					alea = rand() % 7;
					printf("%s", questionHistoire[alea]);
					scanf("%s", &answer);

					tour++;
				}

			case 3 :		//Theme Science
			case 4 :		//Theme Langues
			case 5 :		//Theme Musique
			case 6 :		//Theme Sport
			case 7 :		//Theme Jeux-Vidéos
			case 8 :		//Theme Cinema
			case 9 :		//Theme Culture G
			case 10 :		//Multitheme




			default:
				break;
			}



			/*printf("Bien commencons. 1ere question \n > En quel annee fut couronne Clovis 1er ? \n REPONSE A : 512 \n REPONSE B : 496 \n REPONSE C : 444 \n REPONSE D : 502 \n \n vôtre réponse > ");
			scanf("%s", &answer);
			
			if (strcmp(answer , "b") == 0) {
				
				bonneReponse++;
				printf("Nbr de point > %d", bonneReponse);
			}*/




		}
		
		return 0;
	}
}
