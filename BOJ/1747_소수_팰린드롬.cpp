/*
 * 1747. 소수&팰린드롬
 *
 * 시간복잡도 : O(N*log(logN) + N*log(N)) : 소수 구하는 시간 복잡도 + N개의 크기는 아니지만 N개라 가정했을 때 탐색 복잡도
 *
 * 소수이고 팰린드롬인 조건을 모두 만족하는 수를 찾는 문제이다.
 * 시간을 줄이는 관건은 에라토스테네스의 체를 얼마나 최적화하는가이다.
 * 3부터 N까지 홀수인 경우 소수이고 팰린드롬이면 벡터pp에 저장한다.
 * 팰린드롬은 chk라는 변수에 뒷자리부터 10의 나머지를 넣고 10을 곱해주는 방식으로
 * 하는데 최종적으로 확인하고 싶은 수와 같은 수이면 팰린드롬이라고 판단한다.
 * 이 과정을 모든 경우에 1003001까지 저장해두고 N이 주어지면 이진탐색 lower_bound로
 * Nlog(N)의 시간복잡도로 찾을 수 있다.

 * 백만 * 백만의 값이 int형 범위를 벗어나는 것을 실수했었음.
 * MN의 값은 백만을 넘는 첫 소수이고 팰린드롬의 값이므로 임의로 지정해줌
 *
 */

#define _CRT_SECURE_NO_WARNINGS
#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MN = 1003002; // 1000000 넘는 첫 소수&팰린드롬 : 1003001
bool prime[MN] = { false }; // 소수이면 false로 저장(0, 1 제외)

int main(int argc, char** argv) {

	vector<int> pp(1, 2); // 2로 초기화 된 값을 1개 넣는다

	// 에라토스테네스의 체
	prime[0] = prime[1] = true;
	for (int i = 3; i < MN; i += 2) { // prime 자체만 보면 소수가 아닌데 홀수만 보고 vector에 넣는 값은 모두 소수임
		if (prime[i] == true)
			continue;
		for (long long int j = 1LL * i * i; j < MN; j += i) // 백만 * 백만은 int 범위를 벗어남
			prime[j] = true;

		int chk = 0, tmp = i;
		while (tmp) { // 팰린드롬 확인
			chk = chk * 10 + tmp % 10;
			tmp /= 10;
		}
		if (chk == i) // 소수 & 팰린드롬 이면 vector에 넣어줌
			pp.push_back(i);
	}

	int N;
	cin >> N;
	cout << *lower_bound(pp.begin(), pp.end(), N) << '\n'; // N과 같거나 큰 값중 가장 작은 값을 반환

	return 0;
}