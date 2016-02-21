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

template<typename pp>
struct Point {
	pp x;
	pp y;
	Point(){}
	Point(pp xx, pp yy) : x(xx), y(yy) {}
};


template<typename pp>
struct Line {
	Point<pp> u;
	Point<pp> v;
	Line() {}
	Line(Point<pp> uu, Point<pp> vv) : u(uu), v(vv) {}
};

template<typename pp>
pp direction1(Point<pp> p1, Point<pp> p2, Point<pp> p3) { // >0右拐 <0左拐
	return (p3.x-p1.x)*(p2.y-p1.y)-(p2.x-p1.x)*(p3.y-p1.y);
}

template<typename pp>
pp direction2(Point<pp> p1, Point<pp> p2, Point<pp> p3) { // >0右拐 <0左拐
	return (p1.x*p3.y+p1.y*p2.x+p3.x*p2.y)-(p2.x*p3.y+p1.x*p2.y+p1.y*p3.x);
}


const int maxn = 6666;
int n, m;
int ex1, ey1, ex2, ey2;
Line<int> line[maxn];
int ans[maxn];

int main() {
	// freopen("in", "r", stdin);
	int flg = 1;
	while(~scanf("%d", &n) && n) {
		memset(ans, 0, sizeof(ans));
		scanf("%d %d %d %d %d", &m, &ex1, &ey1, &ex2, &ey2);
		int Ui, Li;
		for(int i = 0; i < n; i++) {
			scanf("%d %d", &Ui, &Li);
			line[i] = Line<int>(Point<int>(Ui, ey1), Point<int>(Li, ey2));
		}
		line[n] = Line<int>(Point<int>(ex2, ey1), Point<int>(ex2, ey2));
		int x, y;
		Point<int> p;
		while(m--) {
			scanf("%d %d", &x, &y);
			p = Point<int>(x, y);
			int ll = 0, rr = n;
			int tmp;
			while(ll <= rr) {
				int mm = (ll + rr) >> 1;
				if(direction1<int>(p, line[mm].u, line[mm].v) > 0) {
					tmp = mm;
					rr = mm - 1;
				}
				else ll = mm + 1;
			}
			ans[tmp]++;
		}
		flg ? flg = 0 : printf("\n");
		for(int i = 0; i <= n; i++) {
			printf("%d: %d\n", i, ans[i]);
		}
	}
	return 0;
}