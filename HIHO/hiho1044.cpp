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

const int maxn = 1111;
int dp[maxn][maxn];
int w[maxn];
int n, m, q;

int main() {
	// freopen("in", "r", stdin);
	while(~scanf("%d %d %d", &n, &m, &q)) {
		for(int i = 1; i <= n; i++) {
			scanf("%d", &w[i]);
		}
		memset(dp, 0, sizeof(dp));
		int s = 1 << m;
		for(int i = 1; i <= n; i++) {
			for(int j = 0; j < s; j++) {
				int ss = 0;
				int tmp = j << 1;
				while(tmp) ss += ((tmp>>=1) & 1);
				if(ss > q) continue;
				if(ss < q) dp[i][j] = 
					max(dp[i-1][j>>1], dp[i-1][(j>>1)+(1<<(m-2))]);
				else dp[i][j] = dp[i-1][j>>1];
				if(j & 1) dp[i][j] += w[i];
			}
		}
		int ans = -1;
		for(int i = 0; i < s; i++) {
			ans = max(ans, dp[n][i]);
		}
		printf("%d\n", ans);
	}
}