/*
 * 1920. 수 찾기
 *
 * 시간복잡도 : O( N * log(N) + M * log(N) )
 *
 * binary search

 * N개의 정수가 주어지고, M개의 정수가 주어졌으며
 * M개의 정수에 해당 하는 값들이 N개의 정수에 있을 때,
 * 1 아니면 0을 출력하는 문제이다.
 
 * 정렬을 하는데 걸리는 시간 복잡도는 N * log(N)
 * M 개의 배열이 N 개의 배열에 있는지 확인하기 때문에 M * log(N)
 * 기본적인 이진탐색을 사용하는 문제이다.
 * 주어진 배열의 크기가 10만개 이므로 단순히 접근하기보다
 * 이분탐색을 바로 생각해내는 것이 필요할 것 같다.
 *
 */

#define fastio() ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#include <iostream>
#include <algorithm>

using namespace std;

int A[100001]; // N 개의 정수를 저장할 배열
int B[100001]; // M 개의 정수를 저장할 배열

int bsearch(int x, int s, int e) { // 찾을 값, 이진탐색 범위 처음, 끝
	int h = (s + e) / 2;
	if (x == A[h]) // 중간값이 존재한다면
		return 1;
	if (s == e) // 그렇지 않고 범위 처음과 끝이 만난다면 종료
		return 0;

	// return이 한번이라도 된다면 종료되도록 함
	if (x <= A[h])
		if (bsearch(x, s, h))
			return 1;
	if (x > A[h])
		if (bsearch(x, h + 1, e))
			return 1;
	return 0;
}

int main(int argc, char** argv) {
	fastio();

	int N, M;
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> A[i];
	sort(A, A + N); // 이진탐색을 하기 위해 정렬
	cin >> M;
	for (int i = 0; i < M; ++i)
		cin >> B[i];
	for (int i = 0; i < M; ++i)
		cout << bsearch(B[i], 0, N - 1) << '\n';

	return 0;
}