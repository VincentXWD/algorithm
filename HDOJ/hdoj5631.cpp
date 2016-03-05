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

typedef struct Edge {
    int u;
    int v;
};

const int maxn = 111;
int n;
Edge e[maxn];
int pre[maxn];
bool vis[maxn];

int find(int x) {
    return x == pre[x] ? x : pre[x] = find(pre[x]);
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if(x != y) {
        pre[y] = x;
    }
}
inline void init() {
    for(int i = 0; i < maxn; i++) {
        pre[i] = i;
    }
}

bool ok() {
    init();
    for(int i = 0; i <= n; i++) {
        if(vis[i]) unite(e[i].u, e[i].v);
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        if(pre[i] == i) cnt++;
        if(cnt > 1) return 0;
    }
    return 1;
}

int main() {
    // freopen("in", "r", stdin);
    int T;
    scanf("%d", &T);
    while(T--) {
        int ans = 0;
        memset(vis, 0, sizeof(vis));
        scanf("%d", &n);
        for(int i = 0; i <= n; i++) {
            scanf("%d %d", &e[i].u, &e[i].v);
            vis[i] = 1;
        }
        for(int i = 0; i <= n; i++) {
            vis[i] = 0;
            if(ok()) ans++;
            for(int j = i + 1; j <= n; j++) {
                vis[j] = 0;
                if(ok()) ans++;
                vis[j] = 1;
            }
            vis[i] = 1;
        }
        printf("%d\n", ans);
    }
    return 0;    
}