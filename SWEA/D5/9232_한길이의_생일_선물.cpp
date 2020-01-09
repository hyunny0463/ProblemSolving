/*
 * 9232. 한길이의 생일 선물
 *
 * 시간복잡도 : O(N)
 *
 * brute-force

 * 지름이 제각각인 놀이세트에 디스크를 위에서부터 넣는다.
 * 디스크을 넣지 못하면 0, 그렇지 않으면
 * 가장 높은 디스크의 위치를 반환하는 문제이다.

 * 문제 해결의 핵심은 놀이세트의 너비를 입력받으면서
 * 입력받은 최소의 너비로 각층의 너비를 선택한다.
 * 그리고나서 아래서부터 디스크를 넣는다.
 *
 */

#define fastio() ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#include <iostream>
using namespace std;

int D, N; // 오븐 깊이, 피자 반죽 개수
int oven[300001];
int piza[300001];

int main(int argc, char** argv) {
	fastio();
	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; ++test_case) {
		cin >> D >> N;
		oven[0] = 1000000000; // 최대의 지름으로 초기화
		for (int i = 1; i <= D; ++i) {
			cin >> oven[i]; // 오븐 너비를 가장 작은 값으로 세팅
			oven[i] = oven[i] < oven[i - 1] ? oven[i] : oven[i - 1];
		}

		for (int i = 0; i < N; ++i)
			cin >> piza[i];

		int idx = 0;
		for (int i = D; i > 0; --i) {
			if (piza[idx] > oven[i])
				continue;
			idx++;
			if (idx >= N) {
				cout << "#" << test_case << ' ' << i << '\n';
				break;
			}
		}

		if (idx < N)
			cout << "#" << test_case << ' ' << 0 << '\n';
	}
	
	return 0;
}