// 239. Sliding Window Maximum

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();

        //next greater ele index
        vector<int> nge(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(st.size() > 0 && nums[st.top()] <= nums[i]) st.pop();   //pop
            if(st.size()>0) nge[i] = st.top();  //mark
            else nge[i] = -1;
            st.push(i);  //push
        }

        // 1 3 -1 -3 5 3 6 7 
        // 1 4 4 4 6 6 7 -1 
        
        vector<int> ans(n-k+1);
        int j = 0;
        for(int i=0;i<n-k+1;i++){
            if(j<i) j = i;
            while(nge[j] != -1 && nge[j] < i+k) j = nge[j];
            ans[i] = nums[j];
        }
        return ans;
    }
};