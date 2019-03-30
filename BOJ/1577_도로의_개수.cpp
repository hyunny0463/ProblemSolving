/*
 * 1577. 도로의 개수
 *
 * 시간복잡도 : O(N * M)
 *
 * Dynamic Programming
 * (0, 0) 기준 가로와 세로의 값은 공사 중인 도로가 없다면 1로 초기화해주고
 * 내부의 값은 해당 좌표 좌측 그리고 위쪽 값을 더해준 값으로 한다
 * 연산 도중에 해당 좌표와 위쪽 도시와의 도로가 공사중이면 위쪽 값은 더해주지 않는다
 * 같은 방법으로 좌측 도시와의 계산을 진행한다.

 * 처음엔 중학교에서 배운좌표에서 좌표로 이동하는 경우의 수를
 * 찾는 방법을 사용해보려했는데 팩토리얼 계산이 쉽지가 않은 점이 있고
 * 공사중인 도로가 아닌 점까지 계산 하는게 쉽지가 않아서 단순하게 계산함
 *
 */

 #define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
 #include <iostream>
 using namespace std;
 
 int main(int argc, char** argv)
 {
 	fastio();
 
 	long long int road[101][101] = { 0 };
 	int underconstruction[101][101][2] = { 0 }; // 0 : 가로, 1 : 세로
 	int N, M, K;
 	cin >> N >> M >> K;
 	for (int i = 0, a, b, c, d; i < K; ++i) { // 공사 중인 도로 입력
 		cin >> a >> b >> c >> d;
 		if (a == c) { // 세로 도로가 공사 중
 			if (b > d)
 				underconstruction[d][c][1]++;
 			else
 				underconstruction[b][a][1]++;
 		}
 		else { // 가로 도로가 공사 중
 			if (a > c)
 				underconstruction[d][c][0]++;
 			else
 				underconstruction[b][a][0]++;
 		}
 	}
 
 	road[0][0] = 1;
 	for (int i = 1; i <= N; ++i) { // 첫번째 행 처리
 		road[0][i] = road[0][i - 1];
 		if (underconstruction[0][i - 1][0])
 			road[0][i] = 0;
 	}
 
 	for (int i = 1; i <= M; ++i) { // 첫번째 열 처리
 		road[i][0] = road[i - 1][0];
 		if (underconstruction[i - 1][0][1])
 			road[i][0] = 0;
 	}
 
 	for (int i = 1; i <= M; ++i) {
 		for (int j = 1; j <= N; ++j) {
 			road[i][j] = road[i - 1][j] + road[i][j - 1]; // 해당 좌표 기준으로 좌측 값, 위쪽 값을 더해줌
 			if (underconstruction[i][j - 1][0]) // 해당 좌표와 좌측 좌표 사이에 도로가 있으면
 				road[i][j] -= road[i][j - 1]; // 좌측 값은 다시 빼줌
 			if (underconstruction[i - 1][j][1]) // 해당 좌표와 위쪽 좌표 사이에 도로가 있으면
 				road[i][j] -= road[i - 1][j]; // 위쪽 값은 다시 빼줌
 		}
 	}
 	cout << road[M][N] << '\n';
 
 	return 0;
 }