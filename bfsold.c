// #include "headers/graph.h"
// #define LEN 10

// void graphLab(node *graph);

// void bfs(int s, node *graph) {
//     int color [LEN] = {0}; // este totul alb
//     int parents[LEN];
//     int distance [LEN];
//     for(int i = 0; i < LEN; ++i) {
//         // distance[i] = __INT_MAX__; // inf
//         distance[i] = 999;
//     }
//     distance[s] = 0;
//     color[s] = 1; // gri
//     queue *q = newQ(s);
//     printf("Before while\n");
//     while(!isEmptyQ(q)) {
//         int u = dequeue(q);
//         printf("u = %d\n", u);
//         printf("%d: ", u);
//         printQ(q);
//         printf("===============\n");
//         if(u == -1) {
//             break;
//         }
//         for(node *head = graph[u].next; head; head = head->next) {
//             printf("Am intrat in for\nhead->value = %d\n", head->value);
//             if(color[head->value] == 0) {
//                 color[head->value] = 1; // gri
//                 distance[head->value] = distance[u] + 1;
//                 parents[head->value] = u;
//                 printf("urmeaza enqueue cuaie\n");
//                 enqueue(q, head->value);
//             }
//             color[u] = 2; // negru
//         }
//     }

// }


// int main() {
//     node *graph = newGraph(LEN);
//     graphLab(graph); // graful de la lab, hardcodat
//     printGraph(graph, LEN);

//     bfs(0, graph);

//     // freeGraph(graph, LEN);
//     return 0;
// }

// void graphLab(node *graph) {
//     addEdge(graph, 0, 1);
//     addEdge(graph, 0, 2);
//     addEdge(graph, 0, 7);

//     addEdge(graph, 1, 3);
//     addEdge(graph, 1, 4);
//     addEdge(graph, 1, 7);
//     addEdge(graph, 1, 8);

//     addEdge(graph, 2, 3);

//     addEdge(graph, 3, 4);
//     addEdge(graph, 3, 9);

//     addEdge(graph, 4, 5);
//     addEdge(graph, 4, 6);

//     addEdge(graph, 5, 6);

//     addEdge(graph, 7, 8);

//     addEdge(graph, 8, 0);
// }

// BFS algorithm in C

#include <stdio.h>
#include <stdlib.h>
#define SIZE 40

struct queue {
  int items[SIZE];
  int front;
  int rear;
};

struct queue* createQueue();
void enqueue(struct queue* q, int);
int dequeue(struct queue* q);
void display(struct queue* q);
int isEmpty(struct queue* q);
void printQueue(struct queue* q);

struct node {
  int vertex;
  struct node* next;
};

struct node* createNode(int);

struct Graph {
  int numVertices;
  struct node** adjLists;
  int* visited;
};

// BFS algorithm
void bfs(struct Graph* graph, int startVertex) {
  struct queue* q = createQueue();

  graph->visited[startVertex] = 1; // culorile oarecum, 1 inseamna gri
  enqueue(q, startVertex);

  while (!isEmpty(q)) {
    // printQueue(q);
    int currentVertex = dequeue(q);
    printf("-%c; ", 'A' + currentVertex);
    printQueue(q);

    struct node* temp = graph->adjLists[currentVertex];

    while (temp) {
      int adjVertex = temp->vertex;

      if (graph->visited[adjVertex] == 0) {
        graph->visited[adjVertex] = 1;
        enqueue(q, adjVertex);
      }
      temp = temp->next;
    }
  }
}

// Creating a node
struct node* createNode(int v) {
  struct node* newNode = malloc(sizeof(struct node));
  newNode->vertex = v;
  newNode->next = NULL;
  return newNode;
}

// Creating a graph
struct Graph* createGraph(int vertices) {
  struct Graph* graph = malloc(sizeof(struct Graph));
  graph->numVertices = vertices;

  graph->adjLists = malloc(vertices * sizeof(struct node*));
  graph->visited = malloc(vertices * sizeof(int));

  int i;
  for (i = 0; i < vertices; i++) {
    graph->adjLists[i] = NULL;
    graph->visited[i] = 0;
  }

  return graph;
}

// Add edge
void addEdge(struct Graph* graph, int src, int dest) {
  // Add edge from src to dest
  struct node* newNode = createNode(dest);
  newNode->next = graph->adjLists[src];
  graph->adjLists[src] = newNode;

  // Add edge from dest to src
//   newNode = createNode(src);
//   newNode->next = graph->adjLists[dest];
//   graph->adjLists[dest] = newNode;
}




// Create a queue
struct queue* createQueue() {
  struct queue* q = malloc(sizeof(struct queue));
  q->front = -1;
  q->rear = -1;
  return q;
}

// Check if the queue is empty
int isEmpty(struct queue* q) {
  if (q->rear == -1)
    return 1;
  else
    return 0;
}

// Adding elements into queue
void enqueue(struct queue* q, int value) {
  if (q->rear == SIZE - 1)
    printf("\nQueue is Full!!");
  else {
    if (q->front == -1)
      q->front = 0;
    q->rear++;
    q->items[q->rear] = value;
  }
}

// Removing elements from queue
int dequeue(struct queue* q) {
  int item;
  if (isEmpty(q)) {
    printf("Queue is empty");
    item = -1;
  } else {
    item = q->items[q->front];
    q->front++;
    if (q->front > q->rear) {
      printf("QUEUE is now Empty\n");
      q->front = q->rear = -1;
    }
  }
  return item;
}

// Print the queue
void printQueue(struct queue* q) {
  int i = q->front;

  if (isEmpty(q)) {
    printf("Queue is empty\n");
  } else {
    printf("Queue contains: ");
    for (i = q->front; i < q->rear + 1; i++) {
      printf("%c ", 'A' + q->items[i]);
    }
    printf("\n");
  }
}

void printGraph(struct Graph *graph, int n) {
    for(int i = 0; i < n; i++) {
        struct node *temp = graph->adjLists[i];
        printf("%c: ", ('A' + i));
        while(temp) {
            printf("%c ", ('A' + temp->vertex));
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
  struct Graph* graph = createGraph(10);
    graphLab(graph);
    printGraph(graph, 10);

  bfs(graph, 0);

  return 0;
}
