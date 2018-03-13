//
// Created by vkdne on 2018-03-13.
//

#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main(){
    queue<int> q;
    string s;

    int N;
    cin >> N;

    int a;
    while(N--){
        cin >> s;

        if(s == "push"){
            cin >> a;
            q.push(a);
            continue;
        }

        if(s == "pop"){
            if(q.empty())
                cout <<"-1";
            else {
                cout << q.front();
                q.pop();
            }
        }

        if(s == "size"){
            cout << q.size();
        }

        if(s == "empty"){
            cout << q.empty() ? "1" : "0";
        }

        if(s == "front"){
            if(q.empty())
                cout << "-1";
            else
                cout <<q.front();
        }

        if(s == "back"){
            if(q.empty())
                cout <<"-1";
            else
                cout << q.back();
        }
        cout << endl;
    }
    return 0;
}