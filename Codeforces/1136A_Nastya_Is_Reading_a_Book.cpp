/*
 * 1136A. Nastya Is Reading a Book
 *
 * 시간복잡도 : O(N)
 *
 * implementation
 * 주어지는 각 chapter의 마지막장을 배열에 저장을 하고
 * marked page를 입력받으면 그 값이 몇 번째 chapter에 속하는지
 * 찾고 n값에서 빼서 답을 구한다.
 *
 */

#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#include <iostream>
using namespace std;


int main(int argc, char** argv) {
	fastio();

	int n;
	cin >> n;
	int pages[101] = { 0 };

	for (int i = 0, l, r; i < n; ++i)
		cin >> l >> pages[i]; // 각 chapter의 마지막 페이지만 저장

	int k, lastchapter;
	cin >> k;
	for (int i = 0; i < n; ++i) {
		if (k <= pages[i]) { // 모든 chapter를 돌면서 marked page를 찾으면
			lastchapter = i;
			break; // 빠져나온다
		}
		lastchapter = i + 1;
	}
	cout << n - lastchapter;

	return 0;
}