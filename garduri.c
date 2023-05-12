#include <stdio.h>
#include<stdlib.h>
#include <string.h>

int main() {

    int k = 2;
    int n = 6; // de la 0 la 6

    int *D = malloc((n+1) * sizeof(int));

    D[0] = 1;
    D[1] = 1;

    for(int i = 2; i < n + 1; ++i) { // calculare nr garduri
        D[i] = D[i-1] + D[i-k];
    }

    char garduri[n+1][D[n]][n+1];
    strcpy(garduri[0][0], "");
    strcpy(garduri[1][0], "v");

    for(int i = 2; i < n + 1; ++i) { // calculare pozitii garduri
        for(int j = 0; j < D[i]; ++j) {
            if(j < D[i-1]) {
                strcpy(garduri[i][j], garduri[i-1][j]);
                strcat(garduri[i][j], "v");
            } else {
                strcpy(garduri[i][j], garduri[i-k][j-D[i-1]]);
                strcat(garduri[i][j], "o");
            }
        }
    }

    printf("k = %d, n = %d\n\n", k, n);

    for(int i = 0; i < n + 1; ++i) {
        printf("n = %d; D[%d] = %d : ",i, i, D[i]);
        for(int j = 0; j < D[i]; ++j) {
            printf("%s | ", garduri[i][j]);
        }
        printf("\n");
    }

    free(D);

    return 0;
}
