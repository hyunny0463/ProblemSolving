/*
 * 1210. [S/W 문제해결 기본] 2일차 - Ladder1
 *
 * 시간복잡도 : O(N * N)
 *
 * 간단하게 DFS로 해결가능한 문제였다.
 * 도착지점인 2에서부터 시작하여 거꾸로 올라오면서
 * 좌우 먼저 살피고 길이 없으면 위로 올라가는 방법으로 진행한다.
 * 실수로 T 값을 입력받지 않아 전체 맵이 한칸씩 쉬프트 되어 답이 제대로 나오지않았다.

 * 다른사람의 소스를 봤는데 움직임은 유사했지만
 * 좌우방향으로 갈 수 있을때 0이 아닌 값까지 while문으로 이동함으로써
 * 조금 더 실행속도를 높일 수 있었다.
 *
 */

#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

#define MN 100
const int dx[] = { -1, 1, 0 }; // 좌, 우, 위
const int dy[] = { 0, 0, -1 };
bool visit[100][102];

int dfs(int x, int y, vector<vector<int>>& ladder) {
	if (y <= 0) // 0에 도착했을 때 종료
		return x;
	int ret = 0;

	visit[y][x] = true;
	for (int i = 0; i < 3; ++i) {
		if (!ladder[y + dy[i]][x + dx[i]] || visit[y + dy[i]][x + dx[i]])
			continue; // 배열의 값이 0 이거나 이미 방문했다면 패스
		ret = dfs(x + dx[i], y + dy[i], ladder);
		if (ret > 0) // y 값이 0에 도달했다면 ret의 값은 0 이상이므로 종료
			break;
	}
	return ret;
}

int main(int argc, char** argv)
{
	vector<vector<int>> ladder(MN, vector<int>(MN + 2, 0));
	pair<int, int> st;

	for (int testcase = 1, T; testcase <= 10; ++testcase) {
		cin >> T;
		for (int i = 0; i < MN; ++i) {
			for (int j = 1; j <= MN; ++j) {
				cin >> ladder[i][j];
				if (ladder[i][j] == 2)
					st = { j, i };
			}
		}
		memset(visit, false, sizeof(visit)); // visit 초기화
		cout << '#' << testcase << ' ' << dfs(st.first, st.second, ladder) - 1 << '\n';
		// 임의로 좌우에 한칸씩 추가해주었기 때문에 결과값-1 한 값을 출력
	}

	return 0;
}