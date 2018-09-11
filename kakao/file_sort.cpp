//
// Created by vkdne on 2018-09-11.
//
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
vector<string> files = {"img0000312.png", "img0000210.png", "img0000102.png", "img0000001.png", "IMG0000001.GIF",
                        "img0000002.JPG"};
//vector<string> files = {"img12.png", "img10.png", "img02.png", "img1.png", "IMG01.GIF", "img2.JPG"};
//vector<string> files = {"F-5 Freedom Fighter", "B-50 Superfortress", "A-10 Thunderbolt II", "F-14 Tomcat"};
struct hnt{
    string head;
    string number;
};
string toUpper(string a) {
    for (int i = 0; i < a.size(); i++) {
        if (a[i] >= 'a' && a[i] <= 'z')
            a[i] = a[i] - 32;
    }
    return a;
}

bool cmp(pair<hnt, string> a, pair<hnt, string> b) {
    if(a.first.head < b.first.head)
        return true;
    else if(a.first.head > b.first.head)
        return false;
    else{
        if(a.first.number < b.first.number)
            return true;
        else if(a.first.number >= b.first.number)
            return false;
    }

}

int main() {
    string name = "";
    int start;
    int end;
    vector<pair<hnt, string>> nfiles;
    for (int i = 0; i < files.size(); i++) {
        name = files[i];
        for (int i = 0; i < name.size(); i++) {
            if (name[i] >= '0' && name[i] <= '9') {
                start = i;
                end = i;
                break;
            }
        }
        for (int i = start + 1; i < name.size(); i++) {
            if (name[i] >= '0' && name[i] <= '9') {
                end++;
                if (end - start == 4)
                    break;
            } else
                break;
        }
        string number = name.substr(start, end - start + 1);
        int size = number.size();
        for (int i = 0; i < 5 - size; i++) {
            number = '0' + number;
        }
        nfiles.push_back({{toUpper(name.substr(0, start)), number}, name});
    }

    stable_sort(nfiles.begin(), nfiles.end(), cmp);

    vector<string> answer;
    for (int i = 0; i < nfiles.size(); i++) {
        answer.push_back(nfiles[i].second);
    }

    return 0;
}