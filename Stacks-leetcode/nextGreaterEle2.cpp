// 503. Next Greater Element II

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n);

        stack<int> st;
        // first push all array ele from last to first in stack : "only catch in this Q"
        for(int i=n-1;i>=0;i--) st.push(arr[i]);

        //same next greater ele finding
        for(int i=n-1;i>=0;i--){
            while(st.size()>0 && st.top() <= arr[i]) st.pop();       //pop
            if(st.size() > 0) ans[i] = st.top();                    //mark
            else ans[i] = -1;
            st.push(arr[i]);                                       //push
        }

        return ans;
    }
};