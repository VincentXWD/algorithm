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
int d[maxn];
int G[maxn][maxn];
int vis[maxn];
int n, m;

void init() {
    memset(vis, 0, sizeof(vis));
    memset(G, 0, sizeof(G));
}

void dijkstra(int start) {
    for(int i = 1; i <= n; i++) d[i] = G[1][i]; //最大承载量
    for(int i = 1; i <= n; i++) {
        int u = -1;
        for(int j = 1; j <= n; j++) {
            if(!vis[j]) {
                if(u == -1|| d[j] > d[u]) {
                    u = j;
                }
            }
        }
        vis[u] = 1;
        for(int j = 1; j <= n; j++) {
            if(!vis[j] && d[j] < min(d[u], G[u][j])) {
                d[j] = min(d[u], G[u][j]);
            }
        }
    }
}

int main() {
    // freopen("in", "r", stdin);
    int T;
    int u, v, w;
    scanf("%d", &T);
    for(int _ = 1; _ <= T; _++) {
        scanf("%d %d", &n, &m);
        init();
        while(m--) {
            scanf("%d %d %d", &u, &v, &w);
            G[u][v] = G[v][u] = w;
        }
        dijkstra(1);
        printf("Scenario #%d:\n%d\n\n", _, d[n]);
    }
}
