/*
 * 15649. N과 M (1)
 *
 * 시간복잡도 : O(nPm)
 *
 * permutaion
 
 * 기본적인 순열 구현
 * N개의 숫자에서 M개의 모든 숫자의 경우를 출력한다.
 *
 */

#define fastio() ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#include <iostream>
using namespace std;

int N, M; // 자연수 크기, 선택할 개수
int t[8] = { 0 }; // 수열 저장하는 배열
int c[9] = { 0 }; // 선택되었는지 확인하는 배열

void dfs(int d) { // 깊이
	if (d == M) { // 깊이가 선택할 개수와 같으면 출력 후 종료
		for (int i = 0; i < d; ++i)
			cout << t[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = 1; i <= N; ++i) { // 순열이므로 처음부터 시작
		if (!c[i]) { // 같은 숫자는 출력하면 안되므로
			t[d] = i;
			c[i] = 1; // visit checked
			dfs(d + 1);
			c[i] = 0; // visit un-checked
		}
	}
}

int main(int argc, char** argv) {
	fastio();
	cin >> N >> M; // 자연수 N까지 M개 선택

	dfs(0);

	return 0;
}