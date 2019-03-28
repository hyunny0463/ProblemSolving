/*
 * 1130B. Two Cakes
 *
 * �ð����⵵ : O(N)
 *
 * greedy
 * 10������ �迭�� ��� ������ ��ġ�� �����Ͽ�
 * sasha�� dima�� ��ġ���� ���� ���� ��ġ���� ������ ��ġ�� n�� �����Ͽ�
 * �� ���꿡�� �ּҰ��� �����ش�
 
 * �̹� ���� ���̿��µ� cost ������ int�� ����ؼ� Ʋ�� ���� �������� ã�Ҵ�.
 *
 */

#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char** argv)
{
	fastio();
	int n, a[100001][2] = { 0 }; // ���� ���������� 2���� ��ġ�� �ٸ��Ƿ�
	cin >> n;
	for (int i = 1, tier; i <= n * 2; ++i) {
		cin >> tier;
		if (!a[tier][0]) // ���� ��ȣ ���� ���� �� ���� ��
			a[tier][0] = i;
		else
			a[tier][1] = i;
	}

	long long int cost = a[1][0] + a[1][1] - 2; // ó�� ��ġ�� ���� 1�� ����������
	for (int i = 2; i <= n; ++i) // ��� ��쿡 �ִ� �Ÿ��� ����
		cost += min(abs(a[i][0] - a[i - 1][0]) + abs(a[i][1] - a[i - 1][1]), abs(a[i][0] - a[i - 1][1]) + abs(a[i][1] - a[i - 1][0]));

	cout << cost << '\n';

	return 0;
}