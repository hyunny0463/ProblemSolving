/*
 * 11559. Puyo Puyo
 *
 * �ð����⵵ : O(N)
 *
 * DFS�� �����Ͽ� ���� ���� 4�� �̻��� puyo�� ã��
 * �ٽ� DFS�� �����Ͽ� �� puyo���� �����ϴ� ������� �����Ѵ�.
 * puyo�� �ٴ����� ������ ���� queue�� ����Ͽ� �Ʒ������� ���������� �״´�.

 * �̷� simulation ������ ��� ó������ ���� ���� �ް�
 * ���۷��� �����ڸ� ����ؼ� ���� �Ѱ� ���� �� �Ʒ������� �����ϴ°� �����ε� �ϴ�.
 *
 */

#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

const int dx[] = { 1, 0, -1, 0 }; // ��, ��, ��, ��
const int dy[] = { 0, -1, 0, 1 };
int visit[6 + 2][12 + 2];

int dfs(int x, int y, char color, vector<vector<char>>& map) // ������ puyo�� 4�̻����� Ȯ��
{
	int ret = 1;

	visit[x][y] = 1;
	for (int i = 0; i < 4; ++i) {
		if (map[x + dx[i]][y + dy[i]] != color || visit[x + dx[i]][y + dy[i]]) // ���� �ٸ��ų� �̹� �湮�� ���
			continue;
		ret += dfs(x + dx[i], y + dy[i], color, map);
	}

	return ret; // �湮�� �� ��ŭ ����
}

void dfs_make_zero(int x, int y, char color, vector<vector<char>>& map) // puyo ����
{
	visit[x][y]++; // �湮�ߴ� ���̱� ������
	map[x][y] = '.';
	for (int i = 0; i < 4; ++i) {
		if (map[x + dx[i]][y + dy[i]] != color || visit[x + dx[i]][y + dy[i]] == 2)
			continue;
		dfs_make_zero(x + dx[i], y + dy[i], color, map);
	}
}

void down_puyo(int x, vector<char>& map) // �߷��� ������ �޴� puyo��
{
	queue<char> q; // '.'�� �ƴ� ���� ����
	for (int i = 12; i >= 1; --i) { // 12�� ���� �Ʒ��̹Ƿ� �Ʒ��� ���� ����
		if (map[i] == '.')
			continue;
		q.push(map[i]);
	}
	for (int i = 12; i >= 1; --i) {
		if (!q.empty()) { // queue�� ������� ������ �ʿ� �����ϰ� �������� '.' ����
			map[i] = q.front();
			q.pop();
		}
		else
			map[i] = '.';
	}
}

int main(int argc, char** argv)
{
	vector<vector<char>> map(6 + 2, vector<char>(12 + 2, '.')); // ������� Ȯ������ �ʱ� ���� �˳��� ����

	for (int i = 1; i <= 12; ++i)
		for (int j = 1; j <= 6; ++j)
			cin >> map[j][i]; // down_puyo�� ȿ�������� �ϱ����� ���� ������ ����

	int is_makedot = 1;
	int cnt = 0;
	while (is_makedot) {
		is_makedot = 0; // puyo�� ������ �ִ��� Ȯ���ϴ� ����
		memset(visit, 0, sizeof(visit)); // down_puyo�� �ϸ� ���� ��ȭ�� ����� ����
		for (int i = 1; i <= 12; ++i) {
			for (int j = 1; j <= 6; ++j) {
				if (map[j][i] != '.' && dfs(j, i, map[j][i], map) >= 4) { // �� ���� ���� Ȯ��
					dfs_make_zero(j, i, map[j][i], map);
					is_makedot++;
				}
			}
		}
		for (int i = 1; i <= 6; ++i) // �� �ึ�� down_puyo ����
			down_puyo(i, map[i]);

		cnt++;
	}
	cout << cnt - 1 << '\n';

	return 0;
}