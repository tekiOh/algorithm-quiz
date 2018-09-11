//
// Created by vkdne on 2018-09-11.
//

#include <string>
#include <vector>
#include <iostream>
using namespace std;

int n = 2;
int t = 4;
int m = 2;
int p = 1;
string total = "";
string answer = "";
int main(){
    int cnt = 1;
    while(1){
        string str = "";
        int a;
        int tmp = cnt;
        while (tmp) {
            a = tmp % n;
            if(a<10)
                str = to_string(tmp % n)+str;
            else
                    str = (char)(55+a)+str;
            tmp /= n;
        }
        total = total+str;
        cnt++;
        if(total.size() > p+(t-1)*m) {
            total = "0"+total;
            break;
        }
    }
    cout << total << endl;
    for(int i = 0 ; i < t ; i++){
        answer += total[p-1+m*i];
    }
    cout << answer << endl;
    return 0;
}