/*
 * 3190. ��
 *
 * �ð����⵵ : O(N * L)
 *
 * ���� �̵��� ��Ÿ���� ���ؼ� deque�� ����ߴ�.
 * �־��� �������� �̵��� �ϰ� �� ������ �� �����̶��
 * �� �ڸ��� deque�� �� �ڿ� �־��ְ�, �����κ��� pop �ϴ� ������� �̵��Ͽ���.
 * ����� ������ ������ pop ���� �ʱ⸸ �ϸ� �ȴ�.

 * �ܼ��� �̵��� ���ؼ��� �����ϴٰ�, ������ ����Ǵ� ������
 * ����� �ľ����� ���ߴ�. �־��� ���� ��ȯ ������ ������ ����ȴٸ�
 * �� ���� �ð��� ����ϸ� �Ǿ�����, �ð� ���� ������ �ʾ��� ��,
 * ������ ũ�⸸ŭ �� ������ ������ �����ϴ� ������ �߰������ν� �ذ��� �� �־���.
 *
 */

 #define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
 #include <iostream>
 #include <deque>
 using namespace std;
 
 int N, K, L; // ����ũ��, ����� ����, ���� ���� ��ȯ Ƚ��
 int time, dir; // ������� ���� �ð�, ���� �ٶ󺸴� ����
 int bd[102][102];
 bool flag = false;
 deque<pair<int, int>> dq;
 pair<int, int> pos;
 
 const int dx[] = { 1, 0, -1, 0 };
 const int dy[] = { 0, 1, 0, -1 };
 
 bool movesnake(int X, char C) {
 	while (time < X) {
 		time++;
 		pos.first += dx[dir];
 		pos.second += dy[dir];
 		dq.push_back(pos);
 		if (!bd[pos.second][pos.first]) { // ���� ������ �ڸ��� �ƹ��͵� ������
 			bd[dq.front().second][dq.front().first] = 0; // �ʿ��� �� ���� �� ĭ ����
 			dq.pop_front(); // dq���� ����
 		}
 		else if (bd[pos.second][pos.first] == 2) { // ���� ���� �����ų� �ڱ� ������ ������ 
 			flag = true; // ���� �÷��׸� ������ ����
 			return 0; // �� ������ �� false�� ����
 		}
 		bd[pos.second][pos.first] = 2; // ������ �� �Ӹ� ǥ��
 	}
 	dir = (C == 'D') ? (dir + 1) % 4 : (dir + 3) % 4; // D �̸� ������, L �̸� �������� ȸ��
 	return 1; // �� �ȸ����� �� true�� ����
 }
 
 int main(int argc, char** argv) {
 
 	cin >> N >> K; // ���� ũ��, ����� ����
 	for (int i = 0; i <= N + 1; ++i) {
 		for (int j = 0; j <= N + 1; ++j) {
 			if (i == 0 || j == 0 || i == N + 1 || j == N + 1) // ���� ���
 				bd[i][j] = 2;
 			else
 				bd[i][j] = 0;
 		}
 	}
 	time = 0, dir = 0;
 	pos = { 1, 1 }; // ó�� ������
 	dq.push_back(pos); // ù �������� dq�� ����
 	bd[pos.second][pos.first] = 2; // ���� ��ġ�� �ڸ��� 2�� ǥ��
 	for (int i = 0, r, c; i < K; ++i) {
 		cin >> r >> c;
 		bd[r][c] = 1; // ��� ��ġ�� 1�� ����
 	}
 	cin >> L;
 	for (int i = 0; i < L; ++i) {
 		int X;
 		char C;
 		cin >> X >> C;
 		if (!movesnake(X, C)) {
 			flag = true;
 			break;
 		}
 	}
 	while (!flag) // �Է� ���� ������ȯ�� ���ص� ������ �ȳ����� ���� ũ�⸸ŭ �ð����� �� ����
 		movesnake(time + N, 0);
 
 	cout << time << '\n'; // �ð� ���
 
 	return 0;
 }