//
// Created by vkdne on 2018-09-15.
//
#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;
vector<vector<string>> relation = {{"100", "ryan",   "music",    "2"},
                                   {"200", "apeach", "math",     "2"},
                                   {"300", "tube",   "omputer",  "3"},
                                   {"400", "con",    "computer", "4"},
                                   {"500", "muzi",   "music",    "3"},
                                   {"600", "apeach", "music",    "2"}};
int column;
int row;
int combinationArr[9];
int sol;
vector<string> comp;

//void print() {
//    for (int i = 0; i < column; i++)
//        cout << combinationArr[i];
//    cout << endl;
//    return;
//}

bool compcomb(string tmp) {
    for (int i = 0; i < comp.size(); i++) {
        string cstr = comp[i];
        string c = "";
        for (int j = 0; j < column; j++) {
            if (cstr[j] == '1' && tmp[j] == '1') {
                c += '1';
            } else
                c += '0';
        }
        //cout << tmp << "\t" << cstr << "\t" << c << endl;
        if (cstr == c)
            return false;
    }
    return true;
}

bool calc() {
    map<int, int> vm;
    for (int i = 0; i < column; i++) {
        if (combinationArr[i] == 1)
            vm.insert({i, 0});
    }
    map<string, int> m;
    for (int i = 0; i < row; i++) {
        string tmp = "";
        for (int j = 0; j < column; j++) {
            if (vm.find(j) != vm.end()) {
                tmp += relation[i][j];
            }
        }
        if (m.find(tmp) == m.end()) {
            m.insert({tmp, 0});
        } else
            return false;
    }
    string tmp = "";
    for (int i = 0; i < column; i++) {
        tmp += to_string(combinationArr[i]);
    }
    if (compcomb(tmp)) {
        sol++;
        comp.push_back(tmp);
        return true;
    }
    return false;
}

void makeComb(int start, int size, int target) {
    if (size == target) {
        calc();
        return;
    } else {
        for (int i = start + 1; i < column - target + size + 1; i++) {
            combinationArr[i] = 1;
            makeComb(i, size + 1, target);
            combinationArr[i] = 0;
        }
    }
}

void Combination(int target) {
    for (int i = 0; i < column - target + 1; i++) {
        combinationArr[i] = 1;
        makeComb(i, 1, target);
        combinationArr[i] = 0;
    }
}

int main() {
    column = relation[0].size();
    row = relation.size();
    //cout << column << "\t" << row << endl;
    //몇명으로 조합을 만들것이야?
    for (int i = 1; i <= column; i++) {
        Combination(i);
    }
    cout << sol << endl;
    return 0;
}
