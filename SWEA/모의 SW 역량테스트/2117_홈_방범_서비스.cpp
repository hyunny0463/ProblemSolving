/*
 * 2117. [모의 SW 역량테스트] 홈 방범 서비스
 *
 * 시간복잡도 : O(N * N * N * N * K(N))
 *
 * simulation
​
 * 모든 집의 위치를 저장해두고 도시의 모든 위치에서 각 집과의 거리를 구한다.
 * 구한 거리가 서비스 영역 K 이내이면 카운트하고
 * 카운트한 숫자 * 하나의 집에서 지불할 수 있는 비용 M > K*k + (K+1)*(K+1) 이면
 * 이 때 카운트한 집 숫자가 결과값보다 크다면 갱신한다.
​
 * 시간복잡도가 N^5이므로 처음엔 이 방법이 가능한지가 의문스러웠다.
 * 하지만 최대 N의 크기가 20이므로 충분히 가능한 방법이였다.
 * 아주 약간 시간을 줄이기 위해 모든 집에서 내는 비용이 영역보다 작으면 리턴해주었다.
 *
 */

#define fastio() ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#include <iostream>
#include <string.h>
#include <queue>

using namespace std;

struct pos {
	int x, y;
};

pos h[400];
int hcnt;
int hservice;

bool isin(pos s, pos t, int K) { // 서비스 위치, 타겟 위치, 운영 영역
	return abs(s.x - t.x) + abs(s.y - t.y) + 1 <= K ? true : false; // 거리가 K 이하이면 true 반환
}

void isservice(int N, int M, int K) { // 도시 크기, 집에서 지불하는 비용, 서비스 지역 크기
	int cost = K * K + (K - 1) * (K - 1); // 방범 영역에 따른 비용 계산
	if (hcnt * M < cost) // 모든 집의 비용을 다 더한 값이 비용보다 작으면 리턴
		return;
	for (int i = 0; i < N; ++i) {
		for (int j = 0, cnt; j < N; ++j) {
			cnt = 0;
			for (int k = 0; k < hcnt; ++k)
				if (isin({ j, i }, h[k], K)) // 모든 위치에서 모든 집과 거리 비교
					cnt++; // 거리가 K 이하인 집 개수 카운트

			if (cnt * M >= cost) // 집 개수 * 집에서 지불하는 돈이 비용보다 크거나 같을 때
				hservice = hservice > cnt ? hservice : cnt; // 기존의 집 개수보다 많다면 교체
		}
	}
}

void solve(int N, int M) { // 서비스 지역 크기를 늘려가며 확인
	for (int K = 2; K < N + 2; K++) // 도시의 전체를 커버할 만큼 서비스 영역을 늘림
		isservice(N, M, K);
}

int main(int argc, char** argv) {
	fastio();
	int T;
	cin >> T;
	for (int testcase = 1, N, M; testcase <= T; ++testcase) {
		cin >> N >> M;
		hcnt = 0;
		hservice = 1;
		for (int i = 0, tmp; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				cin >> tmp;
				if (tmp) // 집이 있을 때 집 위치를 저장
					h[hcnt++] = { j, i };
			}
		}
		solve(N, M);
		cout << '#' << testcase << ' ' << hservice << '\n';
	}

	return 0;
}