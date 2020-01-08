/*
 * 1756. 피자 굽기
 *
 * 시간복잡도 : O(N)
 *
 * brute-force

 * 지름이 제각각인 오븐에 피자 반죽을 위에서부터 넣는다.
 * 피자 반죽을 넣지 못하면 0, 그렇지 않으면
 * 가장 높은 반죽의 위치를 반환하는 문제이다.

 * 문제 해결의 핵심은 오븐의 너비를 입력받으면서
 * 위에서 입력받은 너비보다 더 넓으면 최소의 너비를 선택하고
 * 점점 줄어드는 오븐을 가정하는 것이다.
 * 이런 형태의 배열을 만들어 놓고나서
 * 피자를 아래쪽부터 위치시킬 수 있으면 위치시킨다.

 * 오븐의 지름을 내림차순으로 만드는 것은 똑같으나
 * 이진탐색을 써서 문제를 해결하는 방법도 있다.
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
	cin >> D >> N;
	oven[0] = 1000000000; // 최대의 지름으로 초기화
	for (int i = 1; i <= D; ++i) {
		cin >> oven[i]; // 오븐 너비를 가장 작은 값으로 세팅
		oven[i] = oven[i] < oven[i - 1] ? oven[i] : oven[i - 1];
	}

	for (int i = 0; i < N; ++i)
		cin >> piza[i];

	int idx;
	for (idx = 1; idx <= D; ++idx) {
		if (oven[idx] < piza[0]) { // 첫 피자가 들어갈 위치를 찾음
			idx--;
			break;
		}
	}

	for (int i = 0; i < N; ++i) {
		if (idx <= 0) // 피자 반죽을 다 넣기전에 idx가 0이 되면
			break; // 0을 출력
		while (oven[idx] < piza[i]) // 오븐이 피자보다 작다면
			idx--; // 지름이 더 넓은 오븐으로 올라간다
		idx--; // 반죽을 넣은 것을 의미
		if (i == N - 1) // 모든 반죽을 넣었다면
			idx++; // 반죽의 위치를 반환
	}

	if (idx <= 0)
		cout << 0 << '\n';
	else
		cout << idx << '\n';

	return 0;
}