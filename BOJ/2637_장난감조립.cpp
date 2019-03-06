
// 2637. 장난감조립
// DFS를 이용하여 재귀적으로 자식노드로 이동하면서 부품의 개수를 곱하가며 기본부품의 개수를 알아낸다.



#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#include <iostream>
#include <vector>
using namespace std;


struct part { // K, Y : 부품번호, 개수
	int K, Y;
};
vector<vector<part>> toy;
int parts[101] = { 0 }; //완제품, 중간부품의 개수를 연산, 마지막에 기본부품 개수를 가지고 있는 배열

void dfs(int N, int num) { // 부품번호, 필요한 해당부품 개수의 배수
	if (toy[N].empty()) // 더 이상 자식노드가 없으면 기본부품이라 판단
		return;
	for (int i = 0; i < toy[N].size(); ++i) {
		parts[toy[N][i].K] += num * toy[N][i].Y;
		dfs(toy[N][i].K, num * toy[N][i].Y);
	}
	parts[N] = 0; // 자식노드로의 dfs를 모두 수행하면 해당 중간부품은 더이상 없음
}

int main() {
	fastio();
	int N, M;
	cin >> N >> M;
	vector<vector<part>>& toyy = toy; // 참조연산을 통해 메모리 사용을 줄이고 싶음
	toyy.resize(N + 1);

	for (int i = 0, X, Y, K; i < M; ++i) { // 입력받는 부분
		cin >> X >> Y >> K;
		toyy[X].push_back({ Y, K });
	}
	parts[N] = 1; // ex) 7번완제품이라면 parts[7] = 1 나머지는 0
	dfs(N, 1);

	for (int i = 0; i < N; ++i) {
		if (parts[i])
			cout << i << ' ' << parts[i] << '\n';
	}
	return 0;
}

//input example
//7
//8
//5 1 2
//5 2 2
//7 5 2
//6 5 2
//6 3 3
//6 4 4
//7 6 3
//7 4 5