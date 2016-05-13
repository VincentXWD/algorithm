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
typedef long long ll;
const ll maxn = 100010;
ll sum[maxn<<2];
ll add[maxn<<2];
ll n, q;

void pushUP(ll rt) {
    sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}

void pushDOWN(ll rt, ll m) {
    if(add[rt]) {
        add[rt<<1] = add[rt];
        add[rt<<1|1] = add[rt];
        sum[rt<<1] = (m - (m >> 1)) * add[rt];
        sum[rt<<1|1] = (m >> 1) * add[rt];
        add[rt] = 0;
    }
}

void build(ll l, ll r, ll rt) {
    add[rt] = 0;
    if(l == r) {
    	cin >> sum[rt];
        return;
    }
    ll m = (l + r) >> 1;
    build(lson);
    build(rson);
    pushUP(rt);
}

void update(ll L, ll R, ll c, ll l, ll r, ll rt) {
    if(L <= l && r <= R) {
        add[rt] = c;
        sum[rt] = (ll)c * (r - l + 1);
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
    if(L <= m) ans += query(L, R, lson);
    if(m < R) ans += query(L, R, rson);
    return ans;
}

int main() {
    // freopen("in", "r", stdin);
    ll a, b, c, d;
    while(cin >> n) {
        build(1, n, 1);
        cin >> q;
        while(q--) {
        	cin >> a;
        	if(a == 0) {
        		cin >> b >> c;
        		cout << query(b, c, 1, n, 1) << endl;
        	}
        	else {
        		cin >> b >> c >> d;
        		update(b, c, d, 1, n, 1);
        	}
        }
    }
    return 0;
}