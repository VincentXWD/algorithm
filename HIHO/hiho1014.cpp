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

typedef struct Node {
    Node *next[26];
    int cnt;
    Node() {
        cnt = 0;
        for(int i = 0; i < 26; i++) {
            next[i] = NULL;
        }
    }
}Node;

void insert(Node *p, char *str) {
    for(int i = 0; str[i]; i++) {
        int t = str[i] - 'a';
        if(p->next[t] == NULL) {
            p->next[t] = new Node();
        }
        p = p->next[t];
	    p->cnt++;
    }
}

int find(Node *p, char *str) {
    for(int i = 0; str[i]; i++) {
        int t = str[i] - 'a';
        p = p->next[t];
        if(!p) {
            return 0;
        }
    }
    return p->cnt;
}

const int maxn = 111111;
int n, m;
char tmp[15];

int main() {
	// freopen("in", "r", stdin);
	int T;
	while(~scanf("%d", &n)) {
		Node *root = new Node();
		for(int i = 0; i < n; i++) {
			scanf("%s", tmp);
			insert(root, tmp);
		}
		scanf("%d", &m);
		while(m--) {
			scanf("%s", tmp);
			printf("%d\n", find(root, tmp));
		}
	}
	return 0;
}