/*
 * 17071. 숨바꼭질 5
 *
 * 시간복잡도 : O(N)
 *
 * 주어진 범위 0 ~ 500000에 대해서
 * 수빈이 위치에서부터 BFS를 시행한다.
 * 짝수, 홀수 시간에 따라 배열에 저장한다 이유는
 * 동생이 해당 위치에 도착했지만 시간이 홀수 차이나면
 * 주어진 +1, -1, x2 연산을 하여 만나는 것 보다
 * 그 다음 시간, 위치에서 만나는 것이 빠르다.
 *
 */

#define _CRT_SECURE_NO_WARNINGS
#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;

int arr[500001][2]; // 짝수, 홀수 시간

void bfs(int x) // 수빈이 위치에서 걸리는 시간을 모두 탐색
{
	int t = 0;
	queue<int> q;
	arr[x][t] = 0;
	q.push(x);
	while (!q.empty()) {
		int qsize = q.size(); // 시간에 따라 분류
		t = (t + 1) % 2;

		for (int i = 0; i < qsize; ++i) {
			int xx = q.front();
			q.pop();

			if (xx + 1 <= 500000 && arr[xx + 1][t] == -1) {
				arr[xx + 1][t] = arr[xx][(t + 1) % 2] + 1;
				q.push(xx + 1);
			}
			if (xx - 1 >= 0 && arr[xx - 1][t] == -1) {
				arr[xx - 1][t] = arr[xx][(t + 1) % 2] + 1;
				q.push(xx - 1);
			}
			if (xx * 2 <= 500000 && arr[xx * 2][t] == -1) {
				arr[xx * 2][t] = arr[xx][(t + 1) % 2] + 1;
				q.push(xx * 2);
			}
		}
	}
}

int solve(int x) // 수빈이 동생 위치에서 수빈이와 만날 때까지 탐색
{
	for (int i = 0; x + i <= 500000; ++i) {
		x += i; // 동생 위치는 시간에 따라 x +1 +2 +3 ... 으로 증가
		if (arr[x][i % 2] <= i) // 수빈이가 먼저 도착했거나 동시에 도착했다면
			if (!((i - arr[x][i % 2]) % 2)) // 그리고 시간이 짝수로 차이난다면
				return i; // 동생이 도착한 시간에 둘이 만날 수 있다
	}
	return -1;
}

int main()
{
	fastio();

	int N, K;
	cin >> N >> K;

	memset(arr, -1, sizeof(arr));
	bfs(N);

	cout << solve(K) << '\n';

	return 0;
}