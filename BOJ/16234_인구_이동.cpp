/*
 * 16234. 인구 이동
 *
 * 시간복잡도 : O(N * N)
 *
 * bfs, implementation
 * 주어지는 L값보다 크거나 같고 R값보다 작거나 같을 때 인구 이동이 진행된다.
 * 각각의 지점에서 bfs로 무리를 구하고 그 평균값을 각각의 위치에 넣는다.
 * 하지만 그 위치에 바로 넣으면 다음 실행하는 위치에서 확인 할 때 값이 바뀌어 있으므로
 * 그 위치로 다시 방문 할 수 있으므로 bd 배열을 계속 참조하고 값은 tmp 배열에 갱신한다.
 * 모두 진행하면 다시 tmp 배열의 값들을 bd 배열로 복사해준다.
 * 이걸 적고 있다보니 visit으로 체크하기 때문에 굳이 하지 않아도 되는 부분인 것 같다.
 *
 */

 #define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
 #include <iostream>
 #include <vector>
 #include <queue>
 #include <string.h>
 using namespace std;
 
 int N, L, R;
 int bd[50][50], tmp[50][50];
 bool visit[50][50];
 bool flag = true;
 
 const int dx[] = { 1, 0, -1, 0 };
 const int dy[] = { 0, 1, 0, -1 };
 
 void bfs(int x, int y) {
 	vector<pair<int, int>> v; // 인구 이동이 진행되는 좌표 저장
 	queue<pair<int, int>> q;
 	q.push({ x, y });
 	v.push_back({ x, y });
 	visit[y][x] = true;
 	int sum = bd[y][x];
 	while (!q.empty()) {
 		int xx = q.front().first;
 		int yy = q.front().second;
 		q.pop();
 		for (int i = 0; i < 4; ++i) {
 			int cx = xx + dx[i];
 			int cy = yy + dy[i];
 
 			if (cx < 0 || cy < 0 || cx >= N || cy >= N || visit[cy][cx]) // 경계조건
 				continue;
 			if (L <= abs(bd[yy][xx] - bd[cy][cx]) && abs(bd[yy][xx] - bd[cy][cx]) <= R) {
 				q.push({ cx, cy });
 				v.push_back({ cx, cy });
 				visit[cy][cx] = true;
 				sum += bd[cy][cx];
 			}
 		}
 	}
 
 	if (v.size() != 1) { // 종료조건
 		flag = true;
 		int div = sum / v.size();
 		for (int i = 0; i < v.size(); ++i)
 			tmp[v[i].second][v[i].first] = div;
 	}
 }
 
 
 int main(int argc, char** argv)
 {
 	fastio();
 
 	cin >> N >> L >> R;
 	for (int i = 0; i < N; ++i)
 		for (int j = 0; j < N; ++j)
 			cin >> bd[i][j];
 	memcpy(tmp, bd, sizeof(bd)); // tmp 배열에 bd의 배열을 복사해두고
 	int rslt = 0;
 	while (flag) {
 		flag = false;
 		for (int i = 0; i < N; ++i) {
 			for (int j = 0; j < N; ++j)
 				if (!visit[i][j])
 					bfs(j, i);
 		}
 		rslt++;
 		memcpy(bd, tmp, sizeof(tmp)); // 연산 다된 tmp 배열을 다시 bd배열로 복사
 		memset(visit, false, sizeof(visit));
 	}
 	cout << rslt - 1 << '\n'; // 마지막으로 한번 더 돌면서 1개씩 나뉘어 있는지 확인하기 때문에
 	return 0;
 }