/*
 * 17069. 파이프 옮기기 2
 *
 * 시간복잡도 : O(N^2)
 *
 * memoization
 * 항상 좌표는 파이프의 앞부분을 가지고 있고 dfs로 재귀적으로 좌표를 이동한다
 * 파이프는 가로방향으로 진행하다가 대각방향을 거치지 않고 세로방향으로 이동하지 못하기 때문에 
 * 비트연산을 통해 확인을 하고 대각방향으로 진행할 시 대각방향 뿐만 아니라
 * 나머지 2개의 공간도 비어있는지 확인한다.
 * 메모이제이션을 통해서 지나온 길은 0으로 초기화하고
 * 최종위치까지 도착하면 1을 반환하여 visit 배열에 저장한다.
 * 해당 위치에 도착했을 때, 파이프의 방향까지 같다면 -1이 아닌 값은 반환하여 복잡도를 줄였다.

 * 메모이제이션을 했을 때, 시간복잡도는 간단히 캐시배열을 보면 된다고한다.
 * 여기서는 32 * 32 * 3 개 이므로 3 * N * N 이다.
 * 하지만 정확히는 상태개수가 3 * N * N 이고 각 상태마다 3가지 방향을 보기 때문에
 * 3 * 3 * N * N 이다. 
 *
 */

#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#include <iostream>
#include <string.h>
using namespace std;

int N;
int home[32 + 2][32 + 2]; // 벽을 위한 추가공간
long long int visit[32 + 2][32 + 2][3]; // 해당 공간에 위치했을 때 파이프의 방향까지 저장

// type 가로 1, 세로 2, 대각 3
// 비트연산을 위해서, 가로와 대각, 세로와 대각은 & 연산으로 1이 나오지만 가로와 세로는 &연산시 0 출력
const int dx[] = { 0, 1, 0, 1 }; // 의미x, 가로, 세로, 대각
const int dy[] = { 0, 0, 1, 1 }; // 의미x, 가로, 세로, 대각

long long int dfs(int x, int y, int type) { // x, y, 파이프의 방향
	if (x == N && y == N) // 종료조건
		return 1;
	long long int& ret = visit[y][x][type - 1];
	if (ret != -1) // 지나온 곳은 0으로 만들기 때문에 -1이 아니면 값을 반환
		return ret;
	ret = 0;
	for (int i = 1; i <= 3; ++i) {
		if ((type & i) && !home[y + dy[i]][x + dx[i]]) { // 파이프가 꺽이지 않고 다음 공간이 벽이 아닐 때
			if (i == 1 || i == 2) // 가로거나 세로면 다른 공간을 더 확인하지 않고
				ret += dfs(x + dx[i], y + dy[i], i);
			else if (i == 3 && !home[y][x + 1] && !home[y + 1][x]) // 대각선이면 나머지 공간이 비었는지 확인
				ret += dfs(x + dx[i], y + dy[i], i);
		}
	}
	return ret;
}

int main(int argc, char** argv)
{
	memset(home, -1, sizeof(home));
	memset(visit, -1, sizeof(visit));
	cin >> N;
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			cin >> home[i][j];
	cout << dfs(2, 1, 1) << '\n'; // 초기조건, (2, 1)에서 파이프는 가로방향

	return 0;
}