//
// Created by vkdne on 2018-04-05.
//

#include <iostream>
using namespace std;
int N,L;
int map[101][101];
int visitH[101][101];
int visitV[101][101];
int main(){
    cin >> N >> L;
    for(int i = 1 ; i <= N ; i++)
        for(int j = 1; j <= N ; j++)
            cin >> map[i][j];

    int sol = 0;
    //가로 검사
    for(int i = 1; i <= N ; i++){
        bool chk = true;
        for(int j = 1; j < N && chk ; j++){
            //같으면 다음거 검사
            if(map[i][j] == map[i][j+1])
                continue;
            //다르면 검사
            else{
                //j+1가 j보다 크고 차이가 1
                //경사로를 i+1보다 작은 곳으로
                if(map[i][j+1] - map[i][j] == 1){
                    //경사로 길이 감당가능하면
                    if(j - L +1 > 0){
                        for(int k = j - L + 1 ; k <= j ; k++){
                            //낮은쪽 높이가 다르면 fail
                            if(map[i][k] != map[i][j] || visitH[i][k] != 0){
                                chk = false;
                                break;
                            }
                        }
                        for(int k = j - L + 1 ; k <= j ; k++)
                            visitH[i][k] =1;
                    }
                    else{
                        chk = false;
                        break;
                    }
                }
                //j가 j+1보다 크고 차이가 1
                //경사로를 i+1보다 큰 곳으로
                else if(map[i][j+1] - map[i][j] == -1){
                    //경사로 길이 감당가능하면
                    if(j + L <= N){
                        for(int k = j+1 ; k <= j + L ; k++){
                            //낮은쪽 높이가 다르면 fail
                            if(map[i][j+1] != map[i][k] || visitH[i][k] != 0){
                                chk = false;
                                break;
                            }
                        }
                        for(int k = j+1 ; k <= j + L ; k++)
                            visitH[i][k] = 1;
                    }
                    else{
                        chk = false;
                        break;
                    }
                }
                //높이차가 1보다 크면 fail 길이 아님!
                else{
                    chk = false;
                    break;
                }
            }
        }
        if(chk)
            sol++;
    }

    //세로 검사
    for(int i = 1; i <= N ; i++){
        bool chk = true;
        for(int j = 1; j < N && chk ; j++){
            //같으면 다음거 검사
            if(map[j][i] == map[j+1][i])
                continue;
                //다르면 검사
            else{
                //j+1가 j보다 크고 차이가 1
                //경사로를 i+1보다 작은 곳으로
                if(map[j+1][i] - map[j][i] == 1){
                    //경사로 길이 감당가능하면
                    if(j - L +1 > 0){
                        for(int k = j - L + 1 ; k <= j ; k++){
                            //낮은쪽 높이가 다르면 fail
                            if(map[k][i] != map[j][i] || visitV[k][i] != 0){
                                chk = false;
                                break;
                            }
                        }
                        for(int k = j - L + 1 ; k <= j ; k++)
                            visitV[k][i] = 1;
                    }
                    else{
                        chk = false;
                        break;
                    }
                }
                    //j가 j+1보다 크고 차이가 1
                    //경사로를 i+1보다 큰 곳으로
                else if(map[j][i] - map[j+1][i] == 1){
                    //경사로 길이 감당가능하면
                    if(j + L <= N){
                        for(int k = j+1 ; k <= j + L ; k++){
                            //낮은쪽 높이가 다르면 fail
                            if(map[j+1][i] != map[k][i] || visitV[k][i] != 0){
                                chk = false;
                                break;
                            }
                        }
                        if((j + L + 1 <= N && map[j+L+1][i] <= map[j+1][i]) || j+L == N)
                            ;
                        //경사로 바로 다음 타일의 높이가 다를때
                        else{
                            chk = false;
                            break;
                        }
                        for(int k = j+1 ; k <= j + L ; k++)
                            visitV[k][i] = 1;
                    }
                    else{
                        chk = false;
                        break;
                    }
                }
                    //높이차가 1보다 크면 fail 길이 아님!
                else{
                    chk = false;
                    break;
                }
            }
        }
        if(chk)
            sol++;
    }

    cout << sol << endl;
    return 0;
}