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

const int maxn = 21;
const int dx[5] = {1, -1, 0, 0};
const int dy[5] = {0, 0, 1, -1};

int n, m;
int ans;
int sx, sy;
char G[maxn][maxn];
int vis[maxn][maxn];

bool ok(int x, int y) {
	return x >= 0 && y >= 0 && x < n && y < m;
}

void dfs(int x, int y) {
	for(int i = 0; i < 4; i++) {
		int xx = x + dx[i];
		int yy = y + dy[i];
		if(ok(xx, yy) && G[xx][yy] == '.') {
			G[xx][yy] = '#';
			vis[xx][yy] = 1;
			dfs(xx, yy);
		}
	}
}

int main() {
	// freopen("in", "r", stdin);
	while(~scanf("%d %d", &m, &n) && n + m) {
		for(int i = 0; i < n; i++) {
			scanf("%s", G[i]);
		}
		memset(vis, 0, sizeof(vis));
		ans = 0;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				if(G[i][j] == '@') {
					G[i][j] = '.';
					sx = i;
					sy = j;
				}
			}
		}
		vis[sx][sy] = 1;
		dfs(sx, sy);
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				ans += vis[i][j];
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}