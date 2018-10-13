#include <iostream>
// #include <cstdio>  // uncomment to use scanf/printf instead of cin/cout
#include <sstream>
#include <string>

using namespace std;
int map[1001][1001];
int visit[1001];

int main() {
    int N;
    cin >> N;
    string line;
    // drop a newline traling n
    int max = -1;
    while (N-- > -1) {
        getline(cin, line);
        stringstream ss(line);
        cout << line << endl;
        bool chk = false;
        int from;
        int to;
        //cout << "**************" << endl;
        for (int fork; !(ss >> fork).fail();) {  // read forks from a note
            // @todo Write your code here.
            //cout << fork << endl;
            visit[fork] = 1;
            if (max < fork)
                max = fork;
            if (!chk) {
                from = fork;
                chk = true;
                continue;
            } else {
                map[from][fork] = 1;
                from = fork;
            }
        }
    }

    int cnt;
    for (int i = 1; i <= max; i++) {
        cnt = 0;
        for (int j = 1; j <= max; j++) {
            if (map[i][j])
                cnt++;
            if (cnt > 1) {
                cout << -1 << endl;
                return 0;
            }
        }
    }

    for (int i = 1; i <= max; i++) {
        bool chk1 = true;
        for (int j = 1; j <= max; j++) {
            if (map[i][j]) {
                chk1 = false;
                break;
            }
        }
        if (chk1 && visit[i] == 1) {
            cout << i << " ";
        }
    }
    return 0;
}
