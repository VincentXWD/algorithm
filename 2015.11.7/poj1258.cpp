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

const int inf = 0xffffff;
const int maxn = 111;
int d[maxn];
int G[maxn][maxn];
int vis[maxn];
int n;

void init() {
    memset(vis, 0, sizeof(vis));
    for(int i = 0; i <= n; i++) d[i] = inf;
}

int prim(int s) {
    d[s] = 0;
    for(int i = 0; i < n; i++) {
        int u = -1;
        for(int j = 0; j < n; j++) {
            if(!vis[j] && (u == -1 || d[u] > d[j])) {
                u = j;
            }
        }
        vis[u] = 1;
        for(int j = 0; j < n; j++) {
            if(!vis[j]) {
                d[j] = min(G[u][j], d[j]);
            }
        }
    }
    int sp = 0;
    for(int i = 0; i < n; i++) {
        sp += d[i];
    }
    return sp;
}

int main() {
    // freopen("in", "r", stdin);
    while(~scanf("%d", &n)) {
        init();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                scanf("%d", &G[i][j]);
            }
        }
        printf("%d\n", prim(0));
    }
}
