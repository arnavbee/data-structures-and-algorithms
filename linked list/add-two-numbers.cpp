ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* t1 = l1;
    ListNode* t2 = l2;
    ListNode* dummyNode = new ListNode(-1); // Dummy node to help with edge cases
    ListNode* curr = dummyNode;
    int carry = 0;

    while (t1 != NULL || t2 != NULL) {
        int sum = carry;

        if (t1) {
            sum += t1->val;
            t1 = t1->next;
        }
        if (t2) {
            sum += t2->val;
            t2 = t2->next;
        }

        carry = sum / 10;
        ListNode* newNode = new ListNode(sum % 10);
        curr->next = newNode;
        curr = curr->next;
    }

    // After the loop, check if there's still a carry to add
    if (carry > 0) {
        curr->next = new ListNode(carry);
    }

    return dummyNode->next;
}