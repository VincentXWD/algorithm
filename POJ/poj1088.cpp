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
const int maxn = 111;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

ll dp[maxn][maxn];
int mat[maxn][maxn];
int m, n;
ll ans;

inline void init() {
	memset(dp, 0, sizeof(dp));
}

inline bool edge(int x, int y) {
	return x >= 0 && y >= 0 && x < m && y < n;
}

ll dfs(int x, int y) {
	if(dp[x][y]) {
		return dp[x][y];
	}
	dp[x][y] = 1;
	for(int i = 0; i < 4; i++) {
		int xx = x + dx[i];
		int yy = y + dy[i];
		if(edge(xx, yy) && mat[xx][yy] < mat[x][y]) {
			dp[x][y] = max(dp[x][y], dfs(xx, yy) + 1);
		}
	}
	return dp[x][y];
}

int main() {
	// freopen("in", "r", stdin);
	while(~scanf("%d %d", &m, &n)) {
		init();
		ans = 0;
		for(int i = 0; i < m; i++) {
			for(int j = 0; j < n; j++) {
				scanf("%d", &mat[i][j]);
			}
		}
		for(int i = 0; i < m; i++) {
			for(int j = 0; j < n; j++) {
				ans = max(ans, dfs(i, j));
			}
		}
		printf("%I64d\n", ans);

	}
	return 0;
}