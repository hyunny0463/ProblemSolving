/*
 * 15652. N�� M (4)
 *
 * �ð����⵵ : O(N^M / M!)
 *
 * duplicate combination

 * �⺻���� �ߺ������� ����
 * �ߺ������� ������ �����ϹǷ� idx�� ���� ���� �ѱ� �� �ִ�.
 * N���� �ڿ������� �ߺ� �����ϵ��� M���� �����Ѵ�.
 *
 */

 #define fastio() ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
 #include <iostream>
 using namespace std;
 
 int N, M; // N������ �ڿ���, ������ ����
 int t[8] = { 0 }; // �ߺ����� �����ϴ� �迭
 
 void dfs(int d, int idx) { // ����, ���� �ε���
 	if (d == M) {
 		for (int i = 0; i < d; ++i)
 			cout << t[i] << ' ';
 		cout << '\n';
 		return;
 	}
 
 	for (int i = idx; i <= N; ++i) {
 		t[d] = i; // ���̿� ���� �迭�� i�� ����
 		dfs(d + 1, i); // ���� ����
 	}
 }
 
 int main(int argc, char** argv) {
 	fastio();
 	cin >> N >> M;
 
 	dfs(0, 1);
 
 	return 0;
 }