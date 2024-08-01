#include<iostream>
#include<queue>

class MyStack {
    std::queue<int> qt;
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

