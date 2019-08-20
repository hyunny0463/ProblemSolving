/*
 * 17135. 캐슬 디펜스
 *
 * 시간복잡도 : O(N * M)
 *
 * simulation, conbination

 * 적군의 정보를 입력 받는 동시에 적군의 정보를 deque에 저장했다.
 * 실제 사용은 queue 처럼 사용하긴 하나 구현한 방식 중
 * chkenemy 부분에서 처음부터 끝까지 순회하면서
 * 확인할 필요가 있어서 deque를 사용하게 되었다.
 * 궁수는 총 3명이므로 for문을 이용하여 위치를 선택하였다.
 * 이는 조합과 관련이 있고, 더 많은 궁수가 있다면 permutation으로 해결가능하다.
 * 주어진 조건에 만족하게 가장 가깝고 왼쪽에 있는 적군을 찾아서
 * 지워주고 블럭을 내려주는 각각의 함수를 구성하여 해결헀다.

 * 처음 bd 배열로 적군 정보를 받는데 사용하지 않았기 때문에 필요가 없다.
 * killenemy, blockdown 함수 부분에서는 적군 정보를
 * 자료에서 아예 지워버리고 싶어 queue를 돌려가면서
 * 정보를 지워주었고 또한 blockdown을 하면서 없애줄 적군 정보를 지워주었다.
 * 쓰레기 정보는 남아 있진 않지만 굉장히 번거롭고 느린 방식이다.
 *
 */

#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#include <iostream>
#include <algorithm>
#include <deque>
#include <string.h>
using namespace std;

int N, M, D;
int rslt, cnt;
int bd[15][15];
deque<pair<int, int>> enemy;
pair<int, int> deadenemy[3];
int chkdead[3] = { 0 };

void chkenemy(int x, int n) { // 궁수 위치, 궁수 번호
	int mind = 1000;
	for (int i = 0; i < enemy.size(); ++i) {
		int dis = abs(enemy[i].first - x) + N - enemy[i].second; // 궁수와 적군 거리
		if (dis <= D && dis < mind) { // 더 짧은 거리 적군 찾기
			deadenemy[n] = enemy[i];
			mind = dis;
			chkdead[n] = 1;
		}
		else if (dis <= D && dis <= mind && enemy[i].first < deadenemy[n].first) {
			deadenemy[n] = enemy[i]; // 거리는 같거나 작지만 왼쪽에 있는 적군 찾기
			mind = dis;
		}
	}
}

void killenemy() { // enemy queue를 돌리면서 죽인 적군을 없애는 작업
	int qsize = enemy.size();
	for (int i = 0; i < qsize; ++i) {
		bool flag = false;
		for (int j = 0; j < 3; ++j) {
			if (!chkdead[j]) // 이미 죽인 적군이면 continue
				continue;
			if (enemy.front() == deadenemy[j]) { // 죽여야할 적군과 queue 처음에 있는 적군과 같으면
				flag = true; // queue 뒤에 다시 넣지 않기 위해 flag on
				cnt++; // 죽인 적군 수 카운트
				chkdead[j] = 0;
				break;
			}
		}
		if (!flag) // 아무도 죽이지 않았다면 해당 적군은 맨 뒤로 넣어줌
			enemy.push_back(enemy.front());
		enemy.pop_front(); // queue 가장 앞 적군을 삭제
	}
}

void blockdown() {
	int qsize = enemy.size(); // 전체 맵을 보지 않고 저장해둔 적군의 정보를 이용
	for (int i = 0; i < qsize; ++i) {
		enemy.front().second++; // 행만 플러스
		if (enemy.front().second < N) // 공간을 벗어나지 않으면 queue 뒤에 붙여줌
			enemy.push_back(enemy.front());
		enemy.pop_front(); // 공간을 벗어나면 없애버림
	}
}

void solve(int a, int b, int c) {
	int arr[] = { a, b, c };
	while (enemy.size()) {
		for (int i = 0; i < 3; ++i) // 각 궁수가 죽일 적군 선택
			chkenemy(arr[i], i);
		killenemy(); // 적군 죽이기
		blockdown(); // 적군 아래로 전진
	}
}

int main(int argc, char** argv) {
	fastio();
	cin >> N >> M >> D; // 행, 열, 공격 거리 제한

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> bd[i][j];
			if (bd[i][j])
				enemy.push_back({ j, i }); // 데크에 위치 저장
		}
	}
	deque<pair<int, int>> tmpenemy = enemy;
	rslt = 0;
	for (int i = 0; i < M; ++i) { // 3개 선택하는 조합이므로 for문 사용
		for (int j = i + 1; j < M; ++j) {
			for (int k = j + 1; k < M; ++k) {
				cnt = 0;
				solve(i, j, k); // 각각의 궁수 위치에서 확인
				rslt = rslt > cnt ? rslt : cnt;
				enemy = tmpenemy; // 적군 위치 초기화
			}
		}
	}

	cout << rslt << '\n';

	return 0;
}