#include <stdio.h>
#include<stdlib.h>
#define NRELEM 4

int main() {

    int v[NRELEM] = {3, 1, 2, 4};

    int **D = malloc((NRELEM+1)*sizeof(int*));
    for(int i = 0; i < NRELEM+1; ++i) {
        D[i] = malloc(3*sizeof(int));
    }
    for(int i = 0; i < 3; ++i) { // initializare primele D uri
        D[0][i] = 0;
    }
    
    for(int i = 1; i < NRELEM+1; ++i) {
        switch (v[i-1] % 3) {
            case 0:
                D[i][0] = 1 + 2*D[i-1][0];
                D[i][1] = 2*D[i-1][1];
                D[i][2] = 2*D[i-1][2];
                break;
            case 1:
                D[i][0] = D[i-1][0] + D[i-1][2];
                D[i][1] = 1 + D[i-1][0] + D[i-1][1];
                D[i][2] = D[i-1][1] + D[i-1][2];
                break;
            case 2:
                D[i][0] = D[i-1][0] + D[i-1][1];
                D[i][1] = D[i-1][1] + D[i-1][2];
                D[i][2] = 1 + D[i-1][0] + D[i-1][2];
                break;
        }
    }

    for(int i = 1; i < NRELEM+1; ++i) {
        printf("D[%d][0] = %d\n", i, D[i][0]);
        printf("D[%d][1] = %d\n", i, D[i][1]);
        printf("D[%d][2] = %d\n", i, D[i][2]);
    }

    for(int i = 0; i < NRELEM+1; ++i) {
        free(D[i]);
    }
    free(D);

    return 0;
}
