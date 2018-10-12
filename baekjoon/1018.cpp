//
// Created by vkdne on 2018-10-12.
//

#include<iostream>

using namespace std;
int N,M;
char map[50][50];
int sol = 2500;
void simulation(int y, int x){
    //처음이 B로 시작
    int cntB = 0;
    for(int i = y ; i < y+8 ; i++){
        for(int j = x ; j < x+8 ; j++){
            if((i+j)%2 == 0){
                if(map[i][j] != 'B'){
                    cntB++;
                }
            }
            else{
                if(map[i][j] == 'B'){
                    cntB++;
                }
            }
        }
    }
    if(cntB > 64-cntB)
        cntB = 64-cntB;
    //cout << cntB<<endl;
    if(sol > cntB)
        sol = cntB;
}
int main(){
    cin >> N >> M;
    for(int i = 0 ; i < N ; i++)
        for(int j = 0 ; j < M ; j++)
            cin >> map[i][j];

    int cntB = 0;
    for(int i = 0 ;i <= N-8 ; i++){
        for(int j = 0 ; j <= M-8 ; j++){
            //cout << i<<","<<j<<endl;
            simulation(i,j);
        }
    }
    cout << sol << endl;
    return 0;
}