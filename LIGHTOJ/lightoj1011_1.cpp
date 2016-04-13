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

const int maxn = 18;
int dp[maxn][1<<maxn];
int G[maxn][maxn];

int main() {
	// freopen("in", "r", stdin);
	int T;
	cin >> T;
	int _ = 1;
	while(T--) {
		int n;
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				scanf("%d", &G[i][j]);
			}
		}
		memset(dp, 0, sizeof(dp));
		int s = 1 << n;
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j < s; j++) {
				int cnt = 0;
				for(int k = 0; k < n; k++) {
					if(j & (1 << k)) {
						cnt++;
					}
				}
				if(cnt != i) continue;
				for(int k = 0; k < n; k++) {
					if(j & (1 << k)) {
						dp[i][j] = max(dp[i][j], dp[i-1][j^(1<<k)] + G[i][k+1]);
					}
				}
			}

		}
		printf("Case %d: %d\n", _++, dp[n][(1<<n)-1]);
	}
	return 0;
}