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

const int maxn = 555;
const int inf = 0x7f7f7f;
int n, m;
int mat[maxn][maxn];
int dp[maxn];

int lss() {
	int tmp = -inf, ans = -inf;
	for(int i = 0; i < m; i++) {
		if(tmp > 0) tmp += dp[i];
		else tmp = dp[i];
		ans = max(tmp, ans);
	}
	return ans;
}

int main() {
	// freopen("in", "r", stdin);
	while(~scanf("%d", &n)) {
		m = n;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				scanf("%d", &mat[i][j]);
			}
		}
		int ans = -inf;
		for(int i1 = 0; i1 < n; i1++) {
			memset(dp, 0, sizeof(dp));
			for(int i2 = i1; i2 < n; i2++) {
				for(int j = 0; j < m; j++) {
					dp[j] += mat[i2][j];
				}
				int tmp = lss();
				ans = max(ans, tmp);
			}
		}
		printf("%d\n", ans);
	}
    return 0;
}