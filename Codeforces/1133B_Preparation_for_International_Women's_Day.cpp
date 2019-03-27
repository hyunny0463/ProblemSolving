/*
 * 1133B. Preparation for International Women's Day
 *
 * 시간복잡도 : O(1)
 *
 * math, number theory
 * 입력받은 배열에서 임의로 2개를 선택했을 때
 * k로 나누어 떨어지는지 확인하는 문제이다.
 * 입력을 받을 때 부터 k로 나눈 나머지 값의 배열을 증가시키고
 * i와 j 인덱스를 증가시키며 더한 값이 k로 나누어지는 지 확인한다.
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
		d[dn % k]++; // 입력받는 dn 값을 k로 나눈 나머지 값을 증가
	}

	for (int i = 0; i < k; ++i) { // d 배열에 인덱스 최대 k-1까지 저장되어있음
		if (!d[i])
			continue;
		for (int j = i; j < k; ++j) {
			if (i == j && d[i] < 2) // i와 j가 같은 인덱스를 가르키고 2개 미만이면 넘어감
				continue;
			while ((i + j) % k == 0 && d[i] && d[j]) { // i와 j에 값이 존재하고 (i+j)%k가 0 인 경우
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