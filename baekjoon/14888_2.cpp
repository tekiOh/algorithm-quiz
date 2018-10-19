#include <iostream>
using namespace std;

int N;	//숫자의 개수
int num[100];
int operand[4];	// +-*/
int minsol = 1000000001;
int maxsol = -1000000001;

void dfs(int value, int cnt) {
    if (cnt == N) {
        if (value > maxsol)
            maxsol = value;
        if (value < minsol)
            minsol = value;
        return;
    }
    if (operand[0]) {
        operand[0]--;
        dfs(value + num[cnt], cnt + 1);
        operand[0]++;
    }
    if (operand[1]) {
        operand[1]--;
        dfs(value - num[cnt], cnt + 1);
        operand[1]++;
    }
    if (operand[2]) {
        operand[2]--;
        dfs(value * num[cnt], cnt + 1);
        operand[2]++;
    }
    if (operand[3]) {
        operand[3]--;
        dfs(value / num[cnt], cnt + 1);
        operand[3]++;
    }
}
int main() {
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> num[i];

    for (int i = 0; i < 4; i++)
        cin >> operand[i];

    dfs(num[0], 1);
    cout << maxsol << endl << minsol << endl;
    return 0;
}