// Node definition (Assumed)
struct Node {
    int val;
    Node* next;
    Node* random;
    Node(int x) : val(x), next(nullptr), random(nullptr) {}
};

// Function to insert a copy of each node in between original nodes
void insertCopyInBetween(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        Node* nextElement = temp->next; // Store the next element
        Node* copy = new Node(temp->val); // Create a copy of the current node
        
        copy->next = nextElement; // Point the copy's next to the original's next
        temp->next = copy; // Insert the copy right after the original node
        
        temp = nextElement; // Move to the next original node
    }
}

// Function to connect random pointers of the copied nodes
void connectRandomPointers(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        Node* copyNode = temp->next; // The copy node is right after the original node
        
        if (temp->random) {
            copyNode->random = temp->random->next; // Set the random pointer of the copy
        } else {
            copyNode->random = NULL; // If the original node's random is NULL
        }
        
        temp = temp->next->next; // Move to the next original node (skip the copy node)
    }
}

// Function to extract the copied list and restore the original list
Node* getDeepCopyList(Node* head) {
    Node* temp = head;
    Node* dummyNode = new Node(-1); // Dummy node to ease the construction of the copied list
    Node* res = dummyNode;
    
    while (temp != NULL) {
        res->next = temp->next; // Append the copied node to the result list
        res = res->next;
        
        temp->next = temp->next->next; // Restore the original list's next pointer
        temp = temp->next; // Move to the next original node
    }
    
    return dummyNode->next; // Return the head of the copied list
}

// Main function to deep copy the list
Node* copyRandomList(Node* head) {
    insertCopyInBetween(head); // Step 1: Insert copies in between original nodes
    connectRandomPointers(head); // Step 2: Connect random pointers for the copied nodes
    return getDeepCopyList(head); // Step 3: Extract the copied list and restore the original
}
