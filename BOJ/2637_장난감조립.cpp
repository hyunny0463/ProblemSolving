
// 2637. �峭������
// DFS�� �̿��Ͽ� ��������� �ڽĳ��� �̵��ϸ鼭 ��ǰ�� ������ ���ϰ��� �⺻��ǰ�� ������ �˾Ƴ���.



#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#include <iostream>
#include <vector>
using namespace std;


struct part { // K, Y : ��ǰ��ȣ, ����
	int K, Y;
};
vector<vector<part>> toy;
int parts[101] = { 0 }; //����ǰ, �߰���ǰ�� ������ ����, �������� �⺻��ǰ ������ ������ �ִ� �迭

void dfs(int N, int num) { // ��ǰ��ȣ, �ʿ��� �ش��ǰ ������ ���
	if (toy[N].empty()) // �� �̻� �ڽĳ�尡 ������ �⺻��ǰ�̶� �Ǵ�
		return;
	for (int i = 0; i < toy[N].size(); ++i) {
		parts[toy[N][i].K] += num * toy[N][i].Y;
		dfs(toy[N][i].K, num * toy[N][i].Y);
	}
	parts[N] = 0; // �ڽĳ����� dfs�� ��� �����ϸ� �ش� �߰���ǰ�� ���̻� ����
}

int main() {
	fastio();
	int N, M;
	cin >> N >> M;
	vector<vector<part>>& toyy = toy; // ���������� ���� �޸� ����� ���̰� ����
	toyy.resize(N + 1);

	for (int i = 0, X, Y, K; i < M; ++i) { // �Է¹޴� �κ�
		cin >> X >> Y >> K;
		toyy[X].push_back({ Y, K });
	}
	parts[N] = 1; // ex) 7������ǰ�̶�� parts[7] = 1 �������� 0
	dfs(N, 1);

	for (int i = 0; i < N; ++i) {
		if (parts[i])
			cout << i << ' ' << parts[i] << '\n';
	}
	return 0;
}

//input example
//7
//8
//5 1 2
//5 2 2
//7 5 2
//6 5 2
//6 3 3
//6 4 4
//7 6 3
//7 4 5