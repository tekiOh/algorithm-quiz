//
// Created by vkdne on 2018-03-26.
//

#include<iostream>
#include<queue>
using namespace std;

struct aa{
    int v;
    int cnt;
};
queue<aa> q;
int N,K;
int sol;
int front,cnt,a,b,c;
int arr[100001];
void BFS(){
      while(q.size()){
          front = q.front().v;
          cnt = q.front().cnt;
          q.pop();
          if(front == K){
              cout << cnt << endl;
              return;
          }
          a = front - 1;
          b = front + 1;
          c = front * 2;
          if(a >= 0 && arr[a] == 0){
              arr[a] = cnt + 1;
              q.push({a,cnt+1});
          }

          if(b <= 100000 && arr[b] == 0){
              arr[b] = cnt + 1;
              q.push({b,cnt+1});
          }

          if(c <= 100000 && arr[c] == 0){
              arr[c] = cnt + 1;
              q.push({c,cnt+1});
          }

      }
}

int main(){
    cin >> N >> K;
    if(N > K)
        cout << N-K<<endl;
    else {
        arr[N] = 1;
        q.push({N, 0});
        BFS();
    }
    return 0;
}



