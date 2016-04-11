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

const int maxn = 33;
const int dx[5] = {-1, 1, 0, 0};
const int dy[5] = {0, 0, 1, -1};

int n, m;
int ans;
int sx, sy;
int G[maxn][maxn];

bool ok(int i, int j) {
	return i >= 1 && i <= n && j >= 1 && j <= m;
}

// 0 : left 1 : right 2 : up 3 : down
void dfs(int x, int y, int cur) {
	if(cur <= 10 && ans > cur) {
		for(int i = 0; i < 4; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			if(G[xx][yy] == 1) continue;
			while(G[xx][yy] == 0 && ok(xx, yy)) {
				xx = xx + dx[i];
				yy = yy + dy[i];
			}
			if(G[xx][yy] == 3) ans = cur;
			else if(G[xx][yy] != 0) {
				G[xx][yy] = 0;
				dfs(xx-dx[i], yy-dy[i], cur+1); //
				G[xx][yy] = 1;
			}
		}
	}
}

int main() {
	// freopen("in", "r", stdin);
	while(~scanf("%d %d", &m, &n) && n + m) {
		memset(G, 0, sizeof(G));
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				scanf("%d", &G[i][j]);
				if(G[i][j] == 2) {
					sx = i;
					sy = j;
					G[i][j] = 0;
				}
			}
		}
		ans = 11;
		dfs(sx, sy, 1);
		printf("%d\n", ans > 10 ? -1 : ans);
	}
	return 0;
}