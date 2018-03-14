//
// Created by vkdne on 2018-03-14.
//
#include <iostream>
#include <deque>
using namespace std;
int arr[51];
int main(){
    deque<int> dq;
    int N,M;
    int sol = 0;
    cin >> N >> M;
    for(int i = 1 ; i <= N ; i++)
        dq.push_back(i);

    for(int i = 1; i <= M; i++)
        cin >> arr[i];

    //답찾기
    for(int i = 1; i <=M; i++){
        int cnt = 0;
        int tmp;
        for( auto it = dq.begin(); *it != arr[i]; it++){
            cnt++;
        }

        //front가 유리
        if(cnt < dq.size() - cnt){
            for(int i = 1 ; i <= cnt ; i++){
                tmp = dq.front();
                dq.pop_front();
                dq.push_back(tmp);
            }

            sol += cnt;
            dq.pop_front();
        }
        //back이 유리
        else{
            for(int i = 1 ; i <= dq.size() - cnt ; i++){
                tmp = dq.back();
                dq.pop_back();
                dq.push_front(tmp);
            }

            sol += (dq.size() - cnt);
            dq.pop_front();
        }
    }

    cout << sol;
    return 0;
}