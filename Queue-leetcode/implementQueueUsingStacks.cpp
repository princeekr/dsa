class MyQueue {
public:

    stack<int> st;
    stack<int> helper;

    MyQueue() {
        
    }
    
    void push(int x) {
        st.push(x);
    }
    
    int pop() {
        //only leave the last ele
        while(st.size()>1){
            helper.push(st.top());
            st.pop();
        }

        int top = st.top();  //store the val to return it 
        st.pop();

        while(helper.size()>0){
            st.push(helper.top());
            helper.pop();
        }

        return top;
    }
    
    int peek() {
        while(st.size()>1){
            helper.push(st.top());
            st.pop();
        }

        int top = st.top();

        while(helper.size()>0){
            st.push(helper.top());
            helper.pop();
        }

        return top;
    }
    
    bool empty() {
        if(st.size() > 0) return false;
        else return true;
    }
};
