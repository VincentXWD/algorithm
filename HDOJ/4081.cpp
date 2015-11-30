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
	int u;
	int v;
	double w;
}Edge;

typedef struct Vertex {
	int u;
	int v;
	int p;
}Vertex;

const int maxn = 1111;
const int maxm = 1111 * 1111;
bool vis[maxn];
vector<int> G[maxn];
Edge e[maxm];
Edge res[maxn];
Vertex p[maxn];
int n, cnt;
int pre[maxn];
double sum, ans;
int maxp;

bool cmp(Edge a, Edge b) {
	return a.w < b.w;
}

double dis(Vertex a, Vertex b) {
	return sqrt(1.0 * ((a.u - b.u) * (a.u - b.u) + (a.v - b.v) * (a.v - b.v)));
}

void init() {
	for(int i = 1; i <= n; i++) {
		pre[i] = i;
	}
}

int find(int x) {
	return x == pre[x] ? x : pre[x] = find(pre[x]);
}

bool unite(int x, int y) {
	x = find(x);
	y = find(y);
	if(x != y) {
		pre[x] = y;
		return 1;
	}
	return 0;
}

void kruskal() {
	int k = 0;
	init();
	sort(e, e+cnt, cmp);
	for(int i = 0; i < cnt; i++) {
		if(unite(e[i].u, e[i].v)) {
			G[e[i].u].push_back(e[i].v);
			G[e[i].v].push_back(e[i].u);
			sum += e[i].w;
			res[k++] = e[i];
		}
		if(k == n - 1) {
			break;
		}
	}
}

void dfs(int u) {
	vis[u] = 1;
	if(p[u].p > maxp) {
		maxp = p[u].p;
	}
	for(int i = 0; i < G[u].size(); i++) {
		if(!vis[G[u][i]]) {
			dfs(G[u][i]);
		}
	}
}

int main() {
	// freopen("in", "r", stdin);
	int T_T;
	scanf("%d", &T_T);
	while(T_T--) {
		cnt = 0;
		maxp = -1;
		sum = 0;
		scanf("%d", &n);
		for(int i = 0; i <= n; i++) {
			G[i].clear();
		}
		for(int i = 1;i <= n; i++) {
			scanf("%d %d %d", &p[i].u, &p[i].v, &p[i].p);
		}
		for(int i = 1; i <= n; i++) {
			for(int j = i + 1; j <= n; j++) {				
		        e[cnt].u = i;
		        e[cnt].v = j;
		        e[cnt].w = dis(p[i], p[j]);
		        cnt++;
			}
	    }
	    kruskal();
	    ans = 0;
	    double tmp;
	    for(int i = 0; i < n - 1; i++) {
	    	int u = res[i].u;
	    	int v = res[i].v;
	    	tmp = 0;
	    	memset(vis, 0, sizeof(vis));
	    	vis[v] = 1;
	    	maxp = 0;
	    	dfs(u);
	    	tmp += maxp;
	    	memset(vis, 0, sizeof(vis));
	    	vis[u] = 1;
	    	maxp = 0;
	    	dfs(v);
	    	tmp += maxp;
	    	tmp /= (sum - res[i].w);
	    	ans = tmp > ans ? tmp : ans;
	    }
	    printf("%.2lf\n", ans);
	}
	return 0;
}
