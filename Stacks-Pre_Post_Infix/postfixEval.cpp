
#include<iostream>
#include<stack>
#include<cmath>
using namespace std;

// Idea : put numbers to stack, once u get any operations - pop first as b - top then a. After that just basic operation.  

int operations(int a, int b, string s){
    if(s == "+") return a+b;
    else if(s == "-") return a-b;
    else if(s == "*") return a*b;
    else if(s == "^") return pow(a,b);
    else return floor((double)a/b);
}

int postfix(string arr[], int n){
    stack<int> st;

    for(int i=0; i<n; i++){
        string s = arr[i];

        if(s == "+" || s == "-" || s == "*" || s == "/" || s == "^"){
            int b = st.top();
            st.pop();

            int a = st.top();
            st.pop();

            int ans = operations(a, b, s);
            st.push(ans);
        }
        else{
            st.push(stoi(s));
        }
    }
    return st.top();
}

int main(){
    string arr[] = {"2", "3", "1", "*", "+", "9", "-"};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Post eval : " << postfix(arr, n) << endl;
}
