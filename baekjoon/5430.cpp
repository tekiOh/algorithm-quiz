//
// Created by vkdne on 2018-03-14.
//

#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main() {
    int T;
    cin >> T;

    string c;
    int n;
    char a;
    int input;
    while (T--) {
        deque<int> dq;
        cin >> c;
        cin >> n;
        if (n == 0) {
            cin >> a;
            cin >> a;
        }
        else if (n == 1) {
            cin >> a;
            cin >> input;
            cin >> a;
            dq.push_back(input);
        }
        else {
            char ba;
            cin >> ba;
            cin >> input;
            dq.push_back(input);
            for (int i = 1; i < n; i++) {
                cin >> a;
                cin >> input;
                dq.push_back(input);
            }
            char ab;
            cin >> ab;
        }
        bool front = true;
        bool error = false;
        for (int i = 0; i < c.length(); i++) {
            if (c[i] == 'R'){
                front = !front;
            }
            else {
                if (dq.empty()) {
                    cout << "error" << endl;
                    error = true;
                    break;
                } else {
                    if (front)
                        dq.pop_front();
                    else
                        dq.pop_back();
                }
            }
        }
        if(error) {
            continue;
        }
        if(dq.size() == 0){
            cout<<"[]"<<endl;
        }
        else if(dq.size() == 1){
            cout<<"["<<dq.front()<<"]"<<endl;
        }

        else{
            if(front){
                for(auto it = dq.begin() ; it != dq.end() ; it++){
                    if(it == dq.begin()) {
                        cout << "[" << *it;
                    }
                    else
                        cout <<","<<*it;
                }
                cout <<"]"<<endl;
            }
            else{

                for(auto it = dq.rbegin(); it != dq.rend() ; it++){
                    if(it == dq.rbegin()) {
                        cout << "[" << *it;
                    }
                    else
                        cout <<","<<*it;
                }
                cout <<"]"<<endl;
            }
        }
    }
    return 0;
}