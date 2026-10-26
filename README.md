# Campus Route Finder

A graph-based campus navigation project developed using the C programming language. The project represents campus locations as vertices and paths between locations as edges. It uses Breadth-First Search (BFS) to find the shortest route and Depth-First Search (DFS) to explore reachable locations.

## 1. Project Overview

Finding routes between different campus locations can be represented as a graph problem.

In this project, eight campus locations are connected through paths. Users can display locations, explore graph connections, find the shortest route between two locations, explore reachable locations, and identify disconnected groups.

The project demonstrates fundamental graph concepts and algorithms using simple C programming.

## 2. Problem Statement

Develop a Campus Route Finder that represents campus locations as vertices and paths between locations as edges.

The application should allow users to:

* Display campus locations and their connections.
* Find a route between two locations.
* Find the shortest route in an unweighted graph using BFS.
* Display reachable locations using DFS.
* Identify disconnected locations.
* Find the connected components of the graph.
* Understand graph representation and algorithm complexity.

## 3. Objectives

1. Create a graph containing at least eight campus locations.
2. Represent the graph using an adjacency list.
3. Implement BFS for shortest-path finding.
4. Implement DFS for graph traversal and reachability.
5. Reconstruct a route using a parent array.
6. Identify disconnected locations and connected components.
7. Study the time and space complexity of graph algorithms.

## 4. Technologies Used

* Programming Language: C
* Compiler: GCC
* Data Structure: Graph
* Graph Representation: Adjacency List
* Algorithms: Breadth-First Search and Depth-First Search
* Development Environment: Visual Studio Code

No external libraries are required.

## 5. Campus Locations

The graph contains the following eight locations:

| Number | Location   |
| ------ | ---------- |
| 1      | Main Gate  |
| 2      | Library    |
| 3      | Block 1    |
| 4      | Block 2    |
| 5      | Cafeteria  |
| 6      | Auditorium |
| 7      | Parking    |
| 8      | Lab        |

## 6. Graph Connections

The campus graph contains these undirected connections:

| Starting Location | Connected Location |
| ----------------- | ------------------ |
| Main Gate         | Library            |
| Main Gate         | Block 1            |
| Library           | Block 2            |
| Block 1           | Block 2            |
| Block 1           | Cafeteria          |
| Block 2           | Lab                |
| Cafeteria         | Lab                |
| Auditorium        | Parking            |

The graph contains eight vertices and eight undirected edges.

Because the graph is undirected, a connection can be travelled in either direction.

For example, if Main Gate is connected to Library, Library is also connected to Main Gate.

## 7. Graph Representation

The project uses an adjacency list implemented with arrays.

The program stores the neighbours of each vertex in the `adj` array. The `degree` array stores the number of neighbours for each vertex.

For example:

Main Gate: Library, Block 1

This means that Main Gate has two directly connected locations.

The graph is created using the `addEdge()` function.

Each connection is stored in both directions because the graph is undirected.

### Why use an adjacency list?

An adjacency list stores the existing connections of each vertex. For a standard adjacency-list representation, the graph requires O(V + E) storage, making it suitable for sparse graphs.

The current implementation uses fixed-size arrays for simplicity. Therefore, its allocated adjacency storage is O(V²), even though the algorithms visit only the recorded neighbours.

## 8. Features

### Feature 1: Display Locations

Displays all eight campus locations with their corresponding numbers.

### Feature 2: Display Graph Connections

Displays each location and its directly connected neighbours.

### Feature 3: Find the Shortest Route Using BFS

Allows the user to select a starting location and destination.

BFS explores the graph level by level and finds a route with the minimum number of edges.

The program uses a queue to manage vertices waiting to be explored.

A parent array stores the previous vertex on the discovered route. The program uses this information to reconstruct the route from the destination back to the source.

### Feature 4: Find Reachable Locations Using DFS

Allows the user to select a starting location.

DFS explores connected locations recursively and displays all locations reachable from the selected starting point.

### Feature 5: Find Connected Components

Identifies separate groups of connected locations.

The program starts DFS from every unvisited vertex. Each new DFS traversal identifies another connected component.

The current graph has two connected components:

* Component 1: Main Gate, Library, Block 1, Block 2, Cafeteria, and Lab.
* Component 2: Auditorium and Parking.

### Feature 6: Exit

Allows the user to exit the application.

## 9. Algorithms Used

### Breadth-First Search (BFS)

BFS explores vertices level by level.

Steps:

1. Mark all vertices as unvisited.
2. Add the starting vertex to the queue.
3. Remove a vertex from the queue.
4. Visit its unvisited neighbours.
5. Store each neighbour's parent.
6. Continue until the destination is reached or the queue becomes empty.
7. Reconstruct the route using the parent array.

