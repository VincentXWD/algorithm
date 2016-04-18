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

const int maxn = 100010;
int n, s;
int x[maxn];
int sum[maxn];

bool ok(int mm) {
    for(int i = 1; i <= n - mm + 1; i++) {
        // printf("%d %d\n", i-1, i+mm-1);
        if(sum[i+mm-1] - sum[i-1] >= s) return 1;
    }
    return 0;
}

int main() {
    // freopen("in", "r", stdin);
    int T;
    scanf("%d", &T);
    while(T--) {
        memset(sum, 0, sizeof(sum));
        scanf("%d %d", &n, &s);
        for(int i = 1; i <= n; i++) {
            scanf("%d", &x[i]);
            sum[i] = sum[i-1] + x[i];
        }
        if(sum[n] < s) {
            printf("0\n");
            continue;
        }
        int ans;
        int ll = 0;
        int rr = n;
        while(ll <= rr) {
            int mm = (ll + rr) >> 1;
            if(ok(mm)) {
                ans = mm;
                rr = mm - 1;
            }
            else ll = mm + 1;
        }
        printf("%d\n", ans);
    }
}