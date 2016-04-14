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

const int maxn = 20000010;
int n;
int dp[maxn];

int main() {
	// freopen("in", "r", stdin);
	int T, x;
	memset(dp, 0x7f7f7f7f, sizeof(dp));
	dp[1] = 0;
	for(int i = 1; i < maxn; i++) {
		if((i+1) % 2 == 0) dp[i+1] = min(dp[i+1], dp[(i+1)/2]+1);
		if((i+1) % 3 == 0) dp[i+1] = min(dp[i+1], dp[(i+1)/3]+1);
		dp[i+1] = min(dp[i+1], dp[i]+1);
	}
	scanf("%d", &T);
	for(int _ = 1; _ <= T; _++) {
		scanf("%d", &n);
		printf("Case %d: %d\n", _, dp[n]);
	}
	return 0;
}
