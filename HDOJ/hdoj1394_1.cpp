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
const int maxn = 6666;
int num[maxn<<2];
int tmp[maxn];
int h[maxn], hcnt;

void pushUP(int rt) {
	num[rt] = num[rt<<1] + num[rt<<1|1];
}

void build(int l, int r, int rt) {
	num[rt] = 0;
	if(l == r) return;
	int m = (l + r) >> 1;
	build(lson);
	build(rson);
}

void update(int p, int l, int r, int rt) {
	if(l == r) {
		num[rt]++;
		return;
	}
	int m = (l + r) >> 1;
	if(p <= m) update(p, lson);
	else update(p, rson);
	pushUP(rt);
}

int query(int L, int R, int l, int r, int rt) {
	if(L <= l && r <= R) return num[rt];
	int m = (l + r) >> 1;
	int cur = 0;
	if(L <= m) cur += query(L, R, lson);
	if(R > m) cur += query(L, R, rson);
	return cur;
}

int getid(int x) {
	return lower_bound(h, h+hcnt, x) - h;
}

int main() {
	// freopen("in", "r", stdin);
	int n;
	while(~scanf("%d", &n)) {
		build(0, n-1, 1);
		int inv = 0;
		for(int i = 0; i < n; i++) {
			scanf("%d", &tmp[i]);
			h[i] = tmp[i];
		}
		sort(h, h+n); hcnt = unique(h, h+n) - h;
		for(int i = 0; i < n; i++) {
			inv += query(getid(tmp[i]), n-1, 0, n-1, 1);
			update(getid(tmp[i]), 0, n-1, 1);
		}
		int ans = 0x7f7f7f;
		for(int i = 0; i < n; i++) {
			inv = inv - getid(tmp[i]) + n - getid(tmp[i]) - 1;
			ans = min(ans, inv);
		}
		printf("%d\n", ans);
	}
	return 0;
}