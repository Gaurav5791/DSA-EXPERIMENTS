#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int adj[MAX][MAX];
int visited[MAX];
int n;

// Function to create the graph
void createGraph() {
    int i, j;
    printf("Enter number of cities (vertices): ");
    scanf("%d", &n);

    printf("\nEnter the adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("Is there an edge from city %d to city %d (1/0)? ", i, j);
            scanf("%d", &adj[i][j]);
        }
    }
}

// DFS function
void DFS(int v) {
    int i;
    visited[v] = 1;
    printf("%d ", v);

    for (i = 0; i < n; i++) {
        if (adj[v][i] == 1 && visited[i] == 0)
            DFS(i);
    }
}

// BFS function
void BFS(int start) {
    int queue[MAX], front = 0, rear = -1;
    int i, v;

    for (i = 0; i < n; i++)
        visited[i] = 0;

    visited[start] = 1;
    queue[++rear] = start;

    printf("\nNodes reachable from city %d: ", start);
    while (front <= rear) {
        v = queue[front++];
        printf("%d ", v);

        for (i = 0; i < n; i++) {
            if (adj[v][i] == 1 && visited[i] == 0) {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int start, choice;

    createGraph();

    while (1) {
        printf("\n\n1. DFS Traversal");
        printf("\n2. BFS Traversal");
        printf("\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                for (int i = 0; i < n; i++)
                    visited[i] = 0;
                printf("Enter starting city: ");
                scanf("%d", &start);
                printf("\nCities reachable from city %d using DFS: ", start);
                DFS(start);
                break;

            case 2:
                printf("Enter starting city: ");
                scanf("%d", &start);
                BFS(start);
                break;

            case 3:
                exit(0);

            default:
                printf("Invalid choice!");
        }
    }

    return 0;
}