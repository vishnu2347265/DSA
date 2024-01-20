#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent an edge in the graph
struct Edge {
    int src, dest, weight;
};

// Structure to represent a connected pharmacy location
struct Location {
    char name[50];
};

// Structure to represent a graph
struct Graph {
    int V, E;           // Number of vertices and edges
    struct Edge* edges; // Array to store edges
    struct Location* locations; // Array to store pharmacy locations
};

// Function to create a graph with V vertices and E edges
struct Graph* createGraph(int V, int E) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;

    graph->edges = (struct Edge*)malloc(E * sizeof(struct Edge));
    graph->locations = (struct Location*)malloc(V * sizeof(struct Location));

    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest, int weight) {
    graph->edges[src].src = src;
    graph->edges[src].dest = dest;
    graph->edges[src].weight = weight;
}

// Function to compare edges for qsort() in Kruskal's algorithm
int compareEdges(const void* a, const void* b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}

// Function to find the set of a given vertex
int findSet(int parent[], int i) {
    if (parent[i] == -1)
        return i;
    return findSet(parent, parent[i]);
}

// Function to perform union of two sets in Kruskal's algorithm
void unionSets(int parent[], int x, int y) {
    int rootX = findSet(parent, x);
    int rootY = findSet(parent, y);
    parent[rootX] = rootY;
}

// Function to construct MST using Kruskal's algorithm
void kruskalMST(struct Graph* graph) {
    int V = graph->V;
    struct Edge result[V];
    int e = 0; // An index variable to keep track of the edges added to the MST
    int i = 0; // An index variable to iterate over sorted edges array

    // Sort all edges in the graph in non-decreasing order of their weight
    qsort(graph->edges, graph->E, sizeof(graph->edges[0]), compareEdges);

    int parent[V];
    memset(parent, -1, sizeof(parent));

    // Number of edges to be taken is equal to V-1
    while (e < V - 1 && i < graph->E) {
        struct Edge nextEdge = graph->edges[i++];

        int x = findSet(parent, nextEdge.src);
        int y = findSet(parent, nextEdge.dest);

        // Include this edge in the result if it doesn't form a cycle
        if (x != y) {
            result[e++] = nextEdge;
            unionSets(parent, x, y);
        }
    }

    printf("Edges in the MST (Kruskal's Algorithm):\n");
    for (int j = 0; j < e; j++) {
        printf("%s - %s (%d)\n", graph->locations[result[j].src].name, graph->locations[result[j].dest].name, result[j].weight);
    }
}

// Function to find the vertex with minimum key value in Prim's algorithm
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

// Function to print the MST using Prim's algorithm
void printPrimMST(int parent[], int graph[V][V], int V) {
    printf("Edges in the MST (Prim's Algorithm):\n");
    for (int i = 1; i < V; i++) {
        printf("%s - %s (%d)\n", graph->locations[parent[i]].name, graph->locations[i].name, graph[i][parent[i]]);
    }
}

// Function to construct MST using Prim's algorithm
void primMST(int graph[V][V], int V) {
    int parent[V];  // Array to store constructed MST
    int key[V];     // Key values to pick the minimum weight edge
    int mstSet[V];  // To represent set of vertices included in MST

    // Initialize all keys as INFINITE
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    // Always include the first vertex in MST
    key[0] = 0;
    parent[0] = -1;

    // The MST will have V vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum key vertex from the set of vertices not yet included in MST
        int u = minKey(key, mstSet, V);

        // Add the picked vertex to the MST Set
        mstSet[u] = 1;

        // Update key value and parent index of the adjacent vertices of the picked vertex
        for (int v = 0; v < V; v++) {
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printPrimMST(parent, graph, V);
}

int main() {
    // Number of pharmacy locations
    int V = 5;
    
    // Number of edges
    int E = 7;

    // Create a graph with V vertices and E edges
    struct Graph* graph = createGraph(V, E);

    // Set pharmacy location names
    strcpy(graph->locations[0].name, "Pharmacy A");
    strcpy(graph->locations[1].name, "Pharmacy B");
    strcpy(graph->locations[2].name, "Pharmacy C");
    strcpy(graph->locations[3].name, "Pharmacy D");
    strcpy(graph->locations[4].name, "Pharmacy E");

    // Add edges between pharmacy locations with weights
    addEdge(graph, 0, 1, 2);
    addEdge(graph, 0, 2, 4);
    addEdge(graph, 1, 2, 1);
    addEdge(graph, 1, 3, 7);
    addEdge(graph, 2, 3, 3);
    addEdge(graph, 2, 4, 5);
    addEdge(graph, 3, 4, 6);

    // Perform Kruskal's algorithm to find MST
    kruskalMST(graph);

    printf("\n");

    // Perform Prim's algorithm to find MST
    int graphMatrix[V][V] = {
        {0, 2, 4, 0, 0},
        {2, 0, 1, 7, 0},
        {4, 1, 0, 3, 5},
        {0, 7, 3, 0, 6},
        {0, 0, 5, 6, 0}
    };
    primMST(graphMatrix, V);

    return 0;
}
