#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 100 
typedef struct Graph {
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
    int visited[MAX_VERTICES];
    int numVertices;
} Graph;
void initGraph(Graph* graph, int vertices) {
    graph->numVertices = vertices;
    for (int i = 0; i < vertices; i++) {
        graph->visited[i] = 0;
        for (int j = 0; j < vertices; j++) {
            graph->adjMatrix[i][j] = 0;
        }
    }
}
void addEdge(Graph* graph, int src, int dest) {
    graph->adjMatrix[src][dest] = 1;  
    graph->adjMatrix[dest][src] = 1;  
}
void DFS(Graph* graph, int vertex) {
    graph->visited[vertex] = 1;
    printf("%d ", vertex);
    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->adjMatrix[vertex][i] == 1 && !graph->visited[i]) {
            DFS(graph, i);
        }
    }
}
void BFS(Graph* graph, int startVertex) {
    int queue[MAX_VERTICES], front = 0, rear = 0;
    graph->visited[startVertex] = 1;
    queue[rear++] = startVertex;
    while (front < rear) {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);
        for (int i = 0; i < graph->numVertices; i++) {
            if (graph->adjMatrix[currentVertex][i] == 1 && !graph->visited[i]) {
                graph->visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}
int main() {
    Graph graph;
    int vertices = 6;
    initGraph(&graph, vertices);
    addEdge(&graph, 0, 1);
    addEdge(&graph, 0, 2);
    addEdge(&graph, 1, 3);
    addEdge(&graph, 1, 4);
    addEdge(&graph, 2, 4);
    addEdge(&graph, 3, 5);
    addEdge(&graph, 4, 5);
    printf("DFS starting from vertex 0:\n");
    DFS(&graph, 0);
    for (int i = 0; i < vertices; i++) {
        graph.visited[i] = 0;
    }
    printf("\nBFS starting from vertex 0:\n");
    BFS(&graph, 0);

    return 0;
}
