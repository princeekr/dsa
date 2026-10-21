#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int main(){
    int arr[] = {1,3,-1,-3,5,3,6,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> ans(n, -1);

    stack<int> st;
    for(int i=n-1;i>=0;i--){
        while(st.size() > 0 && arr[i] >= st.top()) st.pop();
        if(st.size() > 0) ans[i] = st.top();
        st.push(arr[i]);
    }

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
}