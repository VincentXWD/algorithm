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

int cmp(Point x, Point y) {
    return x.r < y.r;
}

const int maxn = 10000;
int pre[maxn];
int x[maxn];
int y[maxn];
int c, cnt;
Point poi[maxn];

int find(int x) {
    int r = x;
    int t;
    while(x != pre[x])
        x = pre[x];
    while(r != x) {
        t = pre[r];
        pre[r] = x;
        r = t;
    }
    return x;
}

void unite(int x, int y) {
    int xx = find(x);
    int yy = find(y);
    if(xx != yy) {
        pre[xx] = yy;
    }
}

void init() {
    for(int i = 0; i <= c; i++) {
        pre[i] = i;
    }
}

int main() {
    // freopen("in", "r", stdin);
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &c);
        cnt = 0;
        for(int i = 0; i < c; i++) {
            scanf("%d %d", &x[i], &y[i]);
        }
        for(int i = 0; i < c-1; i++) {
            for(int j = i+1; j < c; j++) {
                double rr = sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
                poi[cnt].x = i;
                poi[cnt].y = j;
                poi[cnt++].r = rr;
            }
        }
        init();
        sort(poi, poi+cnt, cmp);
        double ans = 0;
        for(int i = 0; i < cnt; i++) {
            if(find(poi[i].x != find(poi[i].y)) && poi[i].r >= 10.0000 && poi[i].r <= 1000.00001) {
                unite(poi[i].x, poi[i].y);
                ans += poi[i].r;
            }
        }
        // for(int i = 0; i < c; i++) printf("%d ", pre[i]);
        // printf("\n");
        int flag = 1;
        int s = 0;
        for(int i = 0; i < c; i++) {
            if(pre[i] == i) {
                s++;
            }
            if(s > 1) {
                flag = 0;
                break;
            }
        }
        if(flag) printf("%.1lf\n", ans * 100);
        else printf("oh!\n");
    }
    return 0;
}