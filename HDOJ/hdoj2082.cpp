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

const int maxn = 66;
int x[30];
int dp[maxn][maxn];
int main() {
	// freopen("in", "r", stdin);
	int T;
	scanf("%d", &T);
	while(T--) {
		//前i个字符价值为j的总数
		//求解∑(1,50)dp[26][i]
		memset(dp, 0, sizeof(dp));
		for(int i = 1; i <= 26; i++) {
			scanf("%d", &x[i]);
		}
		for(int i = 0; i <= 26; i++) {
			dp[i][0] = 1;
		}
		for(int i = 1; i <= 26; i++) {
			for(int j = 1; j <= 50; j++) {
				for(int k = 0; k <= x[i]; k++) {
					if(i * k <= j) {
						dp[i][j] += dp[i-1][j-i*k];
					}
				}
			}
		}
		int ans = 0;
		for(int i = 1; i <= 50; i++) {
			ans += dp[26][i];
		}
		printf("%d\n", ans);
	}
	return 0;
}
