//
// Created by vkdne on 2018-09-03.
//

#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct t {
    long start;
    long end;
};
vector<string> lines = {"2016-09-15 20:59:57.421 0.351s", "2016-09-15 20:59:58.233 1.181s",
                        "2016-09-15 20:59:58.299 0.8s", "2016-09-15 20:59:58.688 1.041s",
                        "2016-09-15 20:59:59.591 1.412s", "2016-09-15 21:00:00.464 1.466s",
                        "2016-09-15 21:00:00.741 1.581s", "2016-09-15 21:00:00.748 2.31s",
                        "2016-09-15 21:00:00.966 0.381s", "2016-09-15 21:00:02.066 2.62s"};

//vector<string> lines = {"2016-09-15 01:00:04.002 2.0s", "2016-09-15 01:00:07.000 2s"};


vector<t> list;

void makeList() {
    for (int i = 0; i < lines.size(); i++) {
        string str = lines[i];
        long hour = stol(str.substr(11));
        long min = stol(str.substr(14));
        long sec = stol(str.substr(17, 2));
        long msec = stol(str.substr(20));
        long time = (long) (stod(str.substr(24)) * 1000.0);
        long end = hour * 60 * 60 * 1000 + min * 60 * 1000 + sec * 1000 + msec;
        long start = end - time + 1;
//        cout << str << endl << hour << ":" << min << ":" <<sec<<"."<< msec << "\t" << time << endl;
//        cout << start << "\t" << end << endl;
        list.push_back({start, end});
    }
}

int main() {
    makeList();
    int answer = 0;
    int mlsol = 0;
    int mrsol = 0;
    int msol;
    long istart, iend, jstart, jend;
    for (int i = 0; i < list.size(); i++) {
        mlsol = 0;
        mrsol = 0;
        istart = list[i].start;
        iend = list[i].end;
        for (int j = 0; j < list.size(); j++) {
            jstart = list[j].start;
            jend = list[j].end;
            if ((istart >= jstart && istart <= jend) || (istart <= jstart && istart + 999 >= jend) ||
                (istart + 999 >= jstart && istart + 999 <= jend)) {
                mlsol++;
            }

            if ((iend >= jstart && iend <= jend) || (iend <= jstart && iend + 999 >= jend) ||
                (iend + 999 >= jstart && iend + 999 <= jend)) {
                mrsol++;
            }
        }
        if (mlsol > mrsol)
            msol = mlsol;
        else
            msol = mrsol;
        if (msol > answer)
            answer = msol;
    }
    cout << answer << endl;

    return 0;
}