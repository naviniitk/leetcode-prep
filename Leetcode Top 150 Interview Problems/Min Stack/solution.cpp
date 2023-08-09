class MinStack {
public:
    MinStack() {
        
    }
    vector<int> minVals;
    vector<int> arr;
    
    void push(int val) {
        if(minVals.size() == 0)
            minVals.push_back(val);
        else
            minVals.push_back(min(val, minVals[minVals.size() - 1]));
        arr.push_back(val);
    }
    
    void pop() {
        arr.pop_back();
        minVals.pop_back();
    }
    
    int top() {
        return arr[arr.size() - 1];
    }
    
    int getMin() {
        return minVals[minVals.size() - 1];
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
