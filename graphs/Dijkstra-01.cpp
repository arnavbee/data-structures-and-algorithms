vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    // priority queue 'pq' -> distance, node 
    // 'greater<pair<int, int>>' -> min-heap, pair with the smallest distance -> top.

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<int> dist(V);

    for (int i = 0; i < V; i++)
        dist[i] = 1e9;

    dist[S] = 0;

    pq.push({0, S});

    while (!pq.empty()) {
        int dis = pq.top().first;  
        int node = pq.top().second; 
        pq.pop(); 

        for (auto it : adj[node]) {
            int edgeWeight = it[1]; 
            int adjNode = it[0]; 

            // If a shorter path to 'adjNode' is found, update its distance.
            if (dis + edgeWeight < dist[adjNode]) {
                dist[adjNode] = dis + edgeWeight;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }

    return dist;
}
