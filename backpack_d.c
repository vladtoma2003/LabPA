#include"headers/pereche.h"
#define NRELEM 3

int backpack_rec(int i, int j, pereche **elemente) {
    // printf("[%d][%d]\n", i, j);
    if(i == 0) {
        if(elemente[0]->p1 <= j) {
            return elemente[0]->p2;
        } else {
            return 0;
        }
    }
    return max(backpack_rec(i-1, j, elemente), backpack_rec(i-1, j-elemente[i]->p1, elemente) + elemente[i]->p2);
}

int main() {
    

    pereche **elemente = malloc(10*sizeof(pereche*));
    elemente[0] = alocare(10, 60, "m1");
    elemente[1] = alocare(30, 120, "m2");
    elemente[2] = alocare(20, 100, "m3");

    int R = 50;

    print_perechi(elemente, NRELEM);
    printf("================\n");

    printf("Rezultat: %d\n", backpack_rec(NRELEM-1, R, elemente));
    // printf("%d\n", backpack_rec2(NRELEM-1, R, elemente));

    eliberare(elemente, NRELEM);

    return 0;
}
