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
int dp[maxn][maxn];
int G[maxn][maxn];
int w, n;
char str[111111];

int main() {
    // freopen("in", "r", stdin);
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d %d", &w, &n);
        memset(G, 0, sizeof(G));
        memset(dp, 0, sizeof(dp));
        getchar();
        int u, v;
        for(int i = 1; i <= w; i++) {
            scanf("%d", &u);
            gets(str);
            int len = strlen(str);
            v = 0;
            for(int j = 0; j <= len; j++) {
                if(str[j] >= '0' && str[j] <= '9') {
                    v = v * 10 + str[j] - '0';
                }
                else {
                    G[u][v] = 1;
                    v = 0;
                }
            }
        }
        dp[1][0] = 1;
        for(int i = 1; i <= w; i++) {
            for(int j = 1; j <= n; j++) {
                if(!G[i][j]) {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
                else {
                    dp[i][j] = 0;
                }
            }
        }
        printf("%d\n", dp[w][n]);
        if(T) printf("\n");
    }
    return 0;
}