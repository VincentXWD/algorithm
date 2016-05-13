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
#define pb(a) push_back(a)
#define Rint(a) scanf("%d", &a)
#define Rll(a) scanf("%I64d", &a)
#define Rs(a) scanf("%s", a)
#define FRead() freopen("in", "r", stdin)
#define FWrite() freopen("out", "w", stdout)
#define Rep(i, n) for(int i = 0; i < (n); i++)
#define For(i, a, n) for(int i = (a); i < (n); i++)
#define Cls(a) memset((a), 0, sizeof(a))
#define Ful(a) memset((a), 0x7f7f, sizeof(a))

const int maxn = 10010;
int dp[maxn][maxn];
int n, m;

int main() {
	// FRead();
	int u, v, w;
	while(~Rint(n) && ~Rint(m)) {
		For(i, 1, n+1) {
			For(j, 1, n+1) {
				if(i == j) dp[i][j] = 0;
				else dp[i][j] = 0x7f7f7f;
			}
		}
		Rep(i, m) {
			Rint(u); Rint(v); Rint(w);
			if(dp[u][v] > w) {
				dp[u][v] = dp[v][u] = w;
			}
		}
		For(k, 1, n+1) {		
			For(i, 1, n+1) {
				For(j, 1, n+1) {
					if(dp[i][j] > dp[i][k] + dp[k][j]) {
						dp[i][j] = dp[i][k] + dp[k][j];
					}
				}
			}
		}
		For(i, 1, n+1) {
			For(j, 1, n+1) {
				printf("%d ", dp[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}