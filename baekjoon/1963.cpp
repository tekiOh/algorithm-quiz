//
// Created by vkdne on 2018-04-06.
//

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
int arr[1061][1061];
int visit[1061];
vector <int> v;
int sol;
struct xx{
    int v,d;
};
queue<xx>q;

void makeGraph(){
    bool chk;
    for(int i = 1000 ; i < 10000 ; i++){
        chk = true;
        for(int k = 2 ; k < i ; k++){
            if(i % k == 0){
                chk = false;
                break;
            }
        }
        if(chk) {
            v.push_back(i);
        }
    }
    int a;
    int b,c;
    for(int i = 0 ; i < 1061 ; i++){
        for(int j = i+1 ; j < 1061 ; j++){
            a = 0;
            b = v[i];
            c = v[j];
            if(b / 1000 == c / 1000)
                a++;
            b %=1000;
            c %=1000;
            if(b / 100 == c / 100)
                a++;
            b %=100;
            c %=100;
            if(b / 10 == c / 10)
                a++;
            b %=10;
            c %=10;
            if(b == c)
                a++;
            if(a == 3){
                arr[i][j] = 1;
                arr[j][i] = 1;
            }
        }
    }
}

void bfs(int target){
    while(!q.empty()){
        xx tmp = q.front();
        q.pop();
        for(int i = 0 ; i < 1061 ; i++){
            if(arr[tmp.v][i] == 1 && visit[i] == 0){
                if(i ==target){
                    sol = tmp.d + 1;
                    return;
                }
                visit[i] = 1;
                q.push({i,tmp.d+1});
            }
        }
    }
    sol = -1;
    return;
}
int main(){
    makeGraph();
    int T;
    cin >> T;
    int n1,n2;
    while(T--){
        int v1,v2;
        cin >> n1 >> n2;
        if(n1 == n2 ){
            cout << 0 << endl;
            continue;
        }
        for(int i = 0 ; i < 1061 ; i++){
            if(v[i] == n1)
                v1 = i;
            if(v[i] == n2)
                v2 = i;
        }
        visit[v1] = 1;
        q.push({v1,0});
        bfs(v2);
        if(sol == -1){
            cout <<"Impossible"<<endl;
        }
        else
            cout << sol << endl;
        fill_n(visit,1061,0);
        while(!q.empty())
            q.pop();
    }
    return 0;
}