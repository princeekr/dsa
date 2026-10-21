// 155. Min Stack

class MinStack {
    //make 2 stacks
    stack<int> st;
    stack<int> minSt;
public:
    MinStack(){}
    
    void push(int val) {
        //push to min stack only if the incoming val is less or equal to the min stack top, if val > minSt top then push top val only
        st.push(val);
        if(minSt.size() == 0 || val <= minSt.top()) minSt.push(val);
        else minSt.push(minSt.top());
    }
    
    void pop() {
        //pop from both
        st.pop();
        minSt.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};
