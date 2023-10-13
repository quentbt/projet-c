//#define _CRT_SECURE_NO_WARNINGS
//
//#include <stdio.h>
//#include <stdbool.h>
//#include <stdlib.h>
//#include <locale.h>
//#include <string.h>
//
//bool game = true;
//int menu;
//int theme;
//int alea;
//int score = 0;
//int tour = 0;
//
//char answer[1];
//
////Question à poser 
//
//struct question_et_reponse {
//
//	char* questionHistoire[500];
//	char* reponseHistoire[];
//
//};
//
//// faire en sorte que la fonction sépare et alimente les listes des question/réponses.
//
//void Question(char* question, char* reponse) {
//
//	struct question_et_reponse* jeu;
//
//	for (int i = 0; i < 20; i++) {
//
//		jeu->questionHistoire[i] = question[i];
//		jeu->reponseHistoire[i] = reponse;
//	}
//}
//
////{"Quand a eu lieu la Revolution francaise ? ",
////"Qui était le fondateur de l'Empire romain ?",
////"Quand à eu lieu la Première Guerre mondiale ?",
////"Qui est le 1er président des Etats-Unis ?",
////"Quel pays est le berceau de la Renaissance ?",
////"Qui a peint la joconde ?",
////"Quel explorateur italien a découvert l'Amérique en 1492 ?",
////"Quel invention sera à l'origine de la révolution industrielle ?"
////};
//
//
//char questionHistoire[][5][100] = { {"Quand a eu lieu la Revolution francaise ? ","A> 1789","B> 1769","C> 1799","D> 1759"},		//Question 0
//	{"Qui était le fondateur de l'Empire romain ?","A> Jules Cesar","B> Remus","C> Auguste","D> Romulus"},						//Question 1
//	{"Quand à eu lieu la Première Guerre mondiale ?","A> 1914-1918","B> 1939-1945","C> 1946-1954","D> 1955-1975"},				//Question 2
//	{"Qui est le 1er président des Etats-Unis ?","A> Abraham lincoln","B> George Washington","C> Franklin Roosevelt","D> Barack Obama"},		//Question 3
//	{"Quel pays est le berceau de la Renaissance ?","A> La France", "B> L'allemagne","C> L'Esapgne","D> L'italie"},				//Question 4
//	{"Qui a peint la joconde","A> Claude Monet","B> Andrea del Verrocchio","C> Leonard de Vinci","D> Leonardo diCaprio"},		//Question 5
//	{"Quel explorateur italien a découvert l'Amérique en 1492 ?","A> Vasco de Gama","B> Christophe Colomb","C> Marco Polo", "D> James Cook"},	//Question 6
//	{"Quel invention sera à l'origine de la révolution industrielle ?","A> La machine à vapeur", "B> L'impremerie", "C> La chimie", "D> Le telephone"} };	//Question 7
//char questionMaths[][100] = {"combien font 25 + 37 ?","Trouve la valeur de 8 x 4","Combien font 15 - 42 ?", "Combien font 56/7 ?","Combien font 3/5 + 1/4 ? ","Combien font 9x3-7","Quel est la moitié de 50 ?", "Combien font 1/4 + 2/3 ? "};
////char questionScience[][100] = {" ","Qui était le fondateur de l'Empire romain ?","Quelle était la principale cause de la Première Guerre mondiale ?", "Qui était Mahatma Gandhi ?","Qu'est-ce que la Renaissance ?","Qui étaient les principaux leaders de la lutte pour les droits civiques aux États-Unis","Quelles sont les principales caractéristiques de l'Empire mongol ?", "Quand a commence la révolution industrielle ?"};
////char questionCinema[][100] = {"","Qui était le fondateur de l'Empire romain ?","Quelle était la principale cause de la Première Guerre mondiale ?", "Qui était Mahatma Gandhi ?","Qu'est-ce que la Renaissance ?","Qui étaient les principaux leaders de la lutte pour les droits civiques aux États-Unis","Quelles sont les principales caractéristiques de l'Empire mongol ?", "Quand a commence la révolution industrielle ?"};
////char questionjeuxVideo[][100] = {" ","Qui était le fondateur de l'Empire romain ?","Quelle était la principale cause de la Première Guerre mondiale ?", "Qui était Mahatma Gandhi ?","Qu'est-ce que la Renaissance ?","Qui étaient les principaux leaders de la lutte pour les droits civiques aux États-Unis","Quelles sont les principales caractéristiques de l'Empire mongol ?", "Quand a commence la révolution industrielle ?"};
//
//int main() {
//
//	setlocale(LC_ALL, "C");
//
//	while (game) {
//
//		//printf("%s", questionHistoire[0]);
//
//		printf("Vous souhaitez jouer ou quitter ? 1 pour joeur, 0 pour quitte \n");
//		//printf("%d", sizeof(questionHistoire)/500);
//		scanf("%d", &menu);
//
//		switch (menu)
//		{
//		case 0:
//
//			game = false;
//			break;
//
//		case 1:
//
//			printf("choisissez un thème parmis les suivants : \n 1> Maths \n 2> Histoire \n 3> Science \n 4> Langues \n 5> Musique \n 6> Sport \n 7> Jeux-vidéos \n 8> Cinema \n 9> Culture G \n 10> Multitheme \n");
//			scanf("%d", &theme);
//
//			switch (theme)
//			{
//			case 1 :		//Theme maths
//
//				while (tour < 5) {
//
//					alea = rand() % 7;
//
//					printf("%s", questionMaths[alea]);
//					scanf("%s", &answer);
//
//					switch (questionMaths[alea][0])
//					{
//					case 0:
//						if (strcmp(answer, "a")) {
//
//							score++;
//						}
//						break;
//
//					case 1:
//
//						if (strcmp(answer, "c")) {
//
//							score++;
//						}
//						break;
//
//					case 2:
//
//						if (strcmp(answer, "a")) {
//
//							score++;
//						}
//						break;
//
//					case 3:
//
//						if (strcmp(answer, "b")) {
//
//							score++;
//						}
//						break;
//
//					case 4:
//
//						if (strcmp(answer, "d")) {
//
//							score++;
//						}
//						break;
//
//					case 5:
//
//						if (strcmp(answer, "c")) {
//
//							score++;
//						}
//						break;
//
//					case 6:
//
//						if (strcmp(answer, "b")) {
//
//							score++;
//						}
//						break;
//
//					case 7:
//
//						if (strcmp(answer, "a")) {
//
//							score++;
//						}
//						break;
//					}
//					tour++;
//				}
//
//			case 2 :		//Theme Histoire
//
//				while (tour < 5){
//
//					int j = 1;
//
//					printf("Repondez par a, b , c ou d.\n");
//					alea = rand() % sizeof(questionHistoire)/500;
//					printf("%s\n", questionHistoire[alea][0]);
//					while (j <= 4) {
//
//						printf("%s\n", questionHistoire[alea][j]);
//						j++;
//					}
//
//					scanf("%s", &answer);
//
//					switch (alea)
//					{
//					case 0:
//						if (strcmp(answer, "a") == 0) {
//
//							score++;
//						}
//						break;
//
//					case 1:
//
//						if (strcmp(answer, "c") == 0) {
//
//							score++;
//						}
//						break;
//
//					case 2:
//
//						if (strcmp(answer, "a") == 0) {
//
//							score++;
//						}
//						break;
//
//					case 3:
//
//						if (strcmp(answer, "b") == 0) {
//
//							score++;
//						}
//						break;
//
//					case 4:
//
//						if (strcmp(answer, "d") == 0) {
//
//							score++;
//						}
//						break;
//
//					case 5:
//
//						if (strcmp(answer, "c") == 0) {
//
//							score++;
//						}
//						break;
//
//					case 6:
//
//						if (strcmp(answer, "b") == 0) {
//
//							score++;
//						}
//						break;
//
//					case 7:
//
//						if (strcmp(answer, "a") == 0) {
//
//							score++;
//						}
//						break;
//					}
//
//					printf("Votre score > %d\n", score);
//					tour++;
//				}
//
//			case 3 :		//Theme Science
//			case 4 :		//Theme Langues
//			case 5 :		//Theme Musique
//			case 6 :		//Theme Sport
//			case 7 :		//Theme Jeux-Vidéos
//			case 8 :		//Theme Cinema
//			case 9 :		//Theme Culture G
//			case 10 :		//Multitheme
//
//
//
//
//			default:
//				break;
//			}
//
//
//
//			/*printf("Bien commencons. 1ere question \n > En quel annee fut couronne Clovis 1er ? \n REPONSE A : 512 \n REPONSE B : 496 \n REPONSE C : 444 \n REPONSE D : 502 \n \n vôtre réponse > ");
//			scanf("%s", &answer);
//			
//			if (strcmp(answer , "b") == 0) {
//				
//				bonneReponse++;
//				printf("Nbr de point > %d", bonneReponse);
//			}*/
//
//
//
//
//		}
//		
//		return 0;
//	}
//}