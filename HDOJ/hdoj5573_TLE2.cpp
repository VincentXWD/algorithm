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
        for(int i = 1; i <= k; i++)
            ans[i] = f[i-1];
        if(n % 2 == 0) ans[k]++;
        ll nn = 1 << k;
        bool exflag = 0;
        for(ll i = 1; i < nn; i++) {
            if(exflag) break;
            ll cur = 0;
            memset(sub, 0, sizeof(sub));
            for(ll j = 1; j <= k; j++) {
                if((1 << j) & i) {
                    sub[j] = 1;
                    cur -= ans[j];
                }
                else cur += ans[j];
            }
            if(cur == n) exflag = 1;
        }
        printf("Case #%d:\n", _++);
        for(ll i = 1; i <= k; i++) {
            printf("%I64d ", ans[i]);
            if(sub[i]) printf("-\n");
            else printf("+\n");
        }
    }
    return 0;
}
