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

#define fr first
#define sc second
#define Rint(a) scanf("%d", &a)
#define Rll(a) scanf("%lld", &a)
#define Rs(a) scanf("%s", a)
#define FRead() freopen("in", "r", stdin)
#define FWrite() freopen("out", "w", stdout)
#define Rep(i, n) for(int i = 0; i < (n); i++)
#define For(i, a, n) for(int i = (a); i < (n); i++)
#define Cls(a) memset((a), 0, sizeof(a))
#define Full(a) memset((a), 0x7f7f, sizeof(a))

const int maxn = 1010;
int n, a[maxn], sum[maxn];
int dp[maxn][maxn];

int main() {
	// FRead();
	while(~Rint(n)) {
		Rep(i, n) Rint(a[i]);
		sum[0] = a[0];
		For(i, 1, n) sum[i] = sum[i-1] + a[i];
		Cls(dp);
		for(int v = 2; v <= n; v++) {
			Rep(i, n) {
				int j = i + v - 1;
				dp[i][j] = 0x7f7f7f;
				For(k, i, j) {
					dp[i][j] = min(dp[i][j], 
						dp[i][k]+dp[k+1][j]+sum[j]-sum[i-1]);
				}
			}
		}
		printf("%d\n", dp[0][n-1]);
	}
	return 0;
}