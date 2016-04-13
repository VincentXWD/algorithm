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

int n;
int dp[maxn][maxn];
int G[maxn][maxn];

int main() {
	// freopen("in", "r", stdin);
	while(~scanf("%d", &n)) {
		memset(dp, 0, sizeof(dp));
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= i; j++) {
				scanf("%d", &G[i][j]);
			}
		}
		dp[1][1] = G[1][1];
		for(int i = 2; i <= n; i++) {
			for(int j = 1; j <= i; j++) {
				dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + G[i][j];
			}
		}
		int ans = -1;
		for(int i = 1; i <= n; i++) {
			ans = max(ans, dp[n][i]);
		}
		printf("%d\n", ans);
	}
	return 0;
}