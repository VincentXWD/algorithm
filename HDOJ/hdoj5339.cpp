#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <queue>
#include <map>
#include <stack>
#include <list>
#include <vector>

using namespace std;

const int maxn = 100010;
const int INF = 1<<30;
int n, a;
int b[maxn];

inline int min(int a, int b) {
    return a < b ? a : b;
}
int main() {
    // freopen("in", "r", stdin);
    int T;
    scanf("%d", &T);
    while(T--) {
        int ans = INF;
        scanf("%d %d", &n, &a);
        for(int i = 0; i < n; i++) {
            scanf("%d", &b[i]);
        }
        sort(b, b+n, greater<int>());
        int s = (1 << n);
        int cnt;
        for(int i = 1; i < s; i++) {
            int tmp = a;
            cnt = 0;
            for(int j = 0; j < n; j++) {
                if(i & (1 << j)) {
                    tmp %= b[j];
                    cnt++;
                }
            }
            if(tmp == 0) {
                ans = min(ans, cnt);
            }
        }
        if(ans == INF) {
            printf("-1\n");
        }
        else {
            printf("%d\n", ans);
        }
    }
}