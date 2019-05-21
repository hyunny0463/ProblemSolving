/*
 * 3190. 뱀
 *
 * 시간복잡도 : O(N * L)
 *
 * 뱀의 이동을 나타내기 위해서 deque를 사용했다.
 * 주어진 방향으로 이동을 하고 그 공간이 빈 공간이라면
 * 그 자리를 deque의 맨 뒤에 넣어주고, 꼬리부분을 pop 하는 방식으로 이동하였다.
 * 사과를 만나면 꼬리를 pop 하지 않기만 하면 된다.

 * 단순히 이동에 대해서만 생각하다가, 게임이 종료되는 조건을
 * 제대로 파악하지 못했다. 주어진 방향 전환 이전에 게임이 종료된다면
 * 그 때의 시간을 출력하면 되었지만, 시간 내에 끝나지 않았을 때,
 * 보드의 크기만큼 더 가보고 게임을 종료하는 조건을 추가함으로써 해결할 수 있었다.
 *
 */

 #define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
 #include <iostream>
 #include <deque>
 using namespace std;
 
 int N, K, L; // 보드크기, 사과의 개수, 뱀의 방향 변환 횟수
 int time, dir; // 현재까지 지난 시간, 현재 바라보는 방향
 int bd[102][102];
 bool flag = false;
 deque<pair<int, int>> dq;
 pair<int, int> pos;
 
 const int dx[] = { 1, 0, -1, 0 };
 const int dy[] = { 0, 1, 0, -1 };
 
 bool movesnake(int X, char C) {
 	while (time < X) {
 		time++;
 		pos.first += dx[dir];
 		pos.second += dy[dir];
 		dq.push_back(pos);
 		if (!bd[pos.second][pos.first]) { // 뱀이 움직인 자리에 아무것도 없으면
 			bd[dq.front().second][dq.front().first] = 0; // 맵에서 뱀 꼬리 한 칸 지움
 			dq.pop_front(); // dq에서 지움
 		}
 		else if (bd[pos.second][pos.first] == 2) { // 뱀이 벽을 만나거나 자기 몸통을 만나면 
 			flag = true; // 종료 플래그를 참으로 변경
 			return 0; // 벽 만났을 때 false를 리턴
 		}
 		bd[pos.second][pos.first] = 2; // 지도에 뱀 머리 표시
 	}
 	dir = (C == 'D') ? (dir + 1) % 4 : (dir + 3) % 4; // D 이면 오른쪽, L 이면 왼쪽으로 회전
 	return 1; // 벽 안만났을 때 true를 리턴
 }
 
 int main(int argc, char** argv) {
 
 	cin >> N >> K; // 보드 크기, 사과의 개수
 	for (int i = 0; i <= N + 1; ++i) {
 		for (int j = 0; j <= N + 1; ++j) {
 			if (i == 0 || j == 0 || i == N + 1 || j == N + 1) // 벽인 경우
 				bd[i][j] = 2;
 			else
 				bd[i][j] = 0;
 		}
 	}
 	time = 0, dir = 0;
 	pos = { 1, 1 }; // 처음 시작점
 	dq.push_back(pos); // 첫 시작점을 dq에 넣음
 	bd[pos.second][pos.first] = 2; // 뱀이 위치한 자리는 2로 표시
 	for (int i = 0, r, c; i < K; ++i) {
 		cin >> r >> c;
 		bd[r][c] = 1; // 사과 위치에 1로 저장
 	}
 	cin >> L;
 	for (int i = 0; i < L; ++i) {
 		int X;
 		char C;
 		cin >> X >> C;
 		if (!movesnake(X, C)) {
 			flag = true;
 			break;
 		}
 	}
 	while (!flag) // 입력 받은 방향전환을 다해도 게임이 안끝나면 보드 크기만큼 시간동안 더 진행
 		movesnake(time + N, 0);
 
 	cout << time << '\n'; // 시간 출력
 
 	return 0;
 }