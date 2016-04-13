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

const int maxn = 22;
int n, k;
int dp[maxn][maxn];
int G[maxn][maxn];
int p[maxn];

int main() {
	// freopen("in", "r", stdin);
	int T;
	scanf("%d", &T);
	for(int _ = 1; _ <= T; _++) {
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				scanf("%d", &G[i][j]);
			}
		}
		memset(dp, 0, sizeof(dp));
		int ans = -1;
		int tmp;
		for(int i = 1; i <= n; i++) {
			p[i] = i;
		}
		do {
			tmp = 0;
			for(int i = 1; i <= n; i++) {
				tmp += G[i][p[i]];
			}
			ans = max(ans, tmp);
		}while(next_permutation(p+1, p+n+1));
		printf("Case %d: %d\n", _, ans);
	}
	return 0;
}