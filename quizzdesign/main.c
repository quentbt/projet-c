#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "fonction.h"

bool gagner_million = true;

int menu;

int main2() {


    while (gagner_million) {

        printf("Bienvenue dans \"Qui veut gagner des pepettes\" ! \n 1> JOUER \n 2> OPTION\n 3> QUITTER \n");
        scanf("%d", &menu);

        printf("%d\n", menu);

        switch (menu)
        {
        case 1:

            printf("Repondez aux questions en mettant la lettre de la reponse. \n Bien, commencons avec la 1ere question.");

            jouer();

            break;

        case 2:

            printf("Ici, vous pouvez choisir les themes que vous voulez voir dans les questions. Cependant, chaque theme en moins enleve 10% à votre gain total \n \n");

                Option();
            break;

        case 3:

            Quit();
            break;
        }
    }

    return 0;
}
