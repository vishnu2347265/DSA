#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Function to find the vertex with the minimum key value
int minKey(int key[], int mstSet[], int V) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (mstSet[v] == 0 && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }

    return min_index;
}

// Function to print the constructed MST stored in parent[]
void printMST(int parent[], int graph[V][V], int V) {
    printf("Edge   Weight\n");
    for (int i = 1; i < V; i++)
        printf("%d - %d    %d \n", parent[i], i, graph[i][parent[i]]);
}

// Prim's algorithm to find the MST in a graph
void primMST(int graph[V][V], int V) {
    int parent[V];  // Array to store constructed MST
    int key[V];     // Key values used to pick the minimum weight edge
    int mstSet[V];  // To represent set of vertices included in MST

    // Initialize all keys as INFINITE
    // Initialize all vertices as not in the MST
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    // Always include the first vertex in MST
    key[0] = 0;
    parent[0] = -1; // First node is always the root of MST

    // The MST will have V-1 edges
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum key vertex from the set of vertices not yet included in MST
        int u = minKey(key, mstSet, V);

        // Add the picked vertex to the MST set
        mstSet[u] = 1;

        // Update key value and parent index of adjacent vertices
        // of the picked vertex. Consider only those vertices
        // which are not yet included in the MST
        for (int v = 0; v < V; v++) {
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print the constructed MST
    printMST(parent, graph, V);
}

// Kruskal's algorithm to find the MST in a graph
// Union-Find implementation
int find(int parent[], int i) {
    if (parent[i] == -1)
        return i;
    return find(parent, parent[i]);
}

void unionSets(int parent[], int x, int y) {
    int xset = find(parent, x);
    int yset = find(parent, y);
    parent[xset] = yset;
}

void kruskalMST(int graph[V][V], int V) {
    int parent[V];

    // Initialize all subsets as singletons
    for (int i = 0; i < V; i++)
        parent[i] = -1;

    // Number of edges to be taken is V-1
    for (int count = 0; count < V - 1; count++) {
        int min = INT_MAX, u, v;

        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (find(parent, i) != find(parent, j) && graph[i][j] < min) {
                    min = graph[i][j];
                    u = i;
                    v = j;
                }
            }
        }

        unionSets(parent, u, v);
        printf("%d - %d    %d \n", u, v, min);
    }
}

int main() {
    int V;

    // Get the number of pharmacy locations from the user
    printf("Enter the number of pharmacy locations: ");
    scanf("%d", &V);

    // Example graph represented by the distance between pharmacy locations
    int graph[V][V];

    // Get distances between pharmacy locations from the user
    printf("Enter the distances between pharmacy locations:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("\nChoose the algorithm:\n");
    printf("1. Prim's Algorithm\n");
    printf("2. Kruskal's Algorithm\n");

    int choice;
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Prim's MST:\n");
            primMST(graph, V);
            break;
        case 2:
            printf("Kruskal's MST:\n");
            kruskalMST(graph, V);
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}