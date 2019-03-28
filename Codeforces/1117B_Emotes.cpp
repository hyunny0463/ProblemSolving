/*
 * 1117B. Emotes
 *
 * �ð����⵵ : O(N * logN)
 *
 * greedy, sortings
 * emotes�� ����� �� �ִ밪�� ����ϱ� ���ؼ���
 * ���� ū ���� �ι�°�� ū ���� �˸� �ȴ�.
 * k�� ���� ū���� ���, �׸��� 1���� �ι�°�� ū ���� ����ϴ� ������
 * m���� ä��� m / (k + 1) �� ��ŭ�� ���� ū ���� k�� �ݺ��ϰ�
 * �ι����� ū �� 1���� �ݺ��Ѵ�. �������� ���� ū ���� �ݺ��ϹǷ� �����ָ� �ȴ�.
 *
 */

#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#include <iostream>
#include <algorithm>
using namespace std;

long long a[200000];
int main(int argc, char** argv) {

	long long n, m, k;
	cin >> n >> m >> k; // �Է¹޴� emote ����, ��� Ƚ��, �����ؼ� ��� ������ Ƚ��
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	sort(a, a + n, greater<int>()); // �������� ����

	long long int sum = ((m / (k + 1)) * (k * a[0])) + ((m / (k + 1)) * a[1]);
	sum += (m % (k + 1)) * a[0];

	cout << sum;
	
	return 0;
}
/* ex)
 * 6 9 2
 * 1 3 3 7 4 2
 * -----------------
 * 7 7 4 7 7 4 7 7 4
 * -----------------
 * -> 54
 */