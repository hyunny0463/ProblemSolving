/*
 * 2980. 도로와 신호등
 *
 * 시간복잡도 : O(N * L)
 *
 * 신호등 정보를 모두 저장한 뒤 매 시간마다 모든 위치의 신호등의 정보를 갱신하면서
 * 상근이가 지나갈 수 있는지 판단하고, 상근이가 L 위치에 도달하면 종료한다.
 *
 */


#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#include <iostream>
#include <vector>
using namespace std;

struct light { // 신호등, 빨간불이 켜지는 시간, 파란불이 켜지는 시간
	int D, R, G;
};

int main(int argc, char** argv)
{
	int N, L;
	cin >> N >> L; // 신호등 개수, 도로의 길이

	vector<int> road(L + 1, 1); // 0: 빨간불, 1: 도로, 2: 파란불
	vector<light> tl; // traffic light

	for (int i = 0, D, R, G; i < N; ++i) {
		cin >> D >> R >> G;
		tl.push_back({ D, R, G }); // 벡터에 모든 신호등을 넣음
		road[D] = 0;
	}

	int cnt = 0, sang = 1;
	while (++cnt) { // 상근이가 L 까지 갈 때까지 걸리는 시간
		if (sang == L)
			break;
		if (road[sang]) // 빨간불이 아니면
			sang++;
		for (int i = 0; i < tl.size(); ++i) { // 매 시간 모든 신호등의 상태를 갱신함
			if (!road[tl[i].D] && (cnt % (tl[i].R + tl[i].G)) == tl[i].R)
				road[tl[i].D] = 2;
			else if (road[tl[i].D] == 2 && (cnt % (tl[i].R + tl[i].G)) == 0)
				road[tl[i].D] = 0;
		}
	}

	cout << cnt - 1 << '\n'; // 처음 1을 더한 시간이므로

	return 0;
}