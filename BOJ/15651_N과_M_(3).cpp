/*
 * 15651. N�� M (3)
 *
 * �ð����⵵ : O(N^M)
 *
 * duplicate permutation

 * �⺻���� �ߺ������� ����
 * N���� �ڿ������� ���� ���� �ߺ����� M�� �����Ѵ�.
 *
 */

 #define fastio() ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
 #include <iostream>
 using namespace std;
 
 int N, M; // N������ �ڿ���, M���� ������
 int t[7] = { 0 };
 
 void dfs(int d) { // ����
 	if (d == M) { // ���̰� M�� ������ ���
 		for (int i = 0; i < d; ++i)
 			cout << t[i] << ' ';
 		cout << '\n';
 		return;
 	}
 
 	for (int i = 1; i <= N; ++i) {
 		t[d] = i;
 		dfs(d + 1);
 	}
 }
 
 int main(int argc, char** argv) {
 	fastio();
 	cin >> N >> M;
 
 	dfs(0);
 
 	return 0;
 }