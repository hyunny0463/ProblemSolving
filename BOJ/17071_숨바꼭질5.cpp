/*
 * 17071. ���ٲ��� 5
 *
 * �ð����⵵ : O(N)
 *
 * �־��� ���� 0 ~ 500000�� ���ؼ�
 * ������ ��ġ�������� BFS�� �����Ѵ�.
 * ¦��, Ȧ�� �ð��� ���� �迭�� �����Ѵ� ������
 * ������ �ش� ��ġ�� ���������� �ð��� Ȧ�� ���̳���
 * �־��� +1, -1, x2 ������ �Ͽ� ������ �� ����
 * �� ���� �ð�, ��ġ���� ������ ���� ������.
 *
 */

#define _CRT_SECURE_NO_WARNINGS
#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;

int arr[500001][2]; // ¦��, Ȧ�� �ð�

void bfs(int x) // ������ ��ġ���� �ɸ��� �ð��� ��� Ž��
{
	int t = 0;
	queue<int> q;
	arr[x][t] = 0;
	q.push(x);
	while (!q.empty()) {
		int qsize = q.size(); // �ð��� ���� �з�
		t = (t + 1) % 2;

		for (int i = 0; i < qsize; ++i) {
			int xx = q.front();
			q.pop();

			if (xx + 1 <= 500000 && arr[xx + 1][t] == -1) {
				arr[xx + 1][t] = arr[xx][(t + 1) % 2] + 1;
				q.push(xx + 1);
			}
			if (xx - 1 >= 0 && arr[xx - 1][t] == -1) {
				arr[xx - 1][t] = arr[xx][(t + 1) % 2] + 1;
				q.push(xx - 1);
			}
			if (xx * 2 <= 500000 && arr[xx * 2][t] == -1) {
				arr[xx * 2][t] = arr[xx][(t + 1) % 2] + 1;
				q.push(xx * 2);
			}
		}
	}
}

int solve(int x) // ������ ���� ��ġ���� �����̿� ���� ������ Ž��
{
	for (int i = 0; x + i <= 500000; ++i) {
		x += i; // ���� ��ġ�� �ð��� ���� x +1 +2 +3 ... ���� ����
		if (arr[x][i % 2] <= i) // �����̰� ���� �����߰ų� ���ÿ� �����ߴٸ�
			if (!((i - arr[x][i % 2]) % 2)) // �׸��� �ð��� ¦���� ���̳��ٸ�
				return i; // ������ ������ �ð��� ���� ���� �� �ִ�
	}
	return -1;
}

int main()
{
	fastio();

	int N, K;
	cin >> N >> K;

	memset(arr, -1, sizeof(arr));
	bfs(N);

	cout << solve(K) << '\n';

	return 0;
}