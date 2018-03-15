//
// Created by vkdne on 2018-03-14.
//

#include <iostream>
#include <deque>
#include <string>
using namespace std;


int main(){
    deque<int> dq;
    int N;
    cin >> N;
    string str;
    int a;
    int tmp;
    while(N--){
        cin >> str;
        if(str == "push_back"){
            cin >> a;
            dq.push_back(a);
        }

        else if(str == "push_front"){
            cin >> a;
            dq.push_front(a);
        }

        else if(str == "pop_front") {
            if(dq.empty()){
                cout << "-1" <<endl;
                continue;
            }
            tmp = dq.front();
            dq.pop_front();
            cout << tmp << endl;
        }

        else if(str == "pop_back"){
            if(dq.empty()){
                cout << "-1" <<endl;
                continue;
            }
            tmp = dq.back();
            dq.pop_back();
            cout << tmp << endl;
        }

        else if(str == "size"){
            cout << dq.size() << endl;
        }

        else if(str == "empty"){
            if(dq.empty()){
                cout << "1" <<endl;
            }
            else{
                cout << "0" <<endl;
            }
        }

        else if(str == "front"){
            if(dq.empty()){
                cout << "-1" <<endl;
                continue;
            }
            cout << dq.front() << endl;

        }

        else if(str == "back"){
            if(dq.empty()){
                cout << "-1" <<endl;
                continue;
            }
            cout << dq.back() << endl;
        }
    }


    return 0;
}