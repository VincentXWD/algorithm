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
typedef long long LL;
const int maxn = 100010;
LL sum[maxn<<2];
LL add[maxn<<2];
int n, q;

void pushUP(int rt) {
	sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}

void pushDOWN(int rt, int m) {
	if(add[rt]) {	
		add[rt<<1] += add[rt];
		add[rt<<1|1] += add[rt];
		sum[rt<<1] += (m - (m >> 1)) * add[rt];
		sum[rt<<1|1] += (m >> 1) * add[rt];
		add[rt] = 0;
	}
}

void build(int l, int r, int rt) {
	add[rt] = 0;
	if(l == r) {
		scanf("%I64d", &sum[rt]);
		return;
	}
	int m = (l + r) >> 1;
	build(lson);
	build(rson);
	pushUP(rt);
}

void update(int L, int R, int c, int l, int r, int rt) {
	if(L <= l && r <= R) {
		add[rt] += c;
		sum[rt] += (LL)c * (r - l + 1);
		return;
	}
	pushDOWN(rt, r-l+1);
	int m = (l + r) >> 1;
	if(L <= m) update(L, R, c, lson);
	if(R > m) update(L, R, c, rson);
	pushUP(rt);
}

LL query(int L, int R, int l, int r, int rt) {
	if(L <= l && r <= R) {
		return sum[rt];
	}
	pushDOWN(rt, r - l + 1);
	int m = (l + r) >> 1;
	LL ans = 0;
	if(L <= m) ans += query(L, R, lson);
	if(m < R) ans += query(L, R, rson);
	return ans;
}

int main() {
	// freopen("in", "r", stdin);
	int a, b, c;
	char cmd[3];
	while(~scanf("%d %d", &n, &q)) {
		build(1, n, 1);
		while(q--) {
			scanf("%s", cmd);
			if(cmd[0] == 'Q') {
				scanf("%d %d", &a, &b);
				printf("%I64d\n", query(a, b, 1, n, 1));
			}
			else {
				scanf("%d %d %d", &a, &b, &c);
				update(a, b, c, 1, n, 1);
			}
		}
	}
	return 0;
}