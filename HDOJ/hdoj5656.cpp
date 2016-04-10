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
const int mod = 100000007;
const int maxn = 1010;
ll ans;
int n;
int a[maxn];
int l[maxn][maxn];
int dp[maxn];

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

int main() {
	// freopen("in", "r", stdin);
	int T;
	scanf("%d", &T);
	for(int i = 1; i <= maxn; i++) {
		for(int j = 1; j <= maxn; j++) {
			l[i][j] = gcd(i, j);
		}
	}
	while(T--) {
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
		}
		ans = 0;
		memset(dp, 0, sizeof(dp));
		dp[a[1]] = 1;
		for(int i = 2; i <= n; i++) {
			for(int j = 1; j <= maxn; j++) {
				if(dp[j]) {
					int t = l[a[i]][j];
					dp[t] = (dp[t] + dp[j]) % mod;
				}
			}
			dp[a[i]] = (dp[a[i]] + 1) % mod;
		}
		for(int i = 1; i <= maxn; i++) {
			if(dp[i]) {
				ans = (ans + ll(dp[i]) * ll(i)) % mod;
			}
		}
		cout << ans << endl;
	}
	return 0;
}