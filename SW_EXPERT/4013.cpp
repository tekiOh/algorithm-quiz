#include <iostream>
using namespace std;

int T, K;
int arr[5][9];
int directionArr[5];
int visit[5];
int sol = 0;
int num = 0;
int d = 1;

void leftshift(int num) {
    int temp = arr[num][1];
    for (int i = 1; i < 8; i++)
        arr[num][i] = arr[num][i + 1];
    arr[num][8] = temp;
}
void rightshift(int num) {
    int temp = arr[num][8];
    for (int i = 8; i > 1; i--)
        arr[num][i] = arr[num][i - 1];
    arr[num][1] = temp;
}
void rotate() {
    for (int i = 1; i < 5; i++) {
        if (directionArr[i] == 1)
            rightshift(i);
        if (directionArr[i] == -1)
            leftshift(i);
    }
}

void setDirection(int num, int direction) {
    int left = num - 1;
    int right = num + 1;
    if (left >= 1 && visit[left] == 0) {
        //같은 극이면 안돌고
        if (arr[num][7] == arr[left][3]) {
            visit[left] = 1;
            directionArr[left] = 0;
            setDirection(left, 0);
        }
            //다른 극이면 반대로 돌고
        else {
            visit[left] = 1;
            directionArr[left] = -1 * direction;
            setDirection(left, -1 * direction);
        }
    }

    if (right < 5 && visit[right] == 0) {
        //같은 극이면 안돌고
        if (arr[num][3] == arr[right][7]) {
            visit[right] = 1;
            directionArr[right] = 0;
            setDirection(right, 0);
        }
            //다른 극이면 반대로 돌고
        else {
            visit[right] = 1;
            directionArr[right] = -1 * direction;
            setDirection(right, -1 * direction);
        }
    }

}

void score() {
    int d = 1;
    for (int i = 1; i < 5; i++) {
        sol += (d*arr[i][1]);
        d *= 2;
    }
}

int main() {
    cin >> T;
    int C = 1;
    while(T--){
        cin >> K;
        for (int i = 1; i < 5; i++)
            for (int j = 1; j < 9; j++)
                cin >> arr[i][j];

        while (K--) {
            cin >> num;
            cin >> d;
            directionArr[num] = d;
            visit[num] = 1;
            setDirection(num, d);
            rotate();
            fill_n(visit, 5, 0);
        }
        score();
        cout <<"#"<< C <<" "<< sol << endl;
        sol = 0;
        C++;
    }
    return 0;
}