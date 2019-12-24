/*
 * 15650. N과 M (2)
 *
 * 시간복잡도 : O(nCm)
 *
 * combination

 * 기본적인 조합 구현
 * N개의 자연수에서 M개를 순서에 상관없이 출력한다.
 *
 */

 #define fastio() ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
 #include <iostream>
 using namespace std;
 
 int N, M; // 자연수의 범위, 선택할 개수
 int t[8] = { 0 }; // 조합 저장할 배열
 
 void dfs(int d, int idx) { // 깊이, 인덱스 선택
 	if (d == M) { // 깊이가 선택할 개수와 크기가 같으면 출력
 		for (int i = 0; i < d; ++i)
 			cout << t[i] << ' ';
 		cout << '\n';
 		return;
 	}
 
 	for (int i = idx + 1; i <= N; ++i) { // 이전에 선택한 인덱스 이후로 선택
 		t[d] = i;
 		dfs(d + 1, i);
	}
 }
 
 int main(int argc, char** argv) {
 	fastio();
 	cin >> N >> M;
 
 	dfs(0, 0);
 
 	return 0;
 }