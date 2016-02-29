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

int dist(Point p, Point q) {
	return (p - q) * (p - q);
}

bool toleft(Point p, Point q, Point s) { //1left 0right
	return ((p.x * q.y + s.x * p.y + q.x * s.y) - 
		   (p.y * q.x + p.x * s.y + s.x * q.y)) > 0;
}

const int maxn = 55555;
Point pp[maxn];
Point s[maxn];
int n, st;

int cmp(Point a, Point b) {
	return xmulti(pp[0], b, a) < 0;
}

void graham() {
	Point t[maxn];
	int tt = 0;
	int ltl = 0;
	for(int i = 0; i < n; i++) {
		if(pp[i].y < pp[ltl].y || (pp[i].y == pp[ltl].y && pp[i].x < pp[ltl].x)) {
			ltl = i;
		}
	}
	swap(pp[0], pp[ltl]);
	sort(pp+1, pp+n, cmp);
	s[0] = pp[0], s[1] = pp[1];
	st = 2;
	for(int i = n - 1; i >= 2; i--) {
		t[tt++] = pp[i];
	}
	while(tt > 0) {
		if(st == 0) {
			for(int i = 0; i < n; i++) {
				s[st++] = pp[i];
			}
			break;
		}
		if(toleft(s[st-2], s[st-1], t[tt-1])) {
			--tt;
			s[st] = t[tt];
			st++;
		}
		else {
			--st;
		}
	}
}


int solve() {
	graham();
	int ans = 0;
	if(st == 0) {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < i; j++) {
				ans = max(ans, dist(pp[i], pp[j]));
			}
		}		
	}
	else {	
		for(int i = 0; i < st; i++) {
			for(int j = 0; j < i; j++) {
				ans = max(ans, dist(s[i], s[j]));
			}
		}
	}
	return ans;
}

int main() {
	freopen("in", "r", stdin);
	// freopen("out", "w", stdout);
	while(~scanf("%d", &n)) {
		for(int i = 0; i < n; i++) {
			scanf("%d %d", &pp[i].x, &pp[i].y);	
		}
		printf("%d\n", solve());
	}
	return 0;
}