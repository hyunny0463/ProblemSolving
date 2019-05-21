/*
 * 5658. [���� SW �����׽�Ʈ] �������� ��й�ȣ
 *
 * �ð����⵵ : O(N * log(N))
 *
 * simulation, balanced binary tree(set)
 * ���������� ��й�ȣ�� ȸ���� �� �ִµ�, 4�� ���� �ֱ� ������
 * N/4 �� ȸ���ϸ� �ٽ� �Ȱ��� ���� ���´ٴ� ���� �̿��ϰ�
 * ���� ������ string���� �޾Ƽ� ȸ�� �� ù ���ڸ� �� �ڿ� �����ָ鼭
 * N���� Ȯ���ϴµ� ���� ���� �ߺ����� Ȯ���ؾ��ϱ� ������
 * set �ڷᱸ���� ����ߴ�. �ߺ� �˻�Ӹ� �ƴ϶� ���ĵǸ� �����Ѵ�.
 * ���������� iterator�� ����ؼ� K��° ū ���� ����ߴ�.
 *
 */

#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#include <iostream>
#include <string>
#include <math.h>
#include <set>
using namespace std;

int main(int argc, char** argv) {
	int T;
	cin >> T;
	for (int testcase = 1, N, K; testcase <= T; ++testcase) {
		cin >> N >> K;
		string num;
		cin >> num;

		set<long long int, greater<long long int>> s; // ������������ �����ϴ� set
		int div = N / 4; // �� �鿡 �ִ� ���� ����
		int sq = 0; // 16���� �� ��° �ڸ����� ��Ÿ��
		int sum = 0;

		for (int i = 0; i < div; ++i) {
			for (int j = N + i - 1; j >= i; --j) {
				if ('0' <= num[j] && num[j] <= '9')
					sum += pow(16, sq) * (num[j] - '0');
				else
					sum += pow(16, sq) * (num[j] - 'A' + 10);
				sq++;
				if (sq == div) {
					s.insert(sum);
					sum = 0;
					sq = 0;
				}
			}
			num += num[i]; // num �ڿ� num[0], num[1] ... �� �ٿ���
		}

		set<long long int>::iterator iter;
		iter = s.begin();
		for (int i = 0; i < K - 1; ++i) {
			iter++;
		}
		cout << '#' << testcase << ' ' << *iter << '\n';
	}
	return 0;
}