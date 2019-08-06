/*
 * 14891. ��Ϲ���(���� ���� ã�ư��� ��Ϲ���)
 *
 * �ð����⵵ : O(K)
 *
 * recursion, simulation

 * ������ �߸� �����ϰ� Ǭ �ҽ��̴�.
 * �߸� ������ �ٷδ� ������ ��Ϲ����� ���� �ٸ��ٸ�,
 * ���� ��Ϲ����� �ð�������� ȸ���ϰ� ������ ��Ϲ�����
 * ���� ������ �ٸ��ٸ� ���� ������ ȸ���ؾ��Ѵ�.
 * ���� ������� ��������, ������������ �����Ѵ�.

 * ��� ������ ����� �������� ���ϰ� Ǭ �ҽ�������
 * �ξ� �� �����ϰ� ����ϰ� § �ҽ��� �� ����.
 * �̷� ������ �־ ������ �� ����.
 * 
 *
 */

 #define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
 #include <iostream>
 using namespace std;
 
 int wheel[4][8];
 int LR[4][2];
 
 
 int K, N, C;
 void rotation(int n, int c) { // index�� �ش� �������� ȸ��
 	LR[n - 1][0] = (LR[n - 1][0] + 8 - c) % 8;
 	LR[n - 1][1] = (LR[n - 1][1] + 8 - c) % 8;
 }
 
 void solve(int n, int c, int dir) { // �� : -1 // �� : +1
 	if (n <= 0 || n > 4)
 		return;
 	int p;
 	if (dir == 1)
 		p = 0;
 	else
 		p = 1;
 	int cur = wheel[n - 1][LR[n - 1][p]];
 	int prev = wheel[n - 1 - dir][LR[n - 1 - dir][1 - p]];
 	while (cur != prev) { // ���� ��Ϲ����� �ذ� ���� �� ���� ȸ��
 		rotation(n, c);
 		cur = wheel[n - 1][LR[n - 1][p]]; // ���� ��Ϲ��� �� ����
 	}
 	solve(n + dir, -c, dir); // �����ϴ� �������� ���
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