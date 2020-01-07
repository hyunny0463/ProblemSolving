/*
 * 1948. �Ӱ���
 *
 * �ð� ���⵵ : O(V + E)
 *
 * topological sort

 * ���������� ����Ѵ�.
 * ó�� �����͸� �Է� ���� ��, ������忡 ���� ���������� ����Ѵ�.
 * �������� �־��� �������� �����ϴ� ����� �����ð���
 * getMaxDist �Լ��� ���� ���� �ִ��� ����ġ ������ ���� �� �ִ�.
 * ���� ���Ǵ� ������ ������ �˾� ���� ���� getUsedRoad �Լ���
 * �湮 üũ�ϸ鼭 ����ġ�� ���θ� �˾Ƴ´�. 
 *
 */


#define fastio() ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

int N, M;
int ind[10001]; // ��������
int dist[10001]; // �Ÿ��� ��Ÿ��
int visit[10001]; // ���Ǵ� ���θ� �� �� ���
vector<pair<int, int>> in[10001]; // �־��� ���� �׷����� ����
vector<pair<int, int>> out[10001]; // �־��� ���� �ݴ� �׷��� ����

int getMaxDist(int s, int e) { // ��߳��, �������
	queue<int> q;
	q.push(s); // ù ��� �ε���

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int i = 0, nx, w; i < in[x].size(); ++i) {
			nx = in[x][i].second; // ����� ���� ���
			w = in[x][i].first; // ����� ���� ��� ����ġ
			dist[nx] = dist[nx] > dist[x] + w ? dist[nx] : dist[x] + w; // ���� ��� ����ġ�� �ִ밪

			if (!(--ind[nx])) // ���������� 0 �̸� queue�� ����
				q.push(nx);
		}
	}
	return dist[e]; // ���� �������� ���Ǵ� �Ÿ��� ��ȯ
}

int getUsedRoad(int s) {
	int ret = 0; // ���� ������ ����, ��ȯ�� ��
	queue<int> q;
	q.push(s);

	while (!q.empty()) {
		int x = q.front();
		int w = dist[x];
		q.pop();

		for (int i = 0, nx, nw; i < out[x].size(); ++i) {
			nx = out[x][i].second; // ���� ����� ��ȣ
			nw = out[x][i].first; // ���� ����� ����ġ
			if (w == nw + dist[nx]) {
				ret++; // ���� ���� ����
				if (!visit[nx]) { // visit üũ
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
		in[depart].push_back({ taken_time, arrival }); // ��߳��, �ɸ��� �ð�, �������
		ind[arrival]++; // �������� ���
		out[arrival].push_back({ taken_time, depart }); // �������, �Ÿ��� �ð�, ��߳��
	}
	int s, e; // ��߳��, �������
	cin >> s >> e;
	cout << getMaxDist(s, e) << '\n';
	cout << getUsedRoad(e) << '\n';

	return 0;
}