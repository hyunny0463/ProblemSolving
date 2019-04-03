/*
 * 1226. 미로1
 *
 * 시간복잡도 : O(N * N)
 *
 * bfs
 * 미로 2문제와 배열의 크기 외엔 모두 같다
 * bfs를 이용하여 시작점으로부터 모든 접근 가능한 공간까지 완전탐색을 한다.
 * 종료지점에 도착한 경우 flag를 참으로 만들어주고 그렇지 않다면 거짓이다.
 * bfs의 가장 기본적인 형태로 해결 가능하다.
 *
 */

 #define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
 #include <iostream>
 #include <vector>
 #include <queue>
 using namespace std;
 
 const int dx[] = { 1, 0, -1, 0 };
 const int dy[] = { 0, 1, 0, -1 };
 
 
 int main(int argc, char** argv)
 {
 	fastio();
 
 	for (int testcase = 0, T; testcase < 10; ++testcase) {
 		char bd[16][16] = { 0 };
 		bool visit[16][16] = { false };
 		bool flag = false;
 		cin >> T;
 		pair<int, int> st, en;
 		for (int i = 0; i < 16; ++i) {
 			for (int j = 0; j < 16; ++j) {
 				cin >> bd[i][j];
 				if (bd[i][j] == '2') // 시작점 저장
 					st = { j, i };
 			}
 		}
		// BFS
 		queue<pair<int, int>> q;
 		q.push(st);
 		visit[q.front().second][q.front().first] = true;
 		while (!q.empty()) {
 			int x = q.front().first;
 			int y = q.front().second;
 			q.pop();
 			for (int i = 0; i < 4; ++i) {
 				int xx = x + dx[i];
 				int yy = y + dy[i];
 
 				if (bd[yy][xx] == '3') // 종료점 조건
 					flag = true;
 				if (visit[yy][xx] || bd[yy][xx] == '1') // 이미 방문했거나 벽인 경우
 					continue;
 				q.push({ xx, yy }); // 그 외에는 queue에 저장한다
 				visit[yy][xx] = true; // 방문 표시
 			}
 		}
 		cout << '#' << T << ' ' << flag << '\n';
 	}
 	return 0;
 }