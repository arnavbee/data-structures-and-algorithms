# Queue

Queue is the type of data structure used to store data in the form of FIFO(First In First Out)

It has the same operations as stacks but the first element gets picked out first in the pop operation.

## Implementation Of Queue using Array

class Queue {
    public:
    int size;
    int *arr;
    int start;
    int end;

    int currSize;

    Queue(int s){
    this -> size = s;
    arr = new int[size];
    start = -1;
    end = -1;
    currSize = 0;
    }


    void push(int element){

        if(currSize == size) {
            cout<<"Stack Overflow"<<endl;
        }

    if(currSize == 0){
     start = 0;
      end = 0;
    }

    else {
        end = (end + 1) % size; // handling the circular nature of the push operation
    }

    arr[end] = element;
    currSize++;
    }

    void pop(){
    if(currSize == 0){
        cout<<"Stack Underflow"<<endl;
    }

    if(currSize == 1){
        start = -1;
        end = -1;
    }

    else {
    start = (start + 1) % size;

    }

     currSize--;
        

    }

    void top(){

    if(currSize == 0){
        cout<<"Stack is empty"<<endl;
    }
        cout<< arr[start]<<endl;
    }


};


int main(){

  Queue qt(5);

  qt.push(4);
  qt.push(5);
  qt.push(6);
  qt.push(7);

  qt.top(); // answer is 4

}



## Implement Stack using Queues

#include<iostream>
#include<queue>

class MyStack {
    queue<int> qt;
public:




    
    void push(int x) {
    
        int s = qt.size();

     
    qt.push(x);

    for(int i = 0; i < s; ++i){
        qt.push(qt.front());
        qt.pop();

    }


    
        
    }
    
    int pop() {

        if (qt.empty()) {
            return -1; 
        }

    int topElement = qt.front();
    qt.pop();

    return topElement;

        
    }
    
    int top() {

      if (qt.empty()) {
         
            return -1; 
        }

    int topElement =qt.front();
    return topElement;
        
    }
    
    bool empty() {
   return qt.empty();
    }
        
};