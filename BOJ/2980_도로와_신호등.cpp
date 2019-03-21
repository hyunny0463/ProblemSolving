/*
 * 2980. ���ο� ��ȣ��
 *
 * �ð����⵵ : O(N * L)
 *
 * ��ȣ�� ������ ��� ������ �� �� �ð����� ��� ��ġ�� ��ȣ���� ������ �����ϸ鼭
 * ����̰� ������ �� �ִ��� �Ǵ��ϰ�, ����̰� L ��ġ�� �����ϸ� �����Ѵ�.
 *
 */


#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#include <iostream>
#include <vector>
using namespace std;

struct light { // ��ȣ��, �������� ������ �ð�, �Ķ����� ������ �ð�
	int D, R, G;
};

int main(int argc, char** argv)
{
	int N, L;
	cin >> N >> L; // ��ȣ�� ����, ������ ����

	vector<int> road(L + 1, 1); // 0: ������, 1: ����, 2: �Ķ���
	vector<light> tl; // traffic light

	for (int i = 0, D, R, G; i < N; ++i) {
		cin >> D >> R >> G;
		tl.push_back({ D, R, G }); // ���Ϳ� ��� ��ȣ���� ����
		road[D] = 0;
	}

	int cnt = 0, sang = 1;
	while (++cnt) { // ����̰� L ���� �� ������ �ɸ��� �ð�
		if (sang == L)
			break;
		if (road[sang]) // �������� �ƴϸ�
			sang++;
		for (int i = 0; i < tl.size(); ++i) { // �� �ð� ��� ��ȣ���� ���¸� ������
			if (!road[tl[i].D] && (cnt % (tl[i].R + tl[i].G)) == tl[i].R)
				road[tl[i].D] = 2;
			else if (road[tl[i].D] == 2 && (cnt % (tl[i].R + tl[i].G)) == 0)
				road[tl[i].D] = 0;
		}
	}

	cout << cnt - 1 << '\n'; // ó�� 1�� ���� �ð��̹Ƿ�

	return 0;
}