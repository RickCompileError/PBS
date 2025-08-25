class MinStack {
private:
    stack<int> mn;
    stack<int> data;

public:
    MinStack() {
    }
    
    void push(int val) {
        if (mn.empty() || mn.top() >= val) mn.push(val);
        data.push(val);
    }
    
    void pop() {
        if (mn.top() == data.top()) mn.pop();
        data.pop();
    }
    
    int top() {
        return data.top();
    }
    
    int getMin() {
        return mn.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */