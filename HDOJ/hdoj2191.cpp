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

int n, m;
int dp[2222222];
int v[2222222];
int w[2222222];
int cnt;

int main() {
    // freopen("in", "r", stdin);
    int T;
    scanf("%d", &T);
    while(T--) {
        cnt = 0;
        int p, h ,c;
        scanf("%d %d", &n, &m);
        for(int i = 0; i < m; i++) {
            scanf("%d %d %d", &p, &h, &c);
            while(c--) {
                w[cnt] = p;
                v[cnt] = h;
                cnt++;
            }
        }
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i < cnt; i++) {
            for(int j = n; j >= w[i]; j--) {
                dp[j] = max(dp[j], dp[j-w[i]]+v[i]);
            }
        }
        printf("%d\n", dp[n]);
    }
    return 0;
}