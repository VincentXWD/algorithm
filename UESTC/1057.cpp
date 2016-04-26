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

typedef long long ll;
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
const ll maxn = 10000010;
ll sum[maxn<<2];
ll add[maxn<<2];
ll n, q;

void pushUP(ll rt) {
    //modify
    sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}

void pushDOWN(ll rt, ll m) {
    if(add[rt]) {
        //modify
        add[rt<<1] += add[rt];
        add[rt<<1|1] += add[rt];
        sum[rt<<1] += (m - (m >> 1)) * add[rt];
        sum[rt<<1|1] += (m >> 1) * add[rt];
        add[rt] = 0;
    }
}

void build(ll l, ll r, ll rt) {
    add[rt] = 0;
    if(l == r) {
        scanf("%lld", &sum[rt]);
        return;
    }
    ll m = (l + r) >> 1;
    build(lson);
    build(rson);
    pushUP(rt);
}

void update(ll L, ll R, ll c, ll l, ll r, ll rt) {
    if(L <= l && r <= R) {
        //modify
        add[rt] += c;
        sum[rt] += (ll)c * (r - l + 1);
        return;
    }
    pushDOWN(rt, r-l+1);
    ll m = (l + r) >> 1;
    if(L <= m) update(L, R, c, lson);
    if(R > m) update(L, R, c, rson);
    pushUP(rt);
}

ll query(ll L, ll R, ll l, ll r, ll rt) {
    if(L <= l && r <= R) {
        return sum[rt];
    }
    pushDOWN(rt, r - l + 1);
    ll m = (l + r) >> 1;
    ll ans = 0;
    //modify
    if(L <= m) ans += query(L, R, lson);
    if(m < R) ans += query(L, R, rson);
    return ans;
}

int main() {
    // freopen("in", "r", stdin);
    ll a, b, c;
    while(~scanf("%lld", &n)) {
        build(1, n, 1);
        scanf("%d", &q);
        while(q--) {
        	scanf("%lld %lld  %lld ", &a, &b, &c);
        	update(a, b, c, 1, n, 1);
        	printf("%lld", query(a, b, 1, n, 1));
        	if(q != 0) printf("\n");
        }
    }
    return 0;
}