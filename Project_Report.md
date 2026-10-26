# CAMPUS ROUTE FINDER

## Project Report

## 1. Abstract

Campus Route Finder is a graph-based navigation project developed using the C programming language. It represents campus locations as vertices and the paths between them as edges.

The project implements an adjacency-list-based graph representation and uses Breadth-First Search (BFS) and Depth-First Search (DFS) to explore the graph.

BFS finds a shortest route between two locations in an unweighted graph, while DFS displays reachable locations and helps identify connected components.

The project demonstrates important data structures and algorithms used in computer science and provides a simple example of how graph algorithms can support campus navigation.

## 2. Problem Statement

The objective is to develop a Campus Route Finder that represents campus locations as vertices and paths between locations as edges.

The application allows users to explore connected locations, find a route between two places, and understand different graph traversal approaches.

The system must demonstrate graph representation, BFS, DFS, shortest-path logic for an unweighted graph, and time and space complexity analysis.

## 3. Objectives

The main objectives are:

1. Create a graph containing at least eight campus locations.
2. Represent the graph using an adjacency list.
3. Implement BFS to find a shortest route.
4. Implement DFS to display reachable locations.
5. Allow users to choose a source and destination.
6. Identify unreachable locations and connected components.
7. Explain the time and space complexity of the algorithms.
8. Test the program using different route scenarios.

## 4. System Requirements

### Hardware Requirements

* A computer or laptop.
* Basic memory and storage sufficient to run a C compiler.

### Software Requirements

* Operating system: Windows or Linux.
* Programming language: C.
* Compiler: GCC or another compatible C compiler.
* Code editor: Visual Studio Code or any text editor.

## 5. Graph Design

The graph represents eight campus locations.

Let G = (V, E), where:

* V represents the set of vertices.
* E represents the set of edges.

The vertex set is:

V = {Main Gate, Library, Block 1, Block 2, Cafeteria, Auditorium, Parking, Lab}

The edge set contains these connections:

E = {
(Main Gate, Library),
(Main Gate, Block 1),
(Library, Block 2),
(Block 1, Block 2),
(Block 1, Cafeteria),
(Block 2, Lab),
(Cafeteria, Lab),
(Auditorium, Parking)
}

The graph is undirected because each connection can be travelled in both directions.

The graph has eight vertices and eight edges.

## 6. Graph Representation

The program uses an adjacency list implemented with fixed-size arrays.

The `adj` array stores the neighbouring vertices of each location.

The `degree` array stores the number of neighbours for each vertex.

The `addEdge()` function adds a connection to both vertices, ensuring that the graph is undirected.

For example, Main Gate is connected to Library and Block 1.

Its adjacency list is:

Main Gate: Library, Block 1

### Advantages

* Makes it easy to visit the neighbours of a vertex.
* Avoids checking every possible edge during traversal.
* Has O(V + E) storage in a standard adjacency-list implementation.
* Works well for sparse graphs.

### Limitation of the Current Implementation

The program uses `int adj[V][V]` with a fixed maximum capacity for each vertex. Therefore, its allocated graph storage is O(V²), even though it follows the neighbour-list approach.

A dynamically allocated adjacency list could reduce graph storage to O(V + E), but the fixed-array version is simpler for a beginner-level project.

## 7. Breadth-First Search (BFS)

### Definition

Breadth-First Search is a graph traversal algorithm that explores vertices level by level, visiting closer vertices before more distant vertices.

### Purpose

BFS is used to find a shortest route between two campus locations.

Because the graph is unweighted, every edge has the same cost. BFS therefore finds a route containing the minimum number of edges.

### Working

1. Mark all vertices as unvisited.
2. Set the parent of each vertex to -1.
3. Add the starting vertex to a queue.
4. Mark the starting vertex as visited.
5. Remove the next vertex from the queue.
6. Visit its unvisited neighbours.
7. Record each neighbour's parent and add it to the queue.
8. Continue until the destination is found or the queue becomes empty.
9. If the destination is reachable, reconstruct the route using the parent array.

### Example

Source: Main Gate

Destination: Lab

One possible shortest route is:

Main Gate -> Block 1 -> Block 2 -> Lab

Number of edges: 3

### Complexity

For a standard adjacency-list implementation:

* Time Complexity: O(V + E)
* Auxiliary Space Complexity: O(V)

The queue, parent array, and visited array require space proportional to the number of vertices.

## 8. Depth-First Search (DFS)

### Definition

Depth-First Search is a graph traversal algorithm that explores one path as far as possible before returning to explore other paths.

### Purpose

DFS is used to:

