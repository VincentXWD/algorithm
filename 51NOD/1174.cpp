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
const int maxn = 55555;

int sum[maxn<<2];
int n, m;

void pushUP(int rt) {
	sum[rt] = max(sum[rt<<1], sum[rt<<1|1]);
}

void update(int p, int add, int l, int r, int rt) {
    if(l == r) {
        sum[rt] = max(sum[rt], add);
        return;
    }
    int m = (l + r) >> 1;
    if(p <= m) update(p, add, lson);
    else update(p, add, rson);
    pushUP(rt);
}

int query(int L, int R, int l, int r, int rt) {
	if(L <= l && r <= R) {
		return sum[rt];
	}
	int m = (l + r) >> 1;
	int ret = 0;
	if(L <= m) ret = max(ret, query(L, R, lson));
	if(R > m) ret = max(ret, query(L, R, rson));
	return ret;
}

int main() {
	// freopen("in", "r", stdin);
	while(~scanf("%d", &n)) {
		memset(sum, -1, sizeof(sum));
		int a, b;
		for(int i = 0; i < n; i++) {
			scanf("%d", &a);
			update(i+1, a, 1, n, 1);
		}
		scanf("%d", &m);
		while(m--) {
			scanf("%d%d", &a, &b);
			printf("%d\n", query(a+1, b+1, 1, n, 1));
		}
	}
	return 0;
}