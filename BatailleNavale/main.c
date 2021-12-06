#include <stdio.h>

#define MAX_TAB 10

void menu_principale();
void menu_aide();
void init_tableau();
void affiche_tableau();

void menu_aide() {
    printf("==============================\n");
    printf("Regles du jeu :");
    printf("\nLes bateaux : \n\nIl y a cinq bateaux disponible :\n\nUn zodiaque de 1 case\n"
           "Une vedette rapide de 2 cases\n"
           "Un croiseur de 3 cases\n"
           "Un cuirasse de 4 cases\n"
           "Un porte-avion de 5 cases\n\nDeux bateaux ne peuvent pas se toucher\n"
           "Un bateau ne peut pas etre en contact avec le bord de la grille par plus que 1 case");
    printf("\n==============================");
}

void menu_principale() {
    int votre_choix;
    char votre_nom = "";
    int plateauJeu;
    int debut_partie;
    int grille[MAX_TAB][MAX_TAB];
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
            menu_aide();
            break;

            case 2:
                printf("Votre nom : \n");
                scanf("%c \n", &votre_nom);
                printf("Joueur : %c", votre_nom);
                //init_tableau(grille);
                //affiche_tableau(grille);
                break;

                case 3:
                    printf("Scores :");
                    break;


    }

}

void init_tableau(int plateau[MAX_TAB][MAX_TAB]) {
    for (int x = 0; x < MAX_TAB; x++) {
        for (int y = 0; y < MAX_TAB; y++) {
            plateau[x][y] = 0;
        }
    }
}

void affiche_tableau(int plateau[MAX_TAB][MAX_TAB]) {
    for (int x = 0; x < MAX_TAB; x++) {
        for (int y = 0; y < MAX_TAB; y++) {
            printf("%3d", plateau[x][y]);
        }
        printf("\n");
    }
}

int main() {
    menu_principale();



    return 0;
}
