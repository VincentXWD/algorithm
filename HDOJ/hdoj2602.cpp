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

const int maxn = 555555;
int n, m;
int v[maxn];
int w[maxn];
int dp[maxn];

int main() {
	// freopen("in", "r", stdin);
	int T;
	scanf("%d", &T);
	while(T--) {
		memset(dp, 0, sizeof(dp));
		memset(v, 0, sizeof(v));
		memset(w, 0, sizeof(w));
		scanf("%d %d", &n, &m);
		for(int i = 1; i <= n; i++) scanf("%d", &v[i]);
		for(int i = 1; i <= n; i++) scanf("%d", &w[i]);
		for(int i = 1; i <= n; i++) {
			for(int j = m; j >= w[i]; j--) {
				dp[j] = max(dp[j], dp[j-w[i]]+v[i]);
			}
		}
		printf("%d\n", dp[m]);
	}
	return 0;
}
