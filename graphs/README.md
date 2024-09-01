# Graphs

Graphs are fundamental data structures in computer science and play a crucial role in various applications, from social networks to routing algorithms. A graph is a collection of nodes (also called vertices) and edges that connect pairs of nodes. Graphs can represent a wide range of relationships and processes, making them highly versatile in solving complex problems.

## Key Concepts

	1.	Vertices (Nodes): The fundamental units of a graph. Each node typically represents an entity, such as a city in a network of roads or a person in a social network.
	
    2.	Edges: The connections between nodes. Edges can be directed (one-way) or undirected (two-way), representing the relationship between the connected nodes.
	
    3.	Types of Graphs:
	•	Directed Graph (Digraph): Edges have a direction, indicating a one-way relationship from one node to another.
	•	Undirected Graph: Edges do not have a direction, indicating a two-way, bidirectional relationship.
	•	Weighted Graph: Edges have weights or costs associated with them, often representing distances, costs, or capacities.
	•	Unweighted Graph: All edges are considered equal, without any associated weights.
	
    4.	Graph Representation:
	•	Adjacency Matrix: A 2D array where each cell (i, j) indicates the presence (and possibly the weight) of an edge between nodes i and j.
	•	Adjacency List: A collection of lists or arrays where each list corresponds to a node and contains the nodes it is connected to.
	
    5.	Common Graph Algorithms:
	•	Breadth-First Search (BFS): Explores the graph level by level, useful for finding the shortest path in unweighted graphs.
	•	Depth-First Search (DFS): Explores as far as possible along each branch before backtracking, useful for topological sorting and detecting cycles.
	•	Dijkstra’s Algorithm: Finds the shortest path from a source node to all other nodes in a weighted graph.
	•	Kruskal’s and Prim’s Algorithms: Used to find the Minimum Spanning Tree (MST), which connects all nodes in a graph with the minimum total edge weight.

---

## BFS

Initial Setup:
Vertices (V): Number of vertices in the graph.
Adjacency List (adj[]): Represents the graph.
Visited Array (vis): Keeps track of visited nodes.
Queue (q): Used for BFS traversal.
Result (bfs): Stores the BFS traversal order.

Example:
Let's use the same graph as before for illustration:

Vertices (V): 5
Adjacency List (adj):
cpp
Copy code
adj[0] = {1, 2, 3};
adj[1] = {};
adj[2] = {4};
adj[3] = {};
adj[4] = {};

Initial Conditions:
vis = [1, 0, 0, 0, 0] (Only node 0 is visited)
q = [0] (Starting with node 0 in the queue)
bfs = [] (Empty BFS result)

First Iteration:
Queue (q): [0]
Visited Node (node): 0
Processing Adjacent Nodes of 0: 1, 2, 3
vis[1] = 1, vis[2] = 1, vis[3] = 1 (Mark nodes 1, 2, 3 as visited)
q.push(1), q.push(2), q.push(3) (Add nodes 1, 2, 3 to the queue)
Queue after processing: [1, 2, 3]
BFS result: [0]

Second Iteration:
Queue (q): [1, 2, 3]
Visited Node (node): 1 (Front of the queue)
Processing Adjacent Nodes of 1: {} (No adjacent nodes)
No changes in vis or q
Queue after processing: [2, 3]
BFS result: [0, 1]

Third Iteration:
Queue (q): [2, 3]
Visited Node (node): 2 (Front of the queue)
Processing Adjacent Nodes of 2: 4
vis[4] = 1 (Mark node 4 as visited)
q.push(4) (Add node 4 to the queue)
Queue after processing: [3, 4]
BFS result: [0, 1, 2]

Recap:
After Second Iteration:

vis = [1, 1, 1, 1, 0]
q = [2, 3]
bfs = [0, 1]

After Third Iteration:

vis = [1, 1, 1, 1, 1]
q = [3, 4]
bfs = [0, 1, 2]

In the next iterations, nodes 3 and 4 will be processed similarly until the queue is empty.

---