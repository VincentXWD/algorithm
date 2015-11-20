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

const int inf = 0x7f7f7f;
const int maxn = 111;
int G[maxn][maxn];
int d[maxn];
int n, m;

void init() {
	m = 0;
	memset(d, 0, sizeof(d));
	for(int i = 0; i < maxn; i++) {
		for(int j = 0; j < maxn; j++) {
			G[i][j] = G[j][i] = inf;
		}
		G[i][i] = 0;
	}
}

int main() {
	// freopen("in", "r", stdin);
	int u, v, w;
	while(~scanf("%d", &n) && n) {
		init();
		for(int i = 0; i < n; i++) {
			scanf("%d %d %d", &u, &v, &w);
			if(w < G[u][v]) {
				G[u][v] = G[v][u] = w;
			}
			m = max(m, max(v, u) + 1);
		}
		for(int k = 0; k < m; k++) {
			for(int i = 0; i < m; i++) {
				for(int j = 0; j < m; j++) {
					if(G[i][j] > G[i][k] + G[k][j]) {
						G[i][j] = G[i][k] + G[k][j];
					}
				}
			}
		}
		for(int i = 0; i < m; i++) {
			for(int j = 0; j < m; j++) {
				d[i] += G[i][j];
			}
		}
		int ii = 0;
		int ans = d[0];
		for(int i = 1; i < m; i++) {
			if(ans > d[i]) {
				ans = d[i];
				ii = i;
			}
		}
		printf("%d %d\n", ii, ans);
	}
}