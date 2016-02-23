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

const double eps = 1e-10;

typedef struct Point {
	double x;
	double y;
	Point() {}
	Point(double xx, double yy) : x(xx), y(yy) {}
	Point operator +(const Point& b) const { return Point(x+b.x, y+b.y); }
	Point operator -(const Point& b) const { return Point(x-b.x, y-b.y); }
	Point operator |(const double& b) const { return Point(x*b, y*b); }
	double operator ^(const Point& b) const { return x*b.y-y*b.x; }
	double operator *(const Point& b) const { return x*b.x+y*b.y; }
}Point;

typedef struct Line {
	Point u;
	Point v;
	Line() {}
	Line(Point uu, Point vv) : u(uu), v(vv) {}
}Line;

int sgn(double x) {
	if(fabs(x) < eps) return 0;
	if(x < 0) return -1;
	return 1;
}

double xmulti(Point p0, Point p1, Point p2) {
	return (p1 - p0) ^ (p2 - p0);
}

int onSeg(Line l, Point p) {//==比^优先级高
	return (((l.u-p)^(l.v-p))==0)&&((l.u-p)*(l.v-p)<=0);
}

Point check(Line l1, Line l2) {
	return l1.u+((l1.v-l1.u)|(((l2.v-l2.u)^(l2.u-l1.u))/((l2.v-l2.u)^(l1.v-l1.u))));
}

const int maxn = 22;
int n, m;
Line line[maxn];
int pre[maxn];

int find(int x) {
	return x == pre[x] ? x : pre[x] = find(pre[x]);
}

void unite(int x, int y) {
	x = find(x);
	y = find(y);
	if(x != y) {
		pre[y] = x;
	}
}

inline void init() {
	for(int i = 0; i < maxn; i++) {
		pre[i] = i;
	}
}

inline void cross() {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < i; j++) {
			if(((line[i].u - line[i].v) ^ (line[j].u - line[j].v)) == 0) {
				if(onSeg(line[i], line[j].u)
				|| onSeg(line[i], line[j].v)
				|| onSeg(line[j], line[i].u)
				|| onSeg(line[j], line[i].v)) {
					unite(i, j);
				}
			}
			else {
				Point ppp = check(line[i], line[j]);
				if(onSeg(line[i], ppp) && onSeg(line[j], ppp)) {
					unite(i, j);
				}
			}
		}
	}
}

int main() {
	freopen("in", "r", stdin);
	Point p, q;
	while(~scanf("%d", &n) && n) {
		init();
		for(int i = 0; i < n; i++) {
			scanf("%d %d %d %d", &p.x, &p.y, &q.x, &q.y);
			line[i] = Line(p, q);
		}
		cross();
		int a, b;
		while(scanf("%d %d", &a, &b) && a + b) {
			if(find(a-1) == find(b-1)) {
				puts("CONNECTED");
			}
			else {
				puts("NOT CONNECTED");
			}
		}
	}
	return 0;
}
