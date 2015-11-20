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

const int inf = 0x7f7f7f7f;
const int maxn = 2222;
int N, F, D;
int n[maxn], f[maxn], d[maxn];
int S, T;
struct node {
    int u, v, c, next;
}e[maxn<<1];
int tot, last[maxn];
int cur[maxn], dist[maxn], que[maxn], sta[maxn], top, head, tail;

void adde(int u, int v, int c, int c1) {
    e[tot].u = u; e[tot].v = v; e[tot].c = c; e[tot].next = last[u]; last[u] = tot++;
    e[tot].u = v; e[tot].v = u; e[tot].c = c1; e[tot].next = last[v]; last[v] = tot++;
}

bool bfs(int s, int t, int n) {
    int i, j, u, v;
    for(i = 0; i < n; i++) dist[i] = inf;
    dist[s] = 0;
    head = tail = 0;
    que[tail++] = s;
    while(head < tail) {
        u = que[head++];
        for(j = last[u]; j != -1; j = e[j].next) {
            if(e[j].c == 0) continue;
            v = e[j].v;
            if(dist[v] > dist[u] + 1) {
                dist[v] = dist[u] + 1;
                if(v == t) return true;
                que[tail++] = v;
            }
        }
    }
    return false;
}

int dinic(int s, int t, int n) {
    int i, j, u, v;
    int maxflow = 0;
    while(bfs(s, t, n)) {
        for(i = 0; i < n; i++) cur[i] = last[i];
        u = s; top = 0;
        while(cur[s] != -1) {
            if(u == t) {
                int tp = inf;
                for(i = top - 1; i >= 0; i--) {
                    tp = min(tp, e[sta[i]].c);
                }
                maxflow += tp;
                for(i = top - 1; i >= 0; i--) {
                    e[sta[i]].c -= tp;
                    e[sta[i] ^ 1].c += tp;
                    if(e[sta[i]].c == 0) top = i;
                }
                u = e[sta[top]].u;
            }
            else if(cur[u] != -1 && e[cur[u]].c > 0 && dist[u] + 1 == dist[e[cur[u]].v]) {
                sta[top++] = cur[u];
                u = e[cur[u]].v;
            }
            else {
                while(u != s && cur[u] == -1) {
                    u = e[sta[--top]].u;
                }
                cur[u] = e[cur[u]].next;
            }
        }
    }
    return maxflow;
}

int main() {
    // freopen("in", "r", stdin);
    while(~scanf("%d %d %d", &N, &F, &D)) {
        memset(last, -1, sizeof(last));
        for(int i = 0; i < maxn; i++) e[i].next = -1;
        S = 0;
        T = 2 * N + F + D + 1;
        int ff, dd;
        //把牛的位置拆开，放在食物和饮料中间
        //S指向食物，饮料指向T，牛指向牛
        for(int i = 1; i <= F; i++) adde(S, i, 1, 0);
        for(int i = 1; i <= D; i++) adde(2*N+F+i, T, 1, 0);
        for(int i = 1; i <= N; i++) adde(F+i, F+N+i, 1, 0);
        //确定食物指向牛、牛指向饮料的关系
        for(int i = 1; i <= N; i++) {
            int tmp;
            scanf("%d %d", &ff, &dd);
            for(int j = 0; j < ff; j++) {
                scanf("%d", &tmp);
                adde(tmp, F+i, 1, 0);
            }
            for(int j = 0; j < dd; j++) {
                scanf("%d", &tmp);
                adde(F+N+i, 2*N+F+tmp, 1, 0);
            }
        }
        printf("%d\n", dinic(S, T, T+1));
    }
    return 0;
}