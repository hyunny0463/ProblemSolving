/*
 * 3289. 서로소 집합
 *
 * 시간복잡도 : O(1) < x < O(m*log(n)) --> O(α(n))

 * union-find, disjoint set
 * 유니온 파인드의 기본적인 구현이다.
 * find 함수는 부모를 찾고 그 부모로 자식을 모두 초기화하는
 * 최적화 과정을 가지고 있다.
 * union 함수는 b의 부모를 a로 정해주는 것으로 끝난다.

 * 더 최적화 하기 위해서는 어떤 부모의
 * 깊이가 더 깊은지 확인하고 큰 부모에게 작은 부모 노드를
 * 병합하는 과정이 추가되어야 한다.
 *
 */

#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
using namespace std;

int T;
int s[1000001];

int my_find(int n) {
	if (s[n] == n) // 부모가 자기 자신이면
		return s[n];
	s[n] = my_find(s[n]); // 다음번에 빠르게 찾도록 최적화
	return s[n];
}

void my_union(int a, int b) {
	s[b] = a;
}

int main(int argc, char** argv) {
	fastio();
	cin >> T;
	for (int test_case = 1, n, m; test_case <= T; ++test_case) {
		cin >> n >> m; // 배열의 크기, 연산 횟수

		for (int i = 0; i <= n; ++i) // disjoint set 초기화
			s[i] = i;

		cout << "#" << test_case << ' ';
		for (int i = 0, op, a, b; i < m; ++i) {
			cin >> op >> a >> b;
			a = my_find(a);
			b = my_find(b);

			if (op) { // 출력하는 연산
				if (a == b)
					cout << 1;
				else
					cout << 0;
			}
			else // 출력하는 연산
				my_union(a, b);
		}
		cout << '\n';
	}
	return 0;
}