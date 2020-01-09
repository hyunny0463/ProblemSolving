/*
 * 9232. �ѱ����� ���� ����
 *
 * �ð����⵵ : O(N)
 *
 * brute-force

 * ������ �������� ���̼�Ʈ�� ��ũ�� ���������� �ִ´�.
 * ��ũ�� ���� ���ϸ� 0, �׷��� ������
 * ���� ���� ��ũ�� ��ġ�� ��ȯ�ϴ� �����̴�.

 * ���� �ذ��� �ٽ��� ���̼�Ʈ�� �ʺ� �Է¹����鼭
 * �Է¹��� �ּ��� �ʺ�� ������ �ʺ� �����Ѵ�.
 * �׸����� �Ʒ������� ��ũ�� �ִ´�.
 *
 */

#define fastio() ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#include <iostream>
using namespace std;

int D, N; // ���� ����, ���� ���� ����
int oven[300001];
int piza[300001];

int main(int argc, char** argv) {
	fastio();
	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; ++test_case) {
		cin >> D >> N;
		oven[0] = 1000000000; // �ִ��� �������� �ʱ�ȭ
		for (int i = 1; i <= D; ++i) {
			cin >> oven[i]; // ���� �ʺ� ���� ���� ������ ����
			oven[i] = oven[i] < oven[i - 1] ? oven[i] : oven[i - 1];
		}

		for (int i = 0; i < N; ++i)
			cin >> piza[i];

		int idx = 0;
		for (int i = D; i > 0; --i) {
			if (piza[idx] > oven[i])
				continue;
			idx++;
			if (idx >= N) {
				cout << "#" << test_case << ' ' << i << '\n';
				break;
			}
		}

		if (idx < N)
			cout << "#" << test_case << ' ' << 0 << '\n';
	}
	
	return 0;
}