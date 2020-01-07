/*
 * 1753. �ִܰ��
 *
 * �ð� ���⵵ : O(E * log(E))
 *
 * dijkstra

 * ���ͽ�Ʈ�� �⺻ ����
 * �� �������� ����׷����� ���� �Ǿ� ���� ��,
 * ���� �������� ����ġ�� ����ؼ� heap�� �ִ´�.
 * ���� ����ġ���� ������ ����ġ�� �����Ѵ�.
 *
 */

 #define fastio() ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
 #include <iostream>
 #include <vector>
 #include <queue>
 using namespace std;
 
 int v, e, s; // ���� ����, ���� ����, ���� ����
 int dist[20001]; // ���� �������� �� ���������� �Ÿ�
 vector<vector<pair<int, int>>> g(20001, vector<pair<int, int>>());
 
 void dijkstra(int s) { // ���� ����
 	dist[s] = 0; // ���� ������ ����ġ 0
 	priority_queue<pair<int, int>> q; // �ٽ� �ڷᱸ��, �⺻������ ��������
 	q.push({ 0, s }); // ����ġ, ����
 
 	while (!q.empty()) {
 		int u = q.top().second;
 		int c = -q.top().first; // ���� ����ġ�� ���ؼ� �ְ� ����
 		q.pop();
 
 		if (dist[u] < c) // ����ġ�� ���ŵǾ� �������� ������ �������� ����
 			continue;
 
 		for (int i = 0, v, w; i < g[u].size(); ++i) {
 			v = g[u][i].second; // ���� ����
 			w = g[u][i].first + c; // ���� ������ ����ġ�� ���
 			if (dist[v] > w) { // ���� ���� ������ ����ġ���� ���ġ�� ������
 				dist[v] = w;
 				q.push({ -w, v }); // min heap���� �־��ش�.
 			}
 		}
 	}
 }
 
 int main(int argc, char** argv) {
 	fastio();
 	cin >> v >> e >> s;
 
 	for (int i = 0, u, v, w; i < e; ++i) {
 		cin >> u >> v >> w;
 		g[u].push_back({ w, v });
 	}
 
 	for (int i = 0; i <= v; ++i) {
 		dist[i] = 987654321; // ��� ���� �ſ� ���� ������ �ʱ�ȭ
 	}
 
 	dijkstra(s);
 	for (int i = 1; i <= v; ++i) {
 		if (dist[i] == 987654321)
 			cout << "inf" << '\n';
 		else
 			cout << dist[i] << '\n';
 	}
 	return 0;
 }