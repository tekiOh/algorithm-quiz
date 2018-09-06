//
// Created by vkdne on 2018-09-05.
//

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int m = 6;
int n = 6;
int visit[30][30];
vector<string> board = {"TTTANT", "RRFACC", "RRRFCC", "TRRRAA", "TTMMMF", "TMMTTJ"};
vector<char> map[30];
int answer = 0;

void findMatch() {
    bool chk = false;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            visit[i][j] = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m - 1; j++) {
            if (map[i][j] != 'X' && map[i][j] == map[i + 1][j] && map[i][j] == map[i + 1][j + 1] &&
                map[i][j] == map[i][j + 1]) {
                visit[i][j] = 1;
                visit[i][j + 1] = 1;
                visit[i + 1][j] = 1;
                visit[i + 1][j + 1] = 1;
                chk = true;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (visit[i][j]) {
                map[i][j] = 'X';
                answer++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = m - 1; j > -1; j--) {
            if (map[i][j] == 'X') {
                map[i].erase(map[i].begin() + j);
                map[i].push_back('X');
            }
        }
    }

    if (chk)
        findMatch();
    else
        return;
}

int main() {
    for (int i = m - 1; i > -1; i--) {
        for (int j = 0; j < n; j++) {
            map[j].push_back(board[i][j]);
        }
    }

    findMatch();
    return 0;
}