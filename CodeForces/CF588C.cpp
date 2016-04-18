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
const int maxn = 1100010;
int n;
ll dp[maxn];

int main() {
    // freopen("in", "r", stdin);
    int w;
    while(~scanf("%d", &n)) {
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= n; i++) {
            scanf("%d", &w);
            dp[w]++;
        }
        ll ans = 0;
        for(int i = 0; i < maxn; i++) {
            dp[i+1] += dp[i] / 2;
            ans += dp[i] % 2;
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
