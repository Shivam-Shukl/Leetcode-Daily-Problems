class MinStack {
public:
   
    stack<int> st;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
    }
    
    void pop() {
        if(!st.empty())
        st.pop();
    }
    
    int top() {
        if(!st.empty()){
            return st.top();
        }else{
            return -1;
        }
    }
    
    int getMin() {
        stack<int> temp;
        int mini = 0;
        while(!st.empty()){
            mini = min(mini,st.top());
            temp.push(st.top());
            st.pop();
        }
        while(!temp.empty()){
            st.push(temp.top());
            temp.pop();
        }
        return mini;
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