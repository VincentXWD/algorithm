#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <cmath>
#include <map>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

typedef long long LL;
LL n, m, k;
	
int main() {
	// freopen("in", "r", stdin);
	while(~scanf("%lld %lld %lld", &n, &m, &k)) {
		LL ans = 0;
		k /= 2;
		LL a, b;
		for(LL i = 1; i <= n; i++) {
			if(k < i) {
				break;
			}
			LL tmp = min(k-i, m);
			a = n - i + 1;
			b = (m + (m - tmp + 1)) * tmp / 2;
			ans += a * b;
		}
		printf("%lld\n", ans);
	}
}