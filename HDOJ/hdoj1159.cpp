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
char a[maxn], b[maxn];
int dp[maxn][maxn];
int na, nb;

int main() {
	// freopen("in", "r", stdin);
	while(~scanf("%s %s", a, b)) {
		na = strlen(a);
		nb = strlen(b);
		memset(dp, 0, sizeof(dp));
		for(int i = 0; i < na; i++) {
			for(int j = 0; j < nb; j++) {
				if(a[i] == b[j]) {
					dp[i+1][j+1] = max(dp[i][j]+1, max(dp[i+1][j], dp[i][j+1]));
				}
				else dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
			}
		}
		printf("%d\n", dp[na][nb]);
	}
	return 0;
}