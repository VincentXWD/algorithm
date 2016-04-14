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

const int maxn = 100010;
int n, k;
int dp[maxn];

int main() {
	// freopen("in", "r", stdin);
	for(int i = 0; i <= maxn; i++) {
		dp[i] = i;
	}
	while(~scanf("%d %d", &n, &k)) {
		for(int i = 1; i <= n; i++) {
			dp[2*i-1] = 2 * i;
			dp[2*i] = 2 * i - 1;
		}
		for(int i = 1; k; i++, k--) {
			swap(dp[2*i-1], dp[2*i]);
		}
		for(int i = 1; i <= 2 * n; i++) {
			printf("%d ", dp[i]);
		}
		printf("\n");
	}
	return 0;
}
