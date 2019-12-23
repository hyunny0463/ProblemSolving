/*
 * 3064. Binary Indexed Tree
 *
 * 시간복잡도 : O(M * log(N))

 * fenwick tree, binary indexed tree(BIT)
 * 구간 합을 구하는 기본적인 펜윅트리 구현이다.
 * 데이터를 입력 받을 때 부터 n, t 배열을 업데이트 한다.
 * 업데이트는 해당 인덱스부터 최대 크기 배열까지 더해주며,
 * 인덱스의 마지막 비트 값을 더해주면서 올라간다.
 * 합을 구하는 함수는 해당 인덱스부터 마지막 비트를 빼면서
 * 5인 경우 1001 이므로 t[5] + t[4]를 하여 합을 구한다.
 *
 */

#include <iostream>
#include <string.h>
using namespace std;

int T, N, M;
int n[100001];
long long int t[100001];

long long int sum(int idx) { // 인덱스까지의 합
	long long int ret = 0;
	while (idx > 0) { // 종료조건
		ret += t[idx];
		idx -= (idx & -idx); // 인덱스를 나타낸 2진수에서 마지막 값을 뺌
	}
	return ret;
}

void update(int idx, int diff) { // 인덱스, 더할 값
	while (idx <= N) {
		t[idx] += diff; // 매 업데이트된 인덱스에 값을 더해줌
		idx += (idx & -idx); // 마지막 비트 값을 더해줌
	}
}

int main(int argc, char** argv) {
	freopen("sample_input.txt", "r", stdin);
	scanf(" %d", &T);
	for (int test_case = 1; test_case <= T; ++test_case) {
		scanf(" %d %d", &N, &M);
		memset(t, 0, sizeof(t));
		for (int i = 1; i <= N; ++i) {
			scanf(" %d", &n[i]);
			update(i, n[i]); // t배열의 초기화를 위해서 입력마다 업데이트
		}

		printf("#%d ", test_case);
		for (int i = 0, c, a, b; i < M; ++i) {
			scanf(" %d %d %d", &c, &a, &b);

			if (c & 1) { // 1일 때, a번째 수에 b값을 더함
				n[a] += b; // 실질적으로는 필요없음
				update(a, b); // 
			}
			else { // 2일 때, a번째 수부터 b번째 수까지 합을 계산
				printf("%lld ", sum(b) - sum(a - 1));
			}
		}
		printf("\n");
	}

	return 0;
}