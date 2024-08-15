// Title: Depth-First Search (DFS) Traversal of a Graph

// Recursive function to perform DFS starting from a given node 'u'
void DFS(vector<int> adj[], int u, vector<bool>& visited, vector<int>& result) {
    visited[u] = true;          // Mark the current node as visited
    result.push_back(u);        // Add the current node to the result list

    // Traverse all adjacent nodes of 'u'
    for (int v : adj[u]) {
        if (!visited[v]) {      // If the adjacent node 'v' is not visited
            DFS(adj, v, visited, result);  // Recursively perform DFS on 'v'
        }
    }
}

// Function to return a list containing the DFS traversal of the graph
vector<int> dfsOfGraph(int V, vector<int> adj[]) {
    vector<int> result;          // To store the DFS traversal
    vector<bool> visited(V, false);  // To keep track of visited nodes

    // Perform DFS starting from node 0
    DFS(adj, 0, visited, result);

    return result;               // Return the complete DFS traversal
}
