#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <climits>
#include <complex>
#include <fstream>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <bitset>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <ctime>
#include <set>
#include <map>
#include <cmath>

#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
const int maxn = 55555;
int sum[maxn<<2];

void pushUP(int rt) {
    sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}

void build(int l, int r, int rt) {
    if(l == r) {
        scanf("%d", &sum[rt]);
        printf("%d ", rt);
        return;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    pushUP(rt);
}

void update(int p, int add, int l, int r, int rt) {
    if(l == r) {
        sum[rt] += add;
        return;
    }
    int m = (l + r) >> 1;
    if(p <= m) {
        update(p, add, lson);
    }
    else {
        update(p, add, rson);
    }
    pushUP(rt);
}

int query(int L, int R, int l, int r, int rt) {
    if(L <= l && r <= R) {
        return sum[rt];
    }
    int m = (l + r) >> 1;
    int ret = 0;
    if(L <= m) {
        ret += query(L, R, lson);
    }
    if(R > m) {
        ret += query(L, R, rson);
    }
    return ret;
}

int main() {
    // freopen("in", "r", stdin);
    int T, n;
    scanf("%d", &T);
    for(int ii = 1; ii <= T; ii++) {
        printf("Case %d:\n",ii);
        scanf("%d", &n);
        build(1, n, 1);
        printf("\n");
        char cmd[10];
        while(scanf("%s", cmd)) {
            if(cmd[0] == 'E') {
                break;
            }
            int a, b;
            scanf("%d %d", &a, &b);
            if(cmd[0] == 'Q') {
                printf("%d\n", query(a, b, 1, n, 1));
            }
            else if(cmd[0] == 'A') {
                update(a, b, 1, n, 1);
            }
            else if(cmd[0] == 'S') {
                update(a, -b, 1, n, 1);
            }
        }
    }
    return 0;
}