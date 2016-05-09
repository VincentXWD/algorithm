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

const int maxn = 100010;
const double eps = 1e-10;

int sgn(double x) {
	if(fabs(x) < eps)return 0;
	if(x < 0)return -1;
	else return 1;
}
struct Point {
	double x,y;
	Point(){}
	Point(double _x,double _y) {
		x = _x;y = _y;
	}
	Point operator -(const Point &b)const {
		return Point(x - b.x,y - b.y);
	}
	double operator ^(const Point &b)const {
		return x*b.y - y*b.x;
	}
	double operator *(const Point &b)const {
		return x*b.x + y*b.y;
	}
};
struct Line {
	Point s,e;
	Line(){}
	Line(Point _s,Point _e) {
		s = _s;e = _e;
	}
};
//判断线段相交
bool inter(Line l1,Line l2) {
	return 
		max(l1.s.x,l1.e.x) >= min(l2.s.x,l2.e.x) &&
		max(l2.s.x,l2.e.x) >= min(l1.s.x,l1.e.x) &&
		max(l1.s.y,l1.e.y) >= min(l2.s.y,l2.e.y) &&
		max(l2.s.y,l2.e.y) >= min(l1.s.y,l1.e.y) &&
		sgn((l2.s-l1.s)^(l1.e-l1.s))*sgn((l2.e-l1.s)^(l1.e-l1.s)) <= 0 &&
		sgn((l1.s-l2.s)^(l2.e-l2.s))*sgn((l1.e-l2.s)^(l2.e-l2.s)) <= 0;
}
int n;

int main() {
	// freopen("in", "r", stdin);
	double a, b, c, d;
	int T;
	Line p, q;
	scanf("%d", &T);
	while(T--) {
		cin >> a >> b >> c >> d;
		p = Line(Point(a, b), Point(c, d));
		cin >> a >> b >> c >> d;
		q = Line(Point(a, b), Point(c, d));
		if(inter(p, q)) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
