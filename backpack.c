#include "headers/pereche.h"
#define NRELEM 3

int main() {

    pereche **elemente = malloc(10*sizeof(pereche*));

    elemente[0] = alocare(10, 60, "m1");
    elemente[1] = alocare(30, 120, "m2");
    elemente[2] = alocare(20, 100, "m3");

    print_perechi(elemente, NRELEM);
    printf("================\n");
    sortare_descrescator_raport(elemente, NRELEM);

    int volume = 50;
    int v = volume;
    pereche **rucsac = malloc(10*sizeof(pereche*));
    int contor = 0;
    int sol = 0;

    for(int i = 0; i < NRELEM; ++i) {
        if(volume - elemente[i]->p1 < 0) {
            break;
        }
        volume -= elemente[i]->p1;
        rucsac[contor] = elemente[i];
        sol += elemente[i]->p2;
        ++contor;
    }

    float raport;
    if(contor < NRELEM) {
        raport = (float) volume / elemente[contor]->p1;
        sol += raport*elemente[contor]->p2;
        rucsac[contor] = elemente[contor];
    }
    printf("Volum rucsac: %d\nsolutie: %d\n", v, sol);
    print_perechi(rucsac, contor);
    printf("%g%%", raport*100);
    printf(" %s:(%g, %g)", rucsac[contor]->name, (float)rucsac[contor]->p1*raport, (float)raport*rucsac[contor]->p2);

    eliberare(elemente, NRELEM);
    return 0;
}
