/*
 * 1012. ����� ����
 *
 * �ð����⵵ : O(N * M)
 *
 * BFS(DFS)

 * �ܼ��� bfs, �Ǵ� dfs�� ����ϸ� �ذ�Ǵ� ����
 * ������ ó�� bfs�� Ǯ �� ���߸� queue�� ���� ���� �ƴ϶�
 * queue���� �� ��, 0���� ����� ����
 * �ߺ��� �Ǿ��� ������ �ð��ʰ��� ������.
 * ������ �ܼ��� ������ �ȳ��� �� �������� dfs�� ����ϰų�
 * �ʱ�ȭ �ϴ� ��ġ�� �� �����ؾ� �� ��!
 *
 */

#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };
int T, N, M, K, rslt;
int m[50][50];

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	m[y][x] = 0; // Ʋ�� ����: pop �� �� 0���� �ʱ�ȭ �Ϸ��� ����

	q.push({ x, y });

	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx >= 0 && nx < M && ny >= 0 && ny < N && m[ny][nx]) {
				m[ny][nx] = 0; // queue�� ���� �� �ٸ� ��ġ���� �ٽ� ���ְ� 0���� ����
				q.push({ nx, ny });
			}
		}
	}
}

int main(int argc, char** argv) {
	cin >> T;
	memset(m, 0, sizeof(m)); // ��� ��ġ�� Ȯ���ϸ鼭 0���� �ʱ�ȭ �ϹǷ� ó���� �ϸ��
	for (int testcase = 1; testcase <= T; ++testcase) {
		rslt = 0;
		cin >> M >> N >> K; // ó�� ��, ���� �߸� �޾Ҿ���

		for (int i = 0, x, y; i < K; ++i) {
			cin >> x >> y;
			m[y][x] = 1; // ���� ��ġ�� 1
		}

		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				if (m[i][j]) {
					rslt++; // ���ǹ� �ɸ��� ������ 1 ����
					bfs(j, i);
				}
			}
		}

		cout << rslt << '\n';

	}

	return 0;
}