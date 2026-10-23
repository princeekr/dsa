#include<iostream>
#include<stack>
#include<string>
using namespace std;

//logic is : if numbers then push else pop as first b and then a, finally merge them as : "["("  + a + string(1, ch) + b + ")""]" then push to stack

string infix(string s){
    stack<string> st;
    for(char ch : s){
        if(ch == '*' || ch == '+' || ch == '/' || ch == '-'){
            string b = st.top(); st.pop();
            string a = st.top(); st.pop();
            string c = "("  + a + string(1, ch) + b + ")";
            st.push(c);
        }
        else{
            st.push(string(1, ch));    //converting char to string : use string(1, ch)
        }
    }
    return st.top();
}

int main(){
    string s = "ab+ef/*";
    cout<<"Infix : "<<infix(s)<<endl;
}