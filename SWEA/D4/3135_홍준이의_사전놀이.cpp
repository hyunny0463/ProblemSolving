/*
 * 3135. 홍준이의 사전놀이
 *
 * 시간복잡도 : O(N)

 * trie, prefix tree
 * 트라이를 정적배열을 이용하여 구현했다.
 * 단어에서 다음 글자에 해당하는 문자를 확인하고,
 * 있으면 cnt를 증가시키고 그렇지 않으면
 * 새로운 node를 초기화 시켜준다.
 * query 함수를 통해 해당 단어가 있는지 확인하는데,
 * 다음 인덱스가 -1이 아니고 단어의 끝까지 확인한다.
 *
 */

#include <iostream>
using namespace std;

struct NODE {
	int next[26];
	int cnt; // 해당 노드까지 단어의 개수

	void init() { // 모든 알파벳에 대해 초기화
		for (int i = 0; i < 26; ++i)
			next[i] = -1;
		cnt = 0;
	}
}trie[1000001]; // 각 단어 길이 * 쿼리 횟수

int trieN;

void init(void) {
	trieN = 0;
	trie[0].init();
}

void my_insert(int trieIdx, int bufIdx, int buffer_size, char* buf) {
	trie[trieIdx].cnt++; // 항상 trie[0]에서는 단어의 개수를 증가시킨다.
	if (bufIdx == buffer_size)
		return;

	int ch = buf[bufIdx] - 'a'; // 문자를 숫자로 변환

	if (trie[trieIdx].next[ch] == -1) { // 삽입시 해당 알파벳이 없으면
		trie[trieIdx].next[ch] = ++trieN; // 새로운 노드를 할당
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
		int ch = buf[i] - 'a'; // 찾을 단어의 문자를 숫자로 변환
		trieIdx = trie[trieIdx].next[ch]; // 다음 문자의 노드 인덱스
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