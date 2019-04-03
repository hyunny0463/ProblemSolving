/*
 * 1227. �̷�2
 *
 * �ð����⵵ : O(N * N)
 *
 * bfs
 * �̷� 1������ �迭�� ũ�� �ܿ� ��� ����
 * bfs�� �̿��Ͽ� ���������κ��� ��� ���� ������ �������� ����Ž���� �Ѵ�.
 * ���������� ������ ��� flag�� ������ ������ְ� �׷��� �ʴٸ� �����̴�.
 * bfs�� ���� �⺻���� ���·� �ذ� �����ϴ�.
 *
 */

 #define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
 #include <iostream>
 #include <vector>
 #include <queue>
 using namespace std;
 
 const int dx[] = { 1, 0, -1, 0 };
 const int dy[] = { 0, 1, 0, -1 };
 
 
 int main(int argc, char** argv)
 {
 	fastio();
 
 	for (int testcase = 0, T; testcase < 10; ++testcase) {
 		char bd[100][100] = { 0 };
 		bool visit[100][100] = { false };
 		bool flag = false;
 		cin >> T;
 		pair<int, int> st, en;
 		for (int i = 0; i < 100; ++i) {
 			for (int j = 0; j < 100; ++j) {
 				cin >> bd[i][j];
 				if (bd[i][j] == '2') // ������ ����
 					st = { j, i };
 			}
 		}
		// BFS
 		queue<pair<int, int>> q;
 		q.push(st);
 		visit[q.front().second][q.front().first] = true;
 		while (!q.empty()) {
 			int x = q.front().first;
 			int y = q.front().second;
 			q.pop();
 			for (int i = 0; i < 4; ++i) {
 				int xx = x + dx[i];
 				int yy = y + dy[i];
 
 				if (bd[yy][xx] == '3') // ������ ����
 					flag = true;
 				if (visit[yy][xx] || bd[yy][xx] == '1') // �̹� �湮�߰ų� ���� ���
 					continue;
 				q.push({ xx, yy }); // �� �ܿ��� queue�� �����Ѵ�
 				visit[yy][xx] = true; // �湮 ǥ��
 			}
 		}
 		cout << '#' << T << ' ' << flag << '\n';
 	}
 	return 0;
 }