BFS finds the shortest route in an unweighted graph because it explores paths in increasing order of the number of edges.

### Depth-First Search (DFS)

DFS explores one path as far as possible before returning to explore another path.

Steps:

1. Mark the current vertex as visited.
2. Display the current location.
3. Check its neighbouring vertices.
4. Recursively visit every unvisited neighbour.

DFS is used to display reachable locations and identify connected components.

## 10. Time and Space Complexity

Let:

* V = Number of vertices.
* E = Number of edges.

| Operation                                            | Time Complexity | Auxiliary Space |
| ---------------------------------------------------- | --------------- | --------------- |
| Display locations                                    | O(V)            | O(1)            |
| BFS using a standard adjacency list                  | O(V + E)        | O(V)            |
| DFS using a standard adjacency list                  | O(V + E)        | O(V)            |
| Connected components using a standard adjacency list | O(V + E)        | O(V)            |
| Graph storage in a standard adjacency list           | —               | O(V + E)        |
| Graph storage in an adjacency matrix                 | —               | O(V²)           |

**Implementation note:** The program uses a fixed-size `adj[V][V]` array to store the adjacency list. Its allocated graph storage is O(V²). However, BFS and DFS examine only the neighbours recorded in `degree`, so their traversal time is O(V + E).

The DFS auxiliary space includes the visited array and recursive function calls. BFS uses a queue, a parent array, and a visited array.

## 11. Sample Input and Output

### Example 1: Display Locations

Input:
1

Output:

1. Main Gate
2. Library
3. Block 1
4. Block 2
5. Cafeteria
6. Auditorium
7. Parking
8. Lab

### Example 2: Display Graph Connections

Input:
2

Sample output:

Main Gate: Library, Block 1

Library: Main Gate, Block 2

Block 1: Main Gate, Block 2, Cafeteria

Block 2: Library, Block 1, Lab

Cafeteria: Block 1, Lab

Auditorium: Parking

Parking: Auditorium

Lab: Block 2, Cafeteria

### Example 3: Find the Shortest Route

Input:

* Menu choice: 3
* Starting location: 1
* Destination: 8

Output:

Shortest Route: Main Gate -> Block 1 -> Block 2 -> Lab

Number of edges: 3

Another route with three edges may also be displayed if the neighbour order changes.

### Example 4: Find an Unreachable Destination

Input:

* Menu choice: 3
* Starting location: 1
* Destination: 6

Output:

No route exists between these locations!

### Example 5: Find Connected Components

Input:
5

Output:

Total connected components: 2

The first component contains six locations, and the second contains Auditorium and Parking.

## 12. How to Compile and Run

### Requirements

Install GCC and make sure it is available in your terminal.

### Compile

```bash
gcc main.c -o campus
```

### Run on Windows

```bash
.\campus.exe
```

### Run on Linux

```bash
./campus
```

### Run in Visual Studio Code

1. Open the project folder in VS Code.
2. Open the integrated terminal.
3. Compile the program using GCC.
4. Run the generated executable.
5. Select an operation from the menu.

## 13. Test Cases

The project should be tested using at least these cases:

| Test Case               | Input                   | Expected Result                 |
| ----------------------- | ----------------------- | ------------------------------- |
| Direct route            | Main Gate to Library    | One edge                        |
| Multi-stop route        | Main Gate to Lab        | Shortest route with three edges |
| Unreachable destination | Main Gate to Auditorium | No route exists                 |
| Connected components    | Select option 5         | Two components                  |

The actual output should be verified by running the program.

## 14. Project Limitations

* The campus graph is predefined in the source code.
* Users cannot add or remove locations while the program is running.
* All connections are treated as having equal cost.
* The shortest route is based on the minimum number of edges, not actual distance or travel time.
* The graph uses fixed-size arrays because the project is designed for eight locations.

## 15. Future Improvements

Possible improvements include:

* Allow users to add locations and connections.
* Store actual distances between locations.
* Use Dijkstra's algorithm for weighted routes.
* Create a graphical campus map.
* Implement a dynamically allocated adjacency list.
* Add a graphical user interface.

## 16. Conclusion

Campus Route Finder demonstrates how graph data structures can represent campus locations and their connections.

BFS is used to find shortest routes in an unweighted graph, while DFS explores reachable locations and identifies connected components.

The project provides practical experience with graph representation, queues, recursion, visited arrays, parent tracking, and algorithm complexity.

## 17. Author

Student Project: Campus Route Finder

Language: C

Topic: Graphs, BFS, DFS, and Shortest-Path Algorithms
