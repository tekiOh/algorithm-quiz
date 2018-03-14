//
// Created by vkdne on 2018-03-13.
//

#include <iostream>
#include <queue>

using namespace std;

int main(){
    queue<int> q;
    int N,M;

    cin >> N >> M;
    for(int i = 1; i <= N ; i++){
        q.push(i);
    }
    int tmp;

    if(N == 1){
        cout<<"<"<<q.front()<<">";
        return 0;
    }

    while(!q.empty()){
        for(int i = 1 ; i < M ; i++){
            tmp = q.front();
            q.pop();
            q.push(tmp);
        }
        if(q.size() == N){
            cout << "<" << q.front() << ", ";
        }
        else if(q.size() == 1){
            cout << q.front() << ">";
        }
        else{
            cout <<q.front() << ", ";
        }
        q.pop();
    }
    return 0;
}