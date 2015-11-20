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

typedef pair<int, int> PII;
const int inf = 100010;
const int maxn = 1111;

typedef struct Edge {
    int v;
    int w;
    Edge(int vv, int ww) : v(vv), w(ww) {}
};

vector<Edge> G1[maxn], G2[maxn];
int n, m, x;
int u, v, w;
int d1[maxn], d2[maxn];
int ans;

void dijkstra(int s, vector<Edge>* G, int* d) {
    priority_queue<PII, vector<PII>, greater<PII> > pq;
    for(int i = 1; i <= n; i++) d[i] = inf;
    d[s] = 0;
    pq.push(PII(0, s));
    while(!pq.empty()) {
        PII p = pq.top(); pq.pop();
        int v = p.second;
        if(d[v] < p.first) continue;
        for(int i = 0; i < G[v].size(); i++) {
            if(d[G[v][i].v] > d[v] + G[v][i].w) {
                d[G[v][i].v] = d[v] + G[v][i].w;
                pq.push(PII(d[G[v][i].v], G[v][i].v));
            }
        }
    }
}

int main() {
    // freopen("in", "r", stdin);
    scanf("%d %d %d", &n, &m, &x);
    for(int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        G1[u].push_back(Edge(v, w));
    }
    dijkstra(x, G1, d1);
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < G1[i].size(); j++) {
            G2[G1[i][j].v].push_back(Edge(i, G1[i][j].w));
        }
    }
    dijkstra(x, G2, d2);
    ans = 0;
    for(int i = 2; i <= n; i++) {
        if(i == x) continue;
        ans = max(ans, d1[i]+d2[i]);
    }
    printf("%d\n", ans);
    return 0;
}
