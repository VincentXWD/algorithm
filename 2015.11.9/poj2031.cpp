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

typedef struct Edge {
    int u;
    int v;
    double w;
}E;

typedef struct Ball {
    double x;
    double y;
    double z;
    double r;
}B;

bool cmp(E e1, E e2) {
    return e1.w < e2.w;
}

const int maxn = 111;
int n, m;
int pre[maxn];
B b[maxn];
E e[maxn*maxn];

inline void init() {
    for(int i = 0; i < maxn; i++) {
        pre[i] = i;
    }
    m = 0;
}

int find(int x) {
    return x == pre[x] ? x : pre[x] = find(pre[x]);
}

bool unite(int x, int y) {
    x = find(x);
    y = find(y);
    if(x != y) {
        pre[x] = y;
        return 1;
    }
    return 0;
}

double dis(B b1, B b2) {
    double res = double(sqrt((b1.x-b2.x)*(b1.x-b2.x)+(b1.y-b2.y)*(b1.y-b2.y)+(b1.z-b2.z)*(b1.z-b2.z))-b1.r-b2.r);
    return res > 0 ? res : double(0);
}


int main() {
    // freopen("in", "r", stdin);
    while(~scanf("%d", &n) && n) {
        init();
        for(int i = 0; i < n; i++) {
            scanf("%lf %lf %lf %lf", &b[i].x, &b[i].y, &b[i].z, &b[i].r);
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                e[m].u = i;
                e[m].v = j;
                e[m++].w = dis(b[i], b[j]);
            }
        }
        sort(e, e+m, cmp);
        double mst = 0;
        for(int i = 0; i < m; i++) {
            if(unite(e[i].u, e[i].v)) {
                mst += e[i].w;
            }
        }
        printf("%.3lf\n", mst);
    }
    return 0;
}
