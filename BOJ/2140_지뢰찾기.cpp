/*
 * 2140. 지뢰찾기
 *
 * 시간복잡도 : O(N * M)
 *
 * Implementation
 * 배열의 테두리에만 숫자가 주어지고 테두리 안쪽에는 '#'으로 모르는 상태로 주어진다.
 * 이것을 알아내기 위해서 우선 0이거나 3을 보면 모든 '#'을 0이나 '*'로 바꿔준다.
 * 그리고 1과 2를 봤을 때의 조건을 나누어 주어서 모든 경우에 따라 실행하도록 해주었다.

 * 다른 방법으로는 '#'만 모두 탐색하면서 주변에 숫자가 0이 있는지 확인하고
 * 그렇지 않으면 카운트하면서 모든 지뢰의 개수를 찾는 방법이 있다.
 *
 */

#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#include <iostream>
using namespace std;
 
char bd[102][102] = { 0 };

int look(int x, int y, int xx, int yy, char type) { // x ~ xx, y ~ yy 좌표까지 type의 개수 구함
	int ret = 0;
	for (int i = y; i <= yy; ++i)
		for (int j = x; j <= xx; ++j)
			if (bd[i][j] == type)
				ret++;
	return ret;
}

void change(int x, int y, int xx, int yy, char type) { // x ~ xx, y ~ yy 좌표까지 '#'을 type으로 바꿈
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
			if (i == 1) { // 1행에서 0과 3인 경우
				if (bd[i][j] == '0') // 0이면 주변 '#'을 모두 0으로 바꾼다
					change(j - 1, i + 1, j + 1, i + 1, 0);
				else if (bd[i][j] == '3') // 3이면 주변 '#'을 모두 '*'로 바꾼다
					change(j - 1, i + 1, j + 1, i + 1, '*');
			}
			if (j == 1) { // 1열에 0과 3인 경우
				if (bd[i][j] == '0')
					change(j + 1, i - 1, j + 1, i + 1, 0);
				else if (bd[i][j] == '3')
					change(j + 1, i - 1, j + 1, i + 1, '*');
			}
			if (i == N) { // 마지막 행이 0과 3인 경우
				if (bd[i][j] == '0')
					change(j - 1, i - 1, j + 1, i - 1, 0);
				else if (bd[i][j] == '3')
					change(j - 1, i - 1, j + 1, i - 1, '*');
			}
			if (j == N) { // 마지막 열이 0과 3인 경우
				if (bd[i][j] == '0')
					change(j - 1, i - 1, j - 1, i + 1, 0);
				else if (bd[i][j] == '3')
					change(j - 1, i - 1, j - 1, i + 1, '*');
			}
		}
	}

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			if (i == 1) { // 1행일 때
				int st = look(j - 1, i + 1, j + 1, i + 1, '*');
				int sh = look(j - 1, i + 1, j + 1, i + 1, '#');
				if (bd[i][j] == '1') { // 좌표에서 값이 '1'이면 
					if (st == 0 && sh == 1) // '*'이 0개 '#'이 1개면 나머지는 '*'로
						change(j - 1, i + 1, j + 1, i + 1, '*');
					else if (st == 1 && sh >= 1) // '*'이 1개 '#'이 1개면 나머지는 0으로
						change(j - 1, i + 1, j + 1, i + 1, 0);
				}
				else if (bd[i][j] == '2') { // 좌표에서 값이 '2'이면
					if (st == 0 && sh == 2) // '*'이 0개 '#'이 2개면 나머지는 '*'로
						change(j - 1, i + 1, j + 1, i + 1, '*');
					else if (st == 1 && sh == 1) // '*'이 1개 '#'이 1개면 나머지는 '*'로
						change(j - 1, i + 1, j + 1, i + 1, '*');
					else if (st == 2 && sh == 1) // '*'이 2개 '#'이 1개면 나머지는 0으로
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
				cnt++; // '*'은 지뢰지만 남은 '#' 또한 지뢰로 볼 수 있다. 최대값이고, 숫자가 없으니깐

	cout << cnt << '\n';

	return 0;
}