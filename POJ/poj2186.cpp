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

const int maxn = 11111;
typedef struct Edge {
	int v;
	int next;
	Edge() { next = -1; }
}Edge;

int head[maxn], ecnt;
Edge edge[55555];
int n, m;

int bcnt, dindex;
int dfn[maxn], low[maxn];
int stk[maxn], top;
int belong[maxn];
bool instk[maxn];
int dig[maxn];

void init() {
	memset(edge, 0, sizeof(edge));
	memset(head, -1, sizeof(head));
	memset(instk, 0, sizeof(instk));
	memset(dfn, 0, sizeof(dfn));
	memset(low, 0, sizeof(low));
	memset(belong, 0, sizeof(belong));
	memset(dig, 0, sizeof(dig));
	ecnt = top = bcnt = dindex = 0;
}

void adde(int uu, int vv) {
	edge[ecnt].v = vv;
	edge[ecnt].next = head[uu];
	head[uu] = ecnt++;
}

void tarjan(int u) {
	int v = u;
	dfn[u] = low[u] = ++dindex;
	stk[++top] = u;
	instk[u] = 1;
	for(int i = head[u]; ~i; i=edge[i].next) {
		v = edge[i].v;
		if(!dfn[v]) {
			tarjan(v);
			low[u] = min(low[u], low[v]);
		}
		else if(instk[v] && dfn[v] < low[u]) {
			low[u] = dfn[v];
		}
	}
	if(dfn[u] == low[u]) {
		bcnt++;
		do {
			v = stk[top--];
			instk[v] = 0;
			belong[v] = bcnt;
		} while(v != u && top != 0);
	}
}

int main() {
	// freopen("in", "r", stdin);
	int uu, vv;
	while(~scanf("%d %d", &n, &m)) {
		init();
		for(int i = 0; i < m; i++) {
			scanf("%d %d", &uu, &vv);
			adde(uu, vv);
		}
		for(int i = 1; i <= n; i++) {
			if(!dfn[i]) {
				tarjan(i);
			}
		}
		for(int i = 1; i <= n; i++) {
			for(int j = head[i]; ~j; j = edge[j].next) {
				if(belong[i] != belong[edge[j].v]) {
					dig[belong[i]]++;
				}
			}
		}
		int tmp, cnt = 0, ans = 0;
  		for(int i = 1; i <= bcnt; i++) {
  			if(!dig[i]) {
  				cnt++;
  				tmp = i;
  			}
		}
  		if(cnt == 1) {
  			for(int i = 1; i <= n; i++) {
  				if(belong[i] == tmp) {
  					ans++;
  				}
  			}
  			printf("%d\n", ans);
  		}
  		else {
  			printf("0\n");
  		}
	}
	return 0;
}
