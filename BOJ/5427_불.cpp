/*
 * 5427. ��
 *
 * �ð����⵵ : O(N^2)
 *
 * bfs

 * �ǹ� ������ ���� �Űܰ��� �ְ�,
 * ����̴� �ҿ� ���� �ʰ� �ⱸ�� ã�Ƽ� Ż���ؾ��Ѵ�.

 * �� ������ �ܼ��� ���� ã�� ���� �ƴ϶�
 * ���� Ȯ��ʿ� ���� �̵����� ���ϴ� �浵 �ִ�.
 * ���� Ȯ���� ��, �ð��� ���� ������ ���ڷ� ǥ���߰�,
 * ���� ã�� ���� ���� �ð��� ������ ǥ���
 * ���ں��� ���� ���� �̵� �����ϵ��� �ߴ�.
 * �� ���� ���� ���� ã�ƾ� �ϱ� ������
 * dfs�� �ƴ� bfs�� ����ߴ�.
 * 
 */

#define fastio() ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#include <iostream>
#include <queue>
using namespace std;


struct pxy {
	int x, y;
};

struct pxyt { // ��ǥ, �ð��� �����ϴ� ����ü
	int x, y, t;
};

const int dx[] = { 1, 0, -1, 0 };
const int dy[] = { 0, 1, 0, -1 };
int bd[1001][1001];
int w, h;
pxy sang; // ����� x, y ��ǥ
queue<pxyt> fire; // �� ��ǥ �����ϴ� queue

void fire_spread() { // �� Ȯ���ϴ� �Լ�
	while (!fire.empty()) {
		int cx = fire.front().x;
		int cy = fire.front().y;
		int ct = fire.front().t;
		fire.pop();

		for (int i = 0; i < 4; ++i) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			int nt = ct + 1;

			if (nx < 0 && nx >= w && ny < 0 && ny >= h)
				continue;

			if (bd[ny][nx] == -2) { // �� ������ �ǹ�
				bd[ny][nx] = nt; // �� ������ �ð��� ���� �� ��ȣ�� ����
				fire.push({ nx, ny, nt }); // queue�� �� ������ ����
			}
		}
	}
}

int escape(int x, int y, int d) { // Ż���ϴ� �� ã�� �Լ�
	queue<pxyt> q;
	q.push({ x, y, d });

	while (!q.empty()) {
		int cx = q.front().x;
		int cy = q.front().y;
		int ct = q.front().t;
		q.pop();

		if (cx == 0 || cx == w - 1 || cy == 0 || cy == h - 1) // ��������� �� Ż��
			return ct;

		for (int i = 0; i < 4; ++i) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			int nt = ct + 1;

			if (bd[ny][nx] > nt || bd[ny][nx] == -2) { // ���� �ð��� ���� Ȯ��Ǿ� ���� �ð����� �۰ų� �� ������ ��
				q.push({ nx, ny, nt });
				bd[ny][nx] = 0;
			}
		}
	}

	return -1; // Ż������ ���ϸ� -1 ��ȯ
}


int main(int argc, char** argv) {
	fastio();
	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; ++test_case) {
		cin >> w >> h;
		char tmp;
		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < w; ++j) {
				cin >> tmp;

				if (tmp == '.') // �־��� ���� ������ ���ڷ� ��ȯ
					bd[i][j] = -2;
				else if (tmp == '#')
					bd[i][j] = -1;
				else if (tmp == '*') {
					bd[i][j] = 0;
					fire.push({ j, i, 0 });
				}
				else if (tmp == '@') {
					bd[i][j] = -2;
					sang = { j, i };
				}
			}
		}

		fire_spread();
		int rslt = escape(sang.x, sang.y, 0) + 1;

		if (rslt)
			cout << rslt << '\n';
		else
			cout << "IMPOSSIBLE" << '\n';
	}

	return 0;
}