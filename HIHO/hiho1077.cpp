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

#define fr first
#define sc second
#define pb(a) push_back(a)
#define Rint(a) scanf("%d", &a)
#define Rll(a) scanf("%I64d", &a)
#define Rs(a) scanf("%s", a)
#define FRead() freopen("in", "r", stdin)
#define FWrite() freopen("out", "w", stdout)
#define Rep(i, n) for(int i = 0; i < (n); i++)
#define For(i, a, n) for(int i = (a); i < (n); i++)
#define Cls(a) memset((a), 0, sizeof(a))
#define Full(a) memset((a), 0x7f7f, sizeof(a))

const int maxn = 1000010;
int sum[maxn<<2];
int n, m;
int num[maxn];
int h[maxn], hcnt;

void pushUP(int rt) {
	sum[rt] = min(sum[rt<<1], sum[rt<<1|1]);
}

void update(int p, int x, int l, int r, int rt) {
	if(l == r) {
		sum[rt] = x;
		return;
	}
	int mid = (l + r) >> 1;
	if(p <= mid) update(p, x, l, mid, rt<<1);
	else update(p, x, mid+1, r, rt<<1|1);
	pushUP(rt);
}

int query(int L, int R, int l, int r, int rt) {
	if(L <= l && r <= R) return sum[rt];
	int ret = 0x7f7f7f;
	int mid = (l + r) >> 1;
	if(L <= mid) ret = min(ret, query(L, R, l, mid, rt<<1));
	if(R > mid) ret = min(ret, query(L, R, mid+1, r, rt<<1|1));
	return ret;
}

int getid(int x) {
	return lower_bound(h, h+hcnt, x) - h + 1;
}

int main() {
	// FRead();
	int cmd, a, b;
	while(~Rint(n)) {
		Cls(sum);
		For(i, 1, n+1) {
			Rint(num[i]);
			h[i] = num[i];
		}
		sort(h, h+n); hcnt = unique(h, h+n) - h;
		For(i, 1, n+1) update(i, num[i], 1, n, 1);
		Rint(m);
		while(m--) {
			Rint(cmd); Rint(a); Rint(b);
			if(cmd == 0) printf("%d\n", query(a, b, 1, n, 1));
			else update(a, b, 1, n, 1);
		}
	}
	return 0;
}