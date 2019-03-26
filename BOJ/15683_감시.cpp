/*
 * 15683. 감시
 *
 * 시간복잡도 : O(N)
 *
 * dfs와 simulation의 복합적인 문제
 * 5번카메라의 경우 회전하지 않으므로 전처리를 해주었고
 * 그 외에는 모든 경우를 dfs를 이용하여 카메라를 회전하여
 * 감시영역을 표시하고 저장된 모든 카메라에 대해 표시했을 때
 * 감시되지 않는 영역 개수를 세는 방식으로 해결했다.

 * 처음에는 아무래도 전체맵을 복사하면
 * 각 카메라에 대해 회전했을 때 이전의 값을 없애기위해
 * 맵을 되돌려 주는 것이 효율적이라 생각했는데
 * 맵의 크기가 커질 수록, 깊이가 깊어질수록 사용되는 자원이 많아지므로
 * 최대한 복사하는 것을 자제해야겠다.
 *
 */

#define _CRT_SECURE_NO_WARNINGS
#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
using namespace std;

int N, M, invisiblearea = 0x7FFFFFFF;
vector<tuple<int, int, int>> cctv, cam5;
const int dx[] = { 1, 0, -1, 0 };
const int dy[] = { 0, -1, 0, 1 };

void checksight(int dir, int x, int y, vector<vector<int>>& bd) // 방향, x, y, 전체맵
{
	while (bd[y + dy[dir]][x + dx[dir]] != 6) { // 해당 좌표에서 주어진 방향으로 벽을 만날 때까지 이동함
		x += dx[dir];
		y += dy[dir];
		if (bd[y][x])
			continue;
		bd[y][x] = 7;
	}
}

void paint(int d, vector<vector<int>> bd) // 깊이, 전체맵 복사
{
	if (d >= cctv.size()) { // 종료조건
		int cnt = 0;
		for (int i = 1; i <= N; ++i)
			for (int j = 1; j <= M; ++j)
				if (!bd[i][j])
					++cnt;
		invisiblearea = invisiblearea < cnt ? invisiblearea : cnt;
		return;
	}
	int cam = get<0>(cctv[d]);
	int x = get<2>(cctv[d]);
	int y = get<1>(cctv[d]);
	vector<vector<int>> tmpbd = bd; // checksight를 실행하면서 맵에 그리기 때문에 저장해둠
	switch (cam) { // 카메라 번호에 따라 실행
	case 1:
		for (int dir = 0; dir < 4; ++dir) {
			checksight(dir, x, y, bd); // 카메라 방향으로 확인
			paint(d + 1, bd); // 그 다음 카메라
			bd = tmpbd; // checksight 실행 전으로 돌림
		}
		break;
	case 2:
		for (int dir = 0; dir < 2; ++dir) {
			checksight(dir, x, y, bd);
			checksight(dir + 2, x, y, bd);
			paint(d + 1, bd);
			bd = tmpbd;
		}
		break;
	case 3:
		for (int dir = 0; dir < 4; ++dir) {
			checksight(dir, x, y, bd);
			checksight((dir + 1) % 4, x, y, bd);
			paint(d + 1, bd);
			bd = tmpbd;
		}
		break;
	case 4:
		for (int dir = 0; dir < 4; ++dir) {
			checksight(dir, x, y, bd);
			checksight((dir + 1) % 4, x, y, bd);
			checksight((dir + 2) % 4, x, y, bd);
			paint(d + 1, bd);
			bd = tmpbd;
		}
		break;
	}
}

int main(int argc, char** argv)
{
	cin >> N >> M;
	vector<vector<int>> bd(N + 2, vector<int>(M + 2, 6)); // 6은 벽을 의미
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			cin >> bd[i][j];
			if (bd[i][j] > 0 && bd[i][j] < 5) // 1 ~ 4번 카메라번호와 좌표 저장
				cctv.push_back(make_tuple(bd[i][j], i, j)); // 카메라번호, x, y
			else if (bd[i][j] == 5) // 5번 카메라 좌표 저장
				cam5.push_back(make_tuple(bd[i][j], i, j));
		}
	}

	for (int j = 0; j < cam5.size(); ++j) { // 5번카메라는 회전하며 감시하지 않으므로 전처리
		int y = get<1>(cam5[j]);
		int x = get<2>(cam5[j]);
		for (int i = 0; i < 4; ++i) {
			int xx = x, yy = y;
			while (bd[yy + dy[i]][xx + dx[i]] != 6) {
				if (!bd[yy + dy[i]][xx + dx[i]])
					bd[yy + dy[i]][xx + dx[i]] = 7; // 감시영역을 7로 표현
				xx += dx[i];
				yy += dy[i];
			}
		}
	}

	paint(0, bd);

	cout << invisiblearea;

	return 0;
}