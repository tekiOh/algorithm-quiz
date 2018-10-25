//
// Created by vkdne on 2018-10-25.
//

#include <iostream>
#include <stack>
#include <string>
#include <sstream>
using namespace std;

string postFixStr;
stack<char> st;
stack<double> sol_st;
int priority(char c) {
    switch (c) {
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
    }
}
void makePostFix(string str) {
    stringstream sst(str);
    string k;
    while (sst >> k) {
        //여는 괄호는 그냥 넣고
        if (k[0] == '(') {
            st.push(k[0]);
        }
            //닫는 괄호는 여는 괄호 만날때까지 pop하며 후위표기식에 붙여줌
            //맨 마지막에 여는 괄호까지 pop
        else if (k[0] == ')') {
            while (!st.empty() && st.top() != '(') {
                postFixStr += ' ';
                postFixStr += st.top();
                st.pop();
            }
            st.pop();
        }
            //숫자는 그냥 더 함
        else if (k[0] >= '0' && k[0] <= '9'){
            postFixStr += ' ';
            postFixStr += k;
        }
            //괄호 외의 연산자
        else {
            //top의 우선순위가 더 높거나 같을 때 후위 표기법에 더해주고 pop
            //마지막에 스택에 연산자를 더함
            while (!st.empty() && priority(st.top()) >= priority(k[0])) {
                postFixStr += ' ';
                postFixStr += st.top();
                st.pop();
            }
            st.push(k[0]);
        }
    }
    //스택 전부를 후위 표기법에 더함
    while (!st.empty()) {
        postFixStr += ' ';
        postFixStr += st.top();
        st.pop();
    }
}
int main() {
    string str;
    getline(cin, str);
    makePostFix(str);
    cout << postFixStr << endl;

    stringstream ss(postFixStr);
    string k;
    int solution = 0;
    double first, second;
    //while (ss >> k) {
    //	cout << k << endl;
    //}
    while (ss >> k) {
        switch (k[0]) {
            case '+':
                first = sol_st.top();
                sol_st.pop();
                second = sol_st.top();
                sol_st.pop();
                sol_st.push(first + second);
                break;
            case '-':
                first = sol_st.top();
                sol_st.pop();
                second = sol_st.top();
                sol_st.pop();
                sol_st.push(second - first);
                break;
            case '*':
                first = sol_st.top();
                sol_st.pop();
                second = sol_st.top();
                sol_st.pop();
                sol_st.push(first * second);
                break;
            case '/':
                first = sol_st.top();
                sol_st.pop();
                second = sol_st.top();
                sol_st.pop();
                sol_st.push(second / first);
                break;
            default:
                sol_st.push(stod(k));
        }
    }
    cout << sol_st.top() << endl;
    //cout << sol << endl;
}