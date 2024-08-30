# Linked List

## 1. Add Two Numbers as LinkedList

Numbers in Linkedlist are represented in the reverse order
Which may not be sure with the example given below.

- Input:
l1 = [9,9,9,9,9,9,9]
l2 = [9,9,9,9]

- Initial Setup:
Dummy Node: dummyNode is created with a value of -1. It acts as a placeholder to easily return the head of the resulting linked list.
Current Pointer (curr): Initially points to dummyNode.
Carry: Initially set to 0.
Dry Run of the Loop:

- First Iteration:

t1 points to 9, t2 points to 9.
Sum = 9 (from t1) + 9 (from t2) + 0 (carry) = 18.
New node value = 18 % 10 = 8.
Carry = 18 / 10 = 1.
Add node with value 8 to the result list. dummyNode -> 8.
Move t1, t2, and curr to the next node.

- Second Iteration:

t1 points to 9, t2 points to 9.
Sum = 9 + 9 + 1 (carry) = 19.
New node value = 19 % 10 = 9.
Carry = 19 / 10 = 1.
Add node with value 9 to the result list. dummyNode -> 8 -> 9.
Move t1, t2, and curr to the next node.

- Third Iteration:

t1 points to 9, t2 points to 9.
Sum = 9 + 9 + 1 (carry) = 19.
New node value = 19 % 10 = 9.
Carry = 19 / 10 = 1.
Add node with value 9 to the result list. dummyNode -> 8 -> 9 -> 9.
Move t1, t2, and curr to the next node.

- Fourth Iteration:

t1 points to 9, t2 points to 9.
Sum = 9 + 9 + 1 (carry) = 19.
New node value = 19 % 10 = 9.
Carry = 19 / 10 = 1.
Add node with value 9 to the result list. dummyNode -> 8 -> 9 -> 9 -> 9.
Move t1, t2, and curr to the next node.

- Fifth to Seventh Iterations:

t1 points to 9, t2 is NULL (since list l2 has no more nodes).
Sum = 9 + 0 + 1 (carry) = 10.
New node value = 10 % 10 = 0.
Carry = 10 / 10 = 1.
Add node with value 0 to the result list in each iteration.
dummyNode -> 8 -> 9 -> 9 -> 9 -> 0 -> 0 -> 0.
Move t1 and curr to the next node. t2 remains NULL.

- After the Loop:

t1 and t2 are both NULL, but there is still a carry of 1.
Add a new node with value 1 to the result list. dummyNode -> 8 -> 9 -> 9 -> 9 -> 0 -> 0 -> 0 -> 1.

- Final Step:

Return Statement: return dummyNode->next;
The function returns the node immediately after dummyNode, which is the head of the resulting list.
The returned list represents the sum of the two input lists: [8,9,9,9,0,0,0,1].

This dry run shows how dummyNode->next points to the head of the final linked list containing the result of the addition. The dummy node itself is just a helper and is not part of the result.

---



