/*
 * 5658. [모의 SW 역량테스트] 보물상자 비밀번호
 *
 * 시간복잡도 : O(N * log(N))
 *
 * simulation, balanced binary tree(set)
 * 보물상자의 비밀번호를 회전할 수 있는데, 4개 면이 있기 때문에
 * N/4 번 회전하면 다시 똑같은 값이 나온다는 것을 이용하고
 * 숫자 조합을 string으로 받아서 회전 시 첫 글자를 맨 뒤에 더해주면서
 * N개씩 확인하는데 같은 값은 중복인지 확인해야하기 때문에
 * set 자료구조를 사용했다. 중복 검사뿐만 아니라 정렬되며 삽입한다.
 * 최종적으로 iterator를 사용해서 K번째 큰 값을 출력했다.
 *
 */

#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#include <iostream>
#include <string>
#include <math.h>
#include <set>
using namespace std;

int main(int argc, char** argv) {
	int T;
	cin >> T;
	for (int testcase = 1, N, K; testcase <= T; ++testcase) {
		cin >> N >> K;
		string num;
		cin >> num;

		set<long long int, greater<long long int>> s; // 내림차순으로 정렬하는 set
		int div = N / 4; // 한 면에 있는 숫자 개수
		int sq = 0; // 16진수 몇 번째 자리인지 나타냄
		int sum = 0;

		for (int i = 0; i < div; ++i) {
			for (int j = N + i - 1; j >= i; --j) {
				if ('0' <= num[j] && num[j] <= '9')
					sum += pow(16, sq) * (num[j] - '0');
				else
					sum += pow(16, sq) * (num[j] - 'A' + 10);
				sq++;
				if (sq == div) {
					s.insert(sum);
					sum = 0;
					sq = 0;
				}
			}
			num += num[i]; // num 뒤에 num[0], num[1] ... 을 붙여줌
		}

		set<long long int>::iterator iter;
		iter = s.begin();
		for (int i = 0; i < K - 1; ++i) {
			iter++;
		}
		cout << '#' << testcase << ' ' << *iter << '\n';
	}
	return 0;
}