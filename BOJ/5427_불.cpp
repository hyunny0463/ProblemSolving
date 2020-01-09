/*
 * 5427. 불
 *
 * 시간복잡도 : O(N^2)
 *
 * bfs

 * 건물 내에서 불이 옮겨가고 있고,
 * 상근이는 불에 닿지 않고 출구를 찾아서 탈출해야한다.

 * 이 문제는 단순히 길을 찾는 것이 아니라
 * 불이 확산됨에 따라 이동하지 못하는 길도 있다.
 * 불이 확산할 때, 시간에 따라 지도에 숫자로 표기했고,
 * 길을 찾을 때는 현재 시간이 지도에 표기된
 * 숫자보다 작을 때만 이동 가능하도록 했다.
 * 또 가장 빠른 길을 찾아야 하기 때문에
 * dfs가 아닌 bfs를 사용했다.
 * 
 */

#define fastio() ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#include <iostream>
#include <queue>
using namespace std;


struct pxy {
	int x, y;
};

struct pxyt { // 좌표, 시간을 저장하는 구조체
	int x, y, t;
};

const int dx[] = { 1, 0, -1, 0 };
const int dy[] = { 0, 1, 0, -1 };
int bd[1001][1001];
int w, h;
pxy sang; // 상근이 x, y 좌표
queue<pxyt> fire; // 불 좌표 저장하는 queue

void fire_spread() { // 불 확산하는 함수
	while (!fire.empty()) {
		int cx = fire.front().x;
		int cy = fire.front().y;
		int ct = fire.front().t;
		fire.pop();

		for (int i = 0; i < 4; ++i) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			int nt = ct + 1;

			if (nx < 0 && nx >= w && ny < 0 && ny >= h)
				continue;

			if (bd[ny][nx] == -2) { // 빈 공간을 의미
				bd[ny][nx] = nt; // 빈 공간을 시간에 따른 불 번호로 지정
				fire.push({ nx, ny, nt }); // queue에 불 정보를 넣음
			}
		}
	}
}

int escape(int x, int y, int d) { // 탈출하는 길 찾는 함수
	queue<pxyt> q;
	q.push({ x, y, d });

	while (!q.empty()) {
		int cx = q.front().x;
		int cy = q.front().y;
		int ct = q.front().t;
		q.pop();

		if (cx == 0 || cx == w - 1 || cy == 0 || cy == h - 1) // 경계조건일 때 탈출
			return ct;

		for (int i = 0; i < 4; ++i) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			int nt = ct + 1;

			if (bd[ny][nx] > nt || bd[ny][nx] == -2) { // 현재 시간이 불이 확산되어 오는 시간보다 작거나 빈 공간일 때
				q.push({ nx, ny, nt });
				bd[ny][nx] = 0;
			}
		}
	}

	return -1; // 탈출하지 못하면 -1 반환
}


int main(int argc, char** argv) {
	fastio();
	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; ++test_case) {
		cin >> w >> h;
		char tmp;
		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < w; ++j) {
				cin >> tmp;

				if (tmp == '.') // 주어진 문자 정보를 숫자로 변환
					bd[i][j] = -2;
				else if (tmp == '#')
					bd[i][j] = -1;
				else if (tmp == '*') {
					bd[i][j] = 0;
					fire.push({ j, i, 0 });
				}
				else if (tmp == '@') {
					bd[i][j] = -2;
					sang = { j, i };
				}
			}
		}

		fire_spread();
		int rslt = escape(sang.x, sang.y, 0) + 1;

		if (rslt)
			cout << rslt << '\n';
		else
			cout << "IMPOSSIBLE" << '\n';
	}

	return 0;
}