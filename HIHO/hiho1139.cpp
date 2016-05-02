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

typedef struct Node {
    int v, w;
    Node() {}
    Node(int vv, int ww) : v(vv), w(ww) {}
}Node;

const int maxn = 20010;
int n, m, k, t;
int d[maxn];
vector<Node> G[maxn];
int front, tail;
int que[maxn*10];

int bfs(int w) {
    memset(d, -1, sizeof(d));
    memset(que, 0, sizeof(que));
    front = tail = 0;
    que[tail++] = 1;
    d[1] = 0;
    while(front < tail) {
        int u = que[front++];
        for(int i = 0; i < G[u].size(); i++) {
            if((d[G[u][i].v] == -1 || d[G[u][i].v] > d[u] + 1) && w >= G[u][i].w && d[u] + 1 <= k) {
                d[G[u][i].v] = d[u] + 1;
                que[tail++] = G[u][i].v;
            }
        }
    }
    if(d[t] == -1 || d[t] > k) return 0;
    return 1;
}

int main() {
    // freopen("in", "r", stdin);
    int u, v, w;
    while(~scanf("%d%d%d%d", &n, &m, &k, &t)) {
        for(int i = 0; i < maxn; i++) G[i].clear();
        for(int i = 0; i < m; i++) {
            scanf("%d%d%d", &u, &v, &w);
            G[u].push_back(Node(v, w));
            G[v].push_back(Node(u, w));
        }
        int ll = 1, rr = 1000000;
        int ans = 0;
        while(ll <= rr) {
            int mm = (ll + rr) >> 1;
            if(bfs(mm)) {
                ans = mm;
                rr = mm - 1;
            }
            else ll = mm + 1;
        }
        printf("%d\n", ans);
    }
    return 0;
}