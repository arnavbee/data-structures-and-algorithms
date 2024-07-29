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

### Implementing Two Stacks: https://www.naukri.com/code360/problems/two-stacks_983634

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


## Implementing Queue using Two Stacks 

Create two stacks s1 and s2.

Code follows the basic flow of three steps:

- s1 -> s2
- x -> s1
- s2 -> s1

### Time Complexity - O(n)

class MyQueue {
public:
     stack<int> s1, s2;
    
    void push(int x) {

        while(s1.size()){
            s2.push(s1.top());
            s1.pop();
        }

        s1.push(x);

        while(s2.size()){
            s1.push(s2.top());
            s2.pop();
        }
        
    }
    
    int pop() {

    int popp = s1.top();
    s1.pop();
    return popp;
    
        
    }
    
    int peek() {
    int popp = s1.top();
    return popp;
    
        
    }
    
    bool empty() {
    if(s1.empty() && s2.empty()){
        return true;
    }

    else return false;
        
    }
};


### Time Complexity - O(1)

class MyQueue {
public:
    stack<int> s1, s2;

    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int top = s2.top();
        s2.pop();
        return top;
    }
    
    int peek() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
};








