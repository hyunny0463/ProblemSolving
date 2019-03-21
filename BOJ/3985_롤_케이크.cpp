/*
 * 3985. 롤 케이크
 *
 * 시간복잡도 : O(N * L)
 *
 * 많이 가져갈 것으로 기대하는 사람의 케이크 수와 번호는
 * 단순히 입력 받은 값으로 큰지 작은지만 판별해서 확인가능
 * 실제로 많이 가져가는 사람의 케이크 수와 번호는
 * 해당 케이크가 선점되었는지 확인하면서 카운트하여 이전 값보다 큰지 작은지 판별
 *
 */

#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	int L, N;
	int greedyman = 0, pigman = 0; // 많이 가져갈 것을 기대하는 사람, 많이 가져가는 사람
	int greedycnt = 0, pigcnt = 0; // 많이 가져갈 것을 기대하는 사람 번호, 많이 가져가는 사람 번호
	int cake[1001] = { 0 }; // 가져간 케이크인지 확인

	cin >> L >> N; // 롤케이크 길이, 방청객의 수
	for (int i = 1, P, K; i <= N; ++i) {
		cin >> P >> K; // 방청객이 원하는 첫 케이크 번호, 마지막 케이크 번호

		if (K - P + 1 > greedycnt) {
			greedycnt = K - P + 1; // 많이 가져갈 것을 기대하는 방청객의 케이크 수
			greedyman = i; // 많이 가져갈 것을 기대하는 방청객 번호
		}
		for (int j = P, cnt = 0; j <= K; ++j) {
			if (cake[j]) // 이미 선점한 케이크라면 패스
				continue;
			cake[j] = i;
			cnt++; // 그렇지 않으면 선점
			if (cnt > pigcnt) {
				pigcnt = cnt; // 많이 가져가는 방청객의 케이크 수
				pigman = i; // 많이 가져가는 방청객 번호
			}
		}
	}
	cout << greedyman << '\n' << pigman << '\n';

	return 0;
}