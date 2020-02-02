/*
 * 2531. 회전 초밥
 *
 * 시간복잡도 : O(N)
 *
 * sliding window

 * 이 문제는 이해를 제대로 하지 못해서
 * 쿠폰번호에 해당하는 초밥이 k개의 초밥 앞뒤로 있어야 하는지
 * 확인하고 없을 때, 레일에도 없으면 더해줄 수 있는 조건인 줄 알았다.

 * 단순하게 k개의 초밥을 확인하고, k개의 초밥안에
 * 쿠폰번호에 해당하는 초밥이 없을 때 무조건 +1 해주는 방식으로
 * 쉽게 풀리고, 기존에는 시간복잡도 N * k 였지만
 * sliding window 방식으로 풀어서 N의 시간복잡도로 해결했다.
 *
 */

#include <iostream>
#include <string.h>
using namespace std;

int N, d, k, c; // 접시의 수, 초밥 가짓수, 연속 접시수, 쿠폰번호
int dish[30001]; // 모든 초밥을 가지는 배열
int sushi[3001] = { 0, }; // k개의 초밥
int cnt = 0, mcnt = 0; // 현재 개수, 최대 개수

int main(int argc, char** argv) {

	cin >> N >> d >> k >> c;

	if (k > d) // 연속 접시 수보다 초밥 가짓수가 적으면 작은 수로
		k = d;

	for (int i = 0; i < N; ++i)
		cin >> dish[i];

	for (int i = 0; i < k; ++i) {
		if (!sushi[dish[i]]) // 없는 초밥이면 증가
			cnt++;
		sushi[dish[i]]++; // 초밥 개수 체크
	}

	for (int i = 0; i < N; ++i) {
		if (!--sushi[dish[i]]) // 앞쪽 접시를 빼고 0이면 카운트 감소
			cnt--;
		if (!sushi[dish[(i + k) % N]]++) // 뒷쪽 접시 0이면 카운트 증가하고 더함
			cnt++;

		cnt += !sushi[c]; // 쿠폰 초밥이 없으면 더함
		mcnt = mcnt > cnt ? mcnt : cnt;
		if (mcnt > d)
			break;
		cnt -= !sushi[c]; // 정답을 위해 더했으니 다시 뺌
	}

	cout << mcnt << '\n';

	return 0;
}