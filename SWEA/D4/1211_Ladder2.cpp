/*
 * 1211. [S/W �����ذ� �⺻] 2���� - Ladder2
 *
 * �ð����⵵ : O(N)
 *
 * ladder1 �� ������ �����ε�, ladder1�� 2�� ���� �����ϴ� ������� ã�� �������
 * ladder2�� ���� �Ʒ��� ���� �ּ��� �̵��Ÿ��� ������� ã�� �����̴�.
 * �Ȱ��� dfs�� �ذ��� �� ������ ladder1���� ������ ��� �ݺ������� �ذ��ߴ�.
 *
 */

#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

int min(int a, int b)
{
	return a < b ? a : b;
}

int dfs(int x, int y, vector<vector<int>>& ladder) { // �����δ� dfs�� �ƴϴ�

	int ret = 1; // �̵��Ÿ�

	while (y < 100) {
		if (ladder[y][x + 1]) { // ������ ���� 1�̸� 0�� ���� ���� ������ �̵�
			while (ladder[y][x + 1]) {
				ret++;
				x++;
			}
		}
		else if (ladder[y][x - 1]) { // ���� ���� 1 �̸� 0�� ���� ���� ������ �̵�
			while (ladder[y][x - 1]) {
				ret++;
				x--;
			}
		}
		ret++;
		y++; // �׻� �� ĭ�� �Ʒ������� �̵�
	}
	return ret;
}

int main()
{
	fastio();

	vector<vector<int>> ladder(100, vector<int>(100 + 2, 0)); // ��, �쿡 1���� ������ ��
	for (int testcase = 1, T; testcase <= 10; ++testcase) {

		cin >> T;
		vector<int> st; // ������ x��ǥ �����ϴ� ����
		for (int i = 0; i < 100; ++i) {
			for (int j = 1, tmp; j <= 100; ++j) {
				cin >> ladder[i][j];
				if (i == 0 && ladder[i][j]) // ù ��°�� �̰� ���� 1�̸�
					st.push_back(j);
			}
		}

		int cnt = 10000; // �̵��Ÿ� �ִ밪�� 10000�̶� ����
		int rslt = 0; // �̵��Ÿ��� ���� ª�� x��ǥ ���� ����
		for (int i = 0, ret; i < st.size(); ++i) {
			ret = dfs(st[i], 0, ladder);
			if (cnt >= ret) { // x = 0 ���� �����ϹǷ� ũ�ų� ������ �ٲ�
				cnt = ret;
				rslt = st[i];
			}
		}
		
		cout << '#' << T << ' ' << rslt - 1 << '\n'; // 1���� �����ϴϱ� 1�� ����

	}
	return 0;
}