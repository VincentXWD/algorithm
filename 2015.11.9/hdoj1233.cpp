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

typedef pair<int, int> PII; //w v

typedef struct E{
    int w;
    int v;
    E() {}
    E(int vv, int ww) : v(vv), w(ww) {}
}E;

const int inf = 0x7fffff;
const int maxn = 111111;
int n, nn;
int vis[maxn], d[maxn];
vector<E> e[maxn];
priority_queue<PII, vector<PII>, greater<PII> > pq;

int prim(int s) {
    int mst = 0;
    memset(vis, 0, sizeof(vis));
    for(int i = 0; i <= n; i++) d[i] = inf;
    while(!pq.empty()) pq.pop();
    d[s] = 0;
    pq.push(PII(0, 1));
    while(!pq.empty()) {
        PII cur = pq.top(); pq.pop();
        int w = cur.first;
        int v = cur.second;
        if(vis[v] || d[v] < w) continue;
        vis[v] = 1;
        mst += w;
        for(int i = 0; i < e[v].size(); i++) {
            int u = e[v][i].v;
            int w = e[v][i].w;
            if(!vis[u] && w < d[u]) {
                d[u] = w;
                pq.push(PII(d[u], u));
            }
        }
    }
    return mst;
}

int main() {
    // freopen("in", "r", stdin);
    int u, v, w;
    while(~scanf("%d", &n) && n) {
        nn = n * (n - 1) / 2;
        for(int i = 0; i <= n; i++) e[i].clear();
        for(int i = 0; i < nn; i++) {
            scanf("%d %d %d", &u, &v, &w);
            e[u].push_back(E(v, w));
            e[v].push_back(E(u, w));
        }
        printf("%d\n", prim(1));
    }
}
