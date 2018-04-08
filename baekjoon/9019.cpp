//
// Created by vkdne on 2018-04-08.
//
#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;
int input;
int output;

struct s{
    int v;
    string result = "";
    int cnt = 0;
};
queue<s> q;
s tmp;
int visit[10001];
void bfs(){
    int t,v1,v2,v3,v4;
    int n,time;
    string sol = "";
    s front;
    front.v = input;
    front.cnt = 0;
    visit[input] = 1;
    q.push(front);
    while(!q.empty()){
        front = q.front();
        time = front.cnt;
        n = front.v;
        sol = front.result;
        if(front.v == output){
            cout << front.result << "\n";
            return;
        }
        q.pop();
        t = n;
        v1 = t/1000;
        t %= 1000;
        v2 = t/100;
        t %= 100;
        v3 = t/10;
        t %= 10;
        v4 = t;
        //D
        int aNum = (2*n)%10000;
        if(!visit[aNum]) {
            tmp.v = aNum;
            tmp.result = sol + "D";
            tmp.cnt = time + 1;
            visit[tmp.v] = 1;
            q.push(tmp);
        }
        //S
        aNum = n - 1;
        if(aNum == -1)
            tmp.v = 9999;
        else
            tmp.v = aNum;
        if(!visit[aNum]) {
            tmp.cnt = time + 1;
            tmp.result = sol + "S";
            visit[tmp.v] = 1;
            q.push(tmp);
        }
        //R
        if(!visit[1000*v4 + 100*v1 + 10*v2 + v3]) {
            tmp.v = 1000 * v4 + 100 * v1 + 10 * v2 + v3;
            tmp.result = sol + "R";
            tmp.cnt = time + 1;
            visit[tmp.v] = 1;
            q.push(tmp);
        }
        //L
        if(!visit[1000*v2 + 100*v3 + 10*v4 + v1]) {
            tmp.v = 1000 * v2 + 100 * v3 + 10 * v4 + v1;
            tmp.result = sol + "L";
            tmp.cnt = time + 1;
            visit[tmp.v] = 1;
            q.push(tmp);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while(T--){
        cin >> input >> output;
        bfs();
        while(!q.empty())
            q.pop();
        fill_n(visit,10001,0);
    }
    return 0;
}