//
// Created by vkdne on 2018-04-11.
//

#include <iostream>
using namespace std;

int food[17][17];
int team1[9];
int team2[9];
int N;
int sol = 99999999;
int visit[17];
void calc(){
    for(int i = 1; i <= N/2 ; i++){
        visit[team1[i]] = 1;
    }
    for(int i = 1,j = 1; i <= N ; i++){
        if(visit[i] == 0){
            team2[j] = i;
            j++;
        }
    }

    int s1 = 0;
    int s2 = 0;
    int diff = 0;
    for(int i = 1 ; i < N/2 ; i++){
        for(int j = i+1 ; j <= N/2 ; j++){
            s1 += food[team1[i]][team1[j]];
            s1 += food[team1[j]][team1[i]];
            s2 += food[team2[i]][team2[j]];
            s2 += food[team2[j]][team2[i]];
        }
    }
    if(s1 > s2)
        diff = s1 - s2;
    else
        diff = s2 - s1;
    if(sol > diff)
        sol = diff;

    fill_n(visit,17,0);
}
void dfs(int max, int cnt){
    //조합이 완성되면 시너지 계산
    if(cnt == N/2){
        calc();
        return;
    }
    for(int i = max + 1 ; i <= N/2 + cnt +1 ; i++) {
        team1[cnt+1] = i;
        dfs(i,cnt+1);
    }

}
int main(){
    int T;
    cin >> T;
    int c = 1;
    while(T--){
        cin >> N;
        //시너지 입력
        for(int i = 1; i <= N ; i++){
            for(int j = 1; j <= N ; j++)
                cin >> food[i][j];
        }

        for(int i = 1; i <= N/2+1 ; i++){
            team1[1] = i;
            dfs(i,1);
        }
        cout <<"#"<<c <<" "<< sol << endl;
        sol = 999999999;
        c++;
    }
}