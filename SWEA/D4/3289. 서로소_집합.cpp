/*
 * 3289. ���μ� ����
 *
 * �ð����⵵ : O(1) < x < O(m*log(n)) --> O(��(n))

 * union-find, disjoint set
 * ���Ͽ� ���ε��� �⺻���� �����̴�.
 * find �Լ��� �θ� ã�� �� �θ�� �ڽ��� ��� �ʱ�ȭ�ϴ�
 * ����ȭ ������ ������ �ִ�.
 * union �Լ��� b�� �θ� a�� �����ִ� ������ ������.

 * �� ����ȭ �ϱ� ���ؼ��� � �θ���
 * ���̰� �� ������ Ȯ���ϰ� ū �θ𿡰� ���� �θ� ��带
 * �����ϴ� ������ �߰��Ǿ�� �Ѵ�.
 *
 */

#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
using namespace std;

int T;
int s[1000001];

int my_find(int n) {
	if (s[n] == n) // �θ� �ڱ� �ڽ��̸�
		return s[n];
	s[n] = my_find(s[n]); // �������� ������ ã���� ����ȭ
	return s[n];
}

void my_union(int a, int b) {
	s[b] = a;
}

int main(int argc, char** argv) {
	fastio();
	cin >> T;
	for (int test_case = 1, n, m; test_case <= T; ++test_case) {
		cin >> n >> m; // �迭�� ũ��, ���� Ƚ��

		for (int i = 0; i <= n; ++i) // disjoint set �ʱ�ȭ
			s[i] = i;

		cout << "#" << test_case << ' ';
		for (int i = 0, op, a, b; i < m; ++i) {
			cin >> op >> a >> b;
			a = my_find(a);
			b = my_find(b);

			if (op) { // ����ϴ� ����
				if (a == b)
					cout << 1;
				else
					cout << 0;
			}
			else // ����ϴ� ����
				my_union(a, b);
		}
		cout << '\n';
	}
	return 0;
}