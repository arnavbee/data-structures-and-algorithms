class Solution {
public:
    // Depth-first search (DFS) function to check if the graph is bipartite
    bool dfs(vector<vector<int>>& graph, vector<int>& color, int node, int c) {
        // Color the current node with c (either 1 or 0)
        color[node] = c;

        // Traverse all the neighbors of the current node
        for (int neighbour : graph[node]) {
            // If the neighbor has not been colored yet
            if (color[neighbour] == -1) {
                // Recursively call dfs on the neighbor with the opposite color (!c)
                if (!dfs(graph, color, neighbour, !c)) {
                    return false; // If the recursion finds a conflict, return false
                }
            }
            // If the neighbor has the same color as the current node, it's not bipartite
            else if (color[neighbour] == color[node]) {
                return false;
            }
        }
        // If all neighbors are properly colored, return true
        return true;
    }

    // Main function to check if the graph is bipartite
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size(); // Number of nodes in the graph
        vector<int> color(n, -1); // Initialize all nodes with color -1 (uncolored)

        // Check each node to ensure all components of the graph are bipartite
        for (int i = 0; i < n; i++) {
            if (color[i] == -1) { // If the node is uncolored, perform a DFS
                if (!dfs(graph, color, i, 0)) { // Start DFS with color 0
                    return false; // If any component is not bipartite, return false
                }
            }
        }
        return true; // If all components are bipartite, return true
    }
};
