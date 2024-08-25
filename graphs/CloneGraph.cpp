class Solution {
public:
    // This map keeps track of the original nodes and their corresponding cloned nodes.
    unordered_map<Node*, Node*> mp;

    void DFS(Node* node, Node* clone_node) {
        // Iterate through all the neighbors of the current node.
        for(Node* n : node->neighbors) {
            // If the neighbor hasn't been cloned yet.
            if(mp.find(n) == mp.end()) {
                
                // Create a new node with the same value as the neighbor.
                Node* clone = new Node(n->val);
                
                // Map the original neighbor to its clone.
                mp[n] = clone;
                
                // Add this clone to the neighbors of the current cloned node.
                clone_node->neighbors.push_back(clone);
                
                // Recursively clone the neighbor's neighbors.
                DFS(n, clone);
            
            } else {
                
                // If the neighbor has already been cloned, add it to the neighbors of the current clone.
                clone_node->neighbors.push_back(mp[n]);
            }
        }
    }
   
    // Function to clone the graph.
    Node* cloneGraph(Node* node) {
        // If the input node is null, return null.
        if(!node)
            return NULL;

        // Clear the map in case the function is called multiple times.
        mp.clear();

        // Create the clone of the starting node.
        Node* clone_node = new Node(node->val);

        // Map the original starting node to its clone.
        mp[node] = clone_node;

        // Perform DFS to clone the rest of the graph.
        DFS(node, clone_node);

        // Return the clone of the original graph.
        return clone_node;
    }
};
