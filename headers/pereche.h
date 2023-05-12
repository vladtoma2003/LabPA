#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pereche {

    char *name;
    int p1;
    int p2;

}pereche;

pereche* alocare(int x, int y, char* name) {
    pereche *ceva = malloc(sizeof(pereche));
    ceva->name = malloc(255*sizeof(char));
    ceva->name = strcpy(ceva->name, name);
    ceva->p1 = x;
    ceva->p2 = y;
    return ceva;

}

void swap_perechi(pereche **v, int i, int j) {
    pereche *aux = v[i];
    // printf("Swap: %d\n",)
    v[i] = v[j];
    v[j]= aux;
}

void sortare_cresc_p2(pereche **v, int len) {
    for(int i = 0; i < len; ++i) {
        for(int j = i+1; j < len; ++j) {
            if(v[i]->p2 > v[j]->p2) {
                swap_perechi(v, i, j);
            }
        }
    }
}

void sortare_descrescator_raport(pereche **v, int len) {
    for(int i = 0; i < len; ++i) {
        for(int j = i+1; j < len; ++j) {
            if(v[i]->p2/v[i]->p1 < v[j]->p2/v[j]->p1) {
                swap_perechi(v, i, j);
            }
        }
    }
}

void print_perechi(pereche **v, int len) {
    for (int i = 0; i < len; ++i) {
        printf("%s:(%d, %d)\n",v[i]->name, v[i]->p1, v[i]->p2);
    }
} 

void eliberare(pereche **v, int len) {
    for(int i = 0; i < len; ++i) {
        free(v[i]);
    }
    free(v);
}

int max(int a, int b) {
    // printf("%d\n", a>b? a:b);
    return a>b? a:b;
}
