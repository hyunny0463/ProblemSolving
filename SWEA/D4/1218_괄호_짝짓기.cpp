/*
 * 1218. [S/W �����ذ� �⺻] 4���� - ��ȣ ¦����
 *
 * �ð����⵵ : O(N)
 *
 * ������ �̿��Ͽ� ���� ��ȣ�� ���ÿ� �����ϰ�
 * �ݴ� ��ȣ�� ������ ������ top�� Ȯ���Ͽ�
 * ¦�� �´��� Ȯ���ϴ� ������ ������ Ǯ����

 * stack�̶�� �����̳ʸ� ó�ôµ�
 * �����ϴ� ���� vector�� ũ�� �ٸ��� �ʾƼ� �˻��� �ôµ�
 * stack�� ���� ������ ������ �� ��, �������� ������ �� �ִٴ� ���� �ְ�
 * stack�� �����⸦ ǥ���ϰ� ������ ������ �ٸ� �����̳�(deque, vector, list)�� �����Ͽ�
 * ���ɿ��� ũ�� ���̰� ���� ���� �� �� �־���.
 *
 */

#define _CRT_SECURE_NO_WARNINGS
#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#include<iostream>
#include<stack>
using namespace std;

int main()
{
	fastio();

	char tmp;
	stack<char> bracket;

	for (int testcase = 1, L; testcase <= 10; ++testcase)
	{
		int flag = 1; // �������ϴ��� Ȯ���ϴ� flag ����
		cin >> L;
		for (int i = 0; i < L; ++i) {
			cin >> tmp;

			if (tmp == '(' || tmp == '[' || tmp == '{' || tmp == '<') // ���� ��ȣ�� �׳� ����
				bracket.push(tmp);
			else if (flag) { // ���������� �ʴ��� �Է��� �� �ޱ� ���ؼ�, ��� ��� ��
				if (bracket.top() == '(' && tmp == ')') // �� ��ȣ�� ¦�� ������ ������ top ���� pop
					bracket.pop();
				else if (bracket.top() == '[' && tmp == ']')
					bracket.pop();
				else if (bracket.top() == '{' && tmp == '}')
					bracket.pop();
				else if (bracket.top() == '<' && tmp == '>')
					bracket.pop();
				else
					flag = 0;
			}
		}

		if (!bracket.empty()) { // ������ ��� ���� ������ Ʋ�� ���� �ִٴ� �ǹ�
			cout << '#' << testcase << ' ' << 0 << '\n';
			while (!bracket.empty())
				bracket.pop();
		}
		else
			cout << '#' << testcase << ' ' << 1 << '\n';
	}

	return 0;
}