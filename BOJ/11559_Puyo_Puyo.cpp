/*
 * 11559. Puyo Puyo
 *
 * 시간복잡도 : O(N)
 *
 * DFS를 시행하여 같은 색이 4개 이상인 puyo를 찾고
 * 다시 DFS를 시행하여 그 puyo들을 삭제하는 방식으로 진행한다.
 * puyo를 바닥으로 내리는 것은 queue를 사용하여 아래서부터 순차적으로 쌓는다.

 * 이런 simulation 문제의 경우 처음부터 행을 열로 받고
 * 레퍼런스 연산자를 사용해서 쉽게 넘겨 받은 후 아래쪽으로 정렬하는게 꿀팁인듯 하다.
 *
 */

#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

const int dx[] = { 1, 0, -1, 0 }; // 우, 하, 좌, 상
const int dy[] = { 0, -1, 0, 1 };
int visit[6 + 2][12 + 2];

int dfs(int x, int y, char color, vector<vector<char>>& map) // 삭제할 puyo가 4이상인지 확인
{
	int ret = 1;

	visit[x][y] = 1;
	for (int i = 0; i < 4; ++i) {
		if (map[x + dx[i]][y + dy[i]] != color || visit[x + dx[i]][y + dy[i]]) // 색이 다른거나 이미 방문한 경우
			continue;
		ret += dfs(x + dx[i], y + dy[i], color, map);
	}

	return ret; // 방문한 수 만큼 리턴
}

void dfs_make_zero(int x, int y, char color, vector<vector<char>>& map) // puyo 삭제
{
	visit[x][y]++; // 방문했던 곳이기 때문에
	map[x][y] = '.';
	for (int i = 0; i < 4; ++i) {
		if (map[x + dx[i]][y + dy[i]] != color || visit[x + dx[i]][y + dy[i]] == 2)
			continue;
		dfs_make_zero(x + dx[i], y + dy[i], color, map);
	}
}

void down_puyo(int x, vector<char>& map) // 중력의 영향을 받는 puyo들
{
	queue<char> q; // '.'이 아닌 값을 저장
	for (int i = 12; i >= 1; --i) { // 12가 가장 아래이므로 아래서 부터 저장
		if (map[i] == '.')
			continue;
		q.push(map[i]);
	}
	for (int i = 12; i >= 1; --i) {
		if (!q.empty()) { // queue가 비어있지 않으면 맵에 갱신하고 나머지는 '.' 넣음
			map[i] = q.front();
			q.pop();
		}
		else
			map[i] = '.';
	}
}

int main(int argc, char** argv)
{
	vector<vector<char>> map(6 + 2, vector<char>(12 + 2, '.')); // 경계조건 확인하지 않기 위해 넉넉한 범위

	for (int i = 1; i <= 12; ++i)
		for (int j = 1; j <= 6; ++j)
			cin >> map[j][i]; // down_puyo를 효과적으로 하기위해 열을 행으로 받음

	int is_makedot = 1;
	int cnt = 0;
	while (is_makedot) {
		is_makedot = 0; // puyo의 삭제가 있는지 확인하는 변수
		memset(visit, 0, sizeof(visit)); // down_puyo를 하면 맵의 변화가 생기기 때문
		for (int i = 1; i <= 12; ++i) {
			for (int j = 1; j <= 6; ++j) {
				if (map[j][i] != '.' && dfs(j, i, map[j][i], map) >= 4) { // 앞 조건 부터 확인
					dfs_make_zero(j, i, map[j][i], map);
					is_makedot++;
				}
			}
		}
		for (int i = 1; i <= 6; ++i) // 각 행마다 down_puyo 실행
			down_puyo(i, map[i]);

		cnt++;
	}
	cout << cnt - 1 << '\n';

	return 0;
}