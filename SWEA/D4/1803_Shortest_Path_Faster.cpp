/*
 * 1803. Shortest Path Faster
 *
 * 시간복잡도 : O( (E + V)log(V) )
 
 * dijkstra, heap
 * 힙을 이용한 다익스트라이다.
 * 출발점부터 시작해서 각 노드까지 이동하는 최소거리를 dist에 저장한다.
 * 힙의 성질에 의해 같은 노드에 더 짧게 도착하는 노드를 먼저 확인하므로,
 * 같은 점을 다시 확인하지 않도록
 * 해당 노드에 저장한 가중치가 더 클 때 넘어가는 코드를 추가해줬다.

 * SWEA에서 계속 시간 초과가 났는데 문제는 fastio()를 쓰지 않아서였다.
 * dist의 경우에는 배열을 사용하고 memset을 사용하는게 조금 더 빠르다.
 * g의 경우에는 clear, resize 보다 아래 방법이 조금 더 빠르다.
 *
 */

#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int T, N, M, S, E;
vector<vector<pair<int, int>>> g; // 노드간 관계를 저장(간선)
vector<long long> dist; // 인덱스 번호까지 최단 경로 저장

void dijkstra(int st) { // 출발노드
	priority_queue<pair<int, int>> pq;
	pq.push({0, st}); // 가중치, 노드번호
	dist[st] = 0;

	while (!pq.empty()) {
		long long int wf = -pq.top().first; // min heap 이므로
		int fr = pq.top().second; // from 노드
		pq.pop();

		if (dist[fr] < wf) // 해당노드의 가중치가 기존 거리보다 크면 넘어감
			continue;

		for (int i = 0; i < g[fr].size(); ++i) {
			long long int wt = g[fr][i].first;
			int to = g[fr][i].second;

			if (dist[to] > dist[fr] + wt) { // 다음 노드 > 현재노드 + 가중치
				dist[to] = dist[fr] + wt;
				pq.push({ -dist[to], to }); // min heap으로 만들어줌
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
			g[s].push_back({ w, e }); // 무방향성 그래프
			g[e].push_back({ w, s }); // 무방향성 그래프
		}
		dijkstra(S);
		cout << "#" << test_case << ' ' << dist[E] << '\n';
	}


	return 0;
}