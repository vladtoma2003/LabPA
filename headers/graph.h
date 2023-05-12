#include <stdio.h>
#include <stdlib.h>

typedef struct nod {
    struct nod *next;
    int value;
}node;

typedef struct queue {
    node *head;
    node *tail;
}queue;

node *newNode(int value) {
    node *n = calloc(1, sizeof(node));
    n->next = NULL;
    n->value = value;
    return n;
}


int isEmptyQ(queue *q) {
    if(q == NULL || q->head == NULL) {
        return 1;
    }
    return 0;
}


void printQ(queue *q) {
    if(isEmptyQ(q)) {
        printf("Empty queue\n");
        return;
    }
    node *aux = q->head;
    while(aux) {
        printf("%c ", 'A' + aux->value);
        aux = aux->next;
    }
    printf("\n");
}

void freeList(node *head) {
    if(!head)
        return;
    while(head->next) {
        node *aux = head->next;
        free(head);
        head = aux;
    }
    free(head);
    return;
}

void addToList(node *head, int value) {
    node *n = newNode(value);
    while(head->next) {
        head = head->next;
    }
    head->next = n;
}

queue *newQ(int value) {
    queue *q = calloc(1, sizeof(queue));
    q->head = newNode(value);
    q->tail = q->head;
    return q;
}

void freeQ(queue *q) {
    if(!q) {
        return;
    }
    while(q->head != q->tail) {
        node *aux = q->head->next;
        free(q->head);
        q->head = aux;
    }
    free(q->head);
    free(q);
}

void enqueue(queue *q, int value) {
    if(q == NULL) {
        newQ(value);
    } else if(q->head == NULL) {
        q->head = newNode(value);
        q->tail = q->head;
    } else {
        q->tail->next = newNode(value);
        q->tail = q->tail->next;
    }
}

int dequeue(queue *q) {
    if(q == NULL) {
        return -1;
    }
    if(q->head == q->tail) {
        int value = q->head->value;
        // free(q->head);
        freeQ(q);
        q = NULL;
        return value;
    } else {
        node *aux = q->head;
        int value = aux->value;
        q->head = q->head->next;
        // free(aux);
        return value;
    }
}

node *newGraph(int n) { // no. of nodes
    node *graph = calloc(n, sizeof(node));
    return graph;
}

void addEdge(node *graph, int u, int v) { // oriented graph, add only to the first node
    addToList(&graph[u], v);
}

void printGraph(node *graph, int n) {
    for(int i = 0; i < n; ++i) {
        printf("%c: ", (char)('A' + i));
        node *aux = graph[i].next;
        while(aux) {
            printf("%c ", (char)('A' + aux->value));
            aux = aux->next;
        }
        printf("\n");
    }
}

void freeGraph(node *graph, int n) {
    for(int i = 0; i < n; ++i) {
        freeList(graph[i].next);
    }
    free(graph);
}



void printVectorOfInt(int *v, int n) {
    for(int i = 0; i < n; ++i) {
        printf("%d ", v[i]);
    }
    printf("\n");
}
