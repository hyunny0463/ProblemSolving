/*
 * 15650. N�� M (2)
 *
 * �ð����⵵ : O(nCm)
 *
 * combination

 * �⺻���� ���� ����
 * N���� �ڿ������� M���� ������ ������� ����Ѵ�.
 *
 */

 #define fastio() ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
 #include <iostream>
 using namespace std;
 
 int N, M; // �ڿ����� ����, ������ ����
 int t[8] = { 0 }; // ���� ������ �迭
 
 void dfs(int d, int idx) { // ����, �ε��� ����
 	if (d == M) { // ���̰� ������ ������ ũ�Ⱑ ������ ���
 		for (int i = 0; i < d; ++i)
 			cout << t[i] << ' ';
 		cout << '\n';
 		return;
 	}
 
 	for (int i = idx + 1; i <= N; ++i) { // ������ ������ �ε��� ���ķ� ����
 		t[d] = i;
 		dfs(d + 1, i);
	}
 }
 
 int main(int argc, char** argv) {
 	fastio();
 	cin >> N >> M;
 
 	dfs(0, 0);
 
 	return 0;
 }