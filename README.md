# Stacks 
Stack is a data structure to store data and follows the property of LIFO (Last In First Out).

Following operations can be performed on the stack data structure:

-   push -> to insert -> s.push();
-   pop -> to delete -> s.pop();
-   top -> to view the topmost/last value in the stack -> s.top();

---

## Stack Implementation
Stack Implementation using class can be done in two ways:
- Array
- Linked List

## Stack Implementation Using Class

Basic flow of the stack using array

    class Stack {
     
    // properties
     
    public: 
    int *arr; 
    int top; 
    int size; 
    
    //behaviour - constructor
     
    Stack(int size) { 
    this -> size = size; 
    arr = new int[size]; 
    top = -1; 
    } 
    
    void push(int element){ 
    
    } 
    
    void pop(){
    
     } 
     
     int peek(){ 
     
     } 
     
     bool isEmpty(){ 
     
     } 
     };


## Question Links

- Implementing Two Stacks: https://www.naukri.com/code360/problems/two-stacks_983634

Code:

#include <bits/stdc++.h> 
class TwoStack {

    int *arr;
    int top1;
    int top2;
    int size;

public:

    // Initialize TwoStack.
    TwoStack(int s) {
        this->size = s;
        top1 = -1;
        top2 = s;
        arr = new int[s];
    }

    // Destructor to clean up allocated memory
    ~TwoStack() {
        delete[] arr;
    }
    
    // Push in stack 1.
    void push1(int num) {
        if (top2 - top1 > 1) {  // Corrected the condition
            top1++;
            arr[top1] = num;
        }
    }

    // Push in stack 2.
    void push2(int num) {
        if (top2 - top1 > 1) {  // Corrected the condition
            top2--;
            arr[top2] = num;
        }
    }
    
    // Pop from stack 1 and return popped element.
    int pop1() {
        if (top1 >= 0) {
            int ans = arr[top1];
            top1--;
            return ans;
        } else {
            return -1;
        }
    }

    // Pop from stack 2 and return popped element.
    int pop2() {
        if (top2 < size) {
            int ans = arr[top2];
            top2++;
            return ans;
        } else {
            return -1;
        }
    }
};