* Display locations reachable from a starting point.
* Explore the connected part of the graph.
* Identify connected components.

### Working

1. Mark the current vertex as visited.
2. Display the current location.
3. Check each neighbouring vertex.
4. If a neighbour is unvisited, recursively call DFS for that neighbour.
5. Continue until no unvisited neighbours remain.

### Example

Starting from Main Gate, DFS can visit:

Main Gate, Library, Block 2, Block 1, Cafeteria, Lab.

The exact order depends on the order of neighbours in the adjacency list.

Auditorium and Parking are not reachable from Main Gate.

### Complexity

For a standard adjacency-list implementation:

* Time Complexity: O(V + E)
* Auxiliary Space Complexity: O(V)

The auxiliary space includes the visited array and recursive call stack.

## 9. Shortest-Path Reconstruction

BFS records the parent of each newly visited vertex.

For example, if Lab is reached from Block 2, its parent is recorded as Block 2.

After BFS reaches the destination, the program follows the parent links backwards until it reaches the source.

The collected path is then printed in reverse order to display the route from source to destination.

This avoids needing to store a complete route for every vertex during traversal.

## 10. Connected Components

A connected component is a maximal group of vertices in which every vertex can reach every other vertex.

The program uses DFS to find connected components.

Initially, all vertices are marked as unvisited.

The program then checks every vertex:

* If it is unvisited, a new component is counted.
* DFS visits every vertex reachable from that vertex.
* The process continues until all vertices are visited.

### Result

The campus graph contains two connected components.

**Component 1:**

Main Gate, Library, Block 1, Block 2, Cafeteria, and Lab.

**Component 2:**

Auditorium and Parking.

Therefore, the Main Gate and Auditorium do not have a route between them.

## 11. Complexity Analysis

Let:

* V = Number of vertices.
* E = Number of edges.

### Adjacency List

For a standard adjacency list:

* Graph storage: O(V + E)
* BFS time: O(V + E)
* DFS time: O(V + E)
* Connected-components time: O(V + E)

### Adjacency Matrix

For an adjacency matrix:

* Graph storage: O(V²)
* BFS time: O(V²)
* DFS time: O(V²)

### Comparison

An adjacency list is generally more memory-efficient for sparse graphs because it stores the existing edges.

An adjacency matrix uses a two-dimensional array and allows an edge to be checked in O(1) time.

The current program uses a fixed-size array-based adjacency list. Its allocated graph storage is O(V²), but BFS and DFS still take O(V + E) traversal time because they iterate over each vertex's recorded neighbours.

## 12. Testing

The following cases should be executed to verify the program.

### Test Case 1: Direct Route

Input:

* Source: Main Gate
* Destination: Library

Expected result:

* Route: Main Gate -> Library
* Number of edges: 1

### Test Case 2: Multi-Stop Route

Input:

* Source: Main Gate
* Destination: Lab

Expected result:

* A shortest route with three edges.

One possible route is:

Main Gate -> Block 1 -> Block 2 -> Lab

### Test Case 3: Unreachable Destination

Input:

* Source: Main Gate
* Destination: Auditorium

Expected result:

No route exists between these locations!

### Test Case 4: Connected Components

Input:

* Select the connected-components menu option.

Expected result:

Total connected components: 2

The actual outputs should be captured after running the program.

## 13. Results and Discussion

The graph contains two separate connected components.

BFS can find a shortest route between connected locations because it explores the graph level by level.

DFS can display the locations reachable from a selected source.

The parent array makes route reconstruction possible, while the visited array prevents repeated processing of vertices.

The program demonstrates how graph algorithms can be used to model a simple campus navigation problem.

## 14. Limitations

* The locations and connections are predefined.
* The program does not accept new locations while running.
* All edges have equal cost.
* Shortest routes are measured by the number of edges rather than actual distance.
* The implementation uses fixed-size arrays.
* The application runs in a terminal rather than a graphical map interface.

## 15. Future Scope

The project could be extended by:

* Allowing users to enter locations and connections.
* Adding real distances to edges.
* Using Dijkstra's algorithm for weighted shortest paths.
* Displaying the graph visually.
* Using dynamically allocated adjacency lists.
* Creating a graphical interface for campus navigation.

## 16. Conclusion

Campus Route Finder provides a practical demonstration of graph representation and traversal using C.

It implements BFS for shortest-path finding, DFS for reachability, and DFS-based connected-component detection.

The project also demonstrates queue operations, recursion, visited arrays, parent tracking, and algorithm complexity.

Overall, it provides a simple foundation for understanding graph-based navigation systems.
