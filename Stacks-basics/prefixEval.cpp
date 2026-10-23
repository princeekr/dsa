#include<iostream>
#include<stack>
#include<string>
#include<cmath>
using namespace std;

// same operations fxn
int  operations(int a, int b, string s){
    if(s == "+") return a+b;
    else if(s == "-") return a-b;
    else if(s == "*") return a*b;
    else if(s == "^") return pow(a, b);
    else return a/b;
}

//since it is prefix we use ulta loop, first we pop ele as a and then b. 
int prefix(string arr[], int n){
    stack<int> st;
    for(int i=n-1;i>=0;i--){
        if(arr[i] == "*" || arr[i] == "^" || arr[i] == "+" || arr[i] == "-" || arr[i] == "/"){
            int a = st.top(); st.pop();
            int b = st.top(); st.pop();
            int c = operations(a, b, arr[i]);
            st.push(c);
        }
        else st.push(stoi(arr[i]));
    }
    return st.top();
}

int main(){
    string arr[] = {"^", "+", "2", "3", "2"};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<"Prefix evaluation : "<<prefix(arr, n)<<endl; 
}