/*
 * 2098. 외판원 순회
 *
 * 시간복잡도 : O(N * 2 ^ N)
 *
 * patchSet#1 state dynamic programming
 * patchSet#2 memoization, bit mask

 * 메모이제이션과 비트 마스크로 모든 경우를 최소한으로 확인하는 방법
 * 모든 도시를 순회할 때, 1 -> 2 -> 3 -> 1 이나 2 -> 3 -> 1 -> 2 는 같다.
 * 그러므로 모든 도시에서 시작해서 최소값을 확인하지 않아도 되며,
 * 시작점은 0으로 고정시켜 놓는다.
 * 재귀를 돌면서, 길이 연결되어 있지 않아 0 인 경우와
 * 이미 방문한 도시인 경우만 제외하고 진행한다.
 * 시간 복잡도는 N * 2 ^ N 인것 같은데 확실하지는 않다.
 *
 */

#define fastio() ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#include <iostream>
#include <memory.h>
using namespace std;

const int INF = 1000000000;
int N;
int m[1 << 16][16];
int w[16][16];

int min(int a, int b) {
	return a < b ? a : b;
}

int solution(int s, int p) { // state, position
	if (s == (1 << N) - 1) {
		if (w[p][0] != 0) return w[p][0];
		return INF;
	}

	int& ret = m[s][p];
	if (ret != -1) {
		return ret;
	}
	ret = INF;

	for (int n = 0; n < N; ++n) { // next
		if (w[p][n] == 0) continue;
		if (s & (1 << n)) continue;

		ret = min(ret, w[p][n] + solution(s | (1 << n), n));
	}

	return ret;
}

int main(int argc, char** argv) {
	fastio();
	cin >> N;

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cin >> w[i][j];

	memset(m, -1, sizeof(m));

	cout << solution(1 << 0, 0) << '\n';

	return 0;
}
