#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int enemy[3001][3];//(x,y,R)
int adj[3001][3001];
int visit[3001];
queue<int> q;
int N = 0;
void BFS(){
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int i = 1; i <= N ; i++){
            if(visit[i] == 0 && adj[x][i] == 1){
                visit[i] = 1;
                q.push(i);
            }
        }
    }
    return;
}
int main(){
    int T,x,y,R,sol;
    cin >> T;
    while(T--){
        fill_n(&enemy[1][0],3000*3,0);
        fill_n(&adj[1][0],3000*3000,0);
        fill_n(&visit[1],3000,0);
        sol = 0;
        cin >> N;
        //입력받고
        for(int i = 1 ; i <= N ; i++){
            cin >> enemy[i][0] >> enemy[i][1] >> enemy[i][2];
        }
        //인접행렬 구하고
        int xs,xd,ys,yd,R1,R2,D;
        for(int i = 1 ; i <= N ; i++){
            for(int j = i+1 ; j <= N ; j++){
                xs = enemy[i][0];
                xd = enemy[j][0];
                ys = enemy[i][1];
                yd = enemy[j][1];
                R1 = enemy[i][2];
                R2 = enemy[j][2];
                D = (xd-xs)*(xd-xs) + (yd-ys)*(yd-ys);
                if((R1+R2)*(R1+R2) >= D){
                    adj[i][j] = 1;
                    adj[j][i] = 1;
                }
            }
        }
        for(int i = 1; i <= N ; i++){
            if(visit[i] == 0){
                sol++;
                visit[i] = 1;
                q.push(i);
                BFS();
            }
        }
        cout << sol <<endl;
    }
    return 0;
}


