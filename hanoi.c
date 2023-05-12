#include "headers/stiva.h"

void hanoiTower(int n, stack *a, stack *b, stack *c);
void move(int nr, stack *a, stack *b);

int main() {

    stack *a = newStack(5);
    stack *b = newStack(5);   
    stack *c = newStack(5);   

    push(a, 3);
    push(a, 2);
    push(a, 1);

    printStacksDown(a, b, c);

    hanoiTower(3, a, b, c);

    freeStack(a);
    freeStack(b);
    freeStack(c);

    return 0;
}

void hanoiTower(int n, stack *a, stack *b, stack *c) {
    if(n > 0) {
        hanoiTower(n-1, a, c, b);
        move(1, a, b);
        printStacksDown(a, b, c);
        hanoiTower(n-1, c, b, a);
    }
}

void move(int nr, stack *a, stack *b) {
    for(int i = 0; i < nr; ++i) {
        push(b, pop(a));
    }
}
