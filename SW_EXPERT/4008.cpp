//
// Created by vkdne on 2018-04-12.
//
#include <iostream>
using namespace std;

int num[13];
int op[5];
int N;	//숫자 개수, 연산자 개수 -> N-1개
int minValue = 100000001;
int maxValue = -100000001;


void dfs(int cnt , int value) {
	if (cnt == N) {
		if (minValue > value)
			minValue = value;
		if (maxValue < value)
			maxValue = value;
		return;
	}
	if (op[1]) {
		op[1]--;
		dfs(cnt+1,value+num[cnt+1]);
		op[1]++;
	}
	if (op[2]) {
		op[2]--;
		dfs(cnt+1,value-num[cnt+1]);
		op[2]++;
	}
	if (op[3]) {
		op[3]--;
		dfs(cnt+1,value*num[cnt+1]);
		op[3]++;
	}
	if (op[4]) {
		op[4]--;
		dfs(cnt+1,value/num[cnt+1]);
		op[4]++;
	}
}

int main() {
	int T;
	cin >> T;
	int c = 1;
	while (T--) {
		cin >> N;
		//연산자 개수 입력
		for (int i = 1; i < 5; i++) {
			cin >> op[i];
		}
		//숫자 입력
		for (int i = 1; i <= N; i++) {
			cin >> num[i];
		}

		dfs(1,num[1]);
		cout <<"#" << c << " " << maxValue - minValue << endl;
		minValue = 100000001;
		maxValue = -100000001;
		c++;
	}

	return 0;
}