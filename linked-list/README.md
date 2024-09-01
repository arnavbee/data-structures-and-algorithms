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

## 2. Flattening a List



---

## 3. Rotate a List

Initial Setup:

Input Linked List: 1 -> 2 -> 3 -> 4 -> 5
k: 2

Step-by-Step Execution:

Calculate the Length of the List:

Start with len = 1 and tail = head (initially pointing to 1).
Traverse through the list to find the tail and calculate the length.
Move tail to 2, len = 2.
Move tail to 3, len = 3.
Move tail to 4, len = 4.
Move tail to 5, len = 5.
Now, tail is pointing to 5 and len = 5.

Adjust k:

k = k % len = 2 % 5 = 2.
Since k is not 0, proceed with the rotation.
Make the List Circular:

Connect the tail (node 5) to the head (node 1), making the list circular:
The list now looks like: 1 -> 2 -> 3 -> 4 -> 5 -> 1 -> ... (circular).
Find the New Tail:

We need to find the (len - k)th node, which is the 3rd node (5 - 2 = 3).
Call findNthNode(head, 3):
Start from head (node 1) and traverse:
Move to node 2 (cnt = 2).
Move to node 3 (cnt = 3).
Return node 3 as the new tail (newLastNode).
Set the New Head and Break the Circular Link:

The new head will be the node after newLastNode (3), which is node 4.
Break the circular link by setting newLastNode->next = NULL:
Node 3's next pointer (previously pointing to 4) is set to NULL.

The rotated list becomes 4 -> 5 -> 1 -> 2 -> 3.
Final Output:
Rotated List: 4 -> 5 -> 1 -> 2 -> 3.

---

## 4. Clone List with Random Pointer

The line copyNode->random = temp->random->next; is used because the copyNode is supposed to point to the copied version of the node that temp->random points to, not to the original node itself.

Original Setup:

Let's assume temp is currently pointing to an original node.
temp->random points to some other original node in the list.

After Insertion of Copies:

Every original node is followed by its corresponding copy. 

Original List: 1 -> 2 -> 3 -> NULL
After inserting copies: 1 -> 1' -> 2 -> 2' -> 3 -> 3' -> NULL
Now, temp->random->next is the copied version of the node that temp->random points to.


