/*
 * 17135. ĳ�� ���潺
 *
 * �ð����⵵ : O(N * M)
 *
 * simulation, conbination

 * ������ ������ �Է� �޴� ���ÿ� ������ ������ deque�� �����ߴ�.
 * ���� ����� queue ó�� ����ϱ� �ϳ� ������ ��� ��
 * chkenemy �κп��� ó������ ������ ��ȸ�ϸ鼭
 * Ȯ���� �ʿ䰡 �־ deque�� ����ϰ� �Ǿ���.
 * �ü��� �� 3���̹Ƿ� for���� �̿��Ͽ� ��ġ�� �����Ͽ���.
 * �̴� ���հ� ������ �ְ�, �� ���� �ü��� �ִٸ� permutation���� �ذᰡ���ϴ�.
 * �־��� ���ǿ� �����ϰ� ���� ������ ���ʿ� �ִ� ������ ã�Ƽ�
 * �����ְ� ���� �����ִ� ������ �Լ��� �����Ͽ� �ذ�����.

 * ó�� bd �迭�� ���� ������ �޴µ� ������� �ʾұ� ������ �ʿ䰡 ����.
 * killenemy, blockdown �Լ� �κп����� ���� ������
 * �ڷῡ�� �ƿ� ���������� �;� queue�� �������鼭
 * ������ �����־��� ���� blockdown�� �ϸ鼭 ������ ���� ������ �����־���.
 * ������ ������ ���� ���� ������ ������ ���ŷӰ� ���� ����̴�.
 *
 */

#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#include <iostream>
#include <algorithm>
#include <deque>
#include <string.h>
using namespace std;

int N, M, D;
int rslt, cnt;
int bd[15][15];
deque<pair<int, int>> enemy;
pair<int, int> deadenemy[3];
int chkdead[3] = { 0 };

void chkenemy(int x, int n) { // �ü� ��ġ, �ü� ��ȣ
	int mind = 1000;
	for (int i = 0; i < enemy.size(); ++i) {
		int dis = abs(enemy[i].first - x) + N - enemy[i].second; // �ü��� ���� �Ÿ�
		if (dis <= D && dis < mind) { // �� ª�� �Ÿ� ���� ã��
			deadenemy[n] = enemy[i];
			mind = dis;
			chkdead[n] = 1;
		}
		else if (dis <= D && dis <= mind && enemy[i].first < deadenemy[n].first) {
			deadenemy[n] = enemy[i]; // �Ÿ��� ���ų� ������ ���ʿ� �ִ� ���� ã��
			mind = dis;
		}
	}
}

void killenemy() { // enemy queue�� �����鼭 ���� ������ ���ִ� �۾�
	int qsize = enemy.size();
	for (int i = 0; i < qsize; ++i) {
		bool flag = false;
		for (int j = 0; j < 3; ++j) {
			if (!chkdead[j]) // �̹� ���� �����̸� continue
				continue;
			if (enemy.front() == deadenemy[j]) { // �׿����� ������ queue ó���� �ִ� ������ ������
				flag = true; // queue �ڿ� �ٽ� ���� �ʱ� ���� flag on
				cnt++; // ���� ���� �� ī��Ʈ
				chkdead[j] = 0;
				break;
			}
		}
		if (!flag) // �ƹ��� ������ �ʾҴٸ� �ش� ������ �� �ڷ� �־���
			enemy.push_back(enemy.front());
		enemy.pop_front(); // queue ���� �� ������ ����
	}
}

void blockdown() {
	int qsize = enemy.size(); // ��ü ���� ���� �ʰ� �����ص� ������ ������ �̿�
	for (int i = 0; i < qsize; ++i) {
		enemy.front().second++; // �ุ �÷���
		if (enemy.front().second < N) // ������ ����� ������ queue �ڿ� �ٿ���
			enemy.push_back(enemy.front());
		enemy.pop_front(); // ������ ����� ���ֹ���
	}
}

void solve(int a, int b, int c) {
	int arr[] = { a, b, c };
	while (enemy.size()) {
		for (int i = 0; i < 3; ++i) // �� �ü��� ���� ���� ����
			chkenemy(arr[i], i);
		killenemy(); // ���� ���̱�
		blockdown(); // ���� �Ʒ��� ����
	}
}

int main(int argc, char** argv) {
	fastio();
	cin >> N >> M >> D; // ��, ��, ���� �Ÿ� ����

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> bd[i][j];
			if (bd[i][j])
				enemy.push_back({ j, i }); // ��ũ�� ��ġ ����
		}
	}
	deque<pair<int, int>> tmpenemy = enemy;
	rslt = 0;
	for (int i = 0; i < M; ++i) { // 3�� �����ϴ� �����̹Ƿ� for�� ���
		for (int j = i + 1; j < M; ++j) {
			for (int k = j + 1; k < M; ++k) {
				cnt = 0;
				solve(i, j, k); // ������ �ü� ��ġ���� Ȯ��
				rslt = rslt > cnt ? rslt : cnt;
				enemy = tmpenemy; // ���� ��ġ �ʱ�ȭ
			}
		}
	}

	cout << rslt << '\n';

	return 0;
}