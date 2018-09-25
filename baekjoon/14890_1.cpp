//
// Created by vkdne on 2018-09-25.
//

#include <iostream>

using namespace std;
int map[100][100];
int ladderRow[100][100];
int ladderCol[100][100];
int N,L;
int sol;

bool checkafterRow(int row,int col){
    int h = map[row][col];
    if(col + L - 1 >= N || ladderRow[row][col])
        return false;

    for(int i = col+1 ; i < col + L; i++){
        if(h != map[row][i] || ladderRow[row][i]){
            return false;
        }
    }

    for(int i = col ; i < col + L ; i++)
        ladderRow[row][i] = 1;
    return true;
}

bool checkafterCol(int row,int col){
    int h = map[row][col];
    if(row + L - 1 >= N || ladderCol[row][col])
        return false;

    for(int i = row+1 ; i < row + L; i++){
        if(h != map[i][col] || ladderCol[i][col]){
            return false;
        }
    }
    for(int i = row ; i < row + L ; i++)
        ladderCol[i][col] = 1;
    return true;
}


void rowcheck(int rownum){
    int h = map[rownum][0];
    int s = 1;
    for(int i = 1 ; i < N ; i++){
        //높이 같을 때
        if(map[rownum][i] == h){
            s++;
        }
        //다음이 1 높을 때
        else if(map[rownum][i] - h == 1){
            if(s >= L){
                h = map[rownum][i];
                s = 1;
            }
            else
                return;
        }
        //다음이 1 낮을 때
        else if(map[rownum][i] - h == -1){
            if(checkafterRow(rownum,i)){
                i += L - 1;
                h = map[rownum][i];
                s = 0;
            }
            else
                return;
        }
        //2 이상 차이 >> 끝
        else{
            return;
        }
    }
    sol++;
}

void colcheck(int colnum){

    int h = map[0][colnum];
    int s = 1;
    for(int i = 1 ; i < N ; i++){
        //높이 같을 때
        if(map[i][colnum] == h){
            s++;
        }
            //다음이 1 높을 때
        else if(map[i][colnum] - h == 1){
            if(s >= L){
                h = map[i][colnum];
                s = 1;
            }
            else
                return;
        }
            //다음이 1 낮을 때
        else if(map[i][colnum] - h == -1){
            if(checkafterCol(i,colnum)){
                i += L - 1;
                h = map[i][colnum];
                s = 0;
            }
            else
                return;
        }
            //2 이상 차이 >> 끝
        else{
            return;
        }
    }
    sol++;
}

int main(){
    cin >> N >> L;

    for(int i = 0 ; i < N ; i++)
        for(int j = 0 ; j < N ; j++)
            cin >> map[i][j];

    for(int i = 0 ; i < N ; i++) {
        rowcheck(i);
        colcheck(i);
    }

    cout << sol << endl;
    return 0;
}