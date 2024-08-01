#include<iostream>

using namespace std;


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

    int sizeOf() {
        return size;
    }


};


int main(){

  Queue qt(7);

  qt.push(4);
  qt.push(5);
  qt.push(6);
  qt.push(7);

  qt.top();

  cout<<qt.sizeOf()<<endl;

}


