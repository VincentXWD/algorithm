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

typedef long long ll;
const int maxn = 100010;
const int mod = 9973;
int n;
char s[maxn];
int h[maxn];
int fac[10000];

ll quickmul(int x, int len) {
	ll ans = 1;
	ll t = x;
	while(len) {
		if(len & 1) {
			ans = (ans * t) % mod;
		}
		t = t * t % mod;
		len >>= 1;
	}
	return ans;
}

int main() {
	// FRead();
	fac[0] = 1;
	For(i, 1, mod+1) {
		fac[i] = quickmul(i, mod-2);
	}
	while(~Rint(n)) {
		Rs(s+1);
		int len = strlen(s+1);
		h[0] = 1;
		For(i, 1, len+1) {
			h[i] = (h[i-1] * ((s[i] - 28) % mod)) % mod;
		}
		Rep(i, n) {
			int a,b;
			Rint(a); Rint(b);
			int ans = h[b] * fac[h[a-1]] % mod;
			printf("%d\n",ans % mod);
		}
	}
}