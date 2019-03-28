/*
 * 1130A. Be Positive
 *
 * 시간복잡도 : O(N)
 *
 * implementation
 * 양수나 음수가 입력받는 개수 n 의 반보다 크면
 * 1 또는 -1 을 출력하고 둘다 아니면 0을 출력하는 문제
 *
 */

#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	int n, pos = 0, neg = 0, d[101];
	cin >> n;
	int x = n % 2 ? n / 2 + 1 : n / 2; // 홀수면 n/2 +1, 짝수면 n/2
	for (int i = 0; i < n; ++i) { // 양수와 음수 개수 카운트
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