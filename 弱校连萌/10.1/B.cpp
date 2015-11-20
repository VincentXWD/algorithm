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
const int maxn = 1000010;
int n;
int a[maxn];
int h[maxn];

int main() {
	// freopen("in", "r", stdin);
	while(~scanf("%d", &n)) {
		memset(h, 0, sizeof(h));
		for(int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		LL ans = 0;
		for(LL mod = 10; mod <= 1000000000; mod*=10) {	//no more than 10^9
			for(int i = 0; i < n; i++) {
				h[i] = a[i] % mod;
			}
			sort(h, h+n);
			int m = n - 1;
			for(int i = 0; i < n; i++) {
				while(i < m && h[i] + h[m] >= mod) {
					m--;
				}
				ans += min(n-i-1, n-m-1);
			}
		}
		printf("%lld\n", ans);
	}
}