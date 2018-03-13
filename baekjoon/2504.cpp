//
// Created by vkdne on 2018-03-13.
//

#include <iostream>
#include <stack>
#include <string>
using namespace std;

string str;
stack<char> st;
int main(){
    cin >> str;

    int sol = 0;
    int mul = 1;
    for(int i = 0 ; i < str.length() ; i++){
        if(str[i] == '['){
            mul *= 3;
            st.push(str[i]);
        }
        else if(str[i] == '('){
            mul *= 2;
            st.push(str[i]);
        }
        else if(str[i] == ']'){
            if(str[i-1] == '['){
                sol += mul;
            }

            if(st.top() == '[')
                st.pop();

            mul /= 3;
        }
        else{
            if(str[i-1] == '('){
                sol += mul;
            }

            if(st.top() == '(')
                st.pop();

            mul /= 2;
        }
    }

    if(st.empty())
        cout << sol;
    else
        cout << '0';

    return 0;
}