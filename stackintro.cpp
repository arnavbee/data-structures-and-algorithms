#include<iostream>
#include<stack>
using namespace std;

int main() {
    // creation of stack
    stack<int> s;

    s.push(2);
      s.pop();
    s.push(3);

  

    cout<<s.top()<<endl;

    s.pop();

    if(s.empty()){
        cout<<"Stack is empty"<<endl;
    }

    else {
        cout<<"Stack is not empty"<<endl;
    }

    return 0;
}