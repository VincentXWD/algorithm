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


typedef struct E {
    int w;
    int v;
    E() {}
    E(int vv, int ww) : v(vv), w(ww) {}
}E;

typedef pair<int, int> PII;
const int maxn = 5555;
const int inf = 0xffffff;

priority_queue<PII, vector<PII>, greater<PII> > pq;
vector<E> e[maxn];
int d1[maxn], d2[maxn];
int n, m, u, v, w;

void dijkstra(int s) {
    for(int i = 0; i <= n; i++) d1[i] = d2[i] = inf;
    while(!pq.empty()) pq.pop();
    d1[s] = 0;
    pq.push(PII(0, s));
    while(!pq.empty()) {
        PII cur = pq.top(); pq.pop();
        w = cur.first;
        v = cur.second;
        if(d2[v] < w) continue;
        for(int i = 0; i < e[v].size(); i++) {
            int dd = w + e[v][i].w;
            if(d1[e[v][i].v] > dd) {
                swap(d1[e[v][i].v], dd);
                pq.push(PII(d1[e[v][i].v], e[v][i].v));
            }
            if(d2[e[v][i].v] > dd && dd > d1[e[v][i].v]) {
                d2[e[v][i].v] = dd;
                pq.push(PII(d2[e[v][i].v], e[v][i].v));
            }
        }
    }
}

int main() {
    // freopen("in", "r", stdin);
    while(~scanf("%d %d", &n, &m)) {
        for(int i = 0; i < m; i++) {
            scanf("%d %d %d", &u, &v, &w);
            e[u].push_back(E(v, w));
            e[v].push_back(E(u, w));
        }
        dijkstra(1);
        printf("%d\n", d2[n]);
    }
}