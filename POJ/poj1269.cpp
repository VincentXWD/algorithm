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

const double eps = 1e-8;

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

double ex1, ey1, ex2, ey2;
double ex3, ey3, ex4, ey4;

pair<Point, int> check(Line l1, Line l2) {
	Point ans = l1.u;
	if(sgn((l1.u-l1.v)^(l2.u-l2.v)) == 0) {
		if(sgn((l2.u-l1.u)^(l2.v-l1.u)) == 0) {
			return pair<Point, int>(ans, 0);//chonghe
		}
		else {			
			return pair<Point, int>(ans, 1);//pingxing
		}
	}
	double t = ((l1.u - l2.u) ^ (l2.u - l2.v)) / ((l1.u - l1.v) ^ (l2.u - l2.v));
	ans.x += (l1.v.x - l1.u.x) * t;
	ans.y += (l1.v.y - l1.u.y) * t;
	return pair<Point, int>(ans, 2);//jiaodian ans
}

int main() {
	// freopen("in", "r", stdin);
	int T;
	scanf("%d", &T);
	printf("INTERSECTING LINES OUTPUT\n");
	while(T--) {
		scanf("%lf %lf %lf %lf", &ex1, &ey1, &ex2, &ey2);
		scanf("%lf %lf %lf %lf", &ex3, &ey3, &ex4, &ey4);
		Line l1 = Line(Point(ex1, ey1), Point(ex2, ey2));
		Line l2 = Line(Point(ex3, ey3), Point(ex4, ey4));
		pair<Point, int> ans = check(l1, l2);
		if(ans.second == 0) {
			printf("LINE\n");
		}
		else if(ans.second == 1) {
			printf("NONE\n");
		}
		else {
			printf("POINT %.2f %.2f\n", ans.first.x, ans.first.y);
		}
	}
	printf("END OF OUTPUT\n");
	return 0;
}
