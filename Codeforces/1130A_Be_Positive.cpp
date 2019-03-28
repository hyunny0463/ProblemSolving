/*
 * 1130A. Be Positive
 *
 * �ð����⵵ : O(N)
 *
 * implementation
 * ����� ������ �Է¹޴� ���� n �� �ݺ��� ũ��
 * 1 �Ǵ� -1 �� ����ϰ� �Ѵ� �ƴϸ� 0�� ����ϴ� ����
 *
 */

#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	int n, pos = 0, neg = 0, d[101];
	cin >> n;
	int x = n % 2 ? n / 2 + 1 : n / 2; // Ȧ���� n/2 +1, ¦���� n/2
	for (int i = 0; i < n; ++i) { // ����� ���� ���� ī��Ʈ
		cin >> d[i];
		if (d[i] > 0)
			pos++;
		else if (d[i] < 0)
			neg++;
	}
	if (pos >= x)
		cout << 1;
	else if (neg >= x)
		cout << -1;
	else
		cout << 0;

	return 0;
}