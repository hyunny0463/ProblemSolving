/*
 * 1137A. Skyscrapers
 *
 * 시간복잡도 : O(N * N * log(N))
 *
 * implementation, sorting
 * 각 sky 배열에서 (i, j)의 위치에 따라 가로와 세로에 대해서
 * 크기 순으로 정렬을 하고 그 중 최대값을 sky[i][j]의 값으로 바꾸는 문제
 * pair를 사용해서 각 행과 열의 값을 받고 정렬해서 손쉽게 값을 바꿀 수 있었고
 * 행과 열에 대해 (i, j)의 값이 다른 경우에는 더 작은 값에 그 차이만큼 더해주어
 * 최대값을 비교해보는 식으로 문제 해결
 *
 */

#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, sky[1001][1001], skyrow[1001][1001], skycol[1001][1001];
int mrow[1001], mcol[1001];
int main(int argc, char** argv) {
	
	vector<pair<int, int>> tmpr, tmpc;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> sky[i][j];

	for (int i = 1; i <= n; ++i) { // 각 행에 대해서 실행
		for (int j = 1; j <= m; ++j)
			tmpr.push_back({ sky[i][j], j });
		sort(tmpr.begin(), tmpr.end(), greater<pair<int, int>>()); // 내림차순 정렬

		int cnt = 1, val = 0;
		while (!tmpr.empty()) {
			if (val == tmpr.back().first)	--cnt; // 이전과 같은 값이면 같은 숫자를 넣어주기 위해서
			skyrow[i][tmpr.back().second] = cnt++; // 각 위치에 크기 순으로 번호를 매김
			val = tmpr.back().first;
			tmpr.pop_back(); // 직관적이긴 하지만 굳이 pop하지 않으면 조금 더 빠름
		}
		mrow[i] = cnt - 1; // 각 행의 최대값을 저장
	}

	for (int i = 1; i <= m; ++i) { // 각 열에 대해서 실행
		for (int j = 1; j <= n; ++j)
			tmpc.push_back({ sky[j][i], j });
		sort(tmpc.begin(), tmpc.end(), greater<pair<int, int>>()); // 내림차순 정렬

		int cnt = 1, val = 0;
		while (!tmpc.empty()) {
			if (val == tmpc.back().first)	--cnt; // 이전과 같은 값이면 같은 숫자를 넣어주기 위해서
			skycol[tmpc.back().second][i] = cnt++; // 각 위치에 크기 순으로 번호를 매김
			val = tmpc.back().first;
			tmpc.pop_back();
		}
		mcol[i] = cnt - 1; // 각 열의 최대값을 저장
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (skyrow[i][j] >= skycol[i][j]) // 해당 위치에서 행에 대한 숫자 크기가 크다면 열에 그 차이만큼 더해준 최대값과 비교
				sky[i][j] = mcol[j] + skyrow[i][j] - skycol[i][j] > mrow[i] ? mcol[j] + skyrow[i][j] - skycol[i][j] : mrow[i];
			else
				sky[i][j] = mrow[i] + skycol[i][j] - skyrow[i][j] > mcol[j] ? mrow[i] + skycol[i][j] - skyrow[i][j] : mcol[j];
			cout << sky[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}