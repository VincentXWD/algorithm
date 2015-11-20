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

const int inf = 0x7fffff;
const int maxn = 222;
int G[maxn][maxn];
int pre[maxn];
int vis[maxn];
int m, n, s, t;

void init() {
    memset(G, 0, sizeof(G));
    memset(pre, 0, sizeof(pre));
    memset(vis, 0, sizeof(vis));
}

bool bfs() {
    memset(vis, 0, sizeof(vis));
    memset(pre, 0, sizeof(pre));
    queue<int> q;
    q.push(s);
    vis[s] = 1;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int i = 1; i <= n; i++) {
            if(G[u][i] > 0 && !vis[i]) {
                q.push(i);
                vis[i] = 1;
                pre[i] = u;
                if(i == n) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

int max_flow() {
    int flow = 0;
    while(1) {
        if(!bfs()) return flow;
        int v = n;
        int k = inf;
        while(pre[v]) {
            k = min(k, G[pre[v]][v]);
            v = pre[v];
        }
        v = n;
        flow += k;
        while(pre[v]) {
            G[v][pre[v]] += k;
            G[pre[v]][v] -= k;
            v = pre[v];
        }
    }
    return flow;
}

int main() {
    freopen("in", "r", stdin);
    int u, v, c;
    while(~scanf("%d %d", &m, &n)) {
        init();
        for(int i = 0; i < m; i++) {
            scanf("%d %d %d", &u, &v, &c);
            G[u][v] += c;
        }
        s = 1; t = n;
        printf("%d\n", max_flow());
    }
}
