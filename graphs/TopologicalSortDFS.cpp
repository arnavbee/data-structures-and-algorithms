#include <vector>
#include <stack>

// Function to perform DFS from a given node
// node: the current node being visited
// vis[]: an array to mark visited nodes
// st: a stack to store the topological order
// adj[]: adjacency list representation of the graph
void dfs(int node, int vis[], std::stack<int>& st, std::vector<int> adj[]) {
    // Mark the current node as visited
    vis[node] = 1;
    
    // Explore all adjacent nodes
    for(auto it: adj[node]){
        // If the adjacent node is not visited, call DFS on it
        if(!vis[it]){
            dfs(it, vis, st, adj);
        }
    }
    
    // Push the current node onto the stack after all adjacent nodes are processed
    st.push(node);
}

// Function to return the topological sort of the graph
// V: number of vertices in the graph
// adj[]: adjacency list representation of the graph
std::vector<int> topoSort(int V, std::vector<int> adj[]) {
    // Array to keep track of visited nodes
    int vis[V] = {0};
    
    // Stack to store the nodes in topological order
    std::stack<int> st;
    
    // Perform DFS from each unvisited node to cover disconnected components
    for(int i = 0; i < V; i++){
        if(!vis[i]){
            dfs(i, vis, st, adj);
        }
    }
    
    // Vector to store the final topological order
    std::vector<int> ans;
    
    // Pop all elements from the stack to get the topological order
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    
    // Return the topological order
    return ans;
}
