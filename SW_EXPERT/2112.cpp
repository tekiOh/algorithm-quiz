//
// Created by vkdne on 2018-04-12.
//
#include <iostream>
using namespace std;

int arr[14][21];
int D, W, K;
int med[14];
int medAB[14];
int sol;
bool stop = true;
struct st {
	int tarr[14][21];
	int num;
};
bool check() {
	int tmp;
	int cnt;
	for (int i = 1; i <= W; i++) {
		tmp = arr[1][i];
		cnt = 1;
		for (int j = 2; j <= D; j++) {
			//같으면 cnt++
			if (arr[j][i] == tmp) {
				cnt++;
				if (cnt == K)
					break;
			}
			else {
				tmp = arr[j][i];
				cnt = 1;
			}
		}
		//통과하지못하면 false 반환
		if (cnt != K)
			return false;
	}
	//통과하면 true 반환
	return true;
}

void chk(st f) {
	int tmp;
	int cnt;
	bool ch;
	for (int i = 1; i <= W; i++) {
		tmp = f.tarr[1][i];
		cnt = 1;
		ch = false;
		for (int j = 2; j <= D; j++) {
			//위층이랑 같으면
			if (tmp == f.tarr[j][i]) {
				cnt++;
			}
				//위층이랑 다르면
			else {
				tmp = f.tarr[j][i];
				cnt = 1;
			}

			if (cnt == K) {
				ch = true;
				break;
			}

		}
		if (ch == false) {
			return;
		}
	}
	//통과했으면
	if (ch) {
		sol = f.num;
		stop = false;
		return;
	}

}
st makest(int d) {
	st tmp;
	for (int i = 1; i <= D; i++) {
		for (int j = 1; j <= W; j++) {
			if (medAB[i] == -1)
				tmp.tarr[i][j] = arr[i][j];
			else
				tmp.tarr[i][j] = medAB[i];
		}
	}

	tmp.num = d;
	return tmp;
}

void makeMedAB(int d, int num) {
	if (d == num) {
		chk(makest(num));
		return;
	}
	medAB[med[d + 1]] = 0;
	makeMedAB(d + 1, num);
	medAB[med[d + 1]] = 1;
	makeMedAB(d + 1, num);
}
void dfs(int max, int cd, int td) {
	if (cd == td) {
		fill_n(medAB, 14, -1);
		makeMedAB(0,td);
		//check하고
		//반환
		return;
	}
	for (int i = max + 1; i <= D - (td - cd) + 1; i++) {
		med[cd + 1] = i;
		dfs(i, cd + 1, td);
	}
}
void makeCombination(int num) {
	for (int i = 1; i <= D - num + 1; i++) {
		med[1] = i;
		dfs(i, 1,num);
	}
}

int main() {
	int T;	//test case 수
	cin >> T;
	int c = 1;
	while (T--) {
		cin >> D >> W >> K;
		for (int i = 1; i <= D; i++) {
			for (int j = 1; j <= W; j++) {
				cin >> arr[i][j];
			}
		}
		//바로 검사
		if (check()) {
			cout << "#" << c << " " << 0 << endl;
			c++;
			stop = true;
			continue;
		}
		for (int i = 1; i <= D && stop; i++) {
			makeCombination(i);
		}
		cout << "#" << c << " " << sol << endl;
		stop = true;
		c++;
	}

	return 0;
}
