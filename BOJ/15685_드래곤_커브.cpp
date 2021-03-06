/*
 * 15685. 드래곤 커브
 *
 * 시간복잡도 : O(N * 2^g)
 *
 * simulation
 * 드래곤 커브의 방향을 모두 알아내서 격자에 저장하는 방법을 사용한다.
 * 드래곤 커브 방향의 규칙은 처음 주어진 방향을 시작으로 벡터에 저장한다.
 * 그 다음은 벡터에 존재하는 모든 벡터를 거꾸로 세면서 90도 회전한 방향을
 * 벡터 뒤에 넣어준다. 시계방향으로 90도 회전한 방향은 현재 방향 +1 이 되고
 * 예를 들면 
 * 1
 * 1 - 2 
 * 1 - 2 - 3 - 2
 * 1 - 2 - 3 - 2 - 3 - 0 - 3 - 2
 * 위의 방식으로 드래곤 커브가 그려지고 개수 또한 2^g 으로 증가한다.
 * 드래곤 커브를 그렸다면 마지막으로 현재좌표, 오른쪽, 아래, 대각선아래 모두 확인하며
 * 4개가 모두 있으면 카운트하여 답을낸다.

 * 처음 문제를 풀 때는 위의 방식을 생각하지 않고 bfs를 통해 매번 길의 방향을 찾아서
 * 90도 회전하여 연결해주는 방식으로 문제를 해결하려고 했는데
 * 대체적으로 생각했던 대로 따라갔는데, 문제점이 4개점이 사각형형태로 붙어있으면
 * 원하는 대로 길을 찾아가지 않기 때문에 드래곤 커브를 제대로 만들지 못하는 문제가 있었다.
 
 * 그래서 다시 생각한 방법은 매번 좌표와 방향을 저장하여 따라가는 방법이였는데
 * 이 방법으로는 해결할 수 있지만 아래와 같이 문제를 해결한 방법이 훨씬 효율적이라 생각해서
 * 그 방법으로는 시도하지 않았다.

 * 그리고 아래와 같이 벡터를 사용하지 않고 배열을 사용한다면 조금 더 빠르게 동작가능하다.
 * 배열의 크기는 10세대가 최대이므로 2^10의 크기인 1024를 최대로 잡아놓으면 된다.
 *
 */

#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#include <iostream>
#include <vector>
using namespace std;

int bd[101][101];

const int dx[] = { 1, 0, -1, 0 };
const int dy[] = { 0, -1, 0, 1 };

void makeDC(int x, int y, int d, int g) { // x, y, 방향, 세대
	vector<int> v;
	v.push_back(d); // 첫 방향 push
	for (int i = 0; i < g; ++i) { // 세대 만큼 반복
		for (int j = v.size() - 1; j >= 0; --j) { // 벡터 크기만큼 거꾸로 벡터에 다시 넣어줌
			v.push_back((v[j] + 1) % 4); // 시계방향으로 회전한 방향을 집어넣음
		}
	}

	bd[y][x]++; // 첫 좌표 위치
	for (int i = 0; i < v.size(); ++i) { // 저장해둔 방향들을 따라가면서 체크
		x += dx[v[i]];
		y += dy[v[i]];
		bd[y][x]++;
	}
}

int main(int argc, char** argv)
{
	fastio();
	int N;
	cin >> N;
	for (int i = 0, x, y, d, g; i < N; ++i) { // 매번 입력받은 드래곤 커브를 맵에 표시
		cin >> x >> y >> d >> g;
		makeDC(x, y, d, g);
	}

	int rslt = 0;
	for (int i = 0; i < 100; ++i)
		for (int j = 0; j < 100; ++j) // 4개 인접한지 확인
			if (bd[i][j] && bd[i][j + 1] && bd[i + 1][j] && bd[i + 1][j + 1])
				rslt++;
	cout << rslt << '\n';

	return 0;
}