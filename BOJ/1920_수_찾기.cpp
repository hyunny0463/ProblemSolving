/*
 * 1920. �� ã��
 *
 * �ð����⵵ : O( N * log(N) + M * log(N) )
 *
 * binary search

 * N���� ������ �־�����, M���� ������ �־�������
 * M���� ������ �ش� �ϴ� ������ N���� ������ ���� ��,
 * 1 �ƴϸ� 0�� ����ϴ� �����̴�.
 
 * ������ �ϴµ� �ɸ��� �ð� ���⵵�� N * log(N)
 * M ���� �迭�� N ���� �迭�� �ִ��� Ȯ���ϱ� ������ M * log(N)
 * �⺻���� ����Ž���� ����ϴ� �����̴�.
 * �־��� �迭�� ũ�Ⱑ 10���� �̹Ƿ� �ܼ��� �����ϱ⺸��
 * �̺�Ž���� �ٷ� �����س��� ���� �ʿ��� �� ����.
 *
 */

#define fastio() ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#include <iostream>
#include <algorithm>

using namespace std;

int A[100001]; // N ���� ������ ������ �迭
int B[100001]; // M ���� ������ ������ �迭

int bsearch(int x, int s, int e) { // ã�� ��, ����Ž�� ���� ó��, ��
	int h = (s + e) / 2;
	if (x == A[h]) // �߰����� �����Ѵٸ�
		return 1;
	if (s == e) // �׷��� �ʰ� ���� ó���� ���� �����ٸ� ����
		return 0;

	// return�� �ѹ��̶� �ȴٸ� ����ǵ��� ��
	if (x <= A[h])
		if (bsearch(x, s, h))
			return 1;
	if (x > A[h])
		if (bsearch(x, h + 1, e))
			return 1;
	return 0;
}

int main(int argc, char** argv) {
	fastio();

	int N, M;
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> A[i];
	sort(A, A + N); // ����Ž���� �ϱ� ���� ����
	cin >> M;
	for (int i = 0; i < M; ++i)
		cin >> B[i];
	for (int i = 0; i < M; ++i)
		cout << bsearch(B[i], 0, N - 1) << '\n';

	return 0;
}