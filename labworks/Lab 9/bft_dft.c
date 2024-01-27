#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// BFT
void breadthFirstTraversal(int graph[][5], int start, int vertices) {
    int i;
    bool visited[vertices];
    for (i = 0; i < vertices; i++) {
        visited[i] = false;
    }

    int queue[vertices];
    int front = -1, rear = -1;

    visited[start] = true;
    queue[++rear] = start;

    while (front != rear) {
        int current = queue[++front];
        printf("%d ", current);

        for (i = 0; i < vertices; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                visited[i] = true;
                queue[++rear] = i;
            }
        }
    }
}

// DFT
void depthFirstTraversal(int graph[][5], int start, int vertices, bool visited[]) {
    int i;
    visited[start] = true;
    printf("%d ", start);

    for (i = 0; i < vertices; i++) {
        if (graph[start][i] == 1 && !visited[i]) {
            depthFirstTraversal(graph, i, vertices, visited);
        }
    }
}

int main() {
    int vertices, source, destination,i,j;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    int graph[vertices][vertices];

    for ( i = 0; i < vertices; i++) {
        for ( j = 0; j < vertices; j++) {
            graph[i][j] = 0;
        }
    }

    do {
        printf("Enter source vertex: ");
        scanf("%d", &source);
        printf("Enter destination vertex: ");
        scanf("%d", &destination);

        // Assuming undirected graph, so set both directions as 1
        graph[source][destination] = 1;
        graph[destination][source] = 1;

        printf("Do you want to add more edges? (1 for Yes, 0 for No): ");
        int addMore;
        scanf("%d", &addMore);

        if (addMore != 1) {
            break;
        }
    } while (1);

    printf("\nAdjacency Matrix:\n");
    for ( i = 0; i < vertices; i++) {
        for ( j = 0; j < vertices; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    printf("\nBreadth-First Traversal: ");
    breadthFirstTraversal(graph, 0, vertices);

    printf("\nDepth-First Traversal: ");
    bool visited[vertices];
    for ( i = 0; i < vertices; i++) {
        visited[i] = false;
    }
    depthFirstTraversal(graph, 0, vertices, visited);

    return 0;
}

