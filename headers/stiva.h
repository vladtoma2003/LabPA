#include<stdio.h>
#include<stdlib.h>

typedef struct stack {
    int size;
    int max;
    int *vec;
}stack;

void push(stack *s, int n) {
    if(s->size+1 >= s->max) {
        s->vec = realloc(s->vec, 2*s->max);
        s->max *= 2;
    }
    
    s->vec[s->size] = n;
    s->size++;
}

int pop(stack *s) {
    int temp = s->vec[s->size-1];
    s->vec[s->size-1] = 0;
    s->size--;

    return temp;
}

stack* newStack(int max) {
    stack *s = malloc(sizeof(stack));
    s->max = max;
    s->size = 0;
    s->vec = calloc(max, sizeof(int));
    return s;
}

void printStackUp(stack *s) {
    for(int i = 0; i < s->size; ++i) {
        printf("%d\n", s->vec[i]);
    }
}

void freeStack(stack *s) {
    free(s->vec);
    free(s);
}

void printStackDown(stack *s) {
    for(int i = s->size-1; i >= 0; --i) {
        printf("%d\n", s->vec[i]);
    }
}

void printStacksDown(stack *a, stack *b, stack *c) {
    int maxSize = a->size>=b->size? a->size:b->size;
    maxSize = maxSize>=c->size? maxSize:c->size;

    printf("\n");
    for(int i = maxSize-1; i >= 0; --i) {
        printf("     %d      %d      %d\n", a->vec[i], b->vec[i], c->vec[i]);
    }
    printf("====(a)====(b)====(c)====\n");
}
