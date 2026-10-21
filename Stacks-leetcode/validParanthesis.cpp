// 20. Valid Parentheses

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char ch : s){
            if(ch == '(' || ch == '[' || ch == '{') st.push(ch);       //if any open brac just push initially

            //if stack empty and incoming char is closing brac then false
            else if(st.size() == 0 && (ch == ')' || ch == '}' || ch == ']')) return false;

            //if found any pair then pop
            else if(st.top() == '(' && ch == ')') st.pop();
            else if(st.top() == '[' && ch == ']') st.pop();
            else if(st.top() == '{' && ch == '}') st.pop();
            
            //this mean no matching pair with stack top so for eg st.top == '(' but ch == '}' so in this case we return false
            else return false;
        }

        if(st.size() > 0) return false;
        return true;
        
    }
};