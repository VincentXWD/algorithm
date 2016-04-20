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

const int mod = 100007;
const int maxn = 1010;
char a[maxn];
char b[maxn];
int dp[maxn][maxn];
int fa[mod];
int na, nb;

int main() {
    // freopen("in", "r", stdin);
    while(~scanf("%s %s", a, b)) {
        memset(dp, 0, sizeof(dp));
        memset(fa, -1, sizeof(fa));
        na = strlen(a);
        nb = strlen(b);
        for(int i = 0; i < na; i++) {
            for(int j = 0; j < nb; j++) {
                if(a[i] == b[j]) {
                    if(dp[i][j] + 1 > max(dp[i][j+1], dp[i+1][j])) {
                        dp[i+1][j+1] = dp[i][j] + 1;
                        // int cur = (((i + 1) * 59) % mod + ((j + 1) * 61) % mod) % mod;
                        // int pre = ((i * 59) % mod + (j * 61) % mod) % mod;
                        // fa[cur][0] = pre;
                        // fa[cur][1] = i;
                        // ii = cur;
                    }
                    else dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
                }
                else {
                    dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
                }
            }
        }
        int ii = na;
        int jj = nb;
        char st[maxn];
        int top = 0;
        while(dp[ii][jj]) {
            if(dp[ii][jj] == dp[ii-1][jj]) ii--;
            else if(dp[ii][jj] == dp[ii][jj-1]) jj--;
            else {
                ii--, jj--;
                st[top++] = a[ii];
            }

        }
        while(top) printf("%c", st[--top]);
        printf("\n");
    }
    return 0;
}