/*
 * 3985. �� ����ũ
 *
 * �ð����⵵ : O(N * L)
 *
 * ���� ������ ������ ����ϴ� ����� ����ũ ���� ��ȣ��
 * �ܼ��� �Է� ���� ������ ū�� �������� �Ǻ��ؼ� Ȯ�ΰ���
 * ������ ���� �������� ����� ����ũ ���� ��ȣ��
 * �ش� ����ũ�� �����Ǿ����� Ȯ���ϸ鼭 ī��Ʈ�Ͽ� ���� ������ ū�� ������ �Ǻ�
 *
 */

#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	int L, N;
	int greedyman = 0, pigman = 0; // ���� ������ ���� ����ϴ� ���, ���� �������� ���
	int greedycnt = 0, pigcnt = 0; // ���� ������ ���� ����ϴ� ��� ��ȣ, ���� �������� ��� ��ȣ
	int cake[1001] = { 0 }; // ������ ����ũ���� Ȯ��

	cin >> L >> N; // ������ũ ����, ��û���� ��
	for (int i = 1, P, K; i <= N; ++i) {
		cin >> P >> K; // ��û���� ���ϴ� ù ����ũ ��ȣ, ������ ����ũ ��ȣ

		if (K - P + 1 > greedycnt) {
			greedycnt = K - P + 1; // ���� ������ ���� ����ϴ� ��û���� ����ũ ��
			greedyman = i; // ���� ������ ���� ����ϴ� ��û�� ��ȣ
		}
		for (int j = P, cnt = 0; j <= K; ++j) {
			if (cake[j]) // �̹� ������ ����ũ��� �н�
				continue;
			cake[j] = i;
			cnt++; // �׷��� ������ ����
			if (cnt > pigcnt) {
				pigcnt = cnt; // ���� �������� ��û���� ����ũ ��
				pigman = i; // ���� �������� ��û�� ��ȣ
			}
		}
	}
	cout << greedyman << '\n' << pigman << '\n';

	return 0;
}