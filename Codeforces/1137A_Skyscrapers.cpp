/*
 * 1137A. Skyscrapers
 *
 * �ð����⵵ : O(N * N * log(N))
 *
 * implementation, sorting
 * �� sky �迭���� (i, j)�� ��ġ�� ���� ���ο� ���ο� ���ؼ�
 * ũ�� ������ ������ �ϰ� �� �� �ִ밪�� sky[i][j]�� ������ �ٲٴ� ����
 * pair�� ����ؼ� �� ��� ���� ���� �ް� �����ؼ� �ս��� ���� �ٲ� �� �־���
 * ��� ���� ���� (i, j)�� ���� �ٸ� ��쿡�� �� ���� ���� �� ���̸�ŭ �����־�
 * �ִ밪�� ���غ��� ������ ���� �ذ�
 *
 */

#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, sky[1001][1001], skyrow[1001][1001], skycol[1001][1001];
int mrow[1001], mcol[1001];
int main(int argc, char** argv) {
	
	vector<pair<int, int>> tmpr, tmpc;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> sky[i][j];

	for (int i = 1; i <= n; ++i) { // �� �࿡ ���ؼ� ����
		for (int j = 1; j <= m; ++j)
			tmpr.push_back({ sky[i][j], j });
		sort(tmpr.begin(), tmpr.end(), greater<pair<int, int>>()); // �������� ����

		int cnt = 1, val = 0;
		while (!tmpr.empty()) {
			if (val == tmpr.back().first)	--cnt; // ������ ���� ���̸� ���� ���ڸ� �־��ֱ� ���ؼ�
			skyrow[i][tmpr.back().second] = cnt++; // �� ��ġ�� ũ�� ������ ��ȣ�� �ű�
			val = tmpr.back().first;
			tmpr.pop_back(); // �������̱� ������ ���� pop���� ������ ���� �� ����
		}
		mrow[i] = cnt - 1; // �� ���� �ִ밪�� ����
	}

	for (int i = 1; i <= m; ++i) { // �� ���� ���ؼ� ����
		for (int j = 1; j <= n; ++j)
			tmpc.push_back({ sky[j][i], j });
		sort(tmpc.begin(), tmpc.end(), greater<pair<int, int>>()); // �������� ����

		int cnt = 1, val = 0;
		while (!tmpc.empty()) {
			if (val == tmpc.back().first)	--cnt; // ������ ���� ���̸� ���� ���ڸ� �־��ֱ� ���ؼ�
			skycol[tmpc.back().second][i] = cnt++; // �� ��ġ�� ũ�� ������ ��ȣ�� �ű�
			val = tmpc.back().first;
			tmpc.pop_back();
		}
		mcol[i] = cnt - 1; // �� ���� �ִ밪�� ����
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (skyrow[i][j] >= skycol[i][j]) // �ش� ��ġ���� �࿡ ���� ���� ũ�Ⱑ ũ�ٸ� ���� �� ���̸�ŭ ������ �ִ밪�� ��
				sky[i][j] = mcol[j] + skyrow[i][j] - skycol[i][j] > mrow[i] ? mcol[j] + skyrow[i][j] - skycol[i][j] : mrow[i];
			else
				sky[i][j] = mrow[i] + skycol[i][j] - skyrow[i][j] > mcol[j] ? mrow[i] + skycol[i][j] - skyrow[i][j] : mcol[j];
			cout << sky[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}