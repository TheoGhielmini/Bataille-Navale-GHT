#include <stdio.h>

#define MAX_TAB 10
#define DECAL 49

void menu_principale();

void menu_aide();

void init_tableau();

void affiche_tableau();

void init_coup();

void afficher_coup();

void afficher_carte();

void demander_couper();

void init_carte();

int coupJouer[MAX_TAB][MAX_TAB];
int carte[MAX_TAB][MAX_TAB];


void clear() {
    while (getchar() != '\n');
}

void partie() {
    int index_col = 0;
    char choix[2];
    char votre_nom[50];
    int score = 50;
    printf("Votre nom : \n");
    scanf("%s", votre_nom);

    init_carte();
    init_coup();

    while (choix[0] != 'f') {
        printf("Joueur : %s \n\n", votre_nom);
        printf("Score %d\n", score);
        afficher_coup();
        demander_couper(choix);
        printf("Vous avez choisi : %s\n", choix);
        printf("Votre col : %c et votre ligne : %c\n", choix[0], choix[1]);

        switch (choix[0]) {
            case 'a':
            case 'A':
                // ici on est sur la col 0
                index_col = 0;
                break;
            case 'b':
            case 'B':
                index_col = 1;
                break;
            case 'c':
            case 'C':
                index_col = 2;
                break;
            case 'd':
            case 'D':
                index_col = 3;
                break;
            case 'e':
            case 'E':
                index_col = 4;
                break;
            case 'f':
            case 'F':
                index_col = 5;
                break;
            case 'g':
            case 'G':
                index_col = 6;
                break;
            case 'h':
            case 'H':
                index_col = 7;
                break;
            case 'i':
            case 'I':
                index_col = 8;
                break;
            case 'j':
            case 'J':
                index_col = 9;
                break;

        }
        int index_ligne = choix[1] - DECAL;
        printf("col : %d ligne : %d\n", index_col, index_ligne);
        if (carte[index_col][index_ligne] == 1) {
            printf("toucher ! \n");
            coupJouer[index_col][index_ligne] = 1;
        } else {
            printf("Out !\n");
            coupJouer[index_col][index_ligne] = 9;
            score--;
        }
    }

}

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
    char votre_nom[50];
    int plateauJeu;
    int debut_partie;
    int grille[MAX_TAB][MAX_TAB];
    int index_col = 0;
    char choix[2];
    init_carte();
    init_coup();
    printf("\nWelcome to Batman");
    printf("\n=========================\n");
    printf("Que voulez-vous faire?\n");

    printf("1. Aide\n");
    printf("2. Jouer\n");
    printf("3. Scores\n");
    printf("Votre choix ?\n");
    scanf("%d", &votre_choix);

    while (votre_choix < 1 || votre_choix > 3) {
        printf("Erreur veuillez entrer un nombre entre 1 et 3 :\n");
        scanf("%d", &votre_choix);
    }

    switch (votre_choix) {
        case 1:
            menu_aide();
            break;

        case 2:
            partie();

            break;

        case 3:
            printf("Scores :");
            break;


    }

}

void init_carte() {
    carte[1][1] = 1;
    carte[1][3] = 1;
    carte[2][3] = 1;
    carte[1][5] = 1;
    carte[2][5] = 1;
    carte[3][5] = 1;
    carte[1][7] = 1;
    carte[2][7] = 1;
    carte[3][7] = 1;
    carte[4][7] = 1;
    carte[8][0] = 1;
    carte[8][1] = 1;
    carte[8][2] = 1;
    carte[8][3] = 1;
    carte[8][4] = 1;
}

void init_coup() {
    for (int i = 0; i < MAX_TAB; i++) {
        for (int y = 0; y < MAX_TAB; y++) {
            coupJouer[y][i] = 0;
        }
    }
}

void afficher_coup() {
    printf("      A  B  C  D  E  F  G  H  I  J\n");
    printf("      _  _  _  _  _  _  _  _  _  _\n");
    for (int i = 0; i < MAX_TAB; i++) {
        printf("%2d  |", i + 1);
        for (int y = 0; y < MAX_TAB; y++) {
            printf("%2i ", coupJouer[y][i]);
        }
        printf("\n");
    }
}

void afficher_carte() {
    for (int i = 0; i < MAX_TAB; i++) {
        for (int y = 0; y < MAX_TAB; y++) {
            printf("%i ", carte[y][i]);
        }
        printf("\n");
    }
}

void demander_couper(char monchoix[2]) {
    printf("Merci de donner votre chois : ");

    scanf("%s", monchoix);
    clear();
}

void init_tableau(int plateau[MAX_TAB][MAX_TAB]) {
    for (int y = 0; y < MAX_TAB; y++) {
        for (int x = 0; x < MAX_TAB; x++) {
            plateau[x][y] = 0;
        }
    }
}

void affiche_tableau(int plateau[MAX_TAB][MAX_TAB]) {
    printf("    A  B  C  D  E  F  G  H  I  J\n");
    for (int y = 0; y < MAX_TAB; y++) {
        printf("%2d", y + 1);
        for (int x = 0; x < MAX_TAB; x++) {
            printf("%3d", plateau[x][y]);
        }
        printf("\n");
    }
}


int main() {
    menu_principale();


    return 0;
}
