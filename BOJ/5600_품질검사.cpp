/*
 * 5600. ǰ���˻�
 *
 * �ð����⵵ : O(N)
 *
 * �Է��� �����鼭 �հ��� ��쿡�� parts[index]�� �հ� ���·� �ٲٰ�
 * �׷��� ���� ��쿡�� breakdown �迭�� �����Ѵ�
 * �׸��� ���� breakdown �迭�� ������ ó������ ������ ���鼭
 * �� ���� ��ǰ�� �հ������� ���հ��� �����̸� ������ ��ǰ�� ���հ��̰�
 * �� �� ���� ���´� ������ �� �� ���� �����̹Ƿ� �� ���� ��ȸ�� ��� ���¸� �� �� �ִ�.
 *
 */

#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#include <iostream>
#include <vector>
using namespace std;

struct abc {
	int a, b, c; // a, b, c�� ��ǰ��ȣ
};

int main(int argc, char** argv)
{
	fastio();
	vector<int> parts(300 + 1, 2); // ó������ �� �� ���� ���·� �ʱ�ȭ
	vector<abc> breakdown; // ���հ� ����
	int a, b, c;
	cin >> a >> b >> c;
	int N;
	cin >> N;
	for (int i = 0, aa, bb, cc, rr; i < N; ++i) {
		cin >> aa >> bb >> cc >> rr;
		if (rr) { // �հ��� ���
			parts[aa] = parts[bb] = parts[cc] = 1; // �� �迭�� �հݻ��·� �ٲ�
			continue;
		}
		breakdown.push_back({ aa, bb, cc }); // �׷��� ������ ���հݿ� ����
	}

	for (int i = 0; i < breakdown.size(); ++i) { // ���հ������� �� ���� ��ǰ�� �հ��̸� �������� ���հ�
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