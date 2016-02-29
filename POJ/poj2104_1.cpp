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

#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1 | 1

const int maxn = 111111;
typedef struct Node {
	int l, r;
	int m() { return (l + r) >> 1; }
}Node;

Node tree[maxn<<2];
int seg[1<<5][maxn];
int tmp[maxn];
int n, m, I, J, K;

void build(int l, int r, int rt, int depth) {
	tree[rt].l = l;
	tree[rt].r = r;
	if(l == r) {
		seg[depth][l] = tmp[l];
		return;
	}
	int mid = tree[rt].m();
	build(lson, depth+1);
	build(rson, depth+1);
	int i = l, j = mid + 1, k = l;
	while(i <= mid && j <= r) { //merge
		if(seg[depth+1][i] < seg[depth+1][j]) seg[depth][k++] = seg[depth+1][i++];
		else seg[depth][k++] = seg[depth+1][j++];
	}
	while(j <= r) seg[depth][k++] = seg[depth+1][j++];
	while(i <= mid) seg[depth][k++] = seg[depth+1][i++];
}

int query(int rt, int depth, int v) {
	if(I <= tree[rt].l && J >= tree[rt].r) {
		return lower_bound(&seg[depth][tree[rt].l], &seg[depth][tree[rt].r] + 1, v) - &seg[depth][tree[rt].l];
	}
	int ans = 0;
	if(I <= tree[rt<<1].r) ans += query(rt<<1, depth+1, v);
	if(J >= tree[rt<<1|1].l) ans += query(rt<<1|1, depth+1, v);
	return ans;
}

int main() {
    // freopen("in", "r", stdin);
    while(~scanf("%d %d", &n, &m)) {
    	for(int i = 1; i <= n; i++) {
    		scanf("%d", &tmp[i]);
    	}
    	build(1, n, 1, 1);
    	while(m--) {
    		scanf("%d %d %d", &I, &J, &K);
    		K--;
    		int ll = 1, rr = n;
    		while(ll < rr) {
    			int mm = (ll + rr + 1) >> 1;
    			int pos = query(1, 1, seg[1][mm]);
    			if(pos <= K) ll = mm;
    			else rr = mm - 1;
    		}
    		printf("%d\n", seg[1][ll]);
    	}
    }
	return 0;
}
