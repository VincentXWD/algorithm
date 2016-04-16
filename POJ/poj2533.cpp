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

const int maxn = 40010;
int n;
int dp[maxn];
int s[maxn];
int a[maxn];

int bs(int ll, int rr, int v) {
    while(ll <= rr) {
        int mm = (ll + rr) >> 1;
        if(s[mm] < v) ll = mm + 1;
        else rr = mm - 1;
    }
    return ll;
}

int main() {
    // freopen("in", "r", stdin);
    while(~scanf("%d", &n)) {
        for(int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i < maxn; i++) s[i] = 0x7f7f7f;
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            dp[i] = bs(1, i, a[i]);
            s[dp[i]] = min(s[dp[i]], a[i]);
            ans = max(ans, dp[i]);
        }
        printf("%d\n", ans);
    }
    return 0;
}