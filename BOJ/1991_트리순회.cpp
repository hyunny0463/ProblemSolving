/*
 * 1991. Ʈ����ȸ
 *
 * �ð����⵵ : O(N)
 *
 * Tree, pre-order, in-order, post-order

 * ������ ����� ���� ������ȸ, ������ȸ, ������ȸ �ϴ� �����̴�.
 * �Է��� ��� �޴��Ŀ� ���� �ذ��ϴ� ����� ���ݾ� �޶��� �� �Ѵ�.
 * ��Ʈ ����� ������ ���ĺ� ������ �ƴϹǷ� �� ���ĺ��� ��, �츦
 * ������ �� �ִ� ����ü�� ���� Ʈ�������� �������.
 * ���ĺ��� ���������� �����߰�, �ڽ� ��尡 ���� �� ���� ����
 * Ʈ�� ��ȸ ����� ����Ͽ���.
 *
 */

#include <iostream>
using namespace std;

struct tree {
	int left = -1, right = -1;
};

int N;
tree m[27];

void preorder(int idx) {
	printf("%c", 'A' + idx);
	if (m[idx].left != -1)
		preorder(m[idx].left);
	if (m[idx].right != -1)
		preorder(m[idx].right);
}

void inorder(int idx) {
	if (m[idx].left != -1)
		inorder(m[idx].left);
	printf("%c", 'A' + idx);
	if (m[idx].right != -1)
		inorder(m[idx].right);
}

void postorder(int idx) {
	if (m[idx].left != -1)
		postorder(m[idx].left);
	if (m[idx].right != -1)
		postorder(m[idx].right);
	printf("%c", 'A' + idx);
}

int main(int argc, char** argv) {
	scanf("%d", &N);
	
	for (int i = 0; i < N; ++i) {
		char root, left, right;
		scanf(" %c %c %c", &root, &left, &right);
		
		if (left != '.')
			m[root - 'A'].left = left - 'A';
		if (right != '.')
			m[root - 'A'].right = right - 'A';
	}

	preorder(0);
	printf("\n");
	inorder(0);
	printf("\n");
	postorder(0);
	printf("\n");	

	return 0;
}