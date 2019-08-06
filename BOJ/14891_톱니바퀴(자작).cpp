/*
 * 14891. 톱니바퀴(같은 극을 찾아가는 톱니바퀴)
 *
 * 시간복잡도 : O(K)
 *
 * recursion, simulation

 * 문제를 잘못 이해하고 푼 소스이다.
 * 잘못 이해한 바로는 인접한 톱니바퀴의 극이 다르다면,
 * 왼쪽 톱니바퀴가 시계방향으로 회전하고 오른쪽 톱니바퀴의
 * 극이 여전히 다르다면 같을 때까지 회전해야한다.
 * 같은 방식으로 좌측방향, 우측방향으로 진행한다.

 * 비록 문제를 제대로 이해하지 못하고 푼 소스이지만
 * 훨씬 더 간결하고 깔끔하게 짠 소스인 것 같다.
 * 이런 문제가 있어도 괜찮을 것 같다.
 * 
 *
 */

 #define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
 #include <iostream>
 using namespace std;
 
 int wheel[4][8];
 int LR[4][2];
 
 
 int K, N, C;
 void rotation(int n, int c) { // index를 해당 방향으로 회전
 	LR[n - 1][0] = (LR[n - 1][0] + 8 - c) % 8;
 	LR[n - 1][1] = (LR[n - 1][1] + 8 - c) % 8;
 }
 
 void solve(int n, int c, int dir) { // 좌 : -1 // 우 : +1
 	if (n <= 0 || n > 4)
 		return;
 	int p;
 	if (dir == 1)
 		p = 0;
 	else
 		p = 1;
 	int cur = wheel[n - 1][LR[n - 1][p]];
 	int prev = wheel[n - 1 - dir][LR[n - 1 - dir][1 - p]];
 	while (cur != prev) { // 이전 톱니바퀴의 극과 같을 때 까지 회전
 		rotation(n, c);
 		cur = wheel[n - 1][LR[n - 1][p]]; // 현재 톱니바퀴 극 갱신
 	}
 	solve(n + dir, -c, dir); // 진행하던 방향으로 재귀
 }
 
 int main(int argc, char** argv) {
 
 	for (int i = 0; i < 4; ++i) {
 		for (int j = 0; j < 8; ++j) {
 			char tmp;
 			cin >> tmp;
 			wheel[i][j] = tmp - '0';
 		}
 	}
 
 	for (int i = 0; i < 4; ++i) {
 		LR[i][0] = 6;
 		LR[i][1] = 2;
 	}
 	cin >> K;
 	for (int i = 0; i < K; ++i) {
 		cin >> N >> C;
 		rotation(N, C);
 		solve(N + 1, -C, +1);
 		solve(N - 1, -C, -1);
 	}
 
 	int rslt = 0;
 	for (int i = 0; i < 4; ++i)
 		if (wheel[i][(LR[i][0] + 2) % 8])
 			rslt += (1 << i);
 	cout << rslt << '\n';
 
 	return 0;
 }