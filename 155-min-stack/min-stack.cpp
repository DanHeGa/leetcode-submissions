class MinStack {
public:
    stack<int> mainStk;
    stack<int> minStk;
    MinStack() {
        minStk.push(INT_MAX); //Handles edge case where stk is empty and we have to compare with initial value
    }
    
    void push(int value) {
        mainStk.push(value);
        minStk.push(min(value, minStk.top()));
    }
    
    void pop() {
        //pop from both stks to keep sincronization
        mainStk.pop();
        minStk.pop();
    }
    
    int top() {
        return mainStk.top();
    }
    
    int getMin() {
        return minStk.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */