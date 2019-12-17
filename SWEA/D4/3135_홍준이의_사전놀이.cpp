/*
 * 3135. ȫ������ ��������
 *
 * �ð����⵵ : O(N)

 * trie, prefix tree
 * Ʈ���̸� �����迭�� �̿��Ͽ� �����ߴ�.
 * �ܾ�� ���� ���ڿ� �ش��ϴ� ���ڸ� Ȯ���ϰ�,
 * ������ cnt�� ������Ű�� �׷��� ������
 * ���ο� node�� �ʱ�ȭ �����ش�.
 * query �Լ��� ���� �ش� �ܾ �ִ��� Ȯ���ϴµ�,
 * ���� �ε����� -1�� �ƴϰ� �ܾ��� ������ Ȯ���Ѵ�.
 *
 */

#include <iostream>
using namespace std;

struct NODE {
	int next[26];
	int cnt; // �ش� ������ �ܾ��� ����

	void init() { // ��� ���ĺ��� ���� �ʱ�ȭ
		for (int i = 0; i < 26; ++i)
			next[i] = -1;
		cnt = 0;
	}
}trie[1000001]; // �� �ܾ� ���� * ���� Ƚ��

int trieN;

void init(void) {
	trieN = 0;
	trie[0].init();
}

void my_insert(int trieIdx, int bufIdx, int buffer_size, char* buf) {
	trie[trieIdx].cnt++; // �׻� trie[0]������ �ܾ��� ������ ������Ų��.
	if (bufIdx == buffer_size)
		return;

	int ch = buf[bufIdx] - 'a'; // ���ڸ� ���ڷ� ��ȯ

	if (trie[trieIdx].next[ch] == -1) { // ���Խ� �ش� ���ĺ��� ������
		trie[trieIdx].next[ch] = ++trieN; // ���ο� ��带 �Ҵ�
		trie[trieN].init();
	}

	my_insert(trie[trieIdx].next[ch], bufIdx + 1, buffer_size, buf);
}

void insert(int buffer_size, char* buf) {
	my_insert(0, 0, buffer_size, buf);
}

int query(int buffer_size, char* buf) {
	int trieIdx = 0;

	for (int i = 0; i < buffer_size; ++i) {
		int ch = buf[i] - 'a'; // ã�� �ܾ��� ���ڸ� ���ڷ� ��ȯ
		trieIdx = trie[trieIdx].next[ch]; // ���� ������ ��� �ε���
		if (trieIdx == -1)
			return 0;
	}
	return trie[trieIdx].cnt;
}

int main(void) {
	freopen("input.txt", "r", stdin);
	int test_case;
	for (scanf("%d", &test_case); test_case--;) {
		int Query_N;
		scanf("%d", &Query_N);

		init();

		static int tc = 0;
		printf("#%d", ++tc);

		for (int i = 1; i <= Query_N; i++) {
			int type; scanf("%d", &type);

			if (type == 1) {
				char buf[15] = { 0, };
				scanf("%s", buf);

				int buffer_size = 0;
				while (buf[buffer_size]) buffer_size++;

				insert(buffer_size, buf);
			}
			else {
				char buf[15] = { 0, };
				scanf("%s", buf);

				int buffer_size = 0;
				while (buf[buffer_size])
					buffer_size++;

				printf(" %d", query(buffer_size, buf));
			}
		}
		printf("\n");
		fflush(stdout);
	}
}