// Function to merge two sorted linked lists
Node* mergeTwoLists(Node* list1, Node* list2) {
    if (!list1) return list2;
    if (!list2) return list1;

    Node* result;

    if (list1->data < list2->data) {
        result = list1;
        result->child = mergeTwoLists(list1->child, list2);
    } else {
        result = list2;
        result->child = mergeTwoLists(list1, list2->child);
    }

    result->next = nullptr; // Ensure next is null in the merged list
    return result;
}

// Function to flatten the multilevel linked list into a single list sorted order
Node* flattenLinkedList(Node* head) {
    if (!head) {
        return nullptr;
    }

    // Recursively flatten the next list
    Node* flattenedNext = flattenLinkedList(head->next);

    // Merge the current node's child list with the flattened next list
    head = mergeTwoLists(head, flattenedNext);

    return head;
}

// Utility function to print the flattened list
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->child;
    }
    cout << endl;
}