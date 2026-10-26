
#include <stdio.h>

#define V 8

char *locations[V] = {
    "Main Gate", "Library", "Block 1", "Block 2",
    "Cafeteria", "Auditorium", "Parking", "Lab"
};

/* Adjacency list */
int adj[V][V];
int degree[V] = {0};
int visited[V];

/* Add connection between two locations */
void addEdge(int a, int b)
{
    adj[a][degree[a]++] = b;
    adj[b][degree[b]++] = a;
}

/* Display all campus locations */
void displayLocations()
{
    int i;

    printf("\nCampus Locations:\n");

    for (i = 0; i < V; i++)
        printf("%d. %s\n", i + 1, locations[i]);
}

/* Display graph connections */
void displayGraph()
{
    int i, j;

    printf("\nCampus Graph:\n");

    for (i = 0; i < V; i++)
    {
        printf("%s: ", locations[i]);

        for (j = 0; j < degree[i]; j++)
        {
            printf("%s", locations[adj[i][j]]);

            if (j < degree[i] - 1)
                printf(", ");
        }

        printf("\n");
    }
}

/* BFS: Find shortest route */
void BFS(int start, int end)
{
    int queue[V], parent[V];
    int front = 0, rear = 0;
    int i, current;

    for (i = 0; i < V; i++)
    {
        visited[i] = 0;
        parent[i] = -1;
    }

    queue[rear++] = start;
    visited[start] = 1;

    while (front < rear)
    {
        current = queue[front++];

        if (current == end)
            break;

        for (i = 0; i < degree[current]; i++)
        {
            int next = adj[current][i];

            if (!visited[next])
            {
                visited[next] = 1;
                parent[next] = current;
                queue[rear++] = next;
            }
        }
    }

    if (!visited[end])
    {
        printf("\nNo route exists between these locations!\n");
        return;
    }

    int path[V], count = 0;

    current = end;

    while (current != -1)
    {
        path[count++] = current;
        current = parent[current];
    }

    printf("\nShortest Route: ");

    for (i = count - 1; i >= 0; i--)
    {
        printf("%s", locations[path[i]]);

        if (i > 0)
            printf(" -> ");
    }

    printf("\nNumber of edges: %d\n", count - 1);
}

/* DFS: Display reachable locations */
void DFS(int current)
{
    int i;

    visited[current] = 1;

    printf("%s\n", locations[current]);

    for (i = 0; i < degree[current]; i++)
    {
        int next = adj[current][i];

        if (!visited[next])
            DFS(next);
    }
}

/* Find connected components */
void components()
{
    int i, count = 0;

    for (i = 0; i < V; i++)
        visited[i] = 0;

    for (i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            count++;

            printf("\nComponent %d:\n", count);

            DFS(i);
        }
    }

    printf("\nTotal connected components: %d\n", count);
}

/* Main function */
int main()
{
    int choice, start, end, i;

    /* Campus connections */
    addEdge(0, 1);  /* Main Gate - Library */
    addEdge(0, 2);  /* Main Gate - Block 1 */
    addEdge(1, 3);  /* Library - Block 2 */
    addEdge(2, 3);  /* Block 1 - Block 2 */
    addEdge(2, 4);  /* Block 1 - Cafeteria */
    addEdge(3, 7);  /* Block 2 - Lab */
    addEdge(4, 7);  /* Cafeteria - Lab */
    addEdge(5, 6);  /* Auditorium - Parking */

    do
    {
        printf("\n===== CAMPUS ROUTE FINDER =====\n");
        printf("1. Display Locations\n");
        printf("2. Display Graph Connections\n");
        printf("3. Find Shortest Route (BFS)\n");
        printf("4. Find Reachable Locations (DFS)\n");
        printf("5. Find Connected Components\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input!\n");
            return 1;
        }

        switch (choice)
        {
            case 1:
                displayLocations();
                break;

            case 2:
                displayGraph();
                break;

            case 3:
                displayLocations();

                printf("\nEnter starting location (1-8): ");
                if (scanf("%d", &start) != 1)
                    return 1;

                printf("Enter destination (1-8): ");
                if (scanf("%d", &end) != 1)
                    return 1;

                if (start < 1 || start > V ||
                    end < 1 || end > V)
                {
                    printf("Invalid location!\n");
                }
                else
                {
                    BFS(start - 1, end - 1);
                }

                break;

            case 4:
                displayLocations();

                printf("\nEnter starting location (1-8): ");

                if (scanf("%d", &start) != 1)
                    return 1;

                if (start < 1 || start > V)
                {
                    printf("Invalid location!\n");
                }
                else
                {
                    for (i = 0; i < V; i++)
                        visited[i] = 0;

                    printf("\nReachable locations:\n");

                    DFS(start - 1);
                }

                break;

            case 5:
                components();
                break;

            case 6:
                printf("Thank you for using Campus Route Finder!\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 6);

    return 0;
}

