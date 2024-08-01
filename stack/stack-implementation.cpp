#include<iostream>
#include<stack>

using namespace std;


class Stack {

    // properties
    public:

    int *arr;
    int top;
    int size;

    //behaviour

    Stack(int size) {
        this -> size = size;
        arr = new int[size];
        top = -1;
    }


    void push(int element){
        if(size - top > 1){ /// to check whether the stack has empty space or not
           top++;
           arr[top] = element;
        }

        else {
            cout<<"Stack Overflow";
        }

    }

    void pop(){
        if(top >= 0){
            top--;
        }

        else {
            cout<<"Stack Underflow";
        }
    }


    int peek(){

    if(top >= 0){
     return arr[top];
    }

    else {
        cout<<"Stack is empty";
        return -1;
    }
    } 

    bool isEmpty(){
        if(top == -1){
            return true;
        }

        else {
            return false;
        }



    }

};


   int  main(){
        Stack st(4);

        st.push(43);
        st.push(44);
        st.push(45);
        st.push(46);


        cout<<st.peek()<<endl;

    }



