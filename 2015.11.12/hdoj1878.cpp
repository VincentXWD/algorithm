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

const int maxn = 1111;

int pre[maxn];
int m, n;
int dig[maxn];

void init() {
    memset(dig, 0, sizeof(dig));
    for(int i = 0; i < maxn; i++) pre[i] = i;
}

int find(int x) {
    return x == pre[x] ? x : pre[x] = find(pre[x]);
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if(x != y) pre[x] = y;
}

int main() {
    // freopen("in", "r", stdin);
    int u, v;
    while(~scanf("%d", &n) && n) {
        init();
        scanf("%d", &m);
        for(int i = 0; i < m; i++) {
            scanf("%d %d", &u, &v);
            dig[u]++; dig[v]++;
            unite(u, v);
        }
        int d = 0; int cnt = 0;
        for(int i = 1; i <= n; i++) {
            if(pre[i] == i) {
                cnt++;
                if(cnt > 1) break;
            }
            if(dig[i] & 1) d++;
        }
        if(cnt > 1) {
            printf("0\n");
            continue;
        }
        if(d == 0) printf("1\n");
        else printf("0\n");
    }
}
