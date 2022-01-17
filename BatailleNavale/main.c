#include <stdio.h>

#define MAX_TAB 10
#define DECAL 49

int coupJouer[MAX_TAB][MAX_TAB];
int carte[MAX_TAB][MAX_TAB];


void menu_principal();

void init_bateaux();

void bateau_coule();

void init_coup();

void afficher_coup();

void clear() {
    while (getchar() != '\n');
}

void demander_couper(char monchoix[2]) {
    printf("\nMerci de donner votre choix : ");

    scanf("%s", monchoix);
    clear();
}

void init_carte();

void menu_aide(int menu) {
    char choix = 1;
    printf("==============================\n");
    printf("Regles du jeu\n");
    printf("\nVideo expliquant les regles de la bataille navale : https://www.youtube.com/watch?v=klO6vPWPkzE\n");
    printf("\nLes bateaux : \nIl y a cinq bateaux disponible \n\nUn zodiaque de 1 case\n"
           "Une vedette rapide de 2 cases\n"
           "Un croiseur de 3 cases\n"
           "Un cuirasse de 4 cases\n"
           "Un porte-avion de 5 cases\n\nDeux bateaux ne peuvent pas se toucher\n"
           "Un bateau ne peut pas etre en contact avec le bord de la grille par plus que 1 case");
    printf("\n==============================\n");

    if (menu == 1) {
        if (choix == 1) {
            printf("Voulez-vous retourner au menu principal ? (Oui: 1)\n");
            scanf("%d", &choix);
            menu_principal();
        }
    }
    if (menu == 2) {
        do {
            printf("Voulez-vous retourner en jeu ? (Oui: 1)\n");
            scanf("%d", &choix);

        } while (choix != 1);
    }


}


void touche_coule(int valeur, int ligne, int colonne) {
    switch (valeur) {
        case 100:
            carte[colonne][ligne] = 111;
            printf("touche-coule\n");
            break;

        case 200:
            carte[colonne][ligne] = 210;
            if (bateau_coule(valeur) == 0) {
                printf("touche-coule\n");
            }
            break;

    }

}

int bateau_coule(int valeur) {

    int retour = 0;

    for (int y = 0; y < MAX_TAB; y++) {
        for (int x = 0; x < MAX_TAB; x++) {
            if (carte[x][y] == valeur) {
                retour++;
            }
        }
    }
    return retour;
}


void partie() {
    int col = 0;
    char choix[3];
    char votre_nom[50];
    int score = 2;
    printf("Votre nom : \n");
    scanf("%s", votre_nom);
    clear();

    init_bateaux();
    init_coup();


    while (choix[0] != 'k' && score != 0) {
        printf("Joueur : %s \n\n", votre_nom);
        printf("Score %d\n\n", score);
        afficher_coup();
        demander_couper(choix);
        touche_coule();
        printf("Vous avez choisi : %s\n", choix);
        printf("Votre col : %C et votre ligne : %c%c\n", choix[0], choix[1], choix[2]);

        switch (choix[0]) {
            case 'a':
            case 'A':
                col = 0;
                break;
            case 'b':
            case 'B':
                col = 1;
                break;
            case 'c':
            case 'C':
                col = 2;
                break;
            case 'd':
            case 'D':
                col = 3;
                break;
            case 'e':
            case 'E':
                col = 4;
                break;
            case 'f':
            case 'F':
                col = 5;
                break;
            case 'g':
            case 'G':
                col = 6;
                break;
            case 'h':
            case 'H':
                col = 7;
                break;
            case 'i':
            case 'I':
                col = 8;
                break;
            case 'j':
            case 'J':
                col = 9;
                break;
        }


        if (choix[0] == 48) {
            menu_aide(2);
            score = score + 1;
        }
        int lignes = choix[1] - DECAL;
        if ((choix[1] - DECAL) == 0) {
            if (choix[2] == 48) {
                lignes = 9;
            }
        }
        if (carte[col][lignes] > 0) {
            printf("toucher ! \n");
            coupJouer[col][lignes] = carte[col][lignes];
        } else {
            printf("Out !\n");
            coupJouer[col][lignes] = 9;
            score--;
        }
    }

    if (score == 0) {
        printf("Vous avez perdu!\n");
        printf("\nVoulez-vous retourner au menu principal ? (Oui: 1)\n");
        scanf("%d", &choix);
        menu_principal();
    }


}

void menu_principal() {
    int votre_choix;
    init_carte();
    init_coup();
    printf("\nWelcome to BatNaV");
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
    if (votre_choix == 1) {
        menu_aide(1);
    }
    if (votre_choix == 2) {
        partie();
    }


}

void init_bateaux() {
    carte[1][1] = 100;
    carte[1][3] = 200;
    carte[2][3] = 200;
    carte[1][5] = 300;
    carte[2][5] = 300;
    carte[3][5] = 300;
    carte[1][7] = 400;
    carte[2][7] = 400;
    carte[3][7] = 400;
    carte[4][7] = 400;
    carte[8][0] = 500;
    carte[8][1] = 500;
    carte[8][2] = 500;
    carte[8][3] = 500;
    carte[8][4] = 500;
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


int main() {
    menu_principal();

    return 0;
}




