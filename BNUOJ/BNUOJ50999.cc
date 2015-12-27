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

typedef struct QAQ {
    int a;
    int b;
}Q;

bool cmp(Q x, Q y) {
    if(x.a == y.a) {
        return x.b < y.b;
    }
    return x.a < y.a;
}

const int maxn = 1111;
int n, t;
Q q[maxn];

int main() {
   // freopen("in", "r", stdin);
    int Qrz;
    scanf("%d", &Qrz);
    while(Qrz--) {
        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            scanf("%d %d", &q[i].a, &q[i].b);
        }
        sort(q, q+n, cmp);
        t = 0;
        int cur = 0;
        int cnt = 0;
        if(q[0].a > 0) {
            t += q[0].a + q[0].b;
            cnt++;
            cur = q[0].a;
        }
        for(cnt; cnt < n; cnt++) {
            if(t >= q[cnt].a) {
                t += q[cnt].b;
                cur += q[cnt].a;
            }
            else {
                t += (q[cnt].a - t) + q[cnt].b;
            }
        }
        printf("%d\n", t);
    }
    return 0;
}
