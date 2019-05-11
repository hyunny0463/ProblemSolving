/*
 * 1219. [S/W �����ذ� �⺻] 4���� - ��ã��
 *
 * �ð����⵵ : O(2 * N)
 *
 * bfs
 * ������ 0���� ������ 99���� �����ϴ� ��ΰ� �ִٸ�
 * 1 �׷��� ������ 0�� ����ϴ� ��ã�� �����̴�.
 * �־��� ��ΰ� ������ -1�� �ʱ�ȭ�ϰ�,
 * �� ��ġ���� �ִ� 2���� ��ΰ� �ֱ� ������ -1�� �ƴϸ�
 * ��� ��쿡 ���Ͽ� queue�� �ְ� bfs�ν� 99�� �����ϴ��� Ȯ���Ѵ�.

 * ������� ū ���̰� ������ ��� ���� ������ ã�� ������
 * ������ �߸� �����ؼ� bfs�� �����߰�,
 * 99�� �����Ѵٸ� �����ϴ� �������� ������ �ذ��ߴ�.
 *
 */

#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

int main(int argc, char** argv) {
	int g[2][100];

	for (int testcase = 1, N; testcase <= 10; ++testcase) {
		cin >> testcase >> N;
		memset(g, -1, sizeof(g));
		int cur = 0;
		bool flag = false;

		for (int i = 0, A, B; i < N; ++i) {
			cin >> A >> B;
			if (g[0][A] == -1)
				g[0][A] = B;
			else
				g[1][A] = B;
		}

		queue<int> q;
		q.push(0);
		while (!q.empty()) {
			cur = q.front();
			q.pop();

			for (int i = 0; i < 2; ++i) {
				if (g[i][cur] == -1)
					continue;
				if (g[i][cur] == 99) {
					flag = true;
					break;
				}
				else
					q.push(g[i][cur]);
				g[i][cur] == -1;
			}
			if (flag)
				break;
		}
		cout << '#' << testcase << ' ' << flag << '\n';
	}

	return 0;
}