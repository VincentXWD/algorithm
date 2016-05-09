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
#define Rint(a) scanf("%d", &a)
#define Rll(a) scanf("%lld", &a)
#define Rep(i, n) for(int i = 0; i < (n); i++)
#define For(i, a, n) for(int i = (a); i < (n); i++)

typedef long long ll;
const int maxn = 1010;
ll n;
ll m[maxn], r[maxn];

ll exgcd(ll a, ll b, ll &x, ll &y) {
    if(b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    else {
        ll ret = exgcd(b, a%b, x, y);
        ll tmp = x;
        x = y;
        y = tmp - a / b * y;
        return ret;
    }
}

int main() {
	// freopen("in", "r", stdin);
	Rll(n);
	Rep(i, n) {
		Rll(m[i]); Rll(r[i]);
	}
	ll mm = m[0], rr = r[0];
	For(i, 1, n) {
		ll d = __gcd(mm, m[i]);
		ll c = r[i] - rr;
		if(c % d) {
			printf("-1\n");
			return 0;
		}
		ll k1, k2;
		exgcd(mm / d, m[i] / d, k1, k2);
		k1 = (c / d * k1) % (m[i] / d);
		rr = rr + k1 * mm;
		mm = mm / d * m[i];
		rr %= mm;
	}
	if(rr < 0) rr += mm;
	printf("%lld\n", rr);
	return 0;
}