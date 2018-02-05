//
// Created by vkdne on 2018-02-05.
//

#include <iostream>
using namespace std;

int arr[5][9];
int interm[5];    // -1 : 반시계, 1 : 시계, 0 : 홀드
int visit[5];
int score;

void direction(int num, int dir){
    //cout<< "in the direction func"<<endl;
    visit[num] = 1;
    //왼쪽
    if(num > 1 && visit[num-1] == 0){
        if(arr[num-1][3] == arr[num][7]){
            interm[num-1] = 0;
        }
        else{
            interm[num-1] = (-1)*dir;
            direction(num-1,interm[num-1]);
        }

    }
    //오른쪽
    if(num < 4 && visit[num+1] == 0){
        if(arr[num+1][7] == arr[num][3]){
            interm[num+1] = 0;
        }
        else{
            interm[num+1] = (-1)*dir;
            direction(num+1,interm[num+1]);
        }
    }
};

void rotate(){
    //cout<< "in the rotate func"<<endl;
    int temp;
    for(int i = 1; i < 5 ; i++){
        if(interm[i] == 1){
            temp = arr[i][8];
            for(int j = 8; j > 1; j--){
                arr[i][j] = arr[i][j-1];
            }
            arr[i][1] = temp;
        }
        if(interm[i] == -1){
            temp = arr[i][1];
            for(int j = 1; j < 8; j++){
                arr[i][j] = arr[i][j+1];
            }
            arr[i][8] = temp;
        }
    }
}

void calc(){
    //cout<< "in the calc func"<<endl;
    score = arr[1][1] + 2*arr[2][1] + 4*arr[3][1] + 8*arr[4][1];
};
int main(){
    char s;
    for(int i = 1 ; i <= 4 ; i++){
        for(int j = 1 ; j <= 8 ; j++){ ;
            cin >> s;
            if(s =='1')
                arr[i][j] = 1;
            else
                arr[i][j] = 0;
        }
    }
    int k;
    cin >> k;
    int num;
    int dir;
    while(k--){
        cin >> num >> dir;
        interm[num] = dir;
        direction(num,dir);
        /*for(int i = 1 ; i < 5 ; i++)
            cout<<interm[i];
        cout<<endl;*/
        rotate();

        for(int i = 1 ; i < 5 ; i++) {
            visit[i] = 0;
            interm[i] = 0;
        }
    }
    calc();
    cout << score;
    return 0;
}