#include <stdio.h>
#include <limits.h>
#define teams 4

int minimum_key(int k[], int mst[]) {
    int minimum = INT_MAX, min, i;

    for (i = 0; i < teams; i++)
        if (mst[i] == 0 && k[i] < minimum)
            minimum = k[i], min = i;
    return min;
}

void prim(int g[teams][teams]) {
    int parent[teams];
    int k[teams];
    int mst[teams];
    int i, count, team, v;

    for (i = 0; i < teams; i++) {
        k[i] = INT_MAX;
        mst[i] = 0;
    }

    k[0] = 0;
    parent[0] = -1;

    for (count = 0; count < teams - 1; count++) {
        team = minimum_key(k, mst);
        mst[team] = 1;

        for (v = 0; v < teams; v++) {
            if (g[team][v] && mst[v] == 0 && g[team][v] < k[v]) {
                parent[v] = team, k[v] = g[team][v];
            }
        }
    }
    printf("\n Edge \t  Weight\n");
    for (i = 1; i < teams; i++)
        printf(" %d <-> %d    %d \n", parent[i], i, g[i][parent[i]]);
}

int main() {
    int g[teams][teams];
    int i, j;

    // Taking input for the 4 by 4 adjacency matrix
    printf("Enter the 4 by 4 adjacency matrix:\n");
    for (i = 0; i < teams; i++) {
        for (j = 0; j < teams; j++) {
            printf("Enter weight from %d to %d (or 0 if no connection): ", i, j);
            scanf("%d", &g[i][j]);
        }
    }

    prim(g);
    return 0;
}
		