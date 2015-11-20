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

typedef struct Point {
    int x;
    int y;
    double r;
}Point;

bool cmp(Point x, Point y) {
    return x.r < y.r;
}

const int maxn = 222222;
priority_queue<int> pq;
int n, s, p;
int x[maxn],y[maxn];
double d[maxn];
int pre[maxn];
Point poi[maxn];

void init() {
    while(!pq.empty()) pq.pop();
    for(int i = 0; i <= maxn; i++) {
        pre[i] = i;
    }
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

int main() {
    // freopen("in", "r", stdin);
    scanf("%d", &n);
    while(n--) {
        init();
        scanf("%d %d", &s, &p);
        for(int i = 0; i < p; i++) {
            scanf("%d %d", &x[i], &y[i]);
        }
        int cnt = 0;
        for(int i = 0; i < p; i++) {
            for(int j = i+1; j < p; j++) {
                poi[cnt].x = i;
                poi[cnt].y = j;
                poi[cnt++].r = sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
            }
        }
        sort(poi, poi+cnt, cmp);
        int cur = 0;
        for(int i = 0; i < cnt; i++) {
            if(unite(poi[i].x, poi[i].y)) {
                d[cur++] = poi[i].r;
            }
        }
        printf("%.2f\n", d[cur-s]);
    }
}
