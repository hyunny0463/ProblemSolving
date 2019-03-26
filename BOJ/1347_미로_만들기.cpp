/*
 * 1347. 미로 만들기
 *
 * 시간복잡도 : O(N)
 *
 * 시뮬레이션 문제
 * 홍준이가 바라보는 방향을 sight라는 변수로 나타내었으며
 * R, L 이 나오면 그에 따라 값을 올리거나 내려주었다.
 * 명령어의 개수가 최대 50개 이므로 [100, 100] 크기의 배열을 선언했으며
 * 홍준이의 처음 위치를 [50, 50]로 정했다.
 * x와 y의 최소값, 최대값을 저장하여 이동한 경로를 출력할 수 있게 했다.
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
	char miro[101][101]; // 입력받는 내용 최대 길이가 50이므로
	for (int i = 0; i < 101; ++i)
		for (int j = 0; j < 101; ++j)
			miro[i][j] = '#'; // '#'으로 초기화하여 이동하는 부분 외에는 '#'이 출력
	int cx = 50, cy = 50; // 100, 100 배열에서 50, 50으로 선언하여 상하좌우 50이동해도 괜찮음
	int minx, miny, maxx, maxy; // x, y의 최소 좌표, x, y의 최대 좌표
	minx = miny = maxx = maxy = 50;
	miro[cy][cx] = '.'; // 처음 위치

	int L;
	cin >> L;
	for (int i = 0, sight = 0; i < L; ++i) { // sight : 보고있는 방향
		char command;
		cin >> command; // 한 글자씩 입력받아 명령을 수행함

		if (command == 'F') {
			cx += dx[sight];
			cy += dy[sight];
			miro[cy][cx] = '.';
			maxx = maxx > cx ? maxx : cx;
			minx = minx < cx ? minx : cx;
			maxy = maxy > cy ? maxy : cy;
			miny = miny < cy ? miny : cy;
		}
		else if (command == 'R') // dx, dy상 인덱스를 오른쪽으로 이동
			sight = (sight + 1) % 4; // 남 -> 서 -> 북 -> 동 -> 남
		else if (command == 'L') // dx, dy상 인덱스를 왼쪽으로 이동
			sight = (sight + 3) % 4; // 남 -> 동 -> 북 -> 서 -> 남
	}

	for (int i = miny; i <= maxy; ++i) {
		for (int j = minx; j <= maxx; ++j)
			cout << miro[i][j];
		cout << '\n';
	}

	return 0;
}