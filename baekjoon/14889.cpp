//
// Created by vkdne on 2018-04-05.
//

#include <iostream>
#include <vector>
using namespace std;

int N;
int p[21][21];
int team1[11];
int sol = 99999999;
int calcSin(){
    vector<int> team2;
    int visit[21];
    for(int i = 1; i <= N ; i++)
        visit[i] = 0;
    for(int i = 1; i <=N/2 ; i++)
        visit[team1[i]] = 1;
    //team2생성
    for(int i = 1; i <= N ; i++){
        if(visit[i] == 0)
            team2.push_back(i);
    }
    //team1 시너지 계산
    int t1 = 0;
    int t2 = 0;
    for(int i = 1; i <= N/2 ; i++){
        for(int j = 1 ; j <= N/2 ; j++){
            if(i != j)
                t1 += p[team1[i]][team1[j]];
        }
    }

    for(int i = 0; i < N/2 ; i++){
        for(int j = 0 ; j < N/2 ; j++){
            if(i != j)
                t2 += p[team2[i]][team2[j]];
        }
    }
    int diff;
    if(t1 > t2)
        diff = t1 - t2;
    else
        diff = t2 - t1;

    return diff;
}
void makeTeam(int max, int depth){
    //team 완성되었을 때
    if(depth == N/2){
        int min = calcSin();
            if(sol > min)
                sol = min;
        return;
    }

    for(int i = max + 1 ; i <= N/2 + depth  +1 ; i++){
        team1[depth + 1] = i;
        makeTeam(i,depth+1);
    }
}


int main(){
    cin >> N;
    for(int i = 1; i <= N ; i++)
        for(int j = 1; j <= N ; j++)
            cin >> p[i][j];

    //dfs로 팀을 만듬
    for(int i = 1; i <= (N/2 + 1) ; i++){
        team1[1] = i;
        makeTeam(i,1);
    }

    cout << sol << endl;
    return 0;
}