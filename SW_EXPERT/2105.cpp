//
// Created by vkdne on 2018-04-14.
//
#include <iostream>
#include <algorithm>
using namespace std;

int map[21][21];				//맵
int visit[21][21];				//dfs중 visit행렬
int nodevisit[21][21];			//중복 dfs방지하기위한 visit행렬
int visitDesert[101];			//같은 디저트를 파는곳을 방문하지않기위해
int dx[4] = { 1, 1, -1, -1 };	//오른쪽 위, 오른쪽 아래, 왼쪽 아래, 왼쪽 위
int dy[4] = { -1, 1, 1, -1 }; 
int N;							//맵 크기
int sx, sy;						//투어 시작위치
int sd;
int directionArray[4];	//오른쪽 위, 오른쪽 아래, 왼쪽 아래, 왼쪽 위 방향을 1번씩했는지 확인하는 배열
int sol = -1;

void dfs(int y, int x, int d) {
	int ny = 0;
	int nx = 0;
	//시작점이면
	if (x == sx && y == sy) {
		int sum = 0;
		for (int i = 0; i < 4; i++) {
			sum += directionArray[i];
		}
		if (sol < sum)
			sol = sum;
		return;
	}
	
	//오던 방향으로 계속
	ny = y + dy[d];
	nx = x + dx[d];
	
	//정상범위이고 가본적없는 종류의 디저트일 때 계속 진행 
	if (nx > 0 && nx < N + 1 && ny >0 && ny < N + 1 && visit[ny][nx] == 0 && nodevisit[ny][nx] == 0 && visitDesert[map[ny][nx]] == 0 && (map[ny][nx] != sd || (nx == sx && ny == sy))) {
		visitDesert[map[ny][nx]] = 1;
		visit[ny][nx] = 1;
		directionArray[d]++;
		dfs(ny, nx, d);
		directionArray[d]--;
		visit[ny][nx] = 0;
		visitDesert[map[ny][nx]] = 0;
	}
	//오른쪽 위로 갈건데, 직전에 왼쪽 아래가 아니고, 오른쪽 위로 간적이 없을때
	if (directionArray[0] == 0 && d != 2) {
		ny = y + dy[0];
		nx = x + dx[0];
		//정상 범위 + 가본적없는 종류의 디저트일때
		if (nx > 0 && nx < N + 1 && ny >0 && ny < N + 1 && visit[ny][nx] == 0 && nodevisit[ny][nx] == 0 && visitDesert[map[ny][nx]] == 0 && (map[ny][nx] != sd || (nx == sx && ny == sy))) {
			visitDesert[map[ny][nx]] = 1;
			visit[ny][nx] = 1;
			directionArray[0]++;
			dfs(ny, nx, 0);
			directionArray[0]--;
			visit[ny][nx] = 0;
			visitDesert[map[ny][nx]] = 0;
		}
	}

	//오른쪽 아래로 갈건데, 직전에 왼쪽 위가 아니고, 오른쪽 아래로 간적이 없을때
	if (directionArray[1] == 0 && d != 3) {
		ny = y + dy[1];
		nx = x + dx[1];
		//정상 범위 + 가본적없는 종류의 디저트일때
		if (nx > 0 && nx < N + 1 && ny >0 && ny < N + 1 && visit[ny][nx] == 0 && nodevisit[ny][nx] == 0 && visitDesert[map[ny][nx]] == 0 && (map[ny][nx] != sd || (nx == sx && ny == sy))) {
			visitDesert[map[ny][nx]] = 1;
			visit[ny][nx] = 1;
			directionArray[1]++;
			dfs(ny, nx, 1);
			directionArray[1]--;
			visit[ny][nx] = 0;
			visitDesert[map[ny][nx]] = 0;
		}
	}

	//왼쪽 아래로 간건데, 직전에 오른쪽 위가 아니고, 왼쪽 아래로 간적이 없을때
	if (directionArray[2] == 0 && d != 0) {
		ny = y + dy[2];
		nx = x + dx[2];
		//정상 범위 + 가본적없는 종류의 디저트일때
		if (nx > 0 && nx < N + 1 && ny >0 && ny < N + 1 && visit[ny][nx] == 0 && nodevisit[ny][nx] == 0 && visitDesert[map[ny][nx]] == 0 && (map[ny][nx] != sd || (nx == sx && ny == sy))) {
			visitDesert[map[ny][nx]] = 1;
			visit[ny][nx] = 1;
			directionArray[2]++;
			dfs(ny, nx, 2);
			directionArray[2]--;
			visit[ny][nx] = 0;
			visitDesert[map[ny][nx]] = 0;
		}
	}

	//왼쪽 위로 갈건데, 직전에 오른쪽 아래가 아니고, 왼쪽 위로 간적이 없을때
	if (directionArray[3] == 0 && d != 1) {
		ny = y + dy[3];
		nx = x + dx[3];
		//정상 범위 + 가본적없는 종류의 디저트일때
		if (nx > 0 && nx < N + 1 && ny >0 && ny < N + 1 && visit[ny][nx] == 0 && nodevisit[ny][nx] == 0 && visitDesert[map[ny][nx]] == 0 && map[ny][nx] != sd) {
			visitDesert[map[ny][nx]] = 1;
			visit[ny][nx] = 1;
			directionArray[3]++;
			dfs(ny, nx, 3);
			directionArray[3]--;
			visit[ny][nx] = 0;
			visitDesert[map[ny][nx]] = 0;
		}
	}

}

void find(int y, int x) {
	int ny, nx;
	sy = y;
	sx = x;
	sd = map[y][x];
	for (int i = 0; i < 4; i++) {
		ny = y + dy[i];
		nx = x + dx[i];
		if (nx > 0 && nx < N + 1 && ny > 0 && ny < N + 1 && visitDesert[map[ny][nx]] == 0 && (map[ny][nx] != sd || (nx == sx && ny == sy))) {
			visit[ny][nx] = 1;
			directionArray[i]++;
			visitDesert[map[ny][nx]] = 1;
			dfs(ny, nx, i);
			visit[ny][nx] = 0;
			visitDesert[map[ny][nx]] = 0;
			directionArray[i]--;
		}
	}
	visit[y][x] = 0;
	visitDesert[map[y][x]] = 0;
	nodevisit[y][x] = 1;
	fill_n(visitDesert, 101, 0);
	fill_n(directionArray, 4, 0);
}	

void init() {
	fill_n(&nodevisit[0][0], 21 * 21, 0);
	fill_n(&visit[0][0], 21 * 21, 0);
	sol = -1;
}

int main() {
	int T;
	cin >> T;
	int c = 1;
	while (T--) {
		cin >> N;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				cin >> map[i][j];
			}
		}

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				find(i, j);
			}
		}

		cout <<"#"<<c<<" "<< sol << endl;
		init();
		c++;
	}
}
