void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& st) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited, st);
        }
    }
    st.push(node);
}

void reverseDfs(int node, vector<vector<int>>& transpose, vector<bool>& visited) {
    visited[node] = true;
    for (int neighbor : transpose[node]) {
        if (!visited[neighbor]) {
            reverseDfs(neighbor, transpose, visited);
        }
    }
}

int kosaraju(int V, vector<vector<int>>& adj) {
    stack<int> st;
    vector<bool> visited(V, false);

    // Step 1: Order vertices according to their finishing times in DFS
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i, adj, visited, st);
        }
    }

    // Step 2: Reverse the graph
    vector<vector<int>> transpose(V);
    for (int i = 0; i < V; i++) {
        for (int neighbor : adj[i]) {
            transpose[neighbor].push_back(i);
        }
    }

    // Step 3: Perform DFS in the order of finishing times on the reversed graph
    fill(visited.begin(), visited.end(), false);
    int sccCount = 0;
    while (!st.empty()) {
        int node = st.top();
        st.pop();
        if (!visited[node]) {
            reverseDfs(node, transpose, visited);
            sccCount++;
        }
    }

    return sccCount;
}