/*
 * 16235. ���� ����ũ
 *
 * �ð����⵵ : O(N)
 *
 * simulation
 * �������� �־����� ��� ���󰡸鼭 ó�����ָ� �Ǵ� �����̴�.
 * ó�� �� ������ ���� ��, ������ ���� ������ ��� �����ؾ� �Ǵ����� ���� ����� �����ߴµ�
 * ó�� queue�� ����Ϸ��� �����߾��µ�, �Լ� fall�� �����ϴµ� �־
 * queue�� ���ͷ����Ͱ� ���Ұ����ϰ� �ε����� ���� ���������� �Ұ��ϱ� ������ deque�� ����ϰ� �Ǿ���.
 * �� �������� deque�� �̿��Ͽ� front�� �ִ� ������ Ȯ���ϰ� �������� push �� �� pop �ϴ� �������
 * ��� �����鿡 ���� ��ȸ�ϸ鼭 Ȯ���ߴ�.
 * ������ ��� ������ �ϰ� �ش糪���� �������� �ٷ� push �ع����� ���� �����ϴ� ������ ���İ�ü�� ���̰� ����� �ұ��ϰ�
 * �� ���ʿ� ��ġ�ϴ� ��찡 ����Ƿ� �������� �ѹ��� �ڷ� �Ѱ��ִ� �۾��� ���־���.
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

int Y[12][12]; // ���� ����� ��
int A[12][12]; // �ܿ￡ �߰��ϴ� ����� ��
int N, M, K;
deque<namu> q;

void spring() {
	for (unsigned int i = 0; i < q.size(); ++i) {
		if (Y[q.front().y][q.front().x] >= q.front().age) { // ����� ���̺��� ũ�ų� ���� ��
			Y[q.front().y][q.front().x] -= q.front().age; // ����� ���� ��ŭ ����
			q.front().age++; // ���� ����
		}
		else
			q.front().alive = false; // �׷��� ������ �׾��ٰ� ǥ��
		q.push_back(q.front()); // ù��° ������ ���ʿ� �߰�
		q.pop_front(); // ù��° ���� ��
	}
}
void summer() {
	int qsize = q.size();
	for (unsigned int i = 0; i < qsize; ++i) {
		if (q.front().alive == true) // ������ ��������� ���ʿ� Ǫ��
			q.push_back(q.front());
		else
			Y[q.front().y][q.front().x] += q.front().age / 2; // ������ ���� / 2 ��ŭ ��� �߰�
		q.pop_front(); // �׾����� �˸� ��
	}
}
void fall() {
	int qsize = q.size();
	for (unsigned int i = 0; i < qsize; ++i) { // �켱 queue �����ŭ ����
		if (q[i].age % 5 == 0) { // ���̰� 5�� ����̸�
			for (int j = -1; j <= 1; ++j) {
				for (int k = -1; k <= 1; ++k) { // �ֺ� 8���⿡ ������ �ɴ´�
					int cx = q[i].x + k;
					int cy = q[i].y + j;
					if (cx < 1 || cy < 1 || cx > N || cy > N || (j == 0 && k == 0)) // �������
						continue;
					q.push_back({ cx, cy, 1, true }); // ���� ť�� �߰�
				}
			}
		}
	}
	for (unsigned int i = 0; i < qsize; ++i) { // queue �����ŭ ���ʿ� �־��� ���ʿ� ���� ������� ��ġ�ϰ� ��
		q.push_back(q.front());
		q.pop_front();
	}
}
void winter() {
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			Y[i][j] += A[i][j]; // �ܿ￡ ��� �߰�����
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