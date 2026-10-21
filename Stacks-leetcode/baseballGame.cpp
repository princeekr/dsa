// 682. Baseball Game

class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> st;
        for(string str : ops){
            if(str == "+"){
                int n;
                int p1 = st.top(); st.pop();
                int p2 = st.top(); st.pop();
                st.push(p2); st.push(p1);
                n = p1+p2;
                st.push(n);
            }
            else if(str == "C"){
                st.pop();
            }
            else if(str == "D"){
                int n = st.top();
                st.push(2*n);
            }
            else{
                st.push(stoi(str));
            }
        }
        int ans = 0;
        while(st.size()>0){
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};