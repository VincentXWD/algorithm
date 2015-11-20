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

typedef struct P {
 int x;
 int y;
};

P p[500000];
bool cmp(P a, P b) {
    return a.y < b.y;
}

int main() {
    // freopen("in", "r", stdin);
    int n, m;
    while(~scanf("%d", &n)) {
        for(int i = 0; i < n; i++) {
            scanf("%d %d", &p[i].x, &p[i].y);
        }
        sort(p, p + n, cmp);
        long last = p[0].y;
        int ans = 1;
        for(int i = 1; i < n; i++) {
            if(last < p[i].x) {
                last = p[i].y;
                ans++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}