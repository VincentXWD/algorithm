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

typedef struct Node {
    int w, q, v;
}Node;
const int maxn = 5555;
int n, m;
int dp[maxn];
Node t[maxn];

bool cmp(Node a, Node b) {
    return a.q - a.w < b.q - b.w;
}

int main() {
    // freopen("in", "r", stdin);
    while(~scanf("%d %d", &n, &m)) {
        for(int i = 0; i < n; i++) {
            scanf("%d%d%d", &t[i].w, &t[i].q, &t[i].v);
        }
        memset(dp, 0, sizeof(dp));
        sort(t, t+n, cmp);
        for(int i = 0; i < n; i++) {
            for(int j = m; j >= t[i].q; j--) {
                dp[j] = max(dp[j], dp[j-t[i].w]+t[i].v);
            }
        }
        printf("%d\n", dp[m]);
    }
    return 0;
}