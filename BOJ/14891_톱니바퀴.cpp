/*
 * 14891. 톱니바퀴
 *
 * 시간복잡도 : O(K)
 *
 * recursion, simulation

 * 입력으로 톱니바퀴의 정보가 주어지면,
 * chkrot 함수로 각각의 톱니바퀴가 연쇄적으로 회전가능한지 확인한다.
 * 입력에 따라 톱니바퀴를 rotation 함수로 해당 방향으로 회전시키고,
 * 좌, 우를 재귀적으로 넘어가면서 회전가능하다면 회전하고
 * 그 다음을 확인하는 방법으로 문제를 해결했다.

 * 문제를 처음 제대로 이해하지 못하고 더 어렵게 생각했다.
 * 극이 다르면 반대방향으로 같을 때 까지 톱니바퀴를 회전시키고
 * 그에 따라 연쇄적으로 모든 톱니바퀴를 회전시키는 문제라 생각해서 틀렸다.
 * chk 배열은 쓸 데없이 낭비했지만 매우 작은 크기라 무시하겠다.
 *
 */

#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#include <iostream>
using namespace std;

int wheel[5][8]; // 톱니바퀴의 극 정보를 저장
int LR[5][2]; // 톱니바퀴의 좌우의 인덱스를 가리킴
int chk[4][5]; // 낭비가 있지만 좌, 우 톱니바퀴의 극 상태를 나타냄


int K, N, C;
void rotation(int n, int c) { // 주어진 n 톱니바퀴를 c 방향으로 회전함
	LR[n][0] = (LR[n][0] + 8 - c) % 8;
	LR[n][1] = (LR[n][1] + 8 - c) % 8;
}

void chkrot() { // 모든 톱니바퀴 간의 극성을 알아내는 함수
	for (int i = 1; i < 4; ++i)
		chk[i][i + 1] = (wheel[i][LR[i][1]] == wheel[i + 1][LR[i + 1][0]]) ? 0 : 1;
} // ex) chk[0][1]이면 왼쪽 톱니바퀴와 오른쪽 톱니바퀴의 극성이 같으면 0 그렇지 않으면 1로 세팅

void solve(int n, int c) {
	if (chk[n][n + 1]) { // 오른쪽 톱니바퀴가 다른 극이면
		rotation(n + 1, c); // main에서 -c로 넘겨줬기 때문
		chk[n][n + 1] = 0; // 회전했으므로 0으로 set
		solve(n + 1, -c); // 오른쪽 톱니바퀴로 이동, 반대 방향
	}
	if (chk[n - 1][n]) { // 왼쪽 톱니바퀴가 다른 극이면
		rotation(n - 1, c); // 왼쪽 톱니바퀴 회전
		chk[n - 1][n] = 0; // 회전했으므로 0으로 set
		solve(n - 1, -c); // 왼쪽 톱니바퀴로 이동, 반대방향
	}
}

int main(int argc, char** argv) {
	fastio();
	for (int i = 0; i < 4; ++i) { // 4개의 톱니바퀴
		for (int j = 0; j < 8; ++j) { // 8개의 극
			char tmp;
			cin >> tmp; // 문자로 받고 숫자로 저장함
			wheel[i + 1][j] = tmp - '0'; // 톱니바퀴 번호에 맞게 저장
		}
	}

	for (int i = 1; i <= 4; ++i) { // 각 톱니바퀴의 기준점을 정함
		LR[i][0] = 6; // 톱니바퀴의 왼쪽을 가리키는 인덱스
		LR[i][1] = 2; // 톱니바퀴의 오른쪽을 가리키는 인덱스
	}

	cin >> K;
	for (int i = 0; i < K; ++i) {
		chkrot(); // 회전하기전에 톱니바퀴 간의 상태를 체크
		cin >> N >> C; // 톱니바퀴, 회전방향(1: 시계방향, -1:반시계방향)
		rotation(N, C); // 해당 톱니바퀴 회전
		solve(N, -C); // N 톱니바퀴 기준으로 좌, 우를 주어진 반대방향으로 회전시킴
	}

	int rslt = 0;
	for (int i = 0; i < 4; ++i)
		if (wheel[i + 1][(LR[i + 1][0] + 2) % 8]) // 톱니바퀴의 12시 방향이 S극인지 확인
			rslt += (1 << i); // 각 톱니바퀴마다 2의 배수임
	cout << rslt << '\n';

	return 0;
}