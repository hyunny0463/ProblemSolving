/*
 * 5650. 핀볼 게임
 *
 * 시간복잡도 : O(N * N * N * N)
 *
 * simulation
 * 모든 빈칸에서 4개 방향으로 출발하여 벽을 튕기는 수를 센다.
 * 웜홀은 같은 번호에서 항상 2개 한 쌍이므로 w 배열을 이용하여
 * 입력 받을 때, wormhole 배열에 몇 개 저장했는지 확인하면서 저장한다.

 * 블럭을 방향은 각각의 블럭에 대해서 처리를 했다가
 * 규칙성을 찾아서 소스코드의 길이를 줄일 수 있게 되었다.
 * 하지만 블럭 5의 경우가 규칙에 맞지 않아서 우선적으로 처리해주었다.
 * 웜홀의 경우
 * xx = wormhole[(bd[yy][xx] - 6)][1].x;
 * yy = wormhole[(bd[yy][xx] - 6)][1].y;
 * 이렇게 소스를 짜놓고 왜 범위를 벗어나는지 한참동안 찾았다.
 * cx, cy 변수를 두고 해결 할 수 있었다.

 * 다른 사람의 소스를 봤는데 매번 가는 방향과 블럭의 조합으로 계산하지않고
 * 한번에 배열에 계산된 값을 넣어두고 참조만 하는 식으로 조금 더 빠르게
 * 동작하는 소스를 짤 수 있다는 걸 알게 되었다.
 *
 */
#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#include <iostream>
#include <string.h>
using namespace std;

const int dx[] = { 1, 0, -1, 0 };
const int dy[] = { 0, 1, 0, -1 };

struct worm {
	int x, y;
};

int N;
int bd[102][102];
worm wormhole[5][2];
int w[5];

int solve(int x, int y, int dir) {
	int ret = 0;
	int xx = x;
	int yy = y;
	while (1) {
		xx += dx[dir];
		yy += dy[dir];

		if (bd[yy][xx] == -1)		return ret; // 블랙홀일 경우 리턴
		if (xx == x && yy == y)		return ret; // 시작점 만나면 리턴
		if (bd[yy][xx] == 0)		continue; // 빈칸이면 그대로 진행
		if (1 <= bd[yy][xx] && bd[yy][xx] <= 5) { // 블럭만날 경우
			if (bd[yy][xx] == 5) // 5번 블럭은 따로 처리해줌
				dir = (dir + 2) % 4;
			else if (dir == (bd[yy][xx] + 1) % 4)
				dir = (dir + 1) % 4;
			else if (dir == (bd[yy][xx] % 4))
				dir = (dir + 3) % 4;
			else
				dir = (dir + 2) % 4;
			ret++; // 블럭을 만나는 경우가 벽 튕기는 횟수임
		}
		else { // 웜홀의 경우
			int cx = xx;
			int cy = yy;
			if (wormhole[(bd[cy][cx] - 6)][0].x == cx && wormhole[(bd[cy][xx] - 6)][0].y == cy) {
				xx = wormhole[(bd[cy][cx] - 6)][1].x;
				yy = wormhole[(bd[cy][cx] - 6)][1].y;
			}
			else {
				xx = wormhole[(bd[cy][cx] - 6)][0].x;
				yy = wormhole[(bd[cy][cx] - 6)][0].y;
			}
		}
	}
}

int main(int argc, char** argv) {
	fastio();
	int T;
	cin >> T;
	for (int testcase = 1; testcase <= T; testcase++) {
		cin >> N;
		for (int i = 0; i <= N + 1; ++i)
			bd[0][i] = bd[i][0] = bd[N + 1][i] = bd[i][N + 1] = 5; // 경계에 5번 블럭으로 채움
		memset(w, 0, sizeof(w)); // 웜홀개수 체크하는 배열 초기화
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j) {
				cin >> bd[i][j];
				if (bd[i][j] >= 6) { // 웜홀일 경우만 저장
					wormhole[bd[i][j] - 6][w[bd[i][j] - 6]] = { j, i };
					w[bd[i][j] - 6]++;
				}
			}
		}
		int rslt = 0;
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j) {
				if (bd[i][j]) continue;
				for (int k = 0; k < 4; ++k) { // 매 빈칸마다 4방향으로 확인
					int cnt = solve(j, i, k);
					rslt = rslt > cnt ? rslt : cnt;
				}
			}
		}
		cout << '#' << testcase << ' ' << rslt << '\n';
	}

	return 0;
}