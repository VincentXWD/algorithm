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

const int maxn = 111;
const int dx[11] = {1, -1, 0, 0, -1, -1, 1, 1};
const int dy[11] = {0, 0, 1, -1, 1, -1, 1, -1};

int n, m;
char G[maxn][maxn];
int ans;

bool ok(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}

void dfs(int x, int y) {
	for(int i = 0; i < 8; i++) {
		int xx = x + dx[i];
		int yy = y + dy[i];
		if(ok(xx, yy) && G[xx][yy] == 'W') {
			G[xx][yy] = '.';
			dfs(xx, yy);
		}
	}
}

int main() {
	// freopen("in", "r", stdin);
	// freopen("out", "w", stdout);
	while(~scanf("%d %d", &n, &m)) {
		memset(G, 0, sizeof(G));
		ans = 0;
		for(int i = 0; i < n; i++) {
			scanf("%s", G[i]);
		}
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				if(G[i][j] == 'W') {
					ans++;
					dfs(i, j);
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
