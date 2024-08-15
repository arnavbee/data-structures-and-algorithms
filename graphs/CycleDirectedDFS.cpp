bool dfsCheck(int node, vector<int> adj[], int vis[], int pathVis[]) {
    vis[node] = 1;       // Use assignment `=` instead of comparison `==`
    pathVis[node] = 1;

    // Traversing for adjacent nodes
    for (int adjacentNode : adj[node]) {
        if (!vis[adjacentNode]) {
            if (dfsCheck(adjacentNode, adj, vis, pathVis)) {
                return true;
            }
        } else if (pathVis[adjacentNode]) {
            return true;
        }
    }

    pathVis[node] = 0;  // Reset the pathVis for backtracking
    return false;
}

public:
bool isCyclic(int V, vector<int> adj[]) {
    int vis[V] = {0};
    int pathVis[V] = {0};

    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            if (dfsCheck(i, adj, vis, pathVis)) {
                return true;
            }
        }
    }

    return false;
}