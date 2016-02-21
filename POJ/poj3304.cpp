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

const double eps = 1e-9;

typedef struct Point {
	double x;
	double y;
	Point() {}
	Point(double xx, double yy) : x(xx), y(yy) {}
	Point operator +(const Point& b) const { return Point(x+b.x, y+b.y); }
	Point operator -(const Point& b) const { return Point(x-b.x, y-b.y); }
	double operator ^(const Point& b) const { return x * b.y - y * b.x; }
	double operator *(const Point& b) const { return x * b.x + y * b.y; }
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

double dist(Point a, Point b) {
	return sqrt((b-a)*(b-a));
}

double intersect(Line l1, Line l2) {
	return sgn(xmulti(l2.u, l1.u, l1.v))*sgn(xmulti(l2.v, l1.u, l1.v))<=0;
}

const int maxn = 111;
int n;
Line line[maxn];
double ex1, ey1, ex2, ey2;

int check(Line l1) {
	if(sgn(dist(l1.u, l1.v)) == 0) return 0;
	for(int i = 0; i < n; i++) {
		if(intersect(l1, line[i]) == 0) return 0;
	}
	return 1;
}

int main() {
	// freopen("in", "r", stdin);
	int T;
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		for(int i = 0; i < n; i++) {
			scanf("%lf %lf %lf %lf", &ex1, &ey1, &ex2, &ey2);
			line[i] = Line(Point(ex1, ey1), Point(ex2, ey2));
		}
		int flag = 0;
		for(int i = 0; i < n; i++) {
			for(int j = i; j < n; j++) {
				if(check(Line(line[i].u, line[j].u)) ||
				   check(Line(line[i].u, line[j].v)) ||
				   check(Line(line[i].v, line[j].u)) ||
				   check(Line(line[i].v, line[j].v))) {
					flag = 1;
					break;
				}
			}
		}
		flag ? puts("Yes!") : puts("No!");
	}
	return 0;
}
