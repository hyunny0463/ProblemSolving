/*
 * 1991. 트리순회
 *
 * 시간복잡도 : O(N)
 *
 * Tree, pre-order, in-order, post-order

 * 문제의 제목과 같이 전위순회, 중위순회, 후위순회 하는 문제이다.
 * 입력을 어떻게 받느냐에 따라 해결하는 방법이 조금씩 달라질 것 겉다.
 * 루트 노드의 순서가 알파벳 순서가 아니므로 각 알파벳의 좌, 우를
 * 저장할 수 있는 구조체를 만들어서 트리구조를 만들었다.
 * 알파벳은 정수형으로 저장했고, 자식 노드가 없을 때 까지 들어가며
 * 트리 순회 방법을 사용하였다.
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