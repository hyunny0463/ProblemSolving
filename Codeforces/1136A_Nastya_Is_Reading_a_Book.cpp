/*
 * 1136A. Nastya Is Reading a Book
 *
 * �ð����⵵ : O(N)
 *
 * implementation
 * �־����� �� chapter�� ���������� �迭�� ������ �ϰ�
 * marked page�� �Է¹����� �� ���� �� ��° chapter�� ���ϴ���
 * ã�� n������ ���� ���� ���Ѵ�.
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
		cin >> l >> pages[i]; // �� chapter�� ������ �������� ����

	int k, lastchapter;
	cin >> k;
	for (int i = 0; i < n; ++i) {
		if (k <= pages[i]) { // ��� chapter�� ���鼭 marked page�� ã����
			lastchapter = i;
			break; // �������´�
		}
		lastchapter = i + 1;
	}
	cout << n - lastchapter;

	return 0;
}