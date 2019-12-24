/*
 * 15651. N과 M (3)
 *
 * 시간복잡도 : O(N^M)
 *
 * duplicate permutation

 * 기본적인 중복순열의 구현
 * N개의 자연수에서 같은 수를 중복으로 M개 선택한다.
 *
 */

 #define fastio() ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
 #include <iostream>
 using namespace std;
 
 int N, M; // N까지의 자연수, M개를 선택함
 int t[7] = { 0 };
 
 void dfs(int d) { // 깊이
 	if (d == M) { // 깊이가 M과 같으면 출력
 		for (int i = 0; i < d; ++i)
 			cout << t[i] << ' ';
 		cout << '\n';
 		return;
 	}
 
 	for (int i = 1; i <= N; ++i) {
 		t[d] = i;
 		dfs(d + 1);
 	}
 }
 
 int main(int argc, char** argv) {
 	fastio();
 	cin >> N >> M;
 
 	dfs(0);
 
 	return 0;
 }