/*
 * 15683. ����
 *
 * �ð����⵵ : O(N)
 *
 * dfs�� simulation�� �������� ����
 * 5��ī�޶��� ��� ȸ������ �����Ƿ� ��ó���� ���־���
 * �� �ܿ��� ��� ��츦 dfs�� �̿��Ͽ� ī�޶� ȸ���Ͽ�
 * ���ÿ����� ǥ���ϰ� ����� ��� ī�޶� ���� ǥ������ ��
 * ���õ��� �ʴ� ���� ������ ���� ������� �ذ��ߴ�.

 * ó������ �ƹ����� ��ü���� �����ϸ�
 * �� ī�޶� ���� ȸ������ �� ������ ���� ���ֱ�����
 * ���� �ǵ��� �ִ� ���� ȿ�����̶� �����ߴµ�
 * ���� ũ�Ⱑ Ŀ�� ����, ���̰� ��������� ���Ǵ� �ڿ��� �������Ƿ�
 * �ִ��� �����ϴ� ���� �����ؾ߰ڴ�.
 *
 */

#define _CRT_SECURE_NO_WARNINGS
#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
using namespace std;

int N, M, invisiblearea = 0x7FFFFFFF;
vector<tuple<int, int, int>> cctv, cam5;
const int dx[] = { 1, 0, -1, 0 };
const int dy[] = { 0, -1, 0, 1 };

void checksight(int dir, int x, int y, vector<vector<int>>& bd) // ����, x, y, ��ü��
{
	while (bd[y + dy[dir]][x + dx[dir]] != 6) { // �ش� ��ǥ���� �־��� �������� ���� ���� ������ �̵���
		x += dx[dir];
		y += dy[dir];
		if (bd[y][x])
			continue;
		bd[y][x] = 7;
	}
}

void paint(int d, vector<vector<int>> bd) // ����, ��ü�� ����
{
	if (d >= cctv.size()) { // ��������
		int cnt = 0;
		for (int i = 1; i <= N; ++i)
			for (int j = 1; j <= M; ++j)
				if (!bd[i][j])
					++cnt;
		invisiblearea = invisiblearea < cnt ? invisiblearea : cnt;
		return;
	}
	int cam = get<0>(cctv[d]);
	int x = get<2>(cctv[d]);
	int y = get<1>(cctv[d]);
	vector<vector<int>> tmpbd = bd; // checksight�� �����ϸ鼭 �ʿ� �׸��� ������ �����ص�
	switch (cam) { // ī�޶� ��ȣ�� ���� ����
	case 1:
		for (int dir = 0; dir < 4; ++dir) {
			checksight(dir, x, y, bd); // ī�޶� �������� Ȯ��
			paint(d + 1, bd); // �� ���� ī�޶�
			bd = tmpbd; // checksight ���� ������ ����
		}
		break;
	case 2:
		for (int dir = 0; dir < 2; ++dir) {
			checksight(dir, x, y, bd);
			checksight(dir + 2, x, y, bd);
			paint(d + 1, bd);
			bd = tmpbd;
		}
		break;
	case 3:
		for (int dir = 0; dir < 4; ++dir) {
			checksight(dir, x, y, bd);
			checksight((dir + 1) % 4, x, y, bd);
			paint(d + 1, bd);
			bd = tmpbd;
		}
		break;
	case 4:
		for (int dir = 0; dir < 4; ++dir) {
			checksight(dir, x, y, bd);
			checksight((dir + 1) % 4, x, y, bd);
			checksight((dir + 2) % 4, x, y, bd);
			paint(d + 1, bd);
			bd = tmpbd;
		}
		break;
	}
}

int main(int argc, char** argv)
{
	cin >> N >> M;
	vector<vector<int>> bd(N + 2, vector<int>(M + 2, 6)); // 6�� ���� �ǹ�
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			cin >> bd[i][j];
			if (bd[i][j] > 0 && bd[i][j] < 5) // 1 ~ 4�� ī�޶��ȣ�� ��ǥ ����
				cctv.push_back(make_tuple(bd[i][j], i, j)); // ī�޶��ȣ, x, y
			else if (bd[i][j] == 5) // 5�� ī�޶� ��ǥ ����
				cam5.push_back(make_tuple(bd[i][j], i, j));
		}
	}

	for (int j = 0; j < cam5.size(); ++j) { // 5��ī�޶�� ȸ���ϸ� �������� �����Ƿ� ��ó��
		int y = get<1>(cam5[j]);
		int x = get<2>(cam5[j]);
		for (int i = 0; i < 4; ++i) {
			int xx = x, yy = y;
			while (bd[yy + dy[i]][xx + dx[i]] != 6) {
				if (!bd[yy + dy[i]][xx + dx[i]])
					bd[yy + dy[i]][xx + dx[i]] = 7; // ���ÿ����� 7�� ǥ��
				xx += dx[i];
				yy += dy[i];
			}
		}
	}

	paint(0, bd);

	cout << invisiblearea;

	return 0;
}