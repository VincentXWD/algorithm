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

using namespace std;

#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
const int maxn = 666666;
int num[maxn<<2];
int tmp[maxn];

void pushUP(int rt) {
    num[rt] = max(num[rt<<1], num[rt<<1|1]);
}

void build(int l, int r, int rt, int w) {
    num[rt] = w;
    if(l == r) {
        return;
    }
    int m = (l + r) >> 1;
    build(lson, w);
    build(rson, w);
}

int query(int x, int l, int r, int rt) {
    if(l == r) {
        num[rt] -= x;
        return l;
    }
    int m = (l + r) >> 1;
    int cur = (num[rt<<1] >= x) ? query(x, lson) : query(x, rson);
    pushUP(rt);
    return cur;
}

int main() {
    // freopen("in", "r", stdin);
    int h, w, n;
    while(~scanf("%d %d %d", &h, &w, &n)) {
        if(h > n) {
            h = n;
        }
        build(1, h, 1, w);
        while(n--) {
            int x;
            scanf("%d", &x);
            if(num[1] < x) {
                printf("-1\n");
            }
            else {
                printf("%d\n", query(x, 1, h, 1));
            }
        }
    }
    return 0;
}
