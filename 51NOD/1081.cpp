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
const ll maxn = 50010;
int n, q;
ll s[maxn];

ll lowbit(ll x) {
    return x & (-x);
}

void add(ll i, ll x) {
    while(i <= n) {
        s[i] += x;
        i += lowbit(i);
    }
}

ll sum(ll i) {
    ll ss = 0;
    while(i > 0) {
        ss += s[i];
        i -= lowbit(i);
    }
    return ss;
}

// int main() {
//     // freopen("in", "r", stdin);
//     ll a, b;
//     while(~scanf("%d", &n)) {
//         memset(s, 0, sizeof(s));
//         scanf("%I64d", &s[0]);
//         for(ll i = 1; i < n; i++) {
//             scanf("%I64d", &a);
//             s[i] = s[i-1] + a;
//         }
//         scanf("%d", &q);
//         while(q--) {
//             scanf("%I64d %I64d", &a, &b);
//             a--;
//             b--;
//             if(a == 0) printf("%I64d\n", s[b]);
//             else printf("%I64d\n", s[a+b] - s[a-1]);
//         }
//     }
//     return 0;
// }
int main() {
    // freopen("in", "r", stdin);
    ll a, b;
    while(~scanf("%d", &n)) {
        memset(s, 0, sizeof(s));
        for(ll i = 1; i <= n; i++) {
            scanf("%I64d", &a);
            add(i, a);
        }
        scanf("%d", &q);
        while(q--) {
            scanf("%I64d %I64d", &a, &b);
            printf("%I64d\n", sum(a+b-1)-sum(a-1));
        }
    }
    return 0;
}