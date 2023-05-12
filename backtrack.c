#include <stdio.h>
#include <stdlib.h>

void afisare1(int v[], int lung) {
    int nr_zero = 0;
    for(int i = 1; i <= lung; i++) {
        // printf("%d ", v[i]);
        if(v[i] == 0) {
            nr_zero++;
        }
        if(v[i] != 0) {
            printf("%d ", i);
        }
    }
    if(nr_zero == lung) {
        printf("multimea vida");
    }
    printf("\n");
}

void afisare2(int v[], int lung) {
    for(int i = 1; i <= lung; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

int validare1(int v [], int lung) {
    for(int i = 1; i <= lung; ++i) {
        if(v[i] == -1) {
            return 0;
        }
    }
    return 1;
}

int validare2(int v[], int i) {
    for(int k = 1; k < i; ++k) {
        if(v[i] == v[k]) {
            return 0;
        }
        if(i-k == abs(v[i]-v[k])) {
            return 0;
        }
    }
    return 1;
}

void backtracking_iterativ(int v[], int lungSol, int initVal, int max, int val, int (*validare)(int[], int), void (*afisare)(int[], int)) {
    for(int k = 1; k <= lungSol; k++) {
        v[k] = initVal;
    }
    int i = 1;
    int valid;
    while(i >= 1) {
        valid = 0;
        while(!valid && v[i] <= max) {
            v[i] += val;
            valid = (*validare)(v, i);
        }
        if(v[i] <= max) {
            if(i == lungSol) {
                afisare(v, lungSol);
            } else {
                i += 1;
            }
        } else {
            v[i] = initVal;
            i -= 1;
        }
    }
}

int main() {
    int v[10] = {0};
    printf("Problema1\n\n");
    backtracking_iterativ(v, 3, -1, 1, 1, validare1, afisare1);
    printf("\n\nProblema2\n\n");
    backtracking_iterativ(v, 4, 0, 4, 1, validare2, afisare2);
    return 0;
}
