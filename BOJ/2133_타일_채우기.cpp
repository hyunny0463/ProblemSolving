/*
 * 2133. 타일 채우기
 *
 * 시간복잡도 : O(8 * N)
 *
 * state dynamic programming

 * 현재 위치에서 타일을 놓을 수 있는 경우의 수를 생각한다.
 * 놓을 수 있는 타일의 경우는 이전 타일의 상태에 따라 결정된다.
 * 그리고 현재 타일의 상태는 반드시 가득 채워져야 한다.

 * 타일의 상태는 이진수 표기법으로 표현한다.
 * 현재 위치에서 [0]이 되려면, 이전 타일은 가득 차 있는 [7]만 올 수 있다.
 * 현재 위치에서 [1]이 되려면, 이전 타일은 [6] 이 올 수 있다.
 * 현재 위치에서 [2]가 되려면, 이전 타일은 [5] 가 올 수 있다.
 * 현재 위치에서 [3]이 되려면, 이전 타일은 가득 차 있는 [7] 또는 [4]가 올 수 있다.
 *                                                     ■│       ━━
 *                                                     ■│  or   ━━
 *                                                     ■ㅁ       ■
 * 현재 위치에서 [4]가 되려면, 이전 타일은 [3] 이 올 수 있다.
 * 현재 위치에서 [5]가 되려면, 이전 타일은 [2] 이 올 수 있다.
 * 현재 위치에서 [6]이 되려면, 이전 타일은 [1], [7] 이 올 수 있다.
 * 현재 위치에서 [7]이 되려면, 이전 타일은 [0], [3], [6] 이 올 수 있다.
 *
 */

#define fastio() ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#include <iostream>
using namespace std;

int main(int argc, char** argv) {
	int N;
	int m[8][30] = { 0, };
	cin >> N;
	m[7][0] = 1;
	for (int i = 1; i <= N; ++i) {
		m[0][i] = m[7][i - 1];
		m[1][i] = m[6][i - 1];
		m[2][i] = m[5][i - 1];
		m[3][i] = m[4][i - 1] + m[7][i - 1];
		m[4][i] = m[3][i - 1];
		m[5][i] = m[2][i - 1];
		m[6][i] = m[1][i - 1] + m[7][i - 1];
		m[7][i] = m[0][i - 1] + m[3][i - 1] + m[6][i - 1];
	}
	cout << m[7][N];

	return 0;
}

