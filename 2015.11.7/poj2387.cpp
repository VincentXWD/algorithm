// #include <algorithm>
// #include <iostream>
// #include <iomanip>
// #include <cstring>
// #include <climits>
// #include <complex>
// #include <fstream>
// #include <cassert>
// #include <cstdio>
// #include <bitset>
// #include <vector>
// #include <deque>
// #include <queue>
// #include <stack>
// #include <ctime>
// #include <set>
// #include <map>
// #include <cmath>

// using namespace std;

// const int maxn = 1111;
// const int inf = 0x7fffff;
// int n, m, u, v, w;
// int G[maxn][maxn];

// int main() {
// 	// freopen("in", "r", stdin);
// 	while(~scanf("%d %d", &n, &m)) {
// 		for(int i = 1; i <= m; i++) {
// 			for(int j = 1; j <= m; j++) 
// 				G[i][j] = G[j][i] = inf;
// 			G[i][i] = 0;
// 		}
// 		for(int i = 1; i <= n; i++) {
// 			scanf("%d %d %d", &u, &v, &w);
// 			if(G[u][v] > w) 
// 				G[u][v] = G[v][u] = w;
// 		}
// 		for(int k = 1; k <= m; k++) {
// 			for(int i = 1; i <= m; i++) {
// 				for(int j = 1; j <= m; j++) {
// 					if(G[i][j] > G[i][k] + G[k][j]) {
// 						G[i][j] = G[i][k] + G[k][j];
// 					}
// 				}
// 			}
// 		}
// 		printf("%d\n", G[1][m]);
// 	}
// }



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
const int inf = 0x7fffff;
int d[maxn];
int G[maxn][maxn];
int vis[maxn];
int n, m, u, v, w;

void init() {
	memset(vis, 0, sizeof(vis));
	for(int i = 0; i <= m; i++) {
		d[i] = inf;
		for(int j = 0; j <= m; j++) {
			G[i][j] = G[j][i] = inf;
		}
		G[i][i] = 0;
	}
}

void dijkstra(int start) {
	d[start] = 0;
	for(int i = 1; i <= m; i++) {
		int u = -1;
		for(int j = 1; j <= m; j++) {
			if(!vis[j]) {
				if(u == -1 || d[j] < d[u]) {
					u = j;
				}
			}
		}
		vis[u] = 1;
		for(int j = 1; j <= m; j++) {
			if(!vis[j]) {
				d[j] = min(d[u]+G[u][j], d[j]);
			}
		}
	}
}

int main() {
	// freopen("in", "r", stdin);
	while(~scanf("%d %d", &n, &m)) {
		init();
		for(int i = 1; i <= n; i++) {
			scanf("%d %d %d", &u, &v, &w);
			if(G[u][v] > w) 
				G[u][v] = G[v][u] = w;
		}
		dijkstra(1);
		printf("%d\n", d[m]);
	}
}