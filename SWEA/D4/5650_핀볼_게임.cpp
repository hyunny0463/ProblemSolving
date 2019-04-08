/*
 * 5650. �ɺ� ����
 *
 * �ð����⵵ : O(N * N * N * N)
 *
 * simulation
 * ��� ��ĭ���� 4�� �������� ����Ͽ� ���� ƨ��� ���� ����.
 * ��Ȧ�� ���� ��ȣ���� �׻� 2�� �� ���̹Ƿ� w �迭�� �̿��Ͽ�
 * �Է� ���� ��, wormhole �迭�� �� �� �����ߴ��� Ȯ���ϸ鼭 �����Ѵ�.

 * ���� ������ ������ ���� ���ؼ� ó���� �ߴٰ�
 * ��Ģ���� ã�Ƽ� �ҽ��ڵ��� ���̸� ���� �� �ְ� �Ǿ���.
 * ������ �� 5�� ��찡 ��Ģ�� ���� �ʾƼ� �켱������ ó�����־���.
 * ��Ȧ�� ���
 * xx = wormhole[(bd[yy][xx] - 6)][1].x;
 * yy = wormhole[(bd[yy][xx] - 6)][1].y;
 * �̷��� �ҽ��� ¥���� �� ������ ������� �������� ã�Ҵ�.
 * cx, cy ������ �ΰ� �ذ� �� �� �־���.

 * �ٸ� ����� �ҽ��� �ôµ� �Ź� ���� ����� ���� �������� ��������ʰ�
 * �ѹ��� �迭�� ���� ���� �־�ΰ� ������ �ϴ� ������ ���� �� ������
 * �����ϴ� �ҽ��� © �� �ִٴ� �� �˰� �Ǿ���.
 *
 */
#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#include <iostream>
#include <string.h>
using namespace std;

const int dx[] = { 1, 0, -1, 0 };
const int dy[] = { 0, 1, 0, -1 };

struct worm {
	int x, y;
};

int N;
int bd[102][102];
worm wormhole[5][2];
int w[5];

int solve(int x, int y, int dir) {
	int ret = 0;
	int xx = x;
	int yy = y;
	while (1) {
		xx += dx[dir];
		yy += dy[dir];

		if (bd[yy][xx] == -1)		return ret; // ��Ȧ�� ��� ����
		if (xx == x && yy == y)		return ret; // ������ ������ ����
		if (bd[yy][xx] == 0)		continue; // ��ĭ�̸� �״�� ����
		if (1 <= bd[yy][xx] && bd[yy][xx] <= 5) { // ������ ���
			if (bd[yy][xx] == 5) // 5�� ���� ���� ó������
				dir = (dir + 2) % 4;
			else if (dir == (bd[yy][xx] + 1) % 4)
				dir = (dir + 1) % 4;
			else if (dir == (bd[yy][xx] % 4))
				dir = (dir + 3) % 4;
			else
				dir = (dir + 2) % 4;
			ret++; // ���� ������ ��찡 �� ƨ��� Ƚ����
		}
		else { // ��Ȧ�� ���
			int cx = xx;
			int cy = yy;
			if (wormhole[(bd[cy][cx] - 6)][0].x == cx && wormhole[(bd[cy][xx] - 6)][0].y == cy) {
				xx = wormhole[(bd[cy][cx] - 6)][1].x;
				yy = wormhole[(bd[cy][cx] - 6)][1].y;
			}
			else {
				xx = wormhole[(bd[cy][cx] - 6)][0].x;
				yy = wormhole[(bd[cy][cx] - 6)][0].y;
			}
		}
	}
}

int main(int argc, char** argv) {
	fastio();
	int T;
	cin >> T;
	for (int testcase = 1; testcase <= T; testcase++) {
		cin >> N;
		for (int i = 0; i <= N + 1; ++i)
			bd[0][i] = bd[i][0] = bd[N + 1][i] = bd[i][N + 1] = 5; // ��迡 5�� ������ ä��
		memset(w, 0, sizeof(w)); // ��Ȧ���� üũ�ϴ� �迭 �ʱ�ȭ
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j) {
				cin >> bd[i][j];
				if (bd[i][j] >= 6) { // ��Ȧ�� ��츸 ����
					wormhole[bd[i][j] - 6][w[bd[i][j] - 6]] = { j, i };
					w[bd[i][j] - 6]++;
				}
			}
		}
		int rslt = 0;
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j) {
				if (bd[i][j]) continue;
				for (int k = 0; k < 4; ++k) { // �� ��ĭ���� 4�������� Ȯ��
					int cnt = solve(j, i, k);
					rslt = rslt > cnt ? rslt : cnt;
				}
			}
		}
		cout << '#' << testcase << ' ' << rslt << '\n';
	}

	return 0;
}