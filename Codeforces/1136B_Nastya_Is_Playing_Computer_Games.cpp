/*
 * 1136B. Nastya Is Playing Computer Games
 *
 * 시간복잡도 : O(N)
 *
 * constructive algorithm, math
 * 맨홀의 개수와 nastya가 처음 위치한 맨홀의 위치가 입력으로 주어진다
 * 모든 맨홀 위에는 돌이 하나씩 있고 nastya는 모든 맨홀을 확인해야한다.
 * 그러기 위해서는 맨홀 위에 있는 돌을 다른 맨홀 위로 던지고
 * 맨홀을 확인하면서 모든 맨홀을 최소의 행동으로 확인해야한다.
 * nastya의 위치에서 1과 n 중 가까운 곳을 정해서 가까운쪽 먼저갔다가
 * 반대편으로 가는 방법이 가장 빠른 방법이다.
 * 그러므로 visit을 사용하여 방문표시를 하고 다른 맨홀로 이동하는 것을 더하여
 * 답을 도출해낸다. 처음 nastya 위치에서는 이동할 일이 없지만 더해주고
 * 마지막에 돌을 2번 던져야하는데 1번만 던지는 것으로 행동하므로
 * 실제 행동한 수와 같다
 *
 */

#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#include <iostream>
using namespace std;

int main(int argc, char** argv) {
	int n, k, cnt = 0, visit[5001] = { 0 };
	cin >> n >> k; // 맨홀 개수, nastya 위치
	int fin = (n - k) > (k - 1) ? n : 1; // 마지막에 도달할 위치
	int inc = (fin == 1) ? 1 : -1; // 마지막 위치가 처음이라면 -1연산하고 n이면 +1 연산

	while (!visit[1] || !visit[n]) { // 마지막에 도달하지 않았으면 계속 실행
		if (k == 1 || k == n) { // 1번 또는 n번 맨홀까지 갔을 때 방향을 반대방향으로 바꾼다
			inc *= -1;
		}
		cnt++; // 행동 횟수
		if (!visit[k]) {
			visit[k] = 1;
			cnt += 2; // 돌을 던지는 행동과 맨홀을 열어보는 행동
		}
		k += inc;
	}

	cout << cnt;

	return 0;
}