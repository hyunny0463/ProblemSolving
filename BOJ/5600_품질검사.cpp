/*
 * 5600. 품질검사
 *
 * 시간복잡도 : O(N)
 *
 * 입력을 받으면서 합격일 경우에는 parts[index]를 합격 상태로 바꾸고
 * 그렇지 않은 경우에는 breakdown 배열에 저장한다
 * 그리고 나서 breakdown 배열의 개수를 처음부터 끝까지 보면서
 * 두 가지 부품이 합격이지만 불합격인 상태이면 나머지 부품은 불합격이고
 * 알 수 없는 상태는 여전히 알 수 없는 상태이므로 한 번의 순회로 모든 상태를 알 수 있다.
 *
 */

#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#include <iostream>
#include <vector>
using namespace std;

struct abc {
	int a, b, c; // a, b, c의 부품번호
};

int main(int argc, char** argv)
{
	fastio();
	vector<int> parts(300 + 1, 2); // 처음에는 알 수 없는 상태로 초기화
	vector<abc> breakdown; // 불합격 모음
	int a, b, c;
	cin >> a >> b >> c;
	int N;
	cin >> N;
	for (int i = 0, aa, bb, cc, rr; i < N; ++i) {
		cin >> aa >> bb >> cc >> rr;
		if (rr) { // 합격일 경우
			parts[aa] = parts[bb] = parts[cc] = 1; // 각 배열을 합격상태로 바꿈
			continue;
		}
		breakdown.push_back({ aa, bb, cc }); // 그렇지 않으면 불합격에 저장
	}

	for (int i = 0; i < breakdown.size(); ++i) { // 불합격이지만 두 개의 부품이 합격이면 나머지는 불합격
		if (parts[breakdown[i].a] == 1 && parts[breakdown[i].b] == 1)
			parts[breakdown[i].c] = 0;
		else if (parts[breakdown[i].a] == 1 && parts[breakdown[i].c] == 1)
			parts[breakdown[i].b] = 0;
		else if (parts[breakdown[i].b] == 1 && parts[breakdown[i].c] == 1)
			parts[breakdown[i].a] = 0;
	}

	for (int i = 1; i <= a + b + c; ++i)
		cout << parts[i] << '\n';

	return 0;
}