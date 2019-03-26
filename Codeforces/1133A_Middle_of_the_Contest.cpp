/*
 * 1133A. Middle of the Contest
 *
 * 시간복잡도 : O(1)
 *
 * implementation
 * 주어진 두 시간의 중간을 출력하는 문제
 * 단순히 두 시간에 대해 입력받아 숫자로 바꾸어준다음
 * (나중시간 - 처음시간) / 2 를 처음시간에 더해주었다.
 *
 */

#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#include<iostream>
#include<string>
using namespace std;

int main(int argc, char** argv) {
	string ctime[2];
	int ct[2];

	cin >> ctime[0] >> ctime[1];
	ct[0] = (ctime[0][0] - '0') * 600 + (ctime[0][1] - '0') * 60 + (ctime[0][3] - '0') * 10 + (ctime[0][4] - '0');
	ct[1] = (ctime[1][0] - '0') * 600 + (ctime[1][1] - '0') * 60 + (ctime[1][3] - '0') * 10 + (ctime[1][4] - '0');
	
	int res = ct[0] + (ct[1] - ct[0]) / 2;
	
	//printf("%02d:%02d", res / 60, res % 60); // 시간 표현에 있어서 printf가 더 편함
	cout.fill('0');
	cout.width(2);
	cout << res / 60 << ':';
	cout.width(2);
	cout << res % 60;

	return 0;
}