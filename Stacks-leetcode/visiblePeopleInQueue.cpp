// 1944. Number of Visible People in a Queue

class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, 0);
        stack<int> st;

        for(int i=n-1; i>=0; i--){
            while(st.size() > 0 && arr[i] >= st.top()){  //pop
                st.pop();
                ans[i]++;
            }

            if(st.size() != 0){ //mark
                ans[i]++;
            }

            st.push(arr[i]); //push
        }
        return ans;
    }
};