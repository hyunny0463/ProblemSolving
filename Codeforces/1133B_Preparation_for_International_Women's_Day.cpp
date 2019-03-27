/*
 * 1133B. Preparation for International Women's Day
 *
 * �ð����⵵ : O(1)
 *
 * math, number theory
 * �Է¹��� �迭���� ���Ƿ� 2���� �������� ��
 * k�� ������ ���������� Ȯ���ϴ� �����̴�.
 * �Է��� ���� �� ���� k�� ���� ������ ���� �迭�� ������Ű��
 * i�� j �ε����� ������Ű�� ���� ���� k�� ���������� �� Ȯ���Ѵ�.
 *
 */

#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#include<iostream>
#include<string>
using namespace std;

int main(int argc, char** argv) {
	int n, k, cnt = 0, d[101] = { 0 };
	cin >> n >> k;

	for (int i = 0, dn; i < n; ++i) {
		cin >> dn;
		d[dn % k]++; // �Է¹޴� dn ���� k�� ���� ������ ���� ����
	}

	for (int i = 0; i < k; ++i) { // d �迭�� �ε��� �ִ� k-1���� ����Ǿ�����
		if (!d[i])
			continue;
		for (int j = i; j < k; ++j) {
			if (i == j && d[i] < 2) // i�� j�� ���� �ε����� ����Ű�� 2�� �̸��̸� �Ѿ
				continue;
			while ((i + j) % k == 0 && d[i] && d[j]) { // i�� j�� ���� �����ϰ� (i+j)%k�� 0 �� ���
				d[i]--, d[j]--;
				cnt += 2;
				if (i == j && d[i] < 2)
					break;
			}
		}
	}
	cout << cnt;

	return 0;
}