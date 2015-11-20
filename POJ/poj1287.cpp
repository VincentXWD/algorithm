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
const int inf = 0xffffff;
int d[maxn];
int G[maxn][maxn];
int vis[maxn];
int n, m;   //n:vertex m:edge

void init() {
    memset(vis, 0, sizeof(vis));
    for(int i = 0; i <= n; i++) {
        d[i] = inf;
        for(int j = 0; j <= n; j++) {
            G[i][j] = G[j][i] = inf;
        }
        G[i][i] = 0;
    }
}

int prim(int start) {
    d[start] = 0;
    for(int i = 1; i <= n; i++) {
        int u = -1;
        for(int j = 1; j <= n; j++) {
            if(!vis[j]) {
                if(u == -1 || d[j] < d[u]) {
                    u = j;
                }
            }
        }
        vis[u] = 1;
        for(int j = 1; j <= n; j++) {
            if(!vis[j]) {
                d[j] = min(G[u][j], d[j]);
            }
        }
    }
    int sp = 0;
    for(int i = 1; i <= n; i++) {
        sp += d[i];
    }
    return sp;
}

int main() {
    // freopen("in", "r", stdin);
    int u, v, w;
    while(~scanf("%d %d", &n, &m) && n) {
        init();
        while(m--) {
            scanf("%d %d %d", &u, &v, &w);
            if(w < G[u][v]) {
                G[u][v] = G[v][u] = w;
            }
        }
        printf("%d\n", prim(1));
    }
}
