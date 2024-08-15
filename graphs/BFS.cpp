vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    int vis[V] = {0};  // Initialize a visited array to keep track of visited nodes
    vis[0] = 1;        // Mark the starting node (0) as visited
    queue<int> q;      // Create a queue for BFS
    
    q.push(0);         // Start BFS from node 0
    
    vector<int> bfs;   // Vector to store the BFS traversal
    
    // Perform BFS until the queue is empty
    while (!q.empty()) {
        int node = q.front();  // Get the front node from the queue
        q.pop();               // Remove the front node from the queue
        bfs.push_back(node);   // Add the node to the BFS result
        
        // Traverse all adjacent nodes of the current node
        for (auto it : adj[node]) {
            if (!vis[it]) {    // If the adjacent node is not visited
                vis[it] = 1;   // Mark it as visited
                q.push(it);    // Add it to the queue for further exploration
            }
        }
    }
    
    return bfs;  // Return the complete BFS traversal
}
