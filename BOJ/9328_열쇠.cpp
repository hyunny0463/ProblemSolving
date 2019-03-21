/*
 * 9328. ����
 *
 * �ð����⵵ : O(h * w)
 *
 * �Ա����� ���� BFS�� �����Ͽ� ���� ������ ��� ������ �湮�Ѵ�.
 * �ش��ϴ� �� ���谡 ������ ������
 * �׷��� ������ door ���Ϳ� ���� �����صд�.
 * ���踦 �ֿ��� �� �ش��ϴ� ���� �ִٸ� queue�� �����Ͽ� 
 * ���谡 ���� �湮���� ���� ������ �湮�� �� �ְ� �Ѵ�.
 *
 * ������ ������ �ۿ��� ������ �ѷ� �δ� ������ bfs�� ������ ��
 * 1���� ū�� h�� w ���� �������� ���� ���ǹ��� Ȯ���ϴ� ���� ���̰���
 * �Ա��� ���� ���� �����ߴµ� ������ ������ ������ �ѷ��ο� �ִ� ����
 * ������ �ѷ��ο� �ִ� ��� ���谡 �ִ� �׽�Ʈ ���̽��� �־ 
 * ��ó�� ���־�� �ϴ� �κ��� ��������.
 * �¿���Ͽ� ��ĭ�� ���������� �� �ξ� ������ �ѷ��δ� �������
 * �� ������ �ѷ��δ� ���� ����ٸ� �Ա���� ������� ��ó���� ����
 * �� �����ϰ� ���������ϴ�.
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

			if (visit[yy][xx] || bd[yy][xx] == '*') // �̹� �湮�߰ų� ���� ���� �Ѿ��
				continue;

			visit[yy][xx] = true;

			if (bd[yy][xx] == '$') // ������ �߰��� ���
				ret++;
			else if (bd[yy][xx] >= 'a' && bd[yy][xx] <= 'z') { // ���踦 �߰��� ���
				int idx = bd[yy][xx] - 'a';
				key[idx] = true;
				for (int j = 0; j < door[idx].size(); ++j)
					q.push({ door[idx][j] }); // �������� ���� �̹� ���������� �� ���� ť�� ����
				door[idx].clear();
			}
			else if (bd[yy][xx] >= 'A' && bd[yy][xx] <= 'Z') { // ���� �߰��� ���
				int idx = bd[yy][xx] - 'A';
				if (!key[idx]) { // ������ ���谡 ������
					door[idx].push_back({ xx, yy }); // door ���Ϳ� �����صд�
					continue;
				}
			}
			q.push({ xx, yy });
		}
	}
	return ret; // ã�� ������ ����
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
		vector<vector<char>> bd(h + 2, vector<char>(w + 2, '*')); // �Է¹��� �κ� ���� ������ �ѷ���
		for (int i = 1; i <= h; ++i) {
			for (int j = 1; j <= w; ++j) {
				cin >> bd[i][j];
				if (i == 1 || i == h || j == 1 || j == w) { // �Է� ���� �� �׵θ� �κ�
					if (bd[i][j] == '*')
						continue;
					else if (bd[i][j] == '.') // �Ա��� ���
						enter.push_back({ j, i });
					else if (bd[i][j] >= 'A' && bd[i][j] <= 'Z') // ���谡 �ʿ��� ��
						door[bd[i][j] - 'A'].push_back({ j, i });
					else if (bd[i][j] >= 'a' && bd[i][j] <= 'z') { // ���赵 �Ա��� ��
						key[bd[i][j] - 'a'] = true;
						enter.push_back({ j, i });
						visit[j][i] = true;
					}
					else if (bd[i][j] == '$') { // �ٷ� ������ ���� ��쵵 �Ա��� ��
						rslt++;
						enter.push_back({ j, i });
						visit[j][i] = true;
					}
				}
			}
		}

		string kkey;
		cin >> kkey;
		for (int i = 0; i < kkey.size(); ++i) { // ���� �Է¹޾� ����
			int idx = kkey[i] - 'a';
			if (kkey[0] == '0')
				break;
			key[idx] = true;
		}
		for (int i = 0; i < 'z' - 'a' + 1; ++i) {
			if (key[i]) { // ���谡 ������
				for (int j = 0; j < door[i].size(); ++j)
					enter.push_back({ door[i][j] }); // �ش� ���� �Ա��� ����
				door[i].clear();
			}
		}

		for (int i = enter.size() - 1; i >= 0; --i) {
			rslt += bfs(enter[i].first, enter[i].second, bd); // �Ա��� �ش��ϴ� �������� bfs ����
			enter.pop_back();
		}
		cout << rslt << '\n';
	}
	return 0;
}