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
#define Rll(a) scanf("%I64d", &a)
#define Rs(a) scanf("%s", a)
#define FRead() freopen("in", "r", stdin)
#define FWrite() freopen("out", "w", stdout)
#define Rep(i, n) for(int i = 0; i < (n); i++)
#define For(i, a, n) for(int i = (a); i < (n); i++)
#define Cls(a) memset((a), 0, sizeof(a))
#define Full(a) memset((a), 0x7f7f, sizeof(a))

typedef long long ll;
const int maxn = 1000010;
const int mod = 1000000007;
ll dp[maxn];
int n;

int main() {
    // FRead();
    int T, _ = 1;
    Rint(T);
    Cls(dp);
    dp[1] = 1, dp[2] = 2;
    for(int i = 3; i < maxn; i++) {
        dp[i] = (dp[i-1] + ((i - 1) * dp[i-2]) % mod) % mod;
    }
    while(T--) {
        Rint(n);
        printf("Case #%d:\n", _++);
        printf("%I64d\n", dp[n]);
    }
    return 0;
}