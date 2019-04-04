/*
 * 1231. [S/W 문제해결 기본] 9일차 - 중위순회
 *
 * 시간복잡도 : O(N)
 *
 * inorder
 * 중위순회를 이해하고 구현하는 문제이다.
 * 중위순회를 알기만하고 직접 짜본적은 없는데 간단한 문제가 있어서 기회가 생겼다.
 * 사실 이 문제는 직접 트리를 짠 것이 아니고 배열로 순회를 했는데 입력 테스트케이스가 부족한지
 * 허술한 이 방법으로도 풀 수 있었다. 실제로 사용하려면 구조체라던가 리스트 적으로 구현을 해서
 * 왼쪽 자식과 오른쪽 자식과의 연결이 있고 그에 따라 방문하면 될 것이라 생각한다.
 *
 */

#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#include <iostream>
using namespace std;

int N;
char tr[101];

void inorder(int idx) {
	if (idx * 2 <= N) // 왼쪽 자식 있는지 확인
		inorder(idx * 2);
	cout << tr[idx]; // 왼쪽 자식 끝까지 들어가면 출력 시작
	if (idx * 2 + 1 <= N) // 오른쪽 자식 있는지 확인
		inorder(idx * 2 + 1);
}

int main(int argc, char** argv)
{
	fastio();
	for (int testcase = 1; testcase <= 10; ++testcase) {
		cin >> N;
		for (int i = 0, n, a, b; i < N; ++i) {
			cin >> n;
			cin >> tr[n];
			if ((n * 2) + 1 <= N)
				cin >> a >> b;
			else if (n * 2 <= N)
				cin >> a;
		}
		cout << '#' << testcase << ' ';
		inorder(1);
		cout << '\n';
	}

	return 0;
}