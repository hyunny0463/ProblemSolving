/*
 * 1753. 최단경로
 *
 * 시간 복잡도 : O(E * log(E))
 *
 * dijkstra

 * 다익스트라 기본 구현
 * 각 정점까지 방향그래프로 연결 되어 있을 때,
 * 시작 정점부터 가중치를 계산해서 heap에 넣는다.
 * 작은 가중치부터 꺼내서 가중치를 갱신한다.
 *
 */

 #define fastio() ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
 #include <iostream>
 #include <vector>
 #include <queue>
 using namespace std;
 
 int v, e, s; // 정점 개수, 간선 개수, 시작 정점
 int dist[20001]; // 시작 정점에서 각 정점까지의 거리
 vector<vector<pair<int, int>>> g(20001, vector<pair<int, int>>());
 
 void dijkstra(int s) { // 시작 정점
 	dist[s] = 0; // 시작 정점은 가중치 0
 	priority_queue<pair<int, int>> q; // 핵심 자료구조, 기본적으로 내림차순
 	q.push({ 0, s }); // 가중치, 정점
 
 	while (!q.empty()) {
 		int u = q.top().second;
 		int c = -q.top().first; // 음수 가중치를 곱해서 넣고 뺀다
 		q.pop();
 
 		if (dist[u] < c) // 가중치가 갱신되어 기존보다 작으면 실행하지 않음
 			continue;
 
 		for (int i = 0, v, w; i < g[u].size(); ++i) {
 			v = g[u][i].second; // 다음 정점
 			w = g[u][i].first + c; // 다음 정점의 가중치를 계산
 			if (dist[v] > w) { // 기존 다음 정점의 가중치보다 계산치가 작으면
 				dist[v] = w;
 				q.push({ -w, v }); // min heap으로 넣어준다.
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
 		dist[i] = 987654321; // 모든 정점 매우 높은 값으로 초기화
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