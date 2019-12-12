/*
 * 1803. Shortest Path Faster
 *
 * �ð����⵵ : O( (E + V)log(V) )
 
 * dijkstra, heap
 * ���� �̿��� ���ͽ�Ʈ���̴�.
 * ��������� �����ؼ� �� ������ �̵��ϴ� �ּҰŸ��� dist�� �����Ѵ�.
 * ���� ������ ���� ���� ��忡 �� ª�� �����ϴ� ��带 ���� Ȯ���ϹǷ�,
 * ���� ���� �ٽ� Ȯ������ �ʵ���
 * �ش� ��忡 ������ ����ġ�� �� Ŭ �� �Ѿ�� �ڵ带 �߰������.

 * SWEA���� ��� �ð� �ʰ��� ���µ� ������ fastio()�� ���� �ʾƼ�����.
 * dist�� ��쿡�� �迭�� ����ϰ� memset�� ����ϴ°� ���� �� ������.
 * g�� ��쿡�� clear, resize ���� �Ʒ� ����� ���� �� ������.
 *
 */

#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int T, N, M, S, E;
vector<vector<pair<int, int>>> g; // ��尣 ���踦 ����(����)
vector<long long> dist; // �ε��� ��ȣ���� �ִ� ��� ����

void dijkstra(int st) { // ��߳��
	priority_queue<pair<int, int>> pq;
	pq.push({0, st}); // ����ġ, ����ȣ
	dist[st] = 0;

	while (!pq.empty()) {
		long long int wf = -pq.top().first; // min heap �̹Ƿ�
		int fr = pq.top().second; // from ���
		pq.pop();

		if (dist[fr] < wf) // �ش����� ����ġ�� ���� �Ÿ����� ũ�� �Ѿ
			continue;

		for (int i = 0; i < g[fr].size(); ++i) {
			long long int wt = g[fr][i].first;
			int to = g[fr][i].second;

			if (dist[to] > dist[fr] + wt) { // ���� ��� > ������ + ����ġ
				dist[to] = dist[fr] + wt;
				pq.push({ -dist[to], to }); // min heap���� �������
			}
		}
	}
}

int main(int argc, char** argv) {
	fastio();
	cin >> T;
	for (int test_case = 1; test_case <= T; ++test_case) {
		cin >> N >> M >> S >> E;
		
		g = vector<vector<pair<int, int>>>(N + 1);
		dist = vector<long long>(N + 1, 1e18);

		for (int i = 0, s, e, w; i < M; ++i) {
			cin >> s >> e >> w;
			g[s].push_back({ w, e }); // �����⼺ �׷���
			g[e].push_back({ w, s }); // �����⼺ �׷���
		}
		dijkstra(S);
		cout << "#" << test_case << ' ' << dist[E] << '\n';
	}


	return 0;
}