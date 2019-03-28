/*
 * 1130B. Two Cakes
 *
 * 시간복잡도 : O(N)
 *
 * greedy
 * 10만개의 배열에 모든 케익의 위치를 저장하여
 * sasha와 dima의 위치에서 다음 케익 위치까지 최적의 위치를 n번 연산하여
 * 각 연산에서 최소값을 더해준다
 
 * 이미 맞은 답이였는데 cost 변수를 int로 출력해서 틀린 것을 한참동안 찾았다.
 *
 */

#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char** argv)
{
	fastio();
	int n, a[100001][2] = { 0 }; // 같은 케익이지만 2개의 위치가 다르므로
	cin >> n;
	for (int i = 1, tier; i <= n * 2; ++i) {
		cin >> tier;
		if (!a[tier][0]) // 같은 번호 케익 받은 적 없을 때
			a[tier][0] = i;
		else
			a[tier][1] = i;
	}

	long long int cost = a[1][0] + a[1][1] - 2; // 처음 위치가 각각 1씩 더해져있음
	for (int i = 2; i <= n; ++i) // 모든 경우에 최단 거리를 구함
		cost += min(abs(a[i][0] - a[i - 1][0]) + abs(a[i][1] - a[i - 1][1]), abs(a[i][0] - a[i - 1][1]) + abs(a[i][1] - a[i - 1][0]));

	cout << cost << '\n';

	return 0;
}