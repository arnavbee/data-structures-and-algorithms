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

 





