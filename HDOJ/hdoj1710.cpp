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

const int maxn = 1111;
int n;
int a[maxn], b[maxn];

void dfs(int ll, int rr, int nn, bool flag) {
    if(nn == 1) {
        printf("%d ", a[ll]);
        return;
    }
    if(nn <= 0) return;
    int i;
    for(i = 0; a[ll] != b[rr+i]; i++);
    dfs(ll+1, rr, i, 0);
    dfs(ll+i+1, rr+i+1, nn-i-1, 0);
    if(!flag) printf("%d ", a[ll]);
    else printf("%d", a[ll]);
}
int main() {
    // freopen("in", "r", stdin);
    while(~scanf("%d", &n)) {
        for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
        for(int i = 1; i <= n; i++) scanf("%d", &b[i]);
        dfs(1, 1, n, 1);
        printf("\n");
    }
}