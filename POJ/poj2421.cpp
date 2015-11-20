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
    int u;
    int v;
    int w;
}E;

const int maxn = 1111;
int n, m, q;
int a[maxn];
int pre[maxn];
E e[maxn*maxn];

bool cmp(E e1, E e2) {
    return e1.w < e2.w;
}

void init() {
    m = 0;
    for(int i = 0; i < maxn; i++) {
        pre[i] = i;
    }
}

int find(int x) {
    return x == pre[x] ? x : pre[x] = find(pre[x]);
}

bool unite(int x, int y) {
    x = find(x);
    y = find(y);
    if(x != y) {
        pre[x] = y;
        return 1;
    }
    return 0;
}

int main() {
    int u, v;
    // freopen("in", "r", stdin);
    while(~scanf("%d", &n)) {        
        init();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                scanf("%d", &v);
                e[m].u = i;
                e[m].v = j;
                e[m++].w = v;
            }
        }
        scanf("%d", &q);
        for(int i = 0; i < q; i++) {
            scanf("%d %d", &u, &v);
            int j = 0;
            for(; j < m; j++) {
                if(e[j].u == u - 1 && e[j].v == v - 1) {
                    break;
                }
            }
            e[j].w = 0;
        }
        sort(e, e+m, cmp);
        int ans = 0;
        for(int i = 0; i < m; i++) {
            if(unite(e[i].u, e[i].v)) {
                ans += e[i].w;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
