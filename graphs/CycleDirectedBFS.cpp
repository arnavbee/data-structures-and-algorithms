Intuition ->
if it is topo sort -> then it is not cyclic
if it is not topo sort -> then it is cyclic
same code as topo sort bfs but at last true or false condition




bool isCyclic(int V, vector<int> adj[]) {
    // Step 1: Calculate the in-degree of each vertex
    int indegree[V] = {0};
    for(int i = 0; i < V; i++){
        // For each adjacent vertex of vertex i
        for(auto it: adj[i]){
            // Increment the in-degree of the adjacent vertex
            indegree[it]++;
        }
    }

    // Step 2: Initialize a queue and add all vertices with in-degree 0
    queue<int> q;
    for(int i = 0; i < V; i++){
        if(indegree[i] == 0){
            // Push vertices with in-degree 0 into the queue
            q.push(i);
        }
    }

    // Step 3: Perform BFS and count the vertices processed
    int cnt = 0;
    while(!q.empty()){
        int node = q.front();  // Get the front element of the queue
        q.pop();  // Remove the front element from the queue
        cnt++;  // Increment the count of processed vertices
        
        // Reduce the in-degree of all adjacent vertices of the current node
        for(auto it: adj[node]){
            indegree[it]--;
            // If in-degree becomes 0, add the vertex to the queue
            if(indegree[it] == 0)
                q.push(it);
        }
    }

    // Step 4: Check if the number of processed vertices is equal to V
    if(cnt == V) 
        return false;  // No cycle detected
    return true;  // Cycle detected
}
