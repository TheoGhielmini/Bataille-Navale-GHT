#include <stdio.h>

#define MAX_TAB 5
#define DECAL 49

int carte[MAX_TAB][MAX_TAB];
int coupJouer[MAX_TAB][MAX_TAB];

void clear() {
    while (getchar() != '\n');
}

void init_carte() {
    carte[1][2] = 1;
    carte[2][3] = 1;
    carte[2][2] = 1;
    carte[2][1] = 1;
    carte[3][3] = 1;
}

void init_coup() {
    for (int i = 0; i < MAX_TAB; i++) {
        for (int y = 0; y < MAX_TAB; y++) {
            coupJouer[y][i] = 0;
        }
    }
}


void afficher_coup() {
    for (int i = 0; i < MAX_TAB; i++) {
        for (int y = 0; y < MAX_TAB; y++) {
            printf("%i ", coupJouer[y][i]);
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

int main(int argc, char *argv[]) {

    int index_col = 0;
    char choix[2];
    init_carte();
    init_coup();

    while (choix[0] != 'f') {
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
        }
        int index_ligne = choix[1] - DECAL;
        printf("col : %d ligne : %d\n", index_col, index_ligne);
        if (carte[index_col][index_ligne] == 1) {
            printf("toucher ! \n");
            coupJouer[index_col][index_ligne] = 1;
        } else {
            printf("Out !\n");
            coupJouer[index_col][index_ligne] = 9;
        }
    }
}