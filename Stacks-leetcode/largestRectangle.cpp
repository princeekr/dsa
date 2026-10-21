// 84. Largest Rectangle in Histogram

class Solution {
public:

    // idea if for every building we find psi and nsi, these 2 because we want to see how much area we can get before we fall down by next building or previous building. 
    //nsi - next smaller ele index, psi- previous smaller ele index

    int largestRectangleArea(vector<int>& arr) {
        int n = arr.size();
        vector<int> psi(n);
        vector<int> nsi(n);

        //psi
        stack<int> st;
        for(int i=0;i<n;i++){
            while(st.size() > 0 && arr[st.top()] >= arr[i]) st.pop();
            if(st.size() > 0) psi[i] = st.top();
            else psi[i] = -1;
            st.push(i);
        }

        while(st.size()>0) st.pop(); //empty the curr stack for next use

        //nsi
        for(int i=n-1;i>=0;i--){
            while(st.size() > 0 && arr[st.top()] >= arr[i]) st.pop();
            if(st.size() > 0) nsi[i] = st.top();
            else nsi[i] = n; //for calculations we take n instead of -1
            st.push(i);
        }

        int maxArea = INT_MIN;
        for(int i=0;i<n;i++){
            int w = nsi[i] - psi[i] - 1; //-1 bcz we need width where we dont want to consider border indices, we need btw area
            int h = arr[i];
            int ans = w*h;
            maxArea = max(ans, maxArea);
        }
        return maxArea;
    }
};