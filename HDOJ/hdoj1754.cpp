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
const int maxn = 222222;
int score[maxn<<2];

int max(int a, int b) {
    return a > b ? a : b;
}

void pushUP(int rt) {
    score[rt] = max(score[rt<<1], score[rt<<1|1]);
}

void build(int l, int r, int rt) {
    if(l == r) {
        scanf("%d", &score[rt]);
        return;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    pushUP(rt);
}

void update(int p, int cur, int l, int r, int rt) {
    if(l == r) {
        score[rt] = max(cur, score[rt]);
        return;
    }
    int m = (l + r) >> 1;
    if(p <= m) {
        update(p, cur, lson);
    }
    else {
        update(p, cur, rson);
    }
    pushUP(rt);
}

int query(int L, int R, int l, int r, int rt) {
    if(L <= l && r <= R) {
        return score[rt];
    }
    int m = (l + r) >> 1;
    int cur = 0;
    if(L <= m) {
        cur = max(query(L, R, lson), cur);
    }
    if(R > m) {
        cur = max(query(L, R, rson), cur);
    }
    return cur;
}

int main() {
    // freopen("in", "r", stdin);
    int n, q;
    while(~scanf("%d %d", &n, &q)) {
        memset(score, 0, sizeof(score));
        build(1, n, 1);
        char cmd[3];
        int a, b;
        for(int i = 0; i < q; i++) {
            scanf("%s", cmd);
            scanf("%d %d", &a, &b);
            if(cmd[0] == 'Q') {
                printf("%d\n", query(a, b, 1, n, 1));
            }
            else {
                update(a, b, 1, n, 1);
            }
        }
    }
    return 0;
}
