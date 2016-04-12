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

const int maxn = 11;
int n, m;
int a[maxn];
int dp[maxn][maxn];

int main() {
	freopen("in", "r", stdin);
	while(~scanf("%d %d", &n, &m)) {
		for(int i = 0; i < n; i++) {
			a[i] = i + 1;
		}
		do {
			int ts = 0;
			memset(dp, 0, sizeof(dp));
			for(int i = 0; i < n; i++) {
				dp[0][i] = a[i];
			}
			for(int i = 1; i < n; i++) {
				for(int j = 0; j < n; j++) {
					dp[i][j] = dp[i-1][j] + dp[i-1][j+1];
				}
			}
			if(dp[n-1][0] == m) {
				for(int i = 0; i < n; i++) {
					printf("%d ", a[i]);
				}
				printf("\n");
				break;
			}
		}while(next_permutation(a, a + n));
	}
	return 0;
}