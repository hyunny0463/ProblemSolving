/*
 * 1577. ������ ����
 *
 * �ð����⵵ : O(N * M)
 *
 * Dynamic Programming
 * (0, 0) ���� ���ο� ������ ���� ���� ���� ���ΰ� ���ٸ� 1�� �ʱ�ȭ���ְ�
 * ������ ���� �ش� ��ǥ ���� �׸��� ���� ���� ������ ������ �Ѵ�
 * ���� ���߿� �ش� ��ǥ�� ���� ���ÿ��� ���ΰ� �������̸� ���� ���� �������� �ʴ´�
 * ���� ������� ���� ���ÿ��� ����� �����Ѵ�.

 * ó���� ���б����� �����ǥ���� ��ǥ�� �̵��ϴ� ����� ����
 * ã�� ����� ����غ����ߴµ� ���丮�� ����� ������ ���� ���� �ְ�
 * �������� ���ΰ� �ƴ� ������ ��� �ϴ°� ������ �ʾƼ� �ܼ��ϰ� �����
 *
 */

 #define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
 #include <iostream>
 using namespace std;
 
 int main(int argc, char** argv)
 {
 	fastio();
 
 	long long int road[101][101] = { 0 };
 	int underconstruction[101][101][2] = { 0 }; // 0 : ����, 1 : ����
 	int N, M, K;
 	cin >> N >> M >> K;
 	for (int i = 0, a, b, c, d; i < K; ++i) { // ���� ���� ���� �Է�
 		cin >> a >> b >> c >> d;
 		if (a == c) { // ���� ���ΰ� ���� ��
 			if (b > d)
 				underconstruction[d][c][1]++;
 			else
 				underconstruction[b][a][1]++;
 		}
 		else { // ���� ���ΰ� ���� ��
 			if (a > c)
 				underconstruction[d][c][0]++;
 			else
 				underconstruction[b][a][0]++;
 		}
 	}
 
 	road[0][0] = 1;
 	for (int i = 1; i <= N; ++i) { // ù��° �� ó��
 		road[0][i] = road[0][i - 1];
 		if (underconstruction[0][i - 1][0])
 			road[0][i] = 0;
 	}
 
 	for (int i = 1; i <= M; ++i) { // ù��° �� ó��
 		road[i][0] = road[i - 1][0];
 		if (underconstruction[i - 1][0][1])
 			road[i][0] = 0;
 	}
 
 	for (int i = 1; i <= M; ++i) {
 		for (int j = 1; j <= N; ++j) {
 			road[i][j] = road[i - 1][j] + road[i][j - 1]; // �ش� ��ǥ �������� ���� ��, ���� ���� ������
 			if (underconstruction[i][j - 1][0]) // �ش� ��ǥ�� ���� ��ǥ ���̿� ���ΰ� ������
 				road[i][j] -= road[i][j - 1]; // ���� ���� �ٽ� ����
 			if (underconstruction[i - 1][j][1]) // �ش� ��ǥ�� ���� ��ǥ ���̿� ���ΰ� ������
 				road[i][j] -= road[i - 1][j]; // ���� ���� �ٽ� ����
 		}
 	}
 	cout << road[M][N] << '\n';
 
 	return 0;
 }