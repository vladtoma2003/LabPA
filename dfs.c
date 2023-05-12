#include<stdio.h>
#include<stdlib.h>
#define MAX 100;

typedef struct node {
    int *vecini;
    int color;
    int dist;
    int parent;
    int fdist;
}node;

typedef struct graph {
    node *nodes;
    int nrNodes;
}Graph;

typedef struct queue {
    int *continut;
    int first;
    int last;
}queue;

Graph *createGraph(int size) {
    Graph *g = calloc(1, sizeof(Graph));
    g->nrNodes = size;
    g->nodes = calloc(size, sizeof(node));
    for(int i = 0; i < size; i++) {
        g->nodes[i].vecini = calloc(size, sizeof(int));
        g->nodes[i].color = 0;
        g->nodes[i].dist = 0;
    }
    return g;
}

queue *createQueue(int size) {
    queue *q = calloc(1, sizeof(queue));
    q->continut = calloc(size, sizeof(int));
    q->first = 0;
    q->last = 0;
    return q;
}

void enqueue(queue *q, int value) {
    q->continut[q->last] = value;
    q->last++;
}

int dequeue(queue *q) {
    if(q->first > q->last) {
        return -1;
    }
    int value = q->continut[q->first];
    q->first++;
    return value;
}

void addEdge(Graph *g, int u, int v) {
    g->nodes[u].vecini[v] = 1;
}

void graphLab(Graph *graph) {
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 0, 7);

    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 1, 7);
    addEdge(graph, 1, 8);

    addEdge(graph, 2, 3);

    addEdge(graph, 3, 4);
    addEdge(graph, 3, 9);

    addEdge(graph, 4, 5);
    addEdge(graph, 4, 6);

    addEdge(graph, 5, 6);

    addEdge(graph, 7, 8);

    addEdge(graph, 8, 0);
}

void printGraph(Graph *g) {
    for(int i = 0; i < g->nrNodes; i++) {
        printf("%c: ", 'A' + i);
        for(int j = 0; j < g->nrNodes; j++) {
            if(g->nodes[i].vecini[j] == 1) {
                printf("%c ", 'A' + j);
            }
        }
        printf("\n");
    }
}

void printQueue(queue *q) {
    printf("Queue: ");
    for(int i = q->first; i < q->last; i++) {
        printf("%c ", 'A' + q->continut[i]);
    }
    // printf("\n");
    printf(", ");
}

void printColor(int c) {
    if(c == 0) {
        printf("WHITE, ");
    }
    else if(c == 1) {
        printf("GRAY, ");
    }
    else {
        printf("BLACK, ");
    }
}


void freeQueue(queue *q) {
    free(q->continut);
    free(q);
}

void explore(Graph *g, int u, int *time) {
    g->nodes[u].color = 1;
    (*time)++;
    g->nodes[u].dist = *time;
    printf("u:%c, ", 'A' + u);
    printColor(g->nodes[u].color);
    printf("d(%c)=%d, ",'A' + u, g->nodes[u].dist);
    printf("p(%c)=%c\n",'A' + u, (g->nodes[u].parent == -1)? 'n': 'A' + g->nodes[u].parent);
    for(int i = 0; i < g->nrNodes; i++) {
        if(g->nodes[u].vecini[i] == 1) {
            if(g->nodes[i].color == 0) {
                g->nodes[i].parent = u;
                explore(g, i, time);
            }
        }
    }
    g->nodes[u].color = 2;
    (*time)++;
    g->nodes[u].fdist = *time;
    printf("f(%c)=%d, ", 'A' + u, g->nodes[u].fdist);
    printColor(g->nodes[u].color);
    printf("\n");
}

void dfs(Graph *g, int source) {
    for(int i = 0; i < g->nrNodes; i++) {
        g->nodes[i].color = 0;
        g->nodes[i].dist = 0;
        g->nodes[i].parent = -1;
        g->nodes[i].fdist = 0;
    }
    // g->nodes[source].color = 1;
    int time = 0;
    for(int i = 0; i < g->nrNodes; i++) {
        if(g->nodes[i].color == 0) {
            explore(g, i, &time);
        }
    }
}


void destroyGraph(Graph *g) {
    for(int i = 0; i < g->nrNodes; i++) {
        free(g->nodes[i].vecini);
    }
    free(g->nodes);
    free(g);
}

void printStuff(Graph *g) {
    for(int i = 0; i < g->nrNodes; i++) {
        printf("%c: ", 'A' + i);
        printColor(g->nodes[i].color);
        printf("%d, ", g->nodes[i].dist);
        printf("%c, ", (g->nodes[i].parent == -1)? 'n': 'A' + g->nodes[i].parent);
        printf("%d\n", g->nodes[i].fdist);
    }
}

int main() {

    Graph *graph = createGraph(10);
    graphLab(graph);
    printGraph(graph);

    printf("==============STEP BY STEP===============\n");

    dfs(graph, 0);
    printf("\n=============FINAL=====================\n");
    printStuff(graph);
    destroyGraph(graph);

    return 0;
}
