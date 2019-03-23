/*
 * 1211. [S/W 문제해결 기본] 2일차 - Ladder2
 *
 * 시간복잡도 : O(N)
 *
 * ladder1 과 유사한 문제인데, ladder1은 2인 값을 도착하는 출발점을 찾는 문제라면
 * ladder2는 가장 아래행 까지 최소의 이동거리인 출발점을 찾는 문제이다.
 * 똑같이 dfs로 해결할 수 있지만 ladder1에서 깨달은 대로 반복문으로 해결했다.
 *
 */

#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

int min(int a, int b)
{
	return a < b ? a : b;
}

int dfs(int x, int y, vector<vector<int>>& ladder) { // 실제로는 dfs가 아니다

	int ret = 1; // 이동거리

	while (y < 100) {
		if (ladder[y][x + 1]) { // 오른쪽 값이 1이면 0인 값을 만날 때까지 이동
			while (ladder[y][x + 1]) {
				ret++;
				x++;
			}
		}
		else if (ladder[y][x - 1]) { // 왼쪽 값이 1 이면 0인 값을 만날 때까지 이동
			while (ladder[y][x - 1]) {
				ret++;
				x--;
			}
		}
		ret++;
		y++; // 항상 한 칸씩 아래쪽으로 이동
	}
	return ret;
}

int main()
{
	fastio();

	vector<vector<int>> ladder(100, vector<int>(100 + 2, 0)); // 좌, 우에 1열씩 여유를 둠
	for (int testcase = 1, T; testcase <= 10; ++testcase) {

		cin >> T;
		vector<int> st; // 시작점 x좌표 저장하는 벡터
		for (int i = 0; i < 100; ++i) {
			for (int j = 1, tmp; j <= 100; ++j) {
				cin >> ladder[i][j];
				if (i == 0 && ladder[i][j]) // 첫 번째줄 이고 값이 1이면
					st.push_back(j);
			}
		}

		int cnt = 10000; // 이동거리 최대값이 10000이라 가정
		int rslt = 0; // 이동거리가 가장 짧은 x좌표 저장 변수
		for (int i = 0, ret; i < st.size(); ++i) {
			ret = dfs(st[i], 0, ladder);
			if (cnt >= ret) { // x = 0 부터 시작하므로 크거나 같으면 바꿈
				cnt = ret;
				rslt = st[i];
			}
		}
		
		cout << '#' << T << ' ' << rslt - 1 << '\n'; // 1부터 시작하니까 1을 빼줌

	}
	return 0;
}