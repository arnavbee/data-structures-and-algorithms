//Kahn's Algorithm

vector<int> topoSort(int V, vector<int> adj[]) 
{
    // Array to store the in-degree (number of incoming edges) of each vertex
    int indegree[V] = {0};

    // Calculate the in-degree of each vertex by traversing the adjacency list
    for(int i = 0; i < V; i++) {
        for(auto it: adj[i]) {
            indegree[it]++;  // Increase the in-degree of the connected vertex
        }
    }
    
    // Queue to store vertices with in-degree 0 (starting points for topological sort)
    queue<int> q;
    for(int i = 0; i < V; i++) {
        if(indegree[i] == 0) {
            q.push(i);  // Push vertices with in-degree 0 to the queue
        }
    }
    
    // Vector to store the topological order of the vertices
    vector<int> topo;
    
    // Process the vertices in the queue
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        topo.push_back(node);  // Add the vertex to the topological order
        
        // Reduce the in-degree of all adjacent vertices
        for(auto it: adj[node]) {
            indegree[it]--;
            // If in-degree becomes 0, push the vertex to the queue
            if(indegree[it] == 0) {
                q.push(it);
            }
        }
    }
    
    return topo;  // Return the topological order
}
