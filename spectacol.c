#include "headers/pereche.h"
#define LEN 6

int main() {

    pereche **spectacole = malloc(10 * sizeof(pereche*));

    spectacole[0] = alocare(10, 11, "s1");
    spectacole[1] = alocare(11, 13, "s2");
    spectacole[2] = alocare(12, 13, "s3");
    spectacole[3] = alocare(14, 18, "s4");
    spectacole[4] = alocare(16, 17, "s5");
    spectacole[5] = alocare(17, 19, "s6");

    printf("Spectacole initiale:\n");
    print_perechi(spectacole, LEN);
    printf("================\n");

    sortare_cresc_p2(spectacole, LEN);

    pereche **solutie = malloc(10*sizeof(pereche*));
    solutie[0] = spectacole[0];
    int contor = 0;

    for(int i = 1; i < LEN; ++i) {
        if(spectacole[i]->p1 >= solutie[contor]->p2) {
            ++contor;
            solutie[contor] = spectacole[i];
        }
    }
    ++contor;

    print_perechi(solutie, contor);
    printf("%d spectacole.\n", contor);

    eliberare(spectacole, LEN);
    free(solutie);

    return 0;
}
