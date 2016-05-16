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
#define Rep(i, len) for(int i = 0; i < (len); i++)
#define For(i, a, len) for(int i = (a); i < (len); i++)
#define Cls(a) memset((a), 0, sizeof(a))
#define Full(a) memset((a), 0x7f7f, sizeof(a))

#define lrt rt << 1
#define rrt rt << 1 | 1
const int maxn = 100010;
int sum[maxn<<2];
int add[maxn<<2];
int n, q;

void pushUP(int rt) {
	sum[rt] = sum[lrt] + sum[rrt];
}

void pushDOWN(int rt, int m) {
	if(add[rt]) {
		add[lrt] = add[rrt] = add[rt];
		sum[lrt] = (m - (m >> 1)) * add[rt];
		sum[rrt] = (m >> 1) * add[rt];
		add[rt] = 0;
	}
}

void build(int l, int r, int rt) {
	sum[rt] = 1;
	add[rt] = 0;
	if(l == r) return;
	int m = (l + r) >> 1;
	build(l, m, lrt);
	build(m+1, r, rrt);
}

void update(int L, int R, int c, int l, int r, int rt) {
	if(l >= L && R >= r) {
		add[rt] = c;
		sum[rt] = c * (r - l + 1);
		return;
	}
	pushDOWN(rt, r-l+1);
	int m = (l + r) >> 1;
	if(m >= L) update(L, R, c, l, m, lrt);
	if(m < R) update(L,R, c, m+1, r, rrt);
	pushUP(rt);
}

int query(int L, int R, int l, int r, int rt) {
	if(l >= L && R >= r) {
		return sum[rt];
	}
	pushDOWN(rt, r-l+1);
	int m = (l + r) >> 1;
	int ret = 0;
	if(m >= L) ret += query(L, R, l, m, lrt);
	if(m < R) ret += query(L, R, m+1, r, rrt);
	pushUP(rt);
	return ret;
}

int main() {
	// FRead();
	int T, _ = 1;
	int x, y, z;
	Rint(T);
	while(T--) {
		Rint(n); Rint(q);
		build(1, n, 1);
		Rep(i, q) {
			Rint(x); Rint(y); Rint(z);
			update(x, y, z, 1, n, 1);
		}
		// printf("Case %d: The total value of the hook is %d.\n", _++, query(1, n, 1, n, 1));
		printf("Case %d: The total value of the hook is %d.\n", _++, sum[1]);
	}
	return 0;
}