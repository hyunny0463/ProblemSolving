/*
 * 15652. N과 M (4)
 *
 * 시간복잡도 : O(N^M / M!)
 *
 * duplicate combination

 * 기본적인 중복조합의 구현
 * 중복가능한 조합이 가능하므로 idx는 같은 값을 넘길 수 있다.
 * N개의 자연수에서 중복 가능하도록 M개를 선택한다.
 *
 */

 #define fastio() ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
 #include <iostream>
 using namespace std;
 
 int N, M; // N까지의 자연수, 선택할 개수
 int t[8] = { 0 }; // 중복조합 저장하는 배열
 
 void dfs(int d, int idx) { // 깊이, 시작 인덱스
 	if (d == M) {
 		for (int i = 0; i < d; ++i)
 			cout << t[i] << ' ';
 		cout << '\n';
 		return;
 	}
 
 	for (int i = idx; i <= N; ++i) {
 		t[d] = i; // 깊이에 따라 배열에 i를 저장
 		dfs(d + 1, i); // 깊이 증가
 	}
 }
 
 int main(int argc, char** argv) {
 	fastio();
 	cin >> N >> M;
 
 	dfs(0, 1);
 
 	return 0;
 }