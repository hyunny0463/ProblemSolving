/*
 * 2140. ����ã��
 *
 * �ð����⵵ : O(N * M)
 *
 * Implementation
 * �迭�� �׵θ����� ���ڰ� �־����� �׵θ� ���ʿ��� '#'���� �𸣴� ���·� �־�����.
 * �̰��� �˾Ƴ��� ���ؼ� �켱 0�̰ų� 3�� ���� ��� '#'�� 0�̳� '*'�� �ٲ��ش�.
 * �׸��� 1�� 2�� ���� ���� ������ ������ �־ ��� ��쿡 ���� �����ϵ��� ���־���.

 * �ٸ� ������δ� '#'�� ��� Ž���ϸ鼭 �ֺ��� ���ڰ� 0�� �ִ��� Ȯ���ϰ�
 * �׷��� ������ ī��Ʈ�ϸ鼭 ��� ������ ������ ã�� ����� �ִ�.
 *
 */

#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#include <iostream>
using namespace std;
 
char bd[102][102] = { 0 };

int look(int x, int y, int xx, int yy, char type) { // x ~ xx, y ~ yy ��ǥ���� type�� ���� ����
	int ret = 0;
	for (int i = y; i <= yy; ++i)
		for (int j = x; j <= xx; ++j)
			if (bd[i][j] == type)
				ret++;
	return ret;
}

void change(int x, int y, int xx, int yy, char type) { // x ~ xx, y ~ yy ��ǥ���� '#'�� type���� �ٲ�
	for (int i = y; i <= yy; ++i)
		for (int j = x; j <= xx; ++j)
			if (bd[i][j] == '#')
				bd[i][j] = type;
}

int main(int argc, char** argv)
{
	fastio();

	int N;
	cin >> N;
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			cin >> bd[i][j];

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			if (i == 1) { // 1�࿡�� 0�� 3�� ���
				if (bd[i][j] == '0') // 0�̸� �ֺ� '#'�� ��� 0���� �ٲ۴�
					change(j - 1, i + 1, j + 1, i + 1, 0);
				else if (bd[i][j] == '3') // 3�̸� �ֺ� '#'�� ��� '*'�� �ٲ۴�
					change(j - 1, i + 1, j + 1, i + 1, '*');
			}
			if (j == 1) { // 1���� 0�� 3�� ���
				if (bd[i][j] == '0')
					change(j + 1, i - 1, j + 1, i + 1, 0);
				else if (bd[i][j] == '3')
					change(j + 1, i - 1, j + 1, i + 1, '*');
			}
			if (i == N) { // ������ ���� 0�� 3�� ���
				if (bd[i][j] == '0')
					change(j - 1, i - 1, j + 1, i - 1, 0);
				else if (bd[i][j] == '3')
					change(j - 1, i - 1, j + 1, i - 1, '*');
			}
			if (j == N) { // ������ ���� 0�� 3�� ���
				if (bd[i][j] == '0')
					change(j - 1, i - 1, j - 1, i + 1, 0);
				else if (bd[i][j] == '3')
					change(j - 1, i - 1, j - 1, i + 1, '*');
			}
		}
	}

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			if (i == 1) { // 1���� ��
				int st = look(j - 1, i + 1, j + 1, i + 1, '*');
				int sh = look(j - 1, i + 1, j + 1, i + 1, '#');
				if (bd[i][j] == '1') { // ��ǥ���� ���� '1'�̸� 
					if (st == 0 && sh == 1) // '*'�� 0�� '#'�� 1���� �������� '*'��
						change(j - 1, i + 1, j + 1, i + 1, '*');
					else if (st == 1 && sh >= 1) // '*'�� 1�� '#'�� 1���� �������� 0����
						change(j - 1, i + 1, j + 1, i + 1, 0);
				}
				else if (bd[i][j] == '2') { // ��ǥ���� ���� '2'�̸�
					if (st == 0 && sh == 2) // '*'�� 0�� '#'�� 2���� �������� '*'��
						change(j - 1, i + 1, j + 1, i + 1, '*');
					else if (st == 1 && sh == 1) // '*'�� 1�� '#'�� 1���� �������� '*'��
						change(j - 1, i + 1, j + 1, i + 1, '*');
					else if (st == 2 && sh == 1) // '*'�� 2�� '#'�� 1���� �������� 0����
						change(j - 1, i + 1, j + 1, i + 1, 0);
				}
			}
			if (j == 1) {
				int st = look(j + 1, i - 1, j + 1, i + 1, '*');
				int sh = look(j + 1, i - 1, j + 1, i + 1, '#');
				if (bd[i][j] == '1') {
					if (st == 0 && sh == 1)
						change(j + 1, i - 1, j + 1, i + 1, '*');
					else if (st == 1 && sh >= 1)
						change(j + 1, i - 1, j + 1, i + 1, 0);
				}
				else if (bd[i][j] == '2') {
					if (st == 0 && sh == 2)
						change(j + 1, i - 1, j + 1, i + 1, '*');
					else if (st == 1 && sh == 1)
						change(j + 1, i - 1, j + 1, i + 1, '*');
					else if (st == 2 && sh == 1)
						change(j + 1, i - 1, j + 1, i + 1, 0);
				}
			}
			if (i == N) {
				int st = look(j - 1, i - 1, j + 1, i - 1, '*');
				int sh = look(j - 1, i - 1, j + 1, i - 1, '#');
				if (bd[i][j] == '1') {
					if (st == 0 && sh == 1)
						change(j - 1, i - 1, j + 1, i - 1, '*');
					if (st == 1 && sh >= 1)
						change(j - 1, i - 1, j + 1, i - 1, 0);
				}
				else if (bd[i][j] == '2') {
					if (st == 0 && sh == 2)
						change(j - 1, i - 1, j + 1, i - 1, '*');
					else if (st == 1 && sh == 1)
						change(j - 1, i - 1, j + 1, i - 1, '*');
					else if (st == 2 && sh == 1)
						change(j - 1, i - 1, j + 1, i - 1, 0);
				}
			}
			if (j == N) {
				int st = look(j - 1, i - 1, j - 1, i + 1, '*');
				int sh = look(j - 1, i - 1, j - 1, i + 1, '#');
				if (bd[i][j] == '1') {
					if (st == 0 && sh == 1)
						change(j - 1, i - 1, j - 1, i + 1, '*');
					if (st == 1 && sh >= 1)
						change(j - 1, i - 1, j - 1, i + 1, 0);
				}
				else if (bd[i][j] == '2') {
					if (st == 0 && sh == 2)
						change(j - 1, i - 1, j - 1, i + 1, '*');
					else if (st == 1 && sh == 1)
						change(j - 1, i - 1, j - 1, i + 1, '*');
					else if (st == 2 && sh == 1)
						change(j - 1, i - 1, j - 1, i + 1, 0);
				}
			}
		}
	}

	int cnt = 0;
	for (int i = 2; i < N; ++i)
		for (int j = 2; j < N; ++j)
			if (bd[i][j] == '*' || bd[i][j] == '#')
				cnt++; // '*'�� �������� ���� '#' ���� ���ڷ� �� �� �ִ�. �ִ밪�̰�, ���ڰ� �����ϱ�

	cout << cnt << '\n';

	return 0;
}