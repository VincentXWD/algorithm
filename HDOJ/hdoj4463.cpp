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

const int maxn = 105;
const double inf = 2222;
int vis[maxn];
double d[maxn];
double G[maxn][maxn];
int n;
int x[maxn], y[maxn];
int s, a;

void init() {
	memset(vis, 0, sizeof(vis));
	for(int i = 0; i <= n; i++) d[i] = inf;
}

double prim() {
	d[s] = d[a] = 0;
	vis[s] = vis[a] = 1;
	double sp = G[s][a];
	for(int i = 0; i < n; i++) {
		d[i] = min(d[i], G[s][i]);
		d[i] = min(d[i], G[i][a]);;
	}
    while(1) {
        int u = -1;
        for(int i = 0; i < n; i++) 
            if(!vis[i] && (u == -1 || d[i] < d[u])) u = i;
        if(u == -1) break;
        vis[u] = 1;
        sp += d[u];
        for(int i = 0; i < n; i++) d[i] = min(d[i], G[i][u]);
    }
	return sp;
}

int main() {
	// freopen("in", "r", stdin);
	while(~scanf("%d", &n) && n) {
		init();
		scanf("%d %d", &s, &a);
		s--;
		a--;
		for(int i = 0; i < n; i++) {
			scanf("%d %d", &x[i], &y[i]);
		}
		for(int i = 0; i < n; i++) {
			G[i][i] = 0;
			for(int j = i+1; j < n; j++) {
				G[i][j] = G[j][i] = sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
			}
		}
		printf("%.2lf\n", prim());
	}
}
