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
	Point() {}
	Point(int xx, int yy) : x(xx), y(yy) {}
	Point operator +(const Point& b) const { return Point(x+b.x, y+b.y); }
	Point operator -(const Point& b) const { return Point(x-b.x, y-b.y); }
	int operator ^(const Point& b) const { return x * b.y - y * b.x; }
	int operator *(const Point& b) const { return x * b.x + y * b.y; }
}Point;

typedef struct Line {
	Point u;
	Point v;
	Line() {}
	Line(Point uu, Point vv) : u(uu), v(vv) {}
}Line;

int xmulti(Point p0, Point p1, Point p2) {
	return (p1 - p0) ^ (p2 - p0);
}

const int maxn = 111;
Point pp[maxn];
int n;

int cmp(Point a, Point b) {
	Point t(0, 0);
	return xmulti(t, b, a) < 0;
}

int main() {
	// freopen("in", "r", stdin);
	for(n = 0; ~scanf("%d %d", &pp[n].x, &pp[n].y); n++);
	sort(pp+1, pp+n, cmp);
	for(int i = 0; i < n; i++) {
		printf("(%d,%d)\n", pp[i].x, pp[i].y);
	}
	return 0;
}