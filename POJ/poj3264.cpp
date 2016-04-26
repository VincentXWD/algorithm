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

#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
typedef pair<int, int> pii;
const int maxn = 50050;
int n, q, a, b;
pii node[maxn<<2];

void pushUP(int rt) {
    int ll = min(node[rt<<1].first, node[rt<<1|1].first);
    int rr = max(node[rt<<1].second, node[rt<<1|1].second);
    node[rt] = pii(ll, rr);
}

void build(int l, int r, int rt) {
    if(l == r) {
        scanf("%d", &node[rt].first);
        node[rt].second = node[rt].first;
        return;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    pushUP(rt);
}

int querymax(int L, int R, int l, int r, int rt) {
    if(L <= l && r <= R) {
        return node[rt].second;
    }
    int m = (l + r) >> 1;
    int ans = -1;
    if(L <= m) ans = max(ans, querymax(L, R, lson));
    if(m < R) ans = max(ans, querymax(L, R, rson));
    return ans;
}

int querymin(int L, int R, int l, int r, int rt) {
    if(L <= l && r <= R) {
        return node[rt].first;
    }
    int m = (l + r) >> 1;
    int ans = 0x7f7f7f;
    if(L <= m) ans = min(ans, querymin(L, R, lson));
    if(m < R) ans = min(ans, querymin(L, R, rson));
    return ans;
}

int main() {
	// freopen("in", "r", stdin);
	while(~scanf("%d %d", &n, &q)) {
		build(1, n, 1);
		while(q--) {
			scanf("%d %d", &a, &b);
			int ll = querymin(a, b, 1, n, 1);
			int rr = querymax(a, b, 1, n, 1);
			printf("%d\n", rr - ll);
		}
	}
	return 0;
}