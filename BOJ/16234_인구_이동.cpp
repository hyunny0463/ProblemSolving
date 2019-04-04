/*
 * 16234. �α� �̵�
 *
 * �ð����⵵ : O(N * N)
 *
 * bfs, implementation
 * �־����� L������ ũ�ų� ���� R������ �۰ų� ���� �� �α� �̵��� ����ȴ�.
 * ������ �������� bfs�� ������ ���ϰ� �� ��հ��� ������ ��ġ�� �ִ´�.
 * ������ �� ��ġ�� �ٷ� ������ ���� �����ϴ� ��ġ���� Ȯ�� �� �� ���� �ٲ�� �����Ƿ�
 * �� ��ġ�� �ٽ� �湮 �� �� �����Ƿ� bd �迭�� ��� �����ϰ� ���� tmp �迭�� �����Ѵ�.
 * ��� �����ϸ� �ٽ� tmp �迭�� ������ bd �迭�� �������ش�.
 * �̰� ���� �ִٺ��� visit���� üũ�ϱ� ������ ���� ���� �ʾƵ� �Ǵ� �κ��� �� ����.
 *
 */

 #define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
 #include <iostream>
 #include <vector>
 #include <queue>
 #include <string.h>
 using namespace std;
 
 int N, L, R;
 int bd[50][50], tmp[50][50];
 bool visit[50][50];
 bool flag = true;
 
 const int dx[] = { 1, 0, -1, 0 };
 const int dy[] = { 0, 1, 0, -1 };
 
 void bfs(int x, int y) {
 	vector<pair<int, int>> v; // �α� �̵��� ����Ǵ� ��ǥ ����
 	queue<pair<int, int>> q;
 	q.push({ x, y });
 	v.push_back({ x, y });
 	visit[y][x] = true;
 	int sum = bd[y][x];
 	while (!q.empty()) {
 		int xx = q.front().first;
 		int yy = q.front().second;
 		q.pop();
 		for (int i = 0; i < 4; ++i) {
 			int cx = xx + dx[i];
 			int cy = yy + dy[i];
 
 			if (cx < 0 || cy < 0 || cx >= N || cy >= N || visit[cy][cx]) // �������
 				continue;
 			if (L <= abs(bd[yy][xx] - bd[cy][cx]) && abs(bd[yy][xx] - bd[cy][cx]) <= R) {
 				q.push({ cx, cy });
 				v.push_back({ cx, cy });
 				visit[cy][cx] = true;
 				sum += bd[cy][cx];
 			}
 		}
 	}
 
 	if (v.size() != 1) { // ��������
 		flag = true;
 		int div = sum / v.size();
 		for (int i = 0; i < v.size(); ++i)
 			tmp[v[i].second][v[i].first] = div;
 	}
 }
 
 
 int main(int argc, char** argv)
 {
 	fastio();
 
 	cin >> N >> L >> R;
 	for (int i = 0; i < N; ++i)
 		for (int j = 0; j < N; ++j)
 			cin >> bd[i][j];
 	memcpy(tmp, bd, sizeof(bd)); // tmp �迭�� bd�� �迭�� �����صΰ�
 	int rslt = 0;
 	while (flag) {
 		flag = false;
 		for (int i = 0; i < N; ++i) {
 			for (int j = 0; j < N; ++j)
 				if (!visit[i][j])
 					bfs(j, i);
 		}
 		rslt++;
 		memcpy(bd, tmp, sizeof(tmp)); // ���� �ٵ� tmp �迭�� �ٽ� bd�迭�� ����
 		memset(visit, false, sizeof(visit));
 	}
 	cout << rslt - 1 << '\n'; // ���������� �ѹ� �� ���鼭 1���� ������ �ִ��� Ȯ���ϱ� ������
 	return 0;
 }