/*
 * 1210. [S/W �����ذ� �⺻] 2���� - Ladder1
 *
 * �ð����⵵ : O(N * N)
 *
 * �����ϰ� DFS�� �ذᰡ���� ��������.
 * ���������� 2�������� �����Ͽ� �Ųٷ� �ö���鼭
 * �¿� ���� ���ǰ� ���� ������ ���� �ö󰡴� ������� �����Ѵ�.
 * �Ǽ��� T ���� �Է¹��� �ʾ� ��ü ���� ��ĭ�� ����Ʈ �Ǿ� ���� ����� �������ʾҴ�.

 * �ٸ������ �ҽ��� �ôµ� �������� ����������
 * �¿�������� �� �� ������ 0�� �ƴ� ������ while������ �̵������ν�
 * ���� �� ����ӵ��� ���� �� �־���.
 *
 */

#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

#define MN 100
const int dx[] = { -1, 1, 0 }; // ��, ��, ��
const int dy[] = { 0, 0, -1 };
bool visit[100][102];

int dfs(int x, int y, vector<vector<int>>& ladder) {
	if (y <= 0) // 0�� �������� �� ����
		return x;
	int ret = 0;

	visit[y][x] = true;
	for (int i = 0; i < 3; ++i) {
		if (!ladder[y + dy[i]][x + dx[i]] || visit[y + dy[i]][x + dx[i]])
			continue; // �迭�� ���� 0 �̰ų� �̹� �湮�ߴٸ� �н�
		ret = dfs(x + dx[i], y + dy[i], ladder);
		if (ret > 0) // y ���� 0�� �����ߴٸ� ret�� ���� 0 �̻��̹Ƿ� ����
			break;
	}
	return ret;
}

int main(int argc, char** argv)
{
	vector<vector<int>> ladder(MN, vector<int>(MN + 2, 0));
	pair<int, int> st;

	for (int testcase = 1, T; testcase <= 10; ++testcase) {
		cin >> T;
		for (int i = 0; i < MN; ++i) {
			for (int j = 1; j <= MN; ++j) {
				cin >> ladder[i][j];
				if (ladder[i][j] == 2)
					st = { j, i };
			}
		}
		memset(visit, false, sizeof(visit)); // visit �ʱ�ȭ
		cout << '#' << testcase << ' ' << dfs(st.first, st.second, ladder) - 1 << '\n';
		// ���Ƿ� �¿쿡 ��ĭ�� �߰����־��� ������ �����-1 �� ���� ���
	}

	return 0;
}