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
char str[maxn];
int dp[maxn][maxn];
int n;

int main() {
	// freopen("in", "r", stdin);
	while(~scanf("%s", str)) {
		if(str[0]=='e') break;
		memset(dp, 0, sizeof(dp));
		n = strlen(str);
		for(int i = 1; i < n; i++) {
			int k = i;
			for(int j = 0; k < n; j++, k++) {
				if((str[j]=='('&&str[k]==')')||(str[j]=='['&&str[k]==']')) {
					dp[j][k] = dp[j+1][k-1] + 2;
				}
				for(int m = j; m < k; m++) {
					dp[j][k] = max(dp[j][k], dp[j][m] + dp[m+1][k]);
				}
			}
		}
		printf("%d\n", dp[0][n-1]);
	}
	return 0;
}
