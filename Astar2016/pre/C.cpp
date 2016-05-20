// #pragma comment(linker, "/STACK:102400000,102400000")
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <climits>
#include <complex>
#include <fstream>
#include <cassert>
#include <cstdio>
#include <bitset>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <ctime>
#include <set>
#include <map>
#include <cmath>

using namespace std;

#define fr first
#define sc second
#define pb(a) push_back(a)
#define Rint(a) scanf("%d", &a)
#define Rll(a) scanf("%I64d", &a)
#define Rs(a) scanf("%s", a)
#define FRead() freopen("in", "r", stdin)
#define FWrite() freopen("out", "p", stdout)
#define Rep(i, len) for(int i = 0; i < (len); i++)
#define For(i, a, len) for(int i = (a); i < (len); i++)
#define Dec(i, a, b) for(int i = (a); i > (b); i--)
#define Cls(a) memset((a), 0, sizeof(a))
#define Full(a) memset((a), 0x7f7f, sizeof(a))

const int maxn = 1000010;
int n;
char str[55];

typedef struct Trie {
	int t[maxn][26];
	int cnt[maxn], d[55];
	int c, k, p, sz;
	Trie() {
		Cls(cnt); Cls(t);
		sz = 0;
	}
	void insert(char* str) {
		p = 0; cnt[0]++;
		while(*str != 0 && t[p][*str-'a']) {
			p = t[p][*str-'a'];
			cnt[p]++;
			str++;
		}
		while(*str != 0) {
			t[p][*str-'a'] = ++sz;
			p = sz;
			cnt[p]++;
			str++;
		}

	}
	void remove(char* str) {
		k = p = 0; d[k] = 0;
		while(*str != 0 && t[p][*str-'a']) {
			p = t[p][*str-'a'];
			d[++k] = p;
			str++;
		}
		if(*str != 0) return;
		c = cnt[d[k]]; cnt[0] -= c; *str--;
		Dec(i, k, 0) {
			cnt[d[i]] -= c;
			if(!cnt[d[i]]) t[d[i-1]][*str-'a'] = 0;
			str--;
		}
	}
	int find(char* str) {
		p = 0;
		while(*str != 0 && t[p][*str-'a']) {
			p = t[p][*str-'a'];
			str++;
		}
		if(*str == 0) return 1;
		return 0;
	}
}Trie;

Trie root;

int main() {
	// FRead();
	char cmd[55];
	while(~Rint(n)) {
		Rep(i, n) {
			Rs(cmd); Rs(str);
			if(cmd[0] == 'i') root.insert(str);
			if(cmd[0] == 's') {
				if(root.find(str) == 0) printf("No\n");
				else printf("Yes\n");
			}
			if(cmd[0] == 'd') root.remove(str);
		}
	}
	return 0;
}
