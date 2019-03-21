/*
 * 2980. 도로와 신호등
 *
 * 시간복잡도 : O(N)
 *
 * 처음에는 모든 신호등의 위치를 입력받고 한칸씩 이동하며 신호등의 모든 상태를 갱신하며
 * 최종 L 까지 도달하며 걸린 시간을 측정했지만

 * 문제에서 신호등은 D가 증가하는 순서로 주어진다는 조건을 통해
 * 입력을 받음과 동시에 해당 신호등까지 걸리는 시간과
 * 그 위치에서 빨간색 신호등이라면 기다려야 하는시간을 더해주고
 * 마지막으로 현재위치에서 L까지 시간을 더해주는 방식으로 문제를 해결함
 *
 */


#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char** argv)
{
	int N, L;
	cin >> N >> L; // 신호등 개수, 도로의 길이

	int t = 0; // 걸린 시간
	int pos = 0; // 상근이 위치
	for (int i = 0, D, R, G, rest; i < N; ++i) {
		cin >> D >> R >> G; // 신호등 위치, 빨간불 켜지는 시간, 초록불 켜지는 시간

		t += (D - pos); // 현재 위치에서 입력받은 신호등까지 걸리는 시간
		pos = D; // 현재 위치는 신호등으로 갱신

		rest = t % (R + G); // 그 시간에 신호등의 상태를 알아보기 위한 변수
		t += rest < R ? R - rest : 0; // R보다 작다면 빨간불이므로 R - rest는 빨간불에서 기다려야 하는 시간
	}
	t += (L - pos); // 마지막 위치에서 L 까지 걸리는 시간

	cout << t << '\n';

	return 0;
}