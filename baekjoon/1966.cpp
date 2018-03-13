//
// Created by vkdne on 2018-03-13.
//

#include <iostream>
#include <queue>

using namespace std;


int main(){
    int T;
    cin >> T;
    int N, M;
    int a;
    while(T--){
        queue<int> q;
        priority_queue<int> pq;
        cin >> N >> M;
        //int max = -1;
        int sol = 0;
        for(int i = 0; i < N ; i++){
            cin >> a;
            q.push(a);
            pq.push(a);
        }
        int tmp;
        int idx = M;
        while(1) {
            //대상물 전까지 push, pop
            for (int i = 0; i < idx; i++) {
                if (q.front() == pq.top()) {
                    q.pop();
                    pq.pop();
                    sol++;
                }
                else {
                    tmp = q.front();
                    q.pop();
                    q.push(tmp);
                }
            }
            //대상물 push or pop
            if (q.front() == pq.top()) {
                q.pop();
                pq.pop();
                sol++;
                cout <<sol<<endl;
                break;
            }
            else{
                tmp = q.front();
                q.pop();
                q.push(tmp);
                idx = q.size() - 1;
            }
        }
    }


    return 0;
}