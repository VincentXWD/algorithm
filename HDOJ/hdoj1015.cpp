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
const ll maxn = 15;
ll aim;
ll n;
char str[maxn];
char ans[maxn];
char wtf[maxn];
bool flag;

ll quickmul(ll x, ll n) {
	ll ans = 1;
	ll t = x;
	while(n) {
		if(n & 1) {
			ans = (ans * t);
		}
		t = t * t;
		n >>= 1;
	}
	return ans;
}

int main() {
	// freopen("in", "r", stdin);
	// freopen("out", "w", stdout);
	while(~scanf("%I64d %s", &aim, str)) {
		if(aim == 0 && strcmp("END", str) == 0) break; 
		memset(wtf, 0, sizeof(wtf));
		n = strlen(str);
		ll nn = 1 << n;
		flag = 0;
		sort(str, str+n, greater<char>());
		for(ll i = 1; i < nn; i++) {
			ll cnt = 0;
			memset(ans, 0, sizeof(ans));
			for(ll j = 0; j < n; j++) {
				if((1 << j) & i) {
					ans[cnt++] = str[j];
				}
			}
			if(cnt != 5) continue;
			sort(ans, ans+cnt);
			do {
				ll tmp = ans[0] - 'A' + 1;
				for(ll k = 1; k < cnt; k++) {
					tmp += quickmul(-1, k) * quickmul(ans[k]-'A'+1, k+1);
				}
				if(tmp == aim) {
					flag = 1;
					if(strcmp(wtf, ans) < 0) {
						strcpy(wtf, ans);
					}
				}
			}while(next_permutation(ans, ans+cnt));
		}
		if(!flag) printf("no solution\n");
		else printf("%s\n", wtf);
	}
	return 0;
}