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
int dp[maxn];

int main() {
	// freopen("in", "r", stdin);
	dp[1] = 1;
	dp[2] = 2;
	for(int i = 3; i <= maxn; i++) {
		dp[i] = dp[i-1] + dp[i-2];
	}
	while(~scanf("%d", &n) && n) {
		printf("%d\n", dp[n]);
	}
	return 0;
}
