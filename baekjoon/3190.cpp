//
// Created by vkdne on 2018-04-03.
//

#include <iostream>
#include <queue>
using namespace std;

int map[101][101];
int N,K,L;
//시계 반대 방향
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
struct sd{
    int sec = 0;
    char dir = 'D';
};
struct tailD{
    int x,y;
    int d;
};
queue<sd> q;
queue<tailD> tdq;
int main(){
    cin >> N >> K;
    int x,y;
    for(int i = 0 ; i < K ; i++){
        cin >> y >> x;
        map[y][x] = 1;
    }
    cin >> L;
    sd temp;
    for(int i = 0 ; i < L ; i++) {
        cin >> temp.sec >> temp.dir;
        q.push(temp);
    }
    map[1][1] = 2;
    int time = 0;
    int direction = 0;  //오른쪽
    int directionTail = 0;
    int headx = 1;
    int heady = 1;
    int tailx = 1;
    int taily = 1;
    while(1){
        sd tmp = q.front();
        //시간이 되면 방향을 변경
        //시간이 안되었으면 뱡향 유지
        if(tmp.sec == time){
            q.pop();
            if(tmp.dir == 'L'){
                if(direction == 0)
                    direction = 3;
                else
                    direction--;
            }
            else{
                if(direction == 3)
                    direction = 0;
                else
                    direction++;
            }
            tailD td;
            td.y = heady;
            td.x = headx;
            td.d = direction;
            tdq.push(td);
        }
        tailD tmp_td = tdq.front();
        if(tmp_td.x == tailx &&tmp_td.y == taily){
            directionTail = tmp_td.d;
            tdq.pop();
        }
        //머리를 늘려 다음칸에 위치
        headx += dx[direction];
        heady += dy[direction];
        //정상범위에 있고, 자기자신을 만나지않았을때
        if(headx > 0 && headx <= N && heady > 0 && heady <= N && map[heady][headx] != 2){
            //사과가 있을 때 -> 머리만 이동하고 꼬리 그대로
            if(map[heady][headx] == 1){
                map[heady][headx] = 2;
            }
            //사과가 없을 때
            else{
                map[heady][headx] = 2;
                map[taily][tailx] = 0;
                tailx += dx[directionTail];
                taily += dy[directionTail];
            }
        }
        //게임 끝
        else{
            cout << time+1 << endl;
            return 0;
        }
        time++;
    }
    return 0;
}