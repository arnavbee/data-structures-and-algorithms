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
