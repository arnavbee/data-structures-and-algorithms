vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    // Declare a priority queue 'pq' that stores pairs of integers.
    // The first integer represents the distance, and the second represents the node.
    // 'greater<pair<int, int>>' makes this a min-heap, where the pair with the smallest distance comes to the top.
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Declare a vector 'dist' to store the shortest distance from the source to each vertex.
    // Initialize the size of 'dist' to V (the number of vertices).
    vector<int> dist(V);

    // Initialize all distances as a large number (infinity).
    // Here, 1e9 is used as a large number representing infinity.
    for (int i = 0; i < V; i++)
        dist[i] = 1e9;

    // The distance from the source node 'S' to itself is 0.
    dist[S] = 0;

    // Push the source node and its distance (0) to the priority queue.
    pq.push({0, S});

    // Process the priority queue until it becomes empty.
    while (!pq.empty()) {
        // Extract the node with the smallest distance from the queue.
        int dis = pq.top().first;  // The current shortest distance to this node.
        int node = pq.top().second; // The node itself.
        pq.pop(); // Remove the top element from the priority queue.

        // Iterate through all adjacent nodes of the current node.
        for (auto it : adj[node]) {
            int edgeWeight = it[1]; // Weight of the edge connecting to the adjacent node.
            int adjNode = it[0]; // The adjacent node.

            // If a shorter path to 'adjNode' is found, update its distance.
            if (dis + edgeWeight < dist[adjNode]) {
                dist[adjNode] = dis + edgeWeight;
                // Push the updated distance and the adjacent node to the priority queue.
                pq.push({dist[adjNode], adjNode});
            }
        }
    }

    // Return the list of shortest distances from the source to all nodes.
    return dist;
}
