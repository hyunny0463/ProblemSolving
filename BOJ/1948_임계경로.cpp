/*
 * 1948. 임계경로
 *
 * 시간 복잡도 : O(V + E)
 *
 * topological sort

 * 위상정렬을 사용한다.
 * 처음 데이터를 입력 받을 때, 도착노드에 의해 진입차수를 계산한다.
 * 문제에서 주어진 마지막에 도착하는 사람의 도착시간은
 * getMaxDist 함수에 의해 가장 최대의 가중치 값으로 얻을 수 있다.
 * 또한 사용되는 도로의 개수를 알아 내기 위해 getUsedRoad 함수로
 * 방문 체크하면서 가중치로 도로를 알아냈다. 
 *
 */


#define fastio() ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

int N, M;
int ind[10001]; // 진입차수
int dist[10001]; // 거리를 나타냄
int visit[10001]; // 사용되는 도로를 셀 때 사용
vector<pair<int, int>> in[10001]; // 주어진 방향 그래프의 정보
vector<pair<int, int>> out[10001]; // 주어진 방향 반대 그래프 정보

int getMaxDist(int s, int e) { // 출발노드, 도착노드
	queue<int> q;
	q.push(s); // 첫 노드 인덱스

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int i = 0, nx, w; i < in[x].size(); ++i) {
			nx = in[x][i].second; // 연결된 다음 노드
			w = in[x][i].first; // 연결된 다음 노드 가중치
			dist[nx] = dist[nx] > dist[x] + w ? dist[nx] : dist[x] + w; // 다음 노드 가중치는 최대값

			if (!(--ind[nx])) // 진입차수가 0 이면 queue에 삽입
				q.push(nx);
		}
	}
	return dist[e]; // 가장 오래동안 사용되는 거리를 반환
}

int getUsedRoad(int s) {
	int ret = 0; // 사용된 도로의 개수, 반환할 값
	queue<int> q;
	q.push(s);

	while (!q.empty()) {
		int x = q.front();
		int w = dist[x];
		q.pop();

		for (int i = 0, nx, nw; i < out[x].size(); ++i) {
			nx = out[x][i].second; // 다음 노드의 번호
			nw = out[x][i].first; // 다음 노드의 가중치
			if (w == nw + dist[nx]) {
				ret++; // 도로 개수 증가
				if (!visit[nx]) { // visit 체크
					visit[nx]++;
					q.push(nx);
				}
			}
		}
	}
	return ret;
}

int main(int argc, char** argv) {
	fastio();
	memset(ind, 0, sizeof(ind));
	memset(dist, 0, sizeof(dist));
	memset(visit, 0, sizeof(visit));
	cin >> N >> M;

	for (int i = 0, depart, arrival, taken_time; i < M; ++i) {
		cin >> depart >> arrival >> taken_time;
		in[depart].push_back({ taken_time, arrival }); // 출발노드, 걸리는 시간, 도착노드
		ind[arrival]++; // 진입차수 계산
		out[arrival].push_back({ taken_time, depart }); // 도착노드, 거리는 시간, 출발노드
	}
	int s, e; // 출발노드, 도착노드
	cin >> s >> e;
	cout << getMaxDist(s, e) << '\n';
	cout << getUsedRoad(e) << '\n';

	return 0;
}