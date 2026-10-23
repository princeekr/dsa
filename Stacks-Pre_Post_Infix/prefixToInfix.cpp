#include<iostream>
#include<stack>
#include<string>
using namespace std;

//logic is : if numbers then push else pop as first b and then a, finally merge them as : "["("  + a + string(1, ch) + b + ")""]" then push to stack

string infix(string s){
    stack<string> st;
    int n = s.length();
    for(int i=n-1;i>=0;i--){   //ultra loop
        if(s[i] == '*' || s[i] == '+' || s[i] == '/' || s[i] == '-'){
            string a = st.top(); st.pop();  //since it is prefix to infix we first take a and then b
            string b = st.top(); st.pop();
            string c = "("  + a + string(1, s[i]) + b + ")";
            st.push(c);
        }
        else{
            st.push(string(1, s[i]));    //converting char to string : use string(1, ch)
        }
    }
    return st.top();
}

int main(){
    string s = "*-A/BC-/AKL";
    cout<<"Infix : "<<infix(s)<<endl;
}