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

ll gg(ll n, ll k) {
    ll ret;
    if(n == 1) return 0;
    if(n < k) {
        ret = 0;
        for(ll i = 2; i <= n; i++) {
            ret = (ret + k) % i;
        }
        return ret;
    }
    ret = gg(n-n/k, k);
    if(ret < n % k) {
        ret = ret - n % k + n;
    }
    else {
        ret = ret - n % k + (ret - n % k) / (k - 1);
    }
    return ret;
}

ll n, k;

int main() {
    // freopen("in", "r", stdin);
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%I64d%I64d", &n, &k);
        cout << gg(n, k);
        if(T) printf("\n");
    }
    return 0;
}