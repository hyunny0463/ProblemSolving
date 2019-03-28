/*
 * 1117B. Emotes
 *
 * 시간복잡도 : O(N * logN)
 *
 * greedy, sortings
 * emotes를 출력할 때 최대값을 출력하기 위해서는
 * 가장 큰 값과 두번째로 큰 값만 알면 된다.
 * k번 가장 큰값을 출력, 그리고 1번만 두번째로 큰 값을 출력하는 식으로
 * m번을 채우면 m / (k + 1) 번 만큼에 가장 큰 값을 k번 반복하고
 * 두번쨰로 큰 값 1번을 반복한다. 나머지는 가장 큰 값을 반복하므로 더해주면 된다.
 *
 */

#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#include <iostream>
#include <algorithm>
using namespace std;

long long a[200000];
int main(int argc, char** argv) {

	long long n, m, k;
	cin >> n >> m >> k; // 입력받는 emote 개수, 출력 횟수, 연속해서 출력 가능한 횟수
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	sort(a, a + n, greater<int>()); // 내림차순 정렬

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