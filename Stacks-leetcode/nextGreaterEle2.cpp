// 503. Next Greater Element II

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, -1);

        stack<int> st; //put all arr ele in stack 
        for(int i=n-1;i>=0;i--) st.push(arr[i]);

        for(int i=n-1;i>=0;i--){
            while(st.size() > 0 && arr[i] >= st.top()) st.pop(); //pop
            if(st.size()>0) ans[i] = st.top(); //mark
            st.push(arr[i]); //push
        }
        return ans;
    }
};