/*
 * 1747. �Ҽ�&�Ӹ����
 *
 * �ð����⵵ : O(N*log(logN) + N*log(N)) : �Ҽ� ���ϴ� �ð� ���⵵ + N���� ũ��� �ƴ����� N���� �������� �� Ž�� ���⵵
 *
 * �Ҽ��̰� �Ӹ������ ������ ��� �����ϴ� ���� ã�� �����̴�.
 * �ð��� ���̴� ������ �����佺�׳׽��� ü�� �󸶳� ����ȭ�ϴ°��̴�.
 * 3���� N���� Ȧ���� ��� �Ҽ��̰� �Ӹ�����̸� ����pp�� �����Ѵ�.
 * �Ӹ������ chk��� ������ ���ڸ����� 10�� �������� �ְ� 10�� �����ִ� �������
 * �ϴµ� ���������� Ȯ���ϰ� ���� ���� ���� ���̸� �Ӹ�����̶�� �Ǵ��Ѵ�.
 * �� ������ ��� ��쿡 1003001���� �����صΰ� N�� �־����� ����Ž�� lower_bound��
 * Nlog(N)�� �ð����⵵�� ã�� �� �ִ�.

 * �鸸 * �鸸�� ���� int�� ������ ����� ���� �Ǽ��߾���.
 * MN�� ���� �鸸�� �Ѵ� ù �Ҽ��̰� �Ӹ������ ���̹Ƿ� ���Ƿ� ��������
 *
 */

#define _CRT_SECURE_NO_WARNINGS
#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MN = 1003002; // 1000000 �Ѵ� ù �Ҽ�&�Ӹ���� : 1003001
bool prime[MN] = { false }; // �Ҽ��̸� false�� ����(0, 1 ����)

int main(int argc, char** argv) {

	vector<int> pp(1, 2); // 2�� �ʱ�ȭ �� ���� 1�� �ִ´�

	// �����佺�׳׽��� ü
	prime[0] = prime[1] = true;
	for (int i = 3; i < MN; i += 2) { // prime ��ü�� ���� �Ҽ��� �ƴѵ� Ȧ���� ���� vector�� �ִ� ���� ��� �Ҽ���
		if (prime[i] == true)
			continue;
		for (long long int j = 1LL * i * i; j < MN; j += i) // �鸸 * �鸸�� int ������ ���
			prime[j] = true;

		int chk = 0, tmp = i;
		while (tmp) { // �Ӹ���� Ȯ��
			chk = chk * 10 + tmp % 10;
			tmp /= 10;
		}
		if (chk == i) // �Ҽ� & �Ӹ���� �̸� vector�� �־���
			pp.push_back(i);
	}

	int N;
	cin >> N;
	cout << *lower_bound(pp.begin(), pp.end(), N) << '\n'; // N�� ���ų� ū ���� ���� ���� ���� ��ȯ

	return 0;
}