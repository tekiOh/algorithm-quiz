//
// Created by vkdne on 2018-09-25.
//

#include <iostream>
using namespace std;

int arr[4][8];
int visit[4];

void rotate(int num, int direction) {
    //cout << num+1 << "th :" << direction << endl;
    int ldir = -2;
    int rdir = -2;
    //왼쪽 톱니바퀴가 있고, 현재[6] == 왼쪽[2]이면 반대방향 회전
    if (num - 1 >= 0 && visit[num - 1] == 0 && arr[num][6] != arr[num - 1][2]) {
        ldir = -1 * direction;
    }
    //오른쪽 톱니바퀴가 있고, 현재[2] == 오른쪽[6]이면 반대방향 회전
    if (num + 1 < 4 && visit[num + 1] == 0 && arr[num + 1][6] != arr[num][2]) {
        rdir = -1 * direction;
    }
    //본인
    //시계방향
    if (direction == 1) {
        int tmp = arr[num][7];
        for (int i = 7; i > 0; i--)
            arr[num][i] = arr[num][i - 1];
        arr[num][0] = tmp;
    }
    //반시계방향
    else {
        int tmp = arr[num][0];
        for (int i = 1; i < 8; i++)
            arr[num][i - 1] = arr[num][i];
        arr[num][7] = tmp;
    }
    //왼쪽
    if (ldir != -2) {
        visit[num - 1] = 1;
        rotate(num - 1, ldir);
    }
    //오른쪽
    if (rdir != -2) {
        visit[num + 1] = 1;
        rotate(num + 1, rdir);
    }
}

int main() {
    int K;
    char a;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> a;
            if(a == '0')
                arr[i][j] = 0;
            else
                arr[i][j] = 1;
        }
    }
    cin >> K;
    int num, dir;
    while (K--) {
        cin >> num >> dir;
        for (int i = 0; i < 4; i++) {
            visit[i] = 0;
        }
        visit[num-1] = 1;
        rotate(num-1, dir);
    }
    cout << arr[0][0] + arr[1][0]*2 + arr[2][0]*4 + arr[3][0]*8 << endl;
    return 0;
}