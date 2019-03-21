/*
 * 9328. 열쇠
 *
 * 시간복잡도 : O(h * w)
 *
 * 입구에서 부터 BFS를 시작하여 벽을 제외한 모든 공간에 방문한다.
 * 해당하는 문 열쇠가 있으면 들어가지만
 * 그렇지 않으면 door 벡터에 따로 저장해둔다.
 * 열쇠를 주웠을 때 해당하는 문이 있다면 queue에 저장하여 
 * 열쇠가 없어 방문하지 못한 공간을 방문할 수 있게 한다.
 *
 * 빌딩의 데이터 밖에는 벽으로 둘러 싸는 것으로 bfs를 실행할 때
 * 1보다 큰지 h나 w 보다 작은지에 대한 조건문을 확인하는 것을 줄이고자
 * 입구에 대한 것을 생각했는데 오히려 빌딩이 문으로 둘러싸여 있는 경우와
 * 문서로 둘러싸여 있는 경우 열쇠가 있는 테스트 케이스가 있어서 
 * 전처리 해주어야 하는 부분이 많아졌다.
 * 좌우상하에 한칸의 여유공간을 더 두어 빌딩을 둘러싸는 빈공간과
 * 그 공간을 둘러싸는 벽을 만든다면 입구라는 개념없이 전처리도 없이
 * 더 간단하게 구현가능하다.
 *
 */

#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#include <iostream>
#include <string>
#include <string.h> // for memset
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int>> door['Z' - 'A' + 1], enter;
bool visit[101][101];
bool key['z' - 'a' + 1];

const int dx[] = { 1, 0, -1, 0 };
const int dy[] = { 0, -1, 0, 1 };

int bfs(int x, int y, vector<vector<char>>& bd)
{
	int ret = 0;
	queue<pair<int, int>> q;
	q.push({ x, y });
	visit[y][x] = true;

	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int xx = cx + dx[i];
			int yy = cy + dy[i];

			if (visit[yy][xx] || bd[yy][xx] == '*') // 이미 방문했거나 벽인 경우는 넘어간다
				continue;

			visit[yy][xx] = true;

			if (bd[yy][xx] == '$') // 문서를 발견한 경우
				ret++;
			else if (bd[yy][xx] >= 'a' && bd[yy][xx] <= 'z') { // 열쇠를 발견한 경우
				int idx = bd[yy][xx] - 'a';
				key[idx] = true;
				for (int j = 0; j < door[idx].size(); ++j)
					q.push({ door[idx][j] }); // 열지못한 문을 이미 지나왔으면 그 문을 큐에 넣음
				door[idx].clear();
			}
			else if (bd[yy][xx] >= 'A' && bd[yy][xx] <= 'Z') { // 문을 발견한 경우
				int idx = bd[yy][xx] - 'A';
				if (!key[idx]) { // 하지만 열쇠가 없으면
					door[idx].push_back({ xx, yy }); // door 벡터에 저장해둔다
					continue;
				}
			}
			q.push({ xx, yy });
		}
	}
	return ret; // 찾은 문서의 개수
}

int main(int argc, char** argv)
{
	freopen("input.txt", "r", stdin);
	int T;
	cin >> T;
	for (int testcase = 1, h, w; testcase <= T; ++testcase) {
		int rslt = 0;
		memset(visit, 0, sizeof(visit));
		memset(key, false, sizeof(key));
		for (int i = 0; i < 'Z' - 'A' + 1; ++i)
			door[i].clear();

		cin >> h >> w;
		vector<vector<char>> bd(h + 2, vector<char>(w + 2, '*')); // 입력받은 부분 밖은 벽으로 둘러쌈
		for (int i = 1; i <= h; ++i) {
			for (int j = 1; j <= w; ++j) {
				cin >> bd[i][j];
				if (i == 1 || i == h || j == 1 || j == w) { // 입력 받을 때 테두리 부분
					if (bd[i][j] == '*')
						continue;
					else if (bd[i][j] == '.') // 입구일 경우
						enter.push_back({ j, i });
					else if (bd[i][j] >= 'A' && bd[i][j] <= 'Z') // 열쇠가 필요한 문
						door[bd[i][j] - 'A'].push_back({ j, i });
					else if (bd[i][j] >= 'a' && bd[i][j] <= 'z') { // 열쇠도 입구가 됨
						key[bd[i][j] - 'a'] = true;
						enter.push_back({ j, i });
						visit[j][i] = true;
					}
					else if (bd[i][j] == '$') { // 바로 문서가 있을 경우도 입구가 됨
						rslt++;
						enter.push_back({ j, i });
						visit[j][i] = true;
					}
				}
			}
		}

		string kkey;
		cin >> kkey;
		for (int i = 0; i < kkey.size(); ++i) { // 열쇠 입력받아 저장
			int idx = kkey[i] - 'a';
			if (kkey[0] == '0')
				break;
			key[idx] = true;
		}
		for (int i = 0; i < 'z' - 'a' + 1; ++i) {
			if (key[i]) { // 열쇠가 있으면
				for (int j = 0; j < door[i].size(); ++j)
					enter.push_back({ door[i][j] }); // 해당 문을 입구에 저장
				door[i].clear();
			}
		}

		for (int i = enter.size() - 1; i >= 0; --i) {
			rslt += bfs(enter[i].first, enter[i].second, bd); // 입구에 해당하는 지점마다 bfs 실행
			enter.pop_back();
		}
		cout << rslt << '\n';
	}
	return 0;
}