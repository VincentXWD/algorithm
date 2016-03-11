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
	int u, v;
	int next;
}Edge;

typedef pair<int, int> pii;
const int maxn = 40010;
const int mod = 1111111;
int n, m;
int ecnt;
int head[maxn];
int depth[maxn], parent[maxn];
int in[maxn], out[maxn];
int root;
int has[mod];
Edge e[maxn];

void init() {
	ecnt = 0;
	memset(has, 0, sizeof(has));
	memset(head, -1, sizeof(head));
	memset(e, 0, sizeof(e));
}

void adde(int u, int v, int w) {
	e[ecnt].u = u;
	e[ecnt].v = v;
	in[v]++;
	out[u]++;
	e[ecnt].next = head[u];
	head[u] = ecnt++;
	has[((u*1005)%mod+(v*217)%mod)%mod] = w;
}

void dfs(int u, int p, int d) {
	parent[u] = p;
	depth[u] = d;
	for(int i = head[u]; ~i; i = e[i].next) {
		if(p != e[i].v) {
			dfs(e[i].v, u, d+1);
		}
	}
}

int lca(int u, int v) {
	int ans = 0;
	while(depth[u] > depth[v]) {
		ans += has[((parent[u]*1005)%mod+(u*217)%mod)%mod];
		u = parent[u];
	}
	while(depth[v] > depth[u]) {
		ans += has[((parent[v]*1005)%mod+(v*217)%mod)%mod];
		v = parent[v];
	}
	while(u != v) {
		ans += has[((parent[u]*1005)%mod+(u*217)%mod)%mod];
		ans += has[((parent[v]*1005)%mod+(v*217)%mod)%mod];
		u = parent[u];
		v = parent[v];
	}
	return ans;
}

int main() {
	// freopen("in", "r", stdin);
	int T;
	int u, v, w;
	scanf("%d", &T);
	while(T--) {
		init();
		scanf("%d %d", &n, &m);
		for(int i = 0; i < n-1; i++) {
			scanf("%d %d %d", &u, &v, &w);
			adde(u, v, w);
		}
		for(int i = 1; i <= n; i++) {
			if(in[i] == 0) {
				root = i;
				break;
			}
		}
		dfs(root, -1, 0);
		while(m--) {
			scanf("%d %d", &u, &v);
			printf("%d\n", lca(u, v));
		}
	}
	return 0;
}