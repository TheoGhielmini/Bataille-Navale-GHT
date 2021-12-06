#include <stdio.h>

#define MAX_TAB 10

void menu_principale();
void menu_aide();

void menu_aide() {
    printf("Regles du jeu :");
    printf("\nLes bateaux : \nIl y a cinq bateaux disponible :\nUn zodiaque de 1 case\n"
           "Une vedette rapide de 2 cases\n"
           "Un croiseur de 3 cases\n"
           "Un cuirasse de 4 cases\n"
           "Un porte-avion de 5 cases\n\nDeux bateaux ne peuvent pas se toucher\n"
           "Un bateau ne peut pas etre en contact avec le bord de la grille par plus que 1 case");
    menu_principale();
}

void menu_principale() {
    int votre_choix;
    char votre_nom;
    int plateauJeu;
    int debut_partie;
    printf("Welcome to BatNav");
    printf("\n=========================\n");
    printf("Que voulez-vous faire?\n");

    printf("1. Aide\n");
    printf("2. Jouer\n");
    printf("3. Scores\n");
    printf("Votre choix ?\n");
    scanf("%d", &votre_choix);

    while (votre_choix < 1 || votre_choix > 3){
        printf("Erreur veuillez entrer un nombre entre 1 et 3 :\n");
        scanf("%d", &votre_choix);
    }

    switch (votre_choix) {
        case 1:
            printf("Regles du jeu :");
            printf("\nLes bateaux : \nIl y a cinq bateaux disponible :\nUn zodiaque de 1 case\n"
                   "Une vedette rapide de 2 cases\n"
                   "Un croiseur de 3 cases\n"
                   "Un cuirasse de 4 cases\n"
                   "Un porte-avion de 5 cases\n\nDeux bateaux ne peuvent pas se toucher\n"
                   "Un bateau ne peut pas etre en contact avec le bord de la grille par plus que 1 case");
            break;

            case 2:
                printf("Votre nom : ");
                scanf("%c", &votre_nom);
                break;

                case 3:
                    printf("Scores :");
                    break;


    }

}

int main() {
    menu_principale();


    return 0;
}
