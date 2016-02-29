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

const int maxn = 222;
const int INF = 0x7f7f7f;
int n;
int a[maxn], sum[maxn];
int dp[maxn][maxn];

int main() {
	// freopen("in", "r", stdin);
	while(~scanf("%d", &n)) {
		for(int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			sum[i] = sum[i-1] + a[i];
		}
		for(int v = 2; v <= n; v++) {
			for(int i = 0; i < n; i++) {
				int j = i + v - 1;
				dp[i][j] = INF;
				for(int k = i; k < j; k++) {
					dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + sum[j] - sum[i-1]);
				}
			}
		}
		printf("%d\n", dp[0][n-1]);
	}
	return 0;
}
