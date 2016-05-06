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

const int maxn = 1010;
typedef struct Point {
	int x, y;
	Point() {}
	Point(int xx, int yy) : x(xx), y(yy) {}
}Point;
int n, ans;
Point p[maxn];
bool cmp(Point a, Point b) {
	if(a.x == b.x) return a.y < b.y;
	return a.x < b.x;
}

bool bs(int x, int y) {
	int ll = 0, rr = n, mm;
	while(ll <= rr) {
		mm = (ll + rr) >> 1;
		if(p[mm].x == x && p[mm].y == y) return 1;
		else if(cmp(p[mm], Point(x, y))) ll = mm + 1;
		else rr = mm - 1;

	}
	return 0;
}

int main() {
	// freopen("in", "r", stdin);
	int x3, y3, x4, y4;
	while(~scanf("%d", &n) && n) {
		ans = 0;
		for(int i = 0; i < n; i++) {
			scanf("%d%d", &p[i].x, &p[i].y);
		}
		sort(p, p+n, cmp);
		for(int i = 0; i < n; i++) {
			for(int j = i + 1; j < n; j++) {
				x3 = p[j].x - (p[j].y - p[i].y);
				y3 = p[j].y + (p[j].x - p[i].x);
				x4 = p[i].x - (p[j].y - p[i].y);
				y4 = p[i].y + (p[j].x - p[i].x);
				if(bs(x3, y3) && bs(x4, y4)) ans++;
			}
		}
		printf("%d\n", ans / 2);
	}
	return 0;
}