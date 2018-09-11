//
// Created by vkdne on 2018-09-11.
//
#include <string>
#include <vector>
#include <iostream>
using namespace std;

string m = "ABC";
vector<string> musicinfos = {"12:00,12:14,HELLO,C#DEFGAB", "13:00,13:05,WORLD,ABCDEF"};

int main(){
    string answer = "`(None)`";
    int ptime = -1;
    string info;
    int start_hour;
    int start_minute;
    int end_hour;
    int end_minute;
    int interval;
    string name;
    string music;

    string tmp = "";
    for(int i = 0 ; i < m.size() ; i++){
        if(m[i] >= 'A' && m[i] <='G'&& i+1 < m.size() && m[i+1] == '#'){
            tmp += (m[i]+32);
            i++;
        }
        else
            tmp += m[i];
    }
    m = tmp;
    cout << m << endl;
    for(int i = 0 ; i < musicinfos.size(); i++){
        info = musicinfos[i];
        start_hour = stoi(info.substr(0,2));
        start_minute = stoi(info.substr(3,2));
        end_hour = stoi(info.substr(6,2));
        end_minute = stoi(info.substr(9,2));
        interval = 60*(end_hour - start_hour) + end_minute - start_minute;
        info = info.substr(12);
        name = info.substr(0,info.find(','));
        music = info.substr(info.find(',')+1);
        string musictmp = "";
        for(int i = 0 ; i < music.size() ; i++){
            if(music[i] >= 'A' && music[i] <='G'&& i+1 < music.size() && music[i+1] == '#'){
                musictmp += (music[i]+32);
                i++;
            }
            else
                musictmp += music[i];
        }
        music = musictmp;

        string total = "";
        for(int i = 0 ; i < interval/music.size(); i++){
            total += music;
        }
        int n = 0;
        for(int i = 0 ; i < interval%music.size() + n ; i++){
            total += music[i];
        }

        cout << interval << '\t' << name << '\t' << music <<'\t'<<total<<endl;
        if(total.find(m) != string::npos){
            if(interval > ptime){
                ptime = interval;
                answer = name;
            }
        }
    }
    cout << answer << endl;
    return 0;
}