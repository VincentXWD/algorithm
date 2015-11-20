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

typedef struct Com {
    int x;
    int y;
}Com;

const int maxn = 20010;
int pre[maxn];
int con[maxn];
int n, d, m;
Com com[maxn];

bool far(Com c1, Com c2) {
    return (c1.x-c2.x)*(c1.x-c2.x)+(c1.y-c2.y)*(c1.y-c2.y)<=d*d;
}

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
    memset(con, 0, sizeof(con));
    for(int i = 0; i < maxn; i++) {
        pre[i] = i;
    }
    m = 0;
}

int main() {
    // freopen("in", "r", stdin);
    int a, b;
    char cmd[3];
    while(~scanf("%d %d", &n, &d)) {
        init();
        for(int i = 1; i <= n; i++) {
            scanf("%d %d", &com[i].x, &com[i].y);
        }
        while(~scanf("%s", cmd)) {
            if(cmd[0] == 'S') {
                scanf("%d %d", &a, &b);
                if(find(a) == find(b)) printf("SUCCESS\n");
                else printf("FAIL\n");
            }
            else {
                scanf("%d", &a);
                for(int i = 0; i < m; i++) {
                    if(far(com[a], com[con[i]])) {
                        unite(a, con[i]);
                    }
                }
                con[m++] = a;
            }
        }
    }
    return 0;
}