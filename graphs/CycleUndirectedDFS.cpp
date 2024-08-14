#include <vector>
using namespace std;

// Function to perform DFS and detect a cycle in an undirected graph.
bool dfs(int node, int parent, int vis[], vector<int> adj[]) {
    // Mark the current node as visited.
    vis[node] = 1;

    // Traverse all adjacent nodes of the current node.
    for (auto adjacentNode : adj[node]) {
        // If the adjacent node is not visited, perform DFS on it.
        if (vis[adjacentNode] == 0) {
            // Recursively call DFS for the adjacent node.
            if (dfs(adjacentNode, node, vis, adj) == true) {
                return true;  // If a cycle is detected, return true.
            }
        }
        // If the adjacent node is visited and it is not the parent,
        // it indicates the presence of a cycle.
        else if (adjacentNode != parent) {
            return true;  // Cycle detected.
        }
    }

    // If no cycle is found, return false.
    return false;
}

// Function to detect a cycle in an undirected graph.
bool isCycle(int V, vector<int> adj[]) {
    // Initialize a visited array to track visited nodes.
    int vis[V];
    for (int i = 0; i < V; i++) {
        vis[i] = 0;  // Mark all nodes as unvisited initially.
    }

    // Traverse all nodes in the graph.
    for (int i = 0; i < V; i++) {
        // If the node is not visited, start DFS to detect a cycle from that node.
        if (!vis[i]) {
            if (dfs(i, -1, vis, adj) == true) {
                return true;  // If a cycle is detected, return true.
            }
        }
    }

    // If no cycle is detected in the graph, return false.
    return false;
}
