// Topological Sorting Overview:
Topological Sorting is a linear ordering of vertices in a directed acyclic graph (DAG) such that for every directed edge u -> v, 
vertex u appears before v in the ordering. It's widely used in scenarios where tasks need to be performed in a specific sequence.

Example:
Consider a graph with the following directed edges:

A -> B
A -> C
B -> D
C -> D
The topological sort of this graph would be A -> B -> C -> D or A -> C -> B -> D, 
where A appears before B and C, and both B and C appear before D. 
This order respects the dependencies implied by the edges.

Key Points:
DAG Requirement: Topological sorting is only possible for DAGs (graphs with no cycles).
//







#include <vector>
#include <stack>

void dfs(int node, int vis[], std::stack<int>& st, std::vector<int> adj[]) {
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
