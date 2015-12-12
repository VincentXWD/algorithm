/*
简单分析后知道x是没有用的
贪心地选取y的平均数即可
*/
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
const int maxn = 1000010;
ll n, x, y[maxn];

int main() {
    // freopen("in", "r", stdin);
    int T;
    scanf("%d", &T);
    while(T--) {
        ll ave = 0;
        ll ans = 0;
        scanf("%I64d", &n);
        for(int i = 0; i < n; i++) {
            scanf("%I64d %I64d", &x, &y[i]);
        }
        if(n == 0) {
            printf("0\n");
            continue;
        }
        sort(y, y + n);
        ave = n & 1 ? y[n/2] : (y[n/2-1] + y[n/2]) / 2;
        for(int i = 0; i < n; i++) {
            ans += abs(y[i] - ave);
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
