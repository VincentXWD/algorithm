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

const int maxn = 500;
int n, m;
int w[maxn], v[maxn];
int dp[1000011];

int main() {
	// freopen("in", "r", stdin);
	while(~scanf("%d %d", &n, &m)) {
		for(int i = 0; i < n; i++) {
			scanf("%d %d", &w[i], &v[i]);
		}
		memset(dp, 0, sizeof(dp));
		bool exflag = 0;
		for(int i = 0; i < n; i++) {
			if(exflag) break;
			for(int j = m; j >= w[i]; j--) {
				if(exflag) break;
				dp[j] = max(dp[j], dp[j-w[i]]+v[i]);
				if(i == n - 1 && j == m) exflag = 1;
			}
		}
		printf("%d\n", dp[m]);
	}
	return 0;
}
