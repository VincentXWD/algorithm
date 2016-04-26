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

const int maxn = 510;
const int maxm = 2020;
int n;
int pre[maxn];
int len[maxn];
char s[maxn][maxm];

int find(int x) {
    return x == pre[x] ? x : pre[x] = find(pre[x]);
}
bool check(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y) return 1;
    return 0;
}

int main() {
    // freopen("in", "r", stdin);
    int T, _ = 1;
    scanf("%d", &T);
    while(T--) {
        memset(s, 0, sizeof(s));
        memset(len, 0, sizeof(len));
        for(int i = 1; i <= n; i++) {
            pre[i] = i;
        }
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) {
            scanf("%s", s[i]);
        }
        int ans = -1;
        for(int i = 1; i <= n; i++) {
            for(int j = i - 1; j >= 1; j--) {
                if(len[i] < len[j]) continue;
                if(check(i, j)) continue;
                if(strstr(s[i], s[j]) != NULL) {
                    pre[i] = j;
                }
                else {
                    ans = i;
                    break;
                }
            }
        }
        printf("Case #%d: %d\n", _++, ans);
    }
    return 0;
}