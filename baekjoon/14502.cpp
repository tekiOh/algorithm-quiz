//
// Created by vkdne on 2018-02-05.
//
#include <iostream>
using namespace std;

int map[10][10];  //지도 : 0 빈칸 1 벽 2 바이러스
int N,M;        //세로,가로
int arr[64][2]; //빈칸의 위치를 저장
int cnt = 0;    //빈칸의 갯수
int sol = 0;    //답

void recursion(int i,int j){
    if(i > 1 && map[i-1][j] == 0){
        map[i-1][j] = 3;
        recursion(i-1,j);
    }
    if(i < N && map[i+1][j] == 0){
        map[i+1][j] = 3;
        recursion(i+1,j);
    }
    if(j>1 && map[i][j-1] == 0){
        map[i][j-1] = 3;
        recursion(i,j-1);
    }
    if(j<M && map[i][j+1] == 0){
        map[i][j+1] = 3;
        recursion(i,j+1);
    }
};

void countVirus(){
    for(int i = 1 ; i <= N ; i++) {
        for (int j = 1; j <= M; j++) {
            if(map[i][j] == 2)
                recursion(i,j);
        }
    }
    /*cout << "print new map"<<endl;
    for(int i = 1 ; i <= N ; i++){
        for (int j = 1; j <= M; j++){
            cout<<map[i][j] << " ";
        }
        cout << endl;
    }*/

    int temp = 0;
    for(int i = 1 ; i <= N ; i++){
        for (int j = 1; j <= M; j++){
            if(map[i][j] == 0)
                temp++;
            if(map[i][j] == 3)
                map[i][j] = 0;
        }
    }

    if(sol < temp)
        sol = temp;
};

int main(){

    cin >> N >> M;

    for(int i = 1; i <= N ; i++ ){
        for( int j = 1; j <= M ; j++) {
            cin >> map[i][j];
            if (map[i][j] == 0) {
                arr[cnt][0] = i;
                arr[cnt][1] = j;
                cnt++;
            }
        }
    }

    for(int i = 0; i < cnt - 2 ; i++ ){
        for(int j = i+1 ; j < cnt - 1 ; j++){
            for(int k = j+1 ; k < cnt ; k++){
                map[arr[i][0]][arr[i][1]] = 1;
                map[arr[j][0]][arr[j][1]] = 1;
                map[arr[k][0]][arr[k][1]] = 1;
                countVirus();
                map[arr[i][0]][arr[i][1]] = 0;
                map[arr[j][0]][arr[j][1]] = 0;
                map[arr[k][0]][arr[k][1]] = 0;
            }
        }
    }
    cout << sol << endl;
    return 0;
}