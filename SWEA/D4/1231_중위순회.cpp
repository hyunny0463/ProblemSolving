/*
 * 1231. [S/W �����ذ� �⺻] 9���� - ������ȸ
 *
 * �ð����⵵ : O(N)
 *
 * inorder
 * ������ȸ�� �����ϰ� �����ϴ� �����̴�.
 * ������ȸ�� �˱⸸�ϰ� ���� ¥������ ���µ� ������ ������ �־ ��ȸ�� �����.
 * ��� �� ������ ���� Ʈ���� § ���� �ƴϰ� �迭�� ��ȸ�� �ߴµ� �Է� �׽�Ʈ���̽��� ��������
 * ����� �� ������ε� Ǯ �� �־���. ������ ����Ϸ��� ����ü����� ����Ʈ ������ ������ �ؼ�
 * ���� �ڽİ� ������ �ڽİ��� ������ �ְ� �׿� ���� �湮�ϸ� �� ���̶� �����Ѵ�.
 *
 */

#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#include <iostream>
using namespace std;

int N;
char tr[101];

void inorder(int idx) {
	if (idx * 2 <= N) // ���� �ڽ� �ִ��� Ȯ��
		inorder(idx * 2);
	cout << tr[idx]; // ���� �ڽ� ������ ���� ��� ����
	if (idx * 2 + 1 <= N) // ������ �ڽ� �ִ��� Ȯ��
		inorder(idx * 2 + 1);
}

int main(int argc, char** argv)
{
	fastio();
	for (int testcase = 1; testcase <= 10; ++testcase) {
		cin >> N;
		for (int i = 0, n, a, b; i < N; ++i) {
			cin >> n;
			cin >> tr[n];
			if ((n * 2) + 1 <= N)
				cin >> a >> b;
			else if (n * 2 <= N)
				cin >> a;
		}
		cout << '#' << testcase << ' ';
		inorder(1);
		cout << '\n';
	}

	return 0;
}