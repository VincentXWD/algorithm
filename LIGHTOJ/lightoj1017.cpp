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

const int maxn = 111;
int n, w, K;
int y[maxn];
int dp[maxn][maxn];

int main() {
	// freopen("in", "r", stdin);
	int T, x;
	scanf("%d", &T);
	for(int _ = 1; _ <= T; _++) {
		scanf("%d %d %d", &n, &w, &K);
		for(int i = 1; i <= n; i++) {
			scanf("%d %d", &x, &y[i]);
		}
		sort(y+1, y+n+1);
		memset(dp, 0, sizeof(dp));
		for(int i = 1; i <= n; i++) {
			for(int k = 1; k <= K; k++) {
				dp[i][k] = dp[i-1][k];
				int cnt = 0;
				for(int j = i; j >= 1; j--) {
					if(y[i] - y[j] > w) break;
					cnt++;
					dp[i][k] = max(dp[i][k], dp[j-1][k-1]+cnt);
				}
			}
		}
		int ans = -1;
		for(int i = 1; i <= K; i++) {
			ans = max(dp[n][i], ans);
		}
		printf("Case %d: %d\n", _, ans);
	}
	return 0;
}
