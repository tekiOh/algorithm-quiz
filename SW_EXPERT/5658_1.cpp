//
// Created by vkdne on 2018-10-18.
//

#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;

int T, N, K;
vector<int> v;
set<int, greater<int>> s;

void simulation(int idx) {
    int a, sum;
    for (int i = idx; i < v.size() - N / 4 + 1; i += N / 4) {
        a = 1;
        sum = 0;
        for (int j = i + N / 4 - 1; j >= i; j--) {
            sum += a * v[j];
            a *= 16;
        }
        s.insert(sum);
    }
}

int main() {
    //'0' == 48, 'A' == 65
    cin >> T;
    int a = 1;
    char c;
    while (T--) {
        cin >> N >> K;
        for (int i = 0; i < N; i++) {
            cin >> c;
            if (c >= '0' && c <= '9')
                v.push_back(c - '0');
            else
                v.push_back(c - 'A' + 10);
        }
        for (int i = 0; i < N / 4; i++) {
            simulation(i);
            v.push_back(v[i]);
        }
        auto it = s.begin();
        while (K--)
            it++;
        cout << "#" << a++ << " " << *(--it) << endl;
        v.clear();
        s.clear();
    }
    return 0;
}