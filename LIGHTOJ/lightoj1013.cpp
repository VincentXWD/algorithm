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

typedef long long ll;
const int maxn = 55;
char a[maxn];
char b[maxn];
ll dp1[maxn][maxn];
ll dp2[maxn][maxn];
int  na, nb;

int main() {
	// freopen("in", "r", stdin);
	int T;
	scanf("%d", &T);
	for(int _ = 1; _ <= T; _++) {
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		scanf("%s %s", a, b);
		na = strlen(a), nb = strlen(b);
		memset(dp1, 0x3f3f3f3f, sizeof(dp1));
		memset(dp2, 0, sizeof(dp2));
		dp1[0][0] = 0;
		dp2[0][0] = 1;
		for(int i = 1; i <= na; i++) {
			dp1[i][0] = ll(i);
			dp2[i][0] = ll(1);
		}
        for(int i = 1; i <= nb; i++) {
        	dp1[0][i] = ll(i);
        	dp2[0][i] = ll(1);
        }
		for(int i = 1; i <= na; i++) {
			for(int j = 1; j <= nb; j++) {
				dp1[i][j] = min(dp1[i][j], min(dp1[i][j-1]+1, dp1[i-1][j]+1));
				if(a[i-1] == b[j-1]) {
					dp1[i][j] = min(dp1[i][j], dp1[i-1][j-1]+1);
				}
			}
		}
		for(int i = 1; i <= na; i++) {
			for(int j = 1; j <= nb; j++) {
				if(dp1[i][j] == dp1[i-1][j] + 1 && a[i-1] != b[j-1]) {
					dp2[i][j] += dp2[i-1][j];
				}
				if(dp1[i][j] == dp1[i][j-1] + 1 && a[i-1] != b[j-1]) {
					dp2[i][j] += dp2[i][j-1];
				}
				if(dp1[i][j] == dp1[i-1][j-1] + 1 && a[i-1] == b[j-1]) {
					dp2[i][j] += dp2[i-1][j-1];
				}
			}
		}
		printf("Case #%d: %lld %lld\n", _, dp1[na][nb], dp2[na][nb]);
	}
	return 0;
}