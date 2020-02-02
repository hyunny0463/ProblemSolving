/*
 * 1012. 유기농 배추
 *
 * 시간복잡도 : O(N * M)
 *
 * BFS(DFS)

 * 단순한 bfs, 또는 dfs를 사용하면 해결되는 문제
 * 하지만 처음 bfs로 풀 때 배추를 queue에 넣을 때가 아니라
 * queue에서 뺄 때, 0으로 만드는 것이
 * 중복이 되었기 때문에 시간초과가 났었다.
 * 다음엔 단순히 생각이 안나면 좀 느리더라도 dfs를 사용하거나
 * 초기화 하는 위치를 잘 생각해야 할 듯!
 *
 */

#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };
int T, N, M, K, rslt;
int m[50][50];

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	m[y][x] = 0; // 틀린 이유: pop 할 때 0으로 초기화 하려고 했음

	q.push({ x, y });

	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx >= 0 && nx < M && ny >= 0 && ny < N && m[ny][nx]) {
				m[ny][nx] = 0; // queue에 넣을 때 다른 위치에서 다시 못넣게 0으로 만듬
				q.push({ nx, ny });
			}
		}
	}
}

int main(int argc, char** argv) {
	cin >> T;
	memset(m, 0, sizeof(m)); // 모든 위치를 확인하면서 0으로 초기화 하므로 처음만 하면됨
	for (int testcase = 1; testcase <= T; ++testcase) {
		rslt = 0;
		cin >> M >> N >> K; // 처음 행, 열을 잘못 받았었음

		for (int i = 0, x, y; i < K; ++i) {
			cin >> x >> y;
			m[y][x] = 1; // 배추 위치만 1
		}

		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				if (m[i][j]) {
					rslt++; // 조건문 걸리면 무조건 1 증가
					bfs(j, i);
				}
			}
		}

		cout << rslt << '\n';

	}

	return 0;
}