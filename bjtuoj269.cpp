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

const int maxn = 1111;
const int inf = 0xffffff;
int d[11][maxn];
int G[maxn][maxn];
int vis[maxn];
int aim[11];
int N, M, K;
int ans;

void init() {
	ans = inf;
	for(int i = 0; i <= N; i++) {
		for(int j = 0; j <= N; j++) {
			G[i][j] = G[j][i] = inf;
		}
		G[i][i] = 0;
	}
	for(int i = 0; i <= 11; i++) {
		for(int j = 0; j <= N; j++) {
			d[i][j] = inf;
		}
	}
}

void dijkstra(int start, int* d) {
	d[start] = 0;
	memset(vis, 0, sizeof(vis));
	for(int i = 1; i <= N; i++) {
		int u = -1;
		for(int j = 1; j <= N; j++) {
			if(!vis[j]) {
				if(u == -1 || d[j] < d[u]) {
					u = j;
				}
			}
		}
		vis[u] = 1;
		for(int j = 1; j <= N; j++) {
			if(!vis[j]) {
				d[j] = min(d[u]+G[u][j], d[j]);
			}
		}
	}
}

void dfs(int s, int cur, int cnt) {
	if(cur >= ans || cnt > K) return;
	if(cnt == K) {
		ans = min(ans, cur);
		return;
	}
	for(int i = 1; i <= K; i++) {
		if(!vis[aim[i]]) {
	        vis[aim[i]] = 1;
	        dfs(aim[i], cur+d[s][aim[i]], cnt+1);
	        vis[aim[i]] = 0;
		}
	}
}

int main() {
	freopen("in", "r", stdin);
	int T;
	scanf("%d", &T);
	while(T--) {
		scanf("%d %d %d", &N, &M, &K);
		int u, v, w;
		init();
		while(M--) {
			scanf("%d %d %d", &u, &v, &w);
			G[u][v] = G[v][u] = w;
		}
		K++;
		aim[1] = 1;
		dijkstra(1, d[1]);
		for(int i = 2; i <= K; i++) {
			scanf("%d", &aim[i]);
			dijkstra(aim[i], d[i]);
		}
		memset(vis, 0, sizeof(vis));
		vis[1] = 1;
		dfs(1, 0, 1);
		printf("%d\n", ans);
	}
	return 0;
}
