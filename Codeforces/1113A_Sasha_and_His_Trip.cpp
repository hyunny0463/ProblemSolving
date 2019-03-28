/*
 * 1113A. Sasha and His Trip
 *
 * 시간복잡도 : O(N)
 *
 * dp, greedy, math
 * 연료의 비용은 매 도시의 index 비용만큼 커진다
 * 그러므로 조금이라도 연료가 싼 곳에서 주유하는 것이 이득이다
 * 연료탱크의 크기만에 갈 수 있는 도시까지는 매번 주유하면서 가고
 * 한번에 갈 수 있다면 그때부터는 주유하지 않고 가는 방법을 사용했다
 *
 */

#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#include <iostream>
using namespace std;

int main(int argc, char** argv) {
	int n, v, cost = 0;
	cin >> n >> v; // 도시 개수, 자동차 연료탱크 크기

	if (n - 1 <= v) // 도시 개수가 연료 탱크크기보다 작으면
		cost = n - 1; // 도시 개수 - 1 이 정답
	else { // 그렇지 않으면 매 도시마다 연료를 충전하는 것이 이득
		for (int i = 0; i < n - 1 - v; ++i) // 도시 개수 - 연료 탱크크기 만큼 채워야함
			cost += (2 + i); // 첫 도시에서 2 그리고 3, 4..로 채워야하므로
		cost += v; // 처음 연료탱크크기 만큼 채운 것
	}

	cout << cost;

	return 0;
}