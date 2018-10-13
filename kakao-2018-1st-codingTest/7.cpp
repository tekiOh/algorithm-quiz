//
// Created by vkdne on 2018-09-15.
//
#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>> board = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 4, 0, 0, 0},
                             {0, 0, 0, 0, 0, 4, 4, 0, 0, 0},
                             {0, 0, 0, 0, 3, 0, 4, 0, 0, 0},
                             {0, 0, 0, 2, 3, 0, 0, 0, 5, 5},
                             {1, 2, 2, 2, 3, 3, 0, 0, 0, 5},
                             {1, 1, 1, 0, 0, 0, 0, 0, 0, 5}};

int row;
int column;
int sol;
int dy1[3] = {-1,-1,-1};
int dx1[3] = {0,1,2};

int dy2[3] = {-1,-2,-2};
int dx2[3] = {0,0,-1};

int dy3[3] = {-1,-2,-2};
int dx3[3] = {0,0,1};

int dy4[3] = {-1,-1,-1};
int dx4[3] = {0,-1,-1};

int dy5[3] = {-1,-1,-1};
int dx5[3] = {-1,0,1};

bool chkPoint(int _row, int _col){
    if(_row >= 0 && _row < row && _col >= 0 && _col < column)
        return true;
    return false;
}

bool chk1(int _row, int _col){
    if(board[_row][_col+1] == 0 && board[_row][_col+2] == 0){
        for(int i = _row+1 ; i <row ; i++){
            for(int j = _col ; j <= _col+2 ; j++){
                if(board[i][j] != 0)
                    return false;
            }
        }
    }
    return true;
}

bool chk2(int _row, int _col){
    if(board[_row][_col-1] == 0 && board[_row-1][_col-1] == 0){
        for(int i = _row+1 ; i <row ; i++){
            for(int j = _col-1 ; j <= _col ; j++){
                if(board[i][j] != 0)
                    return false;
            }
        }
    }
    return true;
}

bool chk3(int _row, int _col){
    if(board[_row][_col+1] == 0 && board[_row-1][_col+1] == 0){
        for(int i = _row+1 ; i <row ; i++){
            for(int j = _col ; j <= _col+1 ; j++){
                if(board[i][j] != 0)
                    return false;
            }
        }
    }
    return true;
}

bool chk4(int _row, int _col){
    if(board[_row][_col-1] == 0 && board[_row][_col-2] == 0){
        for(int i = _row+1 ; i <row ; i++){
            for(int j = _col-2 ; j <= _col ; j++){
                if(board[i][j] != 0)
                    return false;
            }
        }
    }
    return true;
}

bool chk5(int _row, int _col){
    if(board[_row][_col-1] == 0 && board[_row][_col+1] == 0){
        for(int i = _row+1 ; i <row ; i++){
            for(int j = _col-1 ; j <= _col+1 ; j++){
                if(board[i][j] != 0)
                    return false;
            }
        }
    }
    return true;
}


void chk(int _row, int _col,int num){
    int nrow;
    int ncol;
    bool chk = true;
    //1번 도형
    for(int i = 0; i < 3 ; i++){
        nrow = _row+dy1[i];
        ncol = _col+dx1[i];
        if(chkPoint(nrow,ncol)&&board[nrow][ncol] != num){
            chk = false;
            break;
        }
    }
    //1번 위 검사
    if(chk){
        if(chk1(_row,_col))
            sol++;
    }
    chk = true;
    //2번 도형
    for(int i = 0; i < 3 ; i++){
        nrow = _row+dy2[i];
        ncol = _col+dx2[i];
        if(chkPoint(nrow,ncol)&&board[nrow][ncol] != num){
            chk = false;
            break;
        }
    }
    //2번 위 검사
    if(chk){
        if(chk2(_row,_col))
            sol++;
    }
    chk = true;
    //3번 도형
    for(int i = 0; i < 3 ; i++){
        nrow = _row+dy3[i];
        ncol = _col+dx3[i];
        if(chkPoint(nrow,ncol)&&board[nrow][ncol] != num){
            chk = false;
            break;
        }
    }
    //3번 위 검사
    if(chk){
        if(chk3(_row,_col))
            sol++;
    }
    chk = true;
    //4번 도형
    for(int i = 0; i < 3 ; i++){
        nrow = _row+dy4[i];
        ncol = _col+dx4[i];
        if(chkPoint(nrow,ncol)&&board[nrow][ncol] != num){
            chk = false;
            break;
        }
    }
    //4번 위 검사
    if(chk){
        if(chk4(_row,_col))
            sol++;
    }
    chk = true;
    //5번 도형
    for(int i = 0; i < 3 ; i++){
        nrow = _row+dy5[i];
        ncol = _col+dx5[i];
        if(chkPoint(nrow,ncol)&&board[nrow][ncol] != num){
            chk = false;
            break;
        }
    }
    //5번 위 검사
    if(chk){
        if(chk5(_row,_col))
            sol++;
    }
    chk = true;
}


int main(){
    row = board.size();
    column = board[0].size();
    //누은 박스부터
//    for(int i = row - 2 ; i > -1 ; i--){
//        for(int j = 0 ; j < column - 2; j++){
//            //cout << i << "," << j << endl;
//            chkA(i,j);
//        }
//    }
//    cout << "**********" << endl;
//    for(int i = row - 3  ; i > -1 ; i--){
//        for(int j = 0 ; j < column - 1; j++){
//            //cout << i << "," << j << endl;
//            chkB(i,j);
//        }
//    }
    for(int i = row -1 ; i > -1 ; i--){
        for(int j = 0 ; j < column ; j++){
            if(board[i][j] != 0)
                chk(i,j,board[i][j]);
        }
    }

    cout << sol << endl;
    return 0;
}