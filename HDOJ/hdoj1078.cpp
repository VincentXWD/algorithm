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
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};
int n, k;
int G[maxn][maxn];
int dp[maxn][maxn];

bool ok(int x, int y) {
	return x >= 0 && y >= 0 && x < n && y < n;
}

int dfs(int x, int y) {
	if(dp[x][y]) return dp[x][y];
	int cur = 0;
	for(int i = 0; i < 4; i++) {
		for(int j = 1; j <= k; j++) {
			int xx = x + dx[i] * j;
			int yy = y + dy[i] * j;
			if(ok(xx, yy) && G[xx][yy] > G[x][y]) {
				cur = max(cur, dfs(xx, yy));
			}
		}
	}
	return dp[x][y] = cur + G[x][y];
}

inline bool scan_d(int &num) {
    char in;bool IsN=false;
    in=getchar();
    if(in==EOF) return false;
    while(in!='-'&&(in<'0'||in>'9')) in=getchar();
    if(in=='-'){ IsN=true;num=0;}
    else num=in-'0';
    while(in=getchar(),in>='0'&&in<='9'){
            num*=10,num+=in-'0';
    }
    if(IsN) num=-num;
    return true;
}

int main() {
	// freopen("in", "r", stdin);
	while(~scanf("%d%d", &n, &k) && n + k != -2) {
		memset(dp, 0, sizeof(dp));
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				scan_d(G[i][j]);
			}
		}
		printf("%d\n", dfs(0, 0));
	}
	return 0;
}