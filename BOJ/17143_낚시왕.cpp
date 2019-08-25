/*
 * 17143. 낚시왕
 *
 * 시간복잡도 : O(R * C * C)
 *
 * simulation

 * 낚시왕이 상어를 잡는 것은 쉽게 해결이 가능하고
 * 문제는 상어의 속력이 클 때 어떻게 처리하느냐에 따라
 * 상어를 저장하는 방법을 달리해야 하는 것이 가장 큰 고민이였다.
 * 이 문제를 해결하기 위해 상어의 정보만 하나의 배열에 저장하려 했지만
 * 상어가 이동하고 겹칠 때 서로 잡아 먹는 것을 해결하기 힘들었기 때문에
 * R*C 크기의 m배열에서 이동한 상어만 같은 크기의 n배열에 적어주고
 * 다른 상어가 이동 했을 때 똑같은 위치에 위치하면 크기가 더 큰 상어를 살려두었다.
 * 상어의 이동은 제자리로 돌아오는 거리인 2 * (C - 1) 으로 나누어 쉽게 한번에 처리했다.
 *
 */

#define fastio() ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#include<iostream>
#include<string.h>

using namespace std;

struct Shark {
	int s = 0, d = 0, z = 0; // 속력, 이동방향, 크기
	bool alive = false; // 존재 여부
};

int dx[] = { 0, 0, 0, 1, -1 };
int dy[] = { 0, -1, 1, 0, 0 };

int R, C, M, cnt = 0;
Shark m[101][101]; // 상어 위치와 상태
Shark n[101][101]; // 상어가 이동한 상태 저장

void fisher(int x) {
	for (int y = 0; y < R; y++) {
		if (m[y][x].alive) { // 살아있으면
			m[y][x].alive = false; // 죽었다 말하기
			cnt += m[y][x].z; // 잡은 상어 수
			break;
		}
	}
}

void moveShark() {
	memset(n, 0, sizeof(n));
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			if (m[i][j].alive) { // m배열에 상어가 있으면
				int mx = (j + m[i][j].s * dx[m[i][j].d]) % (2 * (C - 1)); // 상어 이동을 격자판 너비만큼 나눔
				if (mx < 0) // 0보다 작으면 이동방향을 오른쪽으로 바꿈
					m[i][j].d = 3;
				mx = abs(mx);
				if (mx > C - 1) { // 격자판의 너비보다 크면 이동방향을 왼쪽으로 바꿈
					mx = 2 * C - mx - 2;
					m[i][j].d = 4;
				}
				int my = (i + m[i][j].s * dy[m[i][j].d]) % (2 * (R - 1)); // 상어 이동을 격자판 높이만큼 나눔
				if (my < 0) // 0보다 작으면 이동방향을 아래쪽으로 바꿈
					m[i][j].d = 2;
				my = abs(my);
				if (my > R - 1) { // 격자판의 높이보다 크면 이동방향을 위쪽으로 바꿈
					my = 2 * R - my - 2;
					m[i][j].d = 1;
				}

				if (n[my][mx].z > m[i][j].z) // 상어가 이동한 위치에 다른 더 큰 상어가 있으면
					continue; // 넘어가고
				n[my][mx] = m[i][j]; // 그렇지 않으면 더 큰 상어를 위치 시킴
			}
		}
	}

	memcpy(m, n, sizeof(n));
}

int main(int argc, char** argv) {
	fastio();
	cin >> R >> C >> M; // 행, 열, 상어의 수

	for (int i = 0, r, c, s, d, z; i < M; ++i) {
		cin >> r >> c >> s >> d >> z;
		m[r - 1][c - 1] = { s, d, z, true };
	}

	for (int i = 0; i < C; ++i) { // 낚시왕 오른쪽 한 칸 이동
		fisher(i); // 땅과 가까운 상어 잡는다
		moveShark(); // 상어가 이동한다
	}
	cout << cnt << '\n';

	return 0;
}