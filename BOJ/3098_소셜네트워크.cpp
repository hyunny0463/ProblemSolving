/*
 * 3098. 소셜네트워크
 *
 * 시간복잡도 : O(N * N * N)
 *
 * simulation
 * 3중 for문을 이용하여 k가 기준점을 잡고 i, j와 연결되어 있는지 확인하고 연결 여부를 판단한다.
 * 새로운 연결은 tmp에 저장하고 친구 연결 관계를 나타내는 bd 배열과 차이가 있으면 카운트하고
 * 그 연결을 bd배열에 저장하는 방식으로 모든 연결이 될 때 반복문을 종료한다.
 *
 */

#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char** argv)
{
	fastio();
	int N, M;
	bool bd[51][51] = { false };
	cin >> N >> M;
	for (int i = 0, A, B; i < M; ++i) {
		cin >> A >> B;
		bd[A][B] = bd[B][A] = true; // 상호 간 친구이므로
	}

	vector<int> result;
	while (M < N * (N - 1) / 2) { // nCr : NC2 조합의 연결개수가 필요
		bool tmp[51][51] = { false };
		for (int k = 1; k <= N; ++k)
			for (int i = 1; i <= N; ++i)
				for (int j = i + 1; j <= N; ++j)
					if (bd[i][k] && bd[k][j] && !tmp[i][j]) // i-k, k-j가 연결, i-j가 0이면 i-j연결
						tmp[i][j] = true;

		int cnt = 0;
		for (int i = 1; i <= N; ++i) {
			for (int j = i + 1; j <= N; ++j) {
				if (tmp[i][j] && !bd[i][j]) { // 새로 생긴 네트워크 연결이면 카운트
					bd[i][j] = bd[j][i] = true;
					++cnt;
				}
			}
		}
		result.push_back(cnt); // 카운트 개수 저장
		M += cnt; // 새로 생긴 연결만큼 M에 더해줌
	}
	cout << result.size() << '\n';
	for (auto i : result)
		cout << i << '\n';
}