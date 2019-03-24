/*
 * 1218. [S/W 문제해결 기본] 4일차 - 괄호 짝짓기
 *
 * 시간복잡도 : O(N)
 *
 * 스택을 이용하여 여는 괄호는 스택에 저장하고
 * 닫는 괄호를 만나면 스택의 top을 확인하여
 * 짝이 맞는지 확인하는 식으로 문제를 풀었음

 * stack이라는 컨테이너를 처봤는데
 * 동작하는 것이 vector와 크게 다르지 않아서 검색해 봤는데
 * stack을 쓰는 이유는 협업을 할 떄, 가독성을 높여줄 수 있다는 점이 있고
 * stack은 껍데기를 표현하고 실제로 구현은 다른 컨테이너(deque, vector, list)에 위임하여
 * 성능에는 크게 차이가 없는 것을 알 수 있었다.
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
		int flag = 1; // 정상동작하는지 확인하는 flag 변수
		cin >> L;
		for (int i = 0; i < L; ++i) {
			cin >> tmp;

			if (tmp == '(' || tmp == '[' || tmp == '{' || tmp == '<') // 여는 괄호는 그냥 넣음
				bracket.push(tmp);
			else if (flag) { // 정상동작하지 않더라도 입력을 다 받기 위해서, 사실 없어도 됌
				if (bracket.top() == '(' && tmp == ')') // 각 괄호의 짝이 맞으면 스택의 top 값을 pop
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

		if (!bracket.empty()) { // 스택이 비어 있지 않으면 틀린 것이 있다는 의미
			cout << '#' << testcase << ' ' << 0 << '\n';
			while (!bracket.empty())
				bracket.pop();
		}
		else
			cout << '#' << testcase << ' ' << 1 << '\n';
	}

	return 0;
}