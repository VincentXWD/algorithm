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
const int mod = 1000000007;
int n, m;
int dp[maxn][maxn];

int main() {
    // freopen("in", "r", stdin);
    while(~scanf("%d %d", &n, &m)) {
        memset(dp, 0, sizeof(dp));
        dp[1][1] = 1;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                dp[i][j] += (dp[i-1][j] + dp[i][j-1]) % mod;
            }
        }
        printf("%d\n", dp[n][m]);
    }
    return 0;
}