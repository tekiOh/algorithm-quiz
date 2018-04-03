//
// Created by vkdne on 2018-04-03.
//
#include <iostream>
#include <algorithm>
using namespace std;

int arr[507][507];
int N,M;
int sol;
int t[19];
void find(int y,int x){
    t[1] = arr[y][x] + arr[y][x+1] + arr[y][x+2] + arr[y][x+3];
    t[2] = arr[y][x] + arr[y+1][x] + arr[y+2][x] + arr[y+3][x];
    //
    t[3] = arr[y][x] + arr[y][x+1] + arr[y+1][x] + arr[y+1][x+1];
    //
    t[4] = arr[y][x] + arr[y+1][x] +arr[y+2][x] +arr[y+2][x+1];
    t[5] = arr[y][x] + arr[y+1][x] +arr[y+2][x] +arr[y+2][x-1];
    t[6] = arr[y][x] + arr[y+1][x] +arr[y+2][x] +arr[y][x+1];
    t[7] = arr[y][x] + arr[y][x+1] +arr[y+1][x+1] +arr[y+2][x+1];
    //
    t[8] = arr[y][x] + arr[y+1][x] +arr[y+1][x+1] +arr[y+1][x+2];
    t[9] = arr[y][x] + arr[y][x+1] +arr[y][x+2] +arr[y+1][x];
    t[10] = arr[y][x] + arr[y][x+1] +arr[y][x+2] +arr[y+1][x+2];
    t[11] = arr[y][x] + arr[y][x+1] +arr[y][x+2] +arr[y-1][x+2];
    //ㅗ,ㅜ
    t[12] = arr[y][x] + arr[y][x+1] +arr[y][x+2] +arr[y+1][x+1];
    t[13] = arr[y][x] + arr[y][x+1] +arr[y][x+2] +arr[y-1][x+1];
    //ㅓ,ㅏ
    t[14] = arr[y][x] + arr[y+1][x] +arr[y+2][x] +arr[y+1][x+1];
    t[15] = arr[y][x] + arr[y+1][x] +arr[y+2][x] +arr[y+1][x-1];
    //
    t[16] = arr[y][x] + arr[y+1][x] +arr[y+1][x+1] +arr[y+2][x+1];
    t[0] = arr[y][x] + arr[y+1][x] +arr[y][x+1] +arr[y-1][x+1];
    //
    t[17] = arr[y][x] + arr[y][x+1] + arr[y+1][x+1] + arr[y+1][x+2];
    t[18] = arr[y][x] + arr[y][x+1] + arr[y-1][x+1] + arr[y-1][x+2];
    sort(t,t+19);
    if(sol < t[18])
        sol = t[18];
}

int main(){
    cin >> N >> M;

    for(int i = 2; i <= N+1; i++)
        for(int j = 2; j <= M+1 ; j++)
            cin >> arr[i][j];

    for(int i = 2; i <= N+1; i++)
        for(int j = 2; j <= M+1 ; j++)
            find(i,j);

    cout << sol << endl;
    return 0;
}