//
// Created by vkdne on 2018-04-13.
//
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct xy {
	int y, x;
};
queue<xy> q;
int map[21][21];			//맵
int visit[21][21];			//방문체크 배열
int dx[4] = { 0,0,1,-1 };	//4방향 체크
int dy[4] = { 1,-1,0,0 };
int N, M;			//맵의 크기, 지불금액
int sol;
void bfs() {
	//초기값 설정
	int t;
	int d = 1;	//현재 서비스 영역의 크기
	int n = 0;	//현재 서비스를 받는 집의 수
	if (map[q.front().y][q.front().x] == 1)
		n = 1;
	int cost = d*d +(d-1)*(d-1);	//서비스 비용
	if (cost <= n*M) {
		if (sol < n)
			sol = n;
	}
	int ny, nx;
	xy front;
	while (!q.empty()) {
		t = q.size();
		//한 사이클을 체크하기 위해 현재 큐 사이즈만큼만 BFS
		while (t--) {
			front = q.front();
			q.pop();
			for (int i = 0; i < 4; i++) {
				nx = front.x + dx[i];
				ny = front.y + dy[i];
				//유요한 영역이면 큐에 넣음
				if (nx > 0 && nx < N + 1 && ny > 0 && ny < N + 1 && visit[ny][nx] == 0) {
					visit[ny][nx] = 1;
					q.push({ ny,nx });
					//집이면 혜택받는 집++
					if (map[ny][nx] == 1)
						n++;
				}
			}
		}
		d++;	//서비스 영역의 크기 하나 증가
		cost = d*d + (d - 1)*(d - 1);	//비용 계산
		if (cost <= n*M) {				//손해를 안보면 -> 답을 갱신할지 판단
			if (sol < n)
				sol = n;
		}
	}
}

int main() {
	int T;
	cin >> T;
	int c = 1;
	while (T--) {
		//입력
		cin >> N >> M;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				cin >> map[i][j];
			}
		}
		//각 점을 시작으로 BFS를 통해 영역을 확장시켜나감
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				fill_n(&visit[0][0], 21 * 21, 0);
				visit[i][j] = 1;
				q.push({ i,j });
				bfs();
			}
		}
		cout << "#" << c << " " << sol << endl;
		sol = 0;
		c++;
	}
}
