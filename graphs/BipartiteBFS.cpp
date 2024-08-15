// Title: Check if a Graph is Bipartite using BFS

class Solution {
public:
    // Function to check if the graph is bipartite
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size(); // Number of nodes in the graph

        vector<int> color(n, -1); // Initialize all nodes with color -1 (uncolored)

        // Iterate through each node in the graph
        for (int i = 0; i < n; i++) {
            if (color[i] == -1) { // If the node is uncolored, start BFS
                queue<int> q;
                q.push(i);
                color[i] = 0; // Assign the initial color (0)

                // Perform BFS
                while (!q.empty()) {
                    int node = q.front();
                    q.pop();

                    // Traverse all neighbors of the current node
                    for (int neighbour : graph[node]) {
                        if (color[neighbour] == -1) { // If the neighbor is uncolored
                            color[neighbour] = 1 - color[node]; // Assign the opposite color
                            q.push(neighbour); // Add the neighbor to the queue
                        }
                        // If the neighbor has the same color as the current node, it's not bipartite
                        else if (color[neighbour] == color[node]) {
                            return false;
                        }
                    }
                }
            }
        }
        return true; // If all components are bipartite, return true
    }
};
