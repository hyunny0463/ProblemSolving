/*
 * 16235. 나무 재테크
 *
 * 시간복잡도 : O(N)
 *
 * simulation
 * 문제에서 주어지는 대로 따라가면서 처리해주면 되는 문제이다.
 * 처음 이 문제를 봤을 때, 나무에 대한 정보를 어떻게 저장해야 되는지에 대해 고민을 오래했는데
 * 처음 queue를 사용하려고 생각했었는데, 함수 fall을 구현하는데 있어서
 * queue는 이터레이터가 사용불가능하고 인덱스를 통해 직접접근이 불가하기 때문에 deque를 사용하게 되었다.
 * 각 계절마다 deque를 이용하여 front에 있는 나무를 확인하고 뒷쪽으로 push 한 후 pop 하는 방법으로
 * 모든 나무들에 대해 순회하면서 확인했다.
 * 가을의 경우 번식을 하고 해당나무를 뒤쪽으로 바로 push 해버리면 다음 번식하는 나무의 번식개체가 나이가 어림에도 불구하고
 * 더 뒤쪽에 위치하는 경우가 생기므로 마지막에 한번에 뒤로 넘겨주는 작업을 해주었다.
 *
 */

#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#include <iostream>
#include <deque>
using namespace std;

struct namu {
	int x, y, age;
	bool alive;
};

int Y[12][12]; // 현재 양분의 양
int A[12][12]; // 겨울에 추가하는 양분의 양
int N, M, K;
deque<namu> q;

void spring() {
	for (unsigned int i = 0; i < q.size(); ++i) {
		if (Y[q.front().y][q.front().x] >= q.front().age) { // 양분이 나이보다 크거나 같을 때
			Y[q.front().y][q.front().x] -= q.front().age; // 양분을 나이 만큼 삭제
			q.front().age++; // 나이 증가
		}
		else
			q.front().alive = false; // 그렇지 않으면 죽었다고 표시
		q.push_back(q.front()); // 첫번째 나무를 뒤쪽에 추가
		q.pop_front(); // 첫번째 나무 팝
	}
}
void summer() {
	int qsize = q.size();
	for (unsigned int i = 0; i < qsize; ++i) {
		if (q.front().alive == true) // 나무가 살아있으면 뒤쪽에 푸쉬
			q.push_back(q.front());
		else
			Y[q.front().y][q.front().x] += q.front().age / 2; // 나무의 나이 / 2 만큼 양분 추가
		q.pop_front(); // 죽었으면 팝만 함
	}
}
void fall() {
	int qsize = q.size();
	for (unsigned int i = 0; i < qsize; ++i) { // 우선 queue 사이즈만큼 돌고
		if (q[i].age % 5 == 0) { // 나이가 5의 배수이면
			for (int j = -1; j <= 1; ++j) {
				for (int k = -1; k <= 1; ++k) { // 주변 8방향에 나무를 심는다
					int cx = q[i].x + k;
					int cy = q[i].y + j;
					if (cx < 1 || cy < 1 || cx > N || cy > N || (j == 0 && k == 0)) // 경계조건
						continue;
					q.push_back({ cx, cy, 1, true }); // 나무 큐에 추가
				}
			}
		}
	}
	for (unsigned int i = 0; i < qsize; ++i) { // queue 사이즈만큼 뒷쪽에 넣어줌 앞쪽에 나이 어린나무가 위치하게 됨
		q.push_back(q.front());
		q.pop_front();
	}
}
void winter() {
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			Y[i][j] += A[i][j]; // 겨울에 양분 추가해줌
}


int main(int argc, char** argv)
{
	cin >> N >> M >> K;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1, yang; j <= N; ++j) {
			cin >> A[i][j];
			Y[i][j] = 5;
		}
	}

	for (int i = 0, x, y, age; i < M; ++i) {
		cin >> y >> x >> age;
		q.push_back({ x, y, age, true });
	}

	for (int i = 0; i < K; ++i) {
		spring();
		summer();
		fall();
		winter();
	}

	cout << q.size() << '\n';

	return 0;
}