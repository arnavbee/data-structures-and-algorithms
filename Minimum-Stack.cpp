#include <stack>
#include <limits>

class MinStack {
public:
    std::stack<int> st;
    std::stack<int> minStack;

    MinStack() {
    }
    
    void push(int val) {
        st.push(val);

        if (minStack.empty() || val <= minStack.top()) {
            minStack.push(val);
        }
    }
    
    void pop() {
        if (st.empty()) return;

        int topElem = st.top();
        st.pop();

        if (topElem == minStack.top()) {
            minStack.pop();
        }
    }
    
    int top() {
        if (st.empty()) return -1; 
        return st.top();
    }
    
    int getMin() {
        if (minStack.empty()) return -1; 
        return minStack.top();
    }
};
