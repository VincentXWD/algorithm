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

typedef struct Edge {
	int v, w;
	int next;
}Edge;
const int maxn = 10010;
int n, ecnt;
int head[maxn];
Edge e[maxn*maxn];
int dp[maxn];
int ed, lp;

void init() {
	memset(head, -1, sizeof(head));
	ecnt = 0;
}

void adde(int u, int v, int w) {
	e[ecnt].v = v;
	e[ecnt].w = w;
	e[ecnt].next = head[u];
	head[u] = ecnt++;
}

void dfs(int u, int pre, int len) {
	if(len > lp) {
		lp = len;
		ed = u;
	}
	for(int i = head[u]; ~i; i=e[i].next) {
		if(e[i].v == pre) continue;
		dfs(e[i].v, u, len + e[i].w);
		dp[e[i].v] = max(dp[e[i].v], len+e[i].w);
	}
}

int main() {
	freopen("in", "r", stdin);
	int v, w;
	while(~scanf("%d", &n)) {
		init();
		for(int i = 2; i <= n; i++) {
			scanf("%d %d", &v, &w);
			adde(i, v, w);
			adde(v, i, w);
		}
		lp = -1;
		memset(dp, 0, sizeof(dp));
		dfs(1, -1, 0);
		dfs(ed, -1, 0);
		dfs(ed, -1, 0);
		for(int i = 1; i <= n; i++) {
			printf("%d\n", dp[i]);
		}
	}
	return 0;
}