/*
 * 1347. �̷� �����
 *
 * �ð����⵵ : O(N)
 *
 * �ùķ��̼� ����
 * ȫ���̰� �ٶ󺸴� ������ sight��� ������ ��Ÿ��������
 * R, L �� ������ �׿� ���� ���� �ø��ų� �����־���.
 * ��ɾ��� ������ �ִ� 50�� �̹Ƿ� [100, 100] ũ���� �迭�� ����������
 * ȫ������ ó�� ��ġ�� [50, 50]�� ���ߴ�.
 * x�� y�� �ּҰ�, �ִ밪�� �����Ͽ� �̵��� ��θ� ����� �� �ְ� �ߴ�.
 *
 *
 */

#define _CRT_SECURE_NO_WARNINGS
#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#include<iostream>
using namespace std;

const int dx[] = { 0, -1, 0, 1 };
const int dy[] = { 1, 0, -1, 0 };

int main(int argc, char** argv)
{
	char miro[101][101]; // �Է¹޴� ���� �ִ� ���̰� 50�̹Ƿ�
	for (int i = 0; i < 101; ++i)
		for (int j = 0; j < 101; ++j)
			miro[i][j] = '#'; // '#'���� �ʱ�ȭ�Ͽ� �̵��ϴ� �κ� �ܿ��� '#'�� ���
	int cx = 50, cy = 50; // 100, 100 �迭���� 50, 50���� �����Ͽ� �����¿� 50�̵��ص� ������
	int minx, miny, maxx, maxy; // x, y�� �ּ� ��ǥ, x, y�� �ִ� ��ǥ
	minx = miny = maxx = maxy = 50;
	miro[cy][cx] = '.'; // ó�� ��ġ

	int L;
	cin >> L;
	for (int i = 0, sight = 0; i < L; ++i) { // sight : �����ִ� ����
		char command;
		cin >> command; // �� ���ھ� �Է¹޾� ����� ������

		if (command == 'F') {
			cx += dx[sight];
			cy += dy[sight];
			miro[cy][cx] = '.';
			maxx = maxx > cx ? maxx : cx;
			minx = minx < cx ? minx : cx;
			maxy = maxy > cy ? maxy : cy;
			miny = miny < cy ? miny : cy;
		}
		else if (command == 'R') // dx, dy�� �ε����� ���������� �̵�
			sight = (sight + 1) % 4; // �� -> �� -> �� -> �� -> ��
		else if (command == 'L') // dx, dy�� �ε����� �������� �̵�
			sight = (sight + 3) % 4; // �� -> �� -> �� -> �� -> ��
	}

	for (int i = miny; i <= maxy; ++i) {
		for (int j = minx; j <= maxx; ++j)
			cout << miro[i][j];
		cout << '\n';
	}

	return 0;
}