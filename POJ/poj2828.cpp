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
const int maxn = 222222;
int st[maxn<<2];
int pos[maxn], num[maxn], ans[maxn];

void pushUP(int rt) {
    st[rt] = max(st[rt<<1], st[rt<<1|1]);
}

void build(int l, int r, int rt) {
    st[rt] = r - l + 1;
    if(l == r) {
        return;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
}

void update(int p, int l, int r, int rt, int& id) {
    st[rt]--;
    if(l == r) {
        id = l;
        return;
    }
    int m = (l + r) >> 1;
    if(st[rt<<1] >= p) {
        update(p, lson, id);
    }
    else {
        p -= st[rt<<1];
        update(p, rson, id);
    }
}

int main() {
    // freopen("in", "r", stdin);
    int n;
    while(~scanf("%d", &n)) {
        build(1, n, 1);
        for(int i = 1; i <= n; i++) {
            scanf("%d %d", &pos[i], &num[i]);
        }
        int id = 0;
        for(int i = n; i >= 1; i--) {
            update(pos[i]+1, 1, n, 1, id);
            ans[id] = num[i];
        }
        for(int i = 1; i <= n; i++) {
            printf("%d ", ans[i]);
        }
        printf("\n");
    }
    return 0;
}
