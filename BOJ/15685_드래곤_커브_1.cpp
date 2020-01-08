/*
 * 15685. 드래곤커브
 *
 * 시간 복잡도 : O()
 *
 * simulation

 * 간단하고 단순한 simulation 문제이다.
 * 구현은 어렵지 않지만 세대가 지나감에 따라
 * 드래곤 커브의 진행방향을 알아내는 것이 어렵다.
 * 해결방법은 지금까지 저장되어 있는 드래곤 커브를
 * 역순으로 보면서 그 방향들을 +1 해주는 방법이다.
 * 예를 들면 처음 오른쪽으로 가는 드래곤 커브가 있다면,
 * 다음 세대의 드래곤 커브는 오른쪽에 +1 한 위쪽방향이고
 * 다음 세대의 드래곤 커브는 위쪽방향의 +1 한 왼쪽 그리고 위쪽이다.
 *
 */

#define fastio() ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#include <iostream>
#include <string.h>
using namespace std;

const int dx[] = { 1, 0, -1, 0 }; // 0: 오른, 1: 위, 2: 왼, 3: 아래
const int dy[] = { 0, -1, 0, 1 };
int m[101][101]; // 드래곤 커브 그리는 배열
int dc[1 << 10]; // 드래곤 커브 세대에 따라 저장하는 배열

int N, M;

int main(int argc, char** argv) {
	fastio();
	memset(m, 0, sizeof(m));
	cin >> N;
	for (int i = 0, x, y, d, g, idx; i < N; ++i) {
		cin >> x >> y >> d >> g; // 드래곤커브 시작점 x, y, 시작방향, 세대

		idx = 0; // 저장한 드래곤 커브 개수
		dc[idx++] = d;
		m[y][x] = 1;
		for (int j = 0; j < g; ++j) // 주어진 세대 수만큼 반복
			for (int k = idx - 1; k >= 0; --k) // 드래곤 커브 개수 -1 개 부터 0 까지
				dc[idx++] = (dc[k] + 1) % 4; // 다음 드래곤 커브는 이전의 드래곤 커브 +1 값을 가짐


		for (int j = 0; j < idx; ++j) { // 저장한 드래곤 커브 배열 따라가면서 그림
			x += dx[dc[j]];
			y += dy[dc[j]];
			m[y][x] = 1;

		}
	}

	int cnt = 0;
	for (int i = 0; i < 100; ++i) // 최종적으로 네 꼭지점이 드래곤 커브의 일부인지 확인하고 카운트
		for (int j = 0; j < 100; ++j)
			if (m[i][j] && m[i][j + 1] && m[i + 1][j] && m[i + 1][j + 1])
				cnt++;

	cout << cnt << '\n';

	return 0;
}