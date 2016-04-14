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
int n, m;
int dp[maxn][maxn];
int G[maxn][maxn];

int main() {
	// freopen("in", "r", stdin);
	int T;
	scanf("%d", &T);
	for(int _ = 1; _ <= T; _++) {
		scanf("%d", &n);
		int cnt = 0;
		bool flag = 0;
		for(int i = 1; i <= 2 * n - 1; i++) {
			if(!flag) cnt++;
			for(int j = 1; j <= cnt; j++) {
				scanf("%d", &G[i][j]);
			}
			if(cnt > n - 1) flag = 1;
			if(flag) cnt--;
		}
		cnt = 0;
		flag = 0;
		memset(dp, 0, sizeof(dp));
		for(int i = 1; i <= 2 * n - 1; i++) {
			if(!flag) cnt++;
			for(int j = 1; j <= cnt; j++) {
				if(i == 1 && j == 1) {
					dp[1][1] = G[1][1];
					continue;
				}
				if(!flag) dp[i][j] = G[i][j] + max(dp[i-1][j-1], dp[i-1][j]);
				else dp[i][j] = G[i][j] + max(dp[i-1][j+1], dp[i-1][j]);
			}
			if(cnt > n - 1) flag = 1;
			if(flag) cnt--;
		}
		printf("Case %d: %d\n", _, dp[2*n-1][1]);
	}
	return 0;
}
