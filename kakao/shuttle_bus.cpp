////
//// Created by vkdne on 2018-09-04.
////
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
//운행횟수, 운행간격, 최대 크루 수
int n = 10 ;
int t = 60;
int m = 45;
string timetable[2000] = {"23:59","23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59"};
//{"08:00", "08:01", "08:02", "08:03"};
//{"08:00", "09:09", "09:10"};
//{"09:00","09:00","09:00","09:00"};
//{"00:01", "00:01", "00:01", "00:01", "00:01"};
//{"23:59"};
//{"23:59","23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59"};
vector<string> shuttletime;
int timetableSize = 16;

void addShuttleTime() {
    shuttletime.push_back("09:00");
    int hour = 9;
    int minute = 0;
    string hourstr = "";
    string minutestr = "";
    for (int i = 1; i <= n - 1; i++) {
        minute += t;
        if (minute >= 60) {
            minute -= 60;
            hour++;
        }
        if (hour / 10 == 0) {
            hourstr = "0" + to_string(hour);
        } else {
            hourstr = to_string(hour);
        }
        if (minute / 10 == 0) {
            minutestr = "0" + to_string(minute);
        } else {
            minutestr = to_string(minute);
        }
        shuttletime.push_back(hourstr + ":" + minutestr);
    }
}

string calcTime(string time) {
    string hourstr = time.substr(0, 2);
    string minutestr = time.substr(3, 2);
    if (hourstr[0] == '0')
        hourstr = hourstr[1];
    if (minutestr[0] == '0') {
        minutestr = minutestr[1];
    }
    int hour = stoi(hourstr);
    int minute = stoi(minutestr);
    if (minute == 0) {
        hour--;
        minute = 59;
    } else {
        minute--;
    }
    if (hour / 10 == 0) {
        hourstr = "0" + to_string(hour);
    } else {
        hourstr = to_string(hour);
    }
    if (minute / 10 == 0) {
        minutestr = "0" + to_string(minute);
    } else {
        minutestr = to_string(minute);
    }
    return hourstr + ":" + minutestr;
}

int main() {
    addShuttleTime();
    for (auto a : shuttletime) {
        cout << a << " ";
    }
    cout << endl;
    sort(timetable, timetable + timetableSize);
    for (int i = 0; i < timetableSize; i++) {
        cout << timetable[i] << " ";
    }
    int pos = -1;
    string lastShuttle = shuttletime[shuttletime.size() - 1];
    for (int i = 0; i < timetableSize; i++) {
        if (timetable[i] > lastShuttle) {
            pos = i;
            break;
        }
    }
    if (pos != -1) {
        timetableSize = pos;
    }

    //셔틀버스 당 계산
    int crewidx = 0; //크루 인덱스 0부터 시작 갱신됨!
    for (int i = 0; i < n; i++) {
        //크루 당 계산
        int curCrewNum = 0;
        for (int j = crewidx; j < timetableSize; j++) {
            //만약 현재 셔틀보다 빠르게 왔고 해당 셔틀에 남은 자리가 있으면
            if (shuttletime[i] >= timetable[j] && curCrewNum < m) {
                //마지막 한자리가 남았다면 태우지말고 내가 타야함
                //j번째 크루보다 1분 일찍
                if (curCrewNum == m - 1 && i == n-1) {
                    cout << "sol : " << calcTime(timetable[j]) << endl;
                    return 0;
                }
                //자리가 2자리 이상 남았으면 그냥 태운다
                else {
                    curCrewNum++;
                }
            }
            else
                break;

        }
        crewidx += curCrewNum;

    }
    cout << "sol : " << lastShuttle << endl;
    return 0;
}