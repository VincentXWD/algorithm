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

const int maxn = 111;
typedef struct Edge {
    int u;
    int v;
    int next;
    Edge() { next = -1; }
}Edge;

int head[maxn], ecnt;
Edge edge[maxn*maxn];
int n, m;

int bcnt, dindex;
int dfn[maxn], low[maxn];
int stk[maxn], top;
int belong[maxn];
int in[maxn], out[maxn];
bool instk[maxn];

void init() {
    memset(edge, 0, sizeof(edge));
    memset(head, -1, sizeof(head));
    memset(instk, 0, sizeof(instk));
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    memset(belong, 0, sizeof(belong));
    memset(in, 0, sizeof(in));
    memset(out, 0, sizeof(out));
    ecnt = top = bcnt = dindex = 0;
}

void adde(int uu, int vv) {
    edge[ecnt].u = uu;
    edge[ecnt].v = vv;
    edge[ecnt].next = head[uu];
    head[uu] = ecnt++;
}

void tarjan(int u) {
    int v = u;
    dfn[u] = low[u] = ++dindex;
    stk[++top] = u;
    instk[u] = 1;
    for(int i = head[u]; ~i; i=edge[i].next) {
        v = edge[i].v;
        if(!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if(instk[v] && dfn[v] < low[u]) {
            low[u] = dfn[v];
        }
    }
    if(dfn[u] == low[u]) {
        bcnt++;
        do {
            v = stk[top--];
            instk[v] = 0;
            belong[v] = bcnt;
        } while(v != u);
    }
}

int main() {
    // freopen("in", "r", stdin);
    int uu, vv;
    while(~scanf("%d", &n)) {
        init();
        for(uu = 1; uu <= n; uu++) {
            while(scanf("%d", &vv) && vv) {            
                adde(uu, vv);
            }
        }
        for(uu = 1; uu <= n; uu++) {
            if(!dfn[uu]) {
                tarjan(uu);
            }
        }
        if(bcnt == 1) {
            printf("1\n0\n");
            continue;
        }
        for(int i = 0; i < ecnt; i++) {
            if(belong[edge[i].u] != belong[edge[i].v]) {
                in[belong[edge[i].u]]++;
                out[belong[edge[i].v]]++;
            }
        }
        int ans1 = 0, ans2 = 0;
        for(int i = 1; i <= bcnt; i++) {
            if(!out[i]) ans1++;
            if(!in[i]) ans2++;
        }
        printf("%d\n%d\n", ans1, max(ans1, ans2));
    }
    return 0;
}