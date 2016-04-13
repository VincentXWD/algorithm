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
const int maxn = 333;
int n, k;
ll dp[maxn][maxn];

int main() {
	// freopen("in", "r", stdin);
	int T;
	scanf("%d", &T);
	memset(dp, 0, sizeof(dp));
	for(int i = 0; i <= maxn; i++) {
		dp[i][0] = 1;
	}
	for(int i = 1; i <= maxn; i++) {
		for(int j = 1; j <= i; j++) {
			dp[i][j] = dp[i-1][j] + (2 * (i - j) + 1) * dp[i-1][j-1];
			if(j >= 2) dp[i][j] += (i - j + 1) * (i - j + 1) * dp[i-1][j-2];
		}
	}
		
	for(int _ = 1; _ <= T; _++) {
		scanf("%d %d", &n, &k);
		printf("Case %d: ", _);
		printf("%lld\n", dp[n][k]);
	}
	return 0;
}