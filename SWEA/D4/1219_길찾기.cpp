/*
 * 1219. [S/W 문제해결 기본] 4일차 - 길찾기
 *
 * 시간복잡도 : O(2 * N)
 *
 * bfs
 * 시작점 0에서 도착점 99까지 도착하는 경로가 있다면
 * 1 그렇지 않으면 0을 출력하는 길찾기 문제이다.
 * 주어진 경로가 없으면 -1로 초기화하고,
 * 각 위치에서 최대 2가지 경로가 있기 때문에 -1가 아니면
 * 모든 경우에 대하여 queue에 넣고 bfs로써 99로 도달하는지 확인한다.

 * 결과에는 큰 차이가 없지만 모든 길의 개수를 찾은 것으로
 * 문제를 잘못 이해해서 bfs를 선택했고,
 * 99로 도달한다면 종료하는 조건으로 문제를 해결했다.
 *
 */

#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

int main(int argc, char** argv) {
	int g[2][100];

	for (int testcase = 1, N; testcase <= 10; ++testcase) {
		cin >> testcase >> N;
		memset(g, -1, sizeof(g));
		int cur = 0;
		bool flag = false;

		for (int i = 0, A, B; i < N; ++i) {
			cin >> A >> B;
			if (g[0][A] == -1)
				g[0][A] = B;
			else
				g[1][A] = B;
		}

		queue<int> q;
		q.push(0);
		while (!q.empty()) {
			cur = q.front();
			q.pop();

			for (int i = 0; i < 2; ++i) {
				if (g[i][cur] == -1)
					continue;
				if (g[i][cur] == 99) {
					flag = true;
					break;
				}
				else
					q.push(g[i][cur]);
				g[i][cur] == -1;
			}
			if (flag)
				break;
		}
		cout << '#' << testcase << ' ' << flag << '\n';
	}

	return 0;
}