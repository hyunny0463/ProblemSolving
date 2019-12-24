/*
 * 15649. N�� M (1)
 *
 * �ð����⵵ : O(nPm)
 *
 * permutaion
 
 * �⺻���� ���� ����
 * N���� ���ڿ��� M���� ��� ������ ��츦 ����Ѵ�.
 *
 */

#define fastio() ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#include <iostream>
using namespace std;

int N, M; // �ڿ��� ũ��, ������ ����
int t[8] = { 0 }; // ���� �����ϴ� �迭
int c[9] = { 0 }; // ���õǾ����� Ȯ���ϴ� �迭

void dfs(int d) { // ����
	if (d == M) { // ���̰� ������ ������ ������ ��� �� ����
		for (int i = 0; i < d; ++i)
			cout << t[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = 1; i <= N; ++i) { // �����̹Ƿ� ó������ ����
		if (!c[i]) { // ���� ���ڴ� ����ϸ� �ȵǹǷ�
			t[d] = i;
			c[i] = 1; // visit checked
			dfs(d + 1);
			c[i] = 0; // visit un-checked
		}
	}
}

int main(int argc, char** argv) {
	fastio();
	cin >> N >> M; // �ڿ��� N���� M�� ����

	dfs(0);

	return 0;
}