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


void dfs(int plus, int minus, int mul, int div, int cnt, int value) {
	if (cnt == N) {
		if (minValue > value)
			minValue = value;
		if (maxValue < value)
			maxValue = value;
		return;
	}
	if (plus != 0) {
		dfs(plus - 1, minus, mul, div, cnt + 1, value + num[cnt + 1]);
	}
	if (minus != 0) {
		dfs(plus, minus - 1, mul, div, cnt + 1, value - num[cnt + 1]);
	}
	if (mul != 0) {
		dfs(plus, minus, mul - 1, div, cnt + 1, value * num[cnt + 1]);
	}
	if (div != 0) {
		dfs(plus, minus, mul, div - 1, cnt + 1, value / num[cnt + 1]);
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

		dfs(op[1],op[2],op[3],op[4],1,num[1]);
		cout <<"#" << c << " " << maxValue - minValue << endl;
		minValue = 100000001;
		maxValue = -100000001;
		c++;
	}

	return 0;
}