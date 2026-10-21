#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int main(){
    int arr[] = {2,1,3,8,7,1,2,3,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> ans(n, -1);

    stack<int> st;
    for(int i=0;i<n;i++){
        while(st.size() > 0 && arr[i] >= arr[st.top()]) st.pop();
        if(st.size() > 0) ans[i] = st.top();
        st.push(i);
    }

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
}