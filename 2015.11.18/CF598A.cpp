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

typedef long long LL;
LL n;

LL quickmul(LL x, LL n) {
    LL ans = 1, t = x;
    while(n) {
        if(n & 1) {
            ans *= t;
        }
        t <<= 1;
        n >>= 1;
    }
    return ans;
}

LL pw[111];

int main() {
    // freopen("in", "r", stdin);
    int T;
    scanf("%d", &T);
    pw[0] = 1;
    for(int i = 1; i < 30; i++) {
        pw[i] = pw[i-1] << 1;
    }
    while(T--) {
        scanf("%I64d", &n);
        LL ans = (1 + n) * n / 2;
        for(int i = 0; pw[i] <= n && i < 30; i++) {
            ans -= 2 * pw[i];
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
