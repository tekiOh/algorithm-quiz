//
// Created by vkdne on 2018-04-14.
//
#include <iostream>
#include <algorithm>
using namespace std;

int N, M;	// 맵의 크기(3<=N<=10), 채취할수있는 벌통의 수(1<=M<=5)
int C;		// 채취할수있는 최대 꿀 양
int map[11][11];	//맵
int man1[2];	//일꾼이 채취를 시작할 지점을 저장하는 배열
int man2[2];	//(y,x)
int comb[6];	//일꿀의 채취할 지점들의 조합을 정하는 배열
int sol;		//답
int sol1;
int sol2;

void calc(int type) {
    int sum = 0;
    int ms = 0;
    //첫번쨰
    if (type == 1) {
        for (int i = 1; i <= M; i++) {
            sum += map[man1[0]][man1[1] + i - 1] * comb[i];
        }
        if (sum <= C) {
            for (int i = 1; i <= M; i++) {
                ms += (map[man1[0]][man1[1] + i - 1] * comb[i])*(map[man1[0]][man1[1] + i - 1] * comb[i]);
            }
            if (ms > sol1)
                sol1 = ms;
        }
    }
        //두번쨰
    else {
        for (int i = 1; i <= M; i++) {
            sum += map[man2[0]][man2[1] + i - 1] * comb[i];
        }
        if (sum <= C) {
            for (int i = 1; i <= M; i++) {
                ms += (map[man2[0]][man2[1] + i - 1] * comb[i])*(map[man2[0]][man2[1] + i - 1] * comb[i]);
            }
            if (ms > sol2)
                sol2 = ms;
        }
    }
}

void dfs(int type,int max , int cd , int td) {
    if (cd == td) {
        //선택된 조합으로 계산
        calc(type);
        return;
    }
    for (int i = max + 1; i <= M - td + cd + 1; i++) {
        comb[i] = 1;
        dfs(type,i, cd + 1, td);
        comb[i] = 0;
    }

}
void makeCom(int type,int num) {
    for (int i = 1; i <= M - num + 1; i++) {
        comb[i] = 1;
        dfs(type,i, 1, num);
        comb[i] = 0;
    }
}

void solution() {
    sol1 = 0;
    sol2 = 0;
    //1번째 일꿀부터 계산
    int sum1 = 0;
    for (int i = man1[1]; i < man1[1] + M; i++)
        sum1 += map[man1[0]][i];
    //전부 다 체취할수있다면 그대로 계산
    if (sum1 <= C) {
        for (int i = man1[1]; i < man1[1] + M; i++)
            sol1 += (map[man1[0]][i])*(map[man1[0]][i]);
    }
        //아니면 조합을 만들어서 계산
    else {
        for (int i = 1; i < M; i++) {
            makeCom(1,i);
        }
    }

    //2번째 일꿀 계산
    int sum2 = 0;
    for (int i = man2[1]; i < man2[1] + M; i++)
        sum2 += map[man2[0]][i];
    //전부 다 체취할수있다면 그대로 계산
    if (sum2 <= C) {
        for (int i = man2[1]; i < man2[1] + M; i++)
            sol2 += (map[man2[0]][i])*((map[man2[0]][i]));
    }
        //아니면 조합을 만들어서 계산
    else {
        for (int i = 1; i < M; i++) {
            makeCom(2, i);
        }
    }

    if (sol < sol1 + sol2) {
        sol = sol1 + sol2;
    }

}
void init() {
    sol = 0;
    sol1 = 0;
    sol2 = 0;
    fill_n(comb, 6, 0);
}
int main() {
    int T;
    cin >> T;
    int c = 1;
    while (T--) {
        //입력
        cin >> N >> M >> C;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                cin >> map[i][j];
            }
        }
        //cout << "N : " << N << ", M : " << M << ", C : " << C << endl;
        //채취할 자리 정하기
        //먼저 첫번째 일꾼의 시작위치부터 정하고
        for (int i = 1; i <= N; i++) {
            man1[0] = i;
            for (int j = 1; j <= N - M + 1; j++) {
                man1[1] = j;
                //두번째 일꿀의 시작위치 정하기
                //만약 첫번째 일꾼의 시작 줄과 같은 높이에서 시작할수있으면
                //같은 높이에서 시작위치 정하기 시작
                if (j + M <= N - M + 1) {
                    man2[0] = i;
                    for (int a = j + M; a <= N - M + 1; a++) {
                        man2[1] = a;
                        //이제 계산***
                        //print();
                        solution();
                    }
                }
                //i+1번째 줄부터 두번째 일꿀의 시작위치 정하기
                for (int a = i + 1; a <= N; a++) {
                    man2[0] = a;
                    for (int b = 1; b <= N - M + 1; b++) {
                        man2[1] = b;
                        //이제 계산***
                        //print();
                        solution();
                    }
                }

            }
        }
        cout << "#" << c << " " << sol << endl;
        c++;
        init();
    }
    return 0;
}