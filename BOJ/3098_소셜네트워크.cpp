/*
 * 3098. �Ҽȳ�Ʈ��ũ
 *
 * �ð����⵵ : O(N * N * N)
 *
 * simulation
 * 3�� for���� �̿��Ͽ� k�� �������� ��� i, j�� ����Ǿ� �ִ��� Ȯ���ϰ� ���� ���θ� �Ǵ��Ѵ�.
 * ���ο� ������ tmp�� �����ϰ� ģ�� ���� ���踦 ��Ÿ���� bd �迭�� ���̰� ������ ī��Ʈ�ϰ�
 * �� ������ bd�迭�� �����ϴ� ������� ��� ������ �� �� �ݺ����� �����Ѵ�.
 *
 */

#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char** argv)
{
	fastio();
	int N, M;
	bool bd[51][51] = { false };
	cin >> N >> M;
	for (int i = 0, A, B; i < M; ++i) {
		cin >> A >> B;
		bd[A][B] = bd[B][A] = true; // ��ȣ �� ģ���̹Ƿ�
	}

	vector<int> result;
	while (M < N * (N - 1) / 2) { // nCr : NC2 ������ ���ᰳ���� �ʿ�
		bool tmp[51][51] = { false };
		for (int k = 1; k <= N; ++k)
			for (int i = 1; i <= N; ++i)
				for (int j = i + 1; j <= N; ++j)
					if (bd[i][k] && bd[k][j] && !tmp[i][j]) // i-k, k-j�� ����, i-j�� 0�̸� i-j����
						tmp[i][j] = true;

		int cnt = 0;
		for (int i = 1; i <= N; ++i) {
			for (int j = i + 1; j <= N; ++j) {
				if (tmp[i][j] && !bd[i][j]) { // ���� ���� ��Ʈ��ũ �����̸� ī��Ʈ
					bd[i][j] = bd[j][i] = true;
					++cnt;
				}
			}
		}
		result.push_back(cnt); // ī��Ʈ ���� ����
		M += cnt; // ���� ���� ���Ḹŭ M�� ������
	}
	cout << result.size() << '\n';
	for (auto i : result)
		cout << i << '\n';
}