#include <stdio.h>
#include<stdlib.h>
#define NRELEM 7

int *removeDuplicates(int *v, int size) {
    int *c = malloc(size * sizeof(int) + 4);
    c[1] = v[0];
    int contor = 1;
    for(int i = 1; i <= size; ++i) {
        if(v[i] != c[contor]) {
            c[contor+1] = v[i];
            ++contor;
        }
    }
    c[0] = contor;
    return c;
}

int main() {

    int sir[] = {1, 2, 9, 3, 8, 4, 7};

    int d = 1;
    int maxJ[NRELEM+1] = {0};
    for(int i = 1; i < NRELEM; ++i) {
        int k = 0;
        for(int j = 0; j < i; ++j) {
            if(sir[j] > sir[i]) {
                continue;
            }
            k = j;
        }
        maxJ[i] = k;
    }
    maxJ[NRELEM] = NRELEM-1;

    printf("Sir initial: ");
    for(int i = 0; i < NRELEM; ++i) {
        printf("%d ", sir[i]);
    }
    printf("\n\n");

    int *c = removeDuplicates(maxJ, NRELEM);

    printf("subsir final: ");
    for(int i = 1; i <= c[0]; ++i) {
        printf("%d ", sir[c[i]]);
    }
    printf("\n\n");

    printf("J maxim: ");
    for(int i = 1; i <= c[0]; ++i) {
        printf("%d ", c[i]);
    }
    printf("\n");

    return 0;
}
