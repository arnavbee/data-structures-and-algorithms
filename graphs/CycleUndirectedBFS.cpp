#include <vector>
using namespace std;


// Function to detect a cycle starting from the source node 'src'.


bool detect(int src, vector<int> adj[], int vis[]) {
    // Mark the current node as visited.
    vis[src] = 1;

    // Initialize a queue to perform BFS, storing pairs of (node, parent).
    queue<pair<int, int>> q;
    q.push({src, -1});  // Push the source node with no parent (-1).

    // Perform BFS.
    while (!q.empty()) {
        // Get the front element in the queue.
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        // Traverse all adjacent nodes of the current node.
        for (auto adjacentNode : adj[node]) {
            // If the adjacent node is not visited, mark it as visited and push it into the queue.
            if (!vis[adjacentNode]) {
                vis[adjacentNode] = 1;
                q.push({adjacentNode, node});
            }
            // If the adjacent node is visited and it is not the parent of the current node,
            // it indicates the presence of a cycle.
            else if (parent != adjacentNode) {
                return true;  // Cycle detected.
            }
        }
    }
    // If no cycle is found during BFS, return false.
    return false;
}

// Function to detect a cycle in an undirected graph.
bool isCycle(int V, vector<int> adj[]) {
    // Initialize a visited array to track visited nodes.
    int vis[V] = {0};

    // Traverse all nodes in the graph.
    for (int i = 0; i < V; i++) {
        // If the node is not visited, start BFS to detect a cycle from that node.
        if (!vis[i]) {
            // If a cycle is detected, return true.
            if (detect(i, adj, vis)) return true;
        }
    }

    // If no cycle is detected in the graph, return false.
    return false;
}
