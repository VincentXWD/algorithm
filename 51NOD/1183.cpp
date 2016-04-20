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

const int maxn = 1010;
char a[maxn];
char b[maxn];
int dp[maxn][maxn];
int na, nb;

int main() {
    // freopen("in", "r", stdin);
    while(~scanf("%s %s", a, b)) {
        na = strlen(a);
        nb = strlen(b);
        memset(dp, 0x7f7f7f7f, sizeof(dp));
        for(int i = 0; i <= na; i++) dp[i][0] = i;
        for(int i = 0; i <= nb; i++) dp[0][i] = i;
        for(int i = 1; i <= na; i++) {
            for(int j = 1; j <= nb; j++) {
                if(a[i-1] == b[j-1]) dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
                else dp[i][j] = min(dp[i][j], dp[i-1][j-1]+1);
                dp[i][j] = min(dp[i][j], dp[i][j-1]+1);
                dp[i][j] = min(dp[i][j], dp[i-1][j]+1);
            }
        }
        printf("%d\n", dp[na][nb]);
    }
    return 0;
}