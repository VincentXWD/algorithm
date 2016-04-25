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
const int maxn = 66;
ll n, k;
ll f[maxn];
ll ans[maxn];
bool sub[maxn];

void init() {
    f[0] = 1;
    for(int i = 1; i < maxn; i++) {
        f[i] = f[i-1] * 2;
    }
}

int main() {
    // freopen("in", "r", stdin);
    int T, _ = 1;
    init();
    scanf("%d", &T);
    while(T--) {
        scanf("%I64d %I64d", &n, &k);
        memset(sub, 0, sizeof(sub));
        for(int i = 1; i <= k; i++)
            ans[i] = f[i-1];
        ll remain = f[k] - n - 1;
        if(n % 2 == 0) {
            ans[k]++;
            remain++;
        }
        remain >>= 1;
        int cnt = 1;
        while(remain) {
            if(remain % 2 == 1) sub[cnt] = 1;
            remain >>= 1;
            cnt++;
        }
        printf("Case #%d:\n", _++);
        for(int i = 1; i <= k; i++) {
            printf("%I64d ", ans[i]);
            sub[i] ? printf("-\n") : printf("+\n");
        }
    }
    return 0;
}
