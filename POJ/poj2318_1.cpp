/*
━━━━━┒ギリギリ♂ eye！
┓┏┓┏┓┃キリキリ♂ mind！
┛┗┛┗┛┃＼○／
┓┏┓┏┓┃ /
┛┗┛┗┛┃ノ)
┓┏┓┏┓┃
┛┗┛┗┛┃
┓┏┓┏┓┃
┛┗┛┗┛┃
┓┏┓┏┓┃
┛┗┛┗┛┃
┓┏┓┏┓┃
┃┃┃┃┃┃
┻┻┻┻┻┻
*/
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
#define fr first
#define sc second
#define cl clear
#define BUG puts("here!!!")
#define W(a) while(a--)
#define pb(a) push_back(a)
#define Rint(a) scanf("%d", &a)
#define Rll(a) scanf("%lld", &a)
#define Rs(a) scanf("%s", a)
#define Cin(a) cin >> a
#define FRead() freopen("in", "r", stdin)
#define FWrite() freopen("out", "w", stdout)
#define Rep(i, len) for(int i = 0; i < (len); i++)
#define For(i, a, len) for(int i = (a); i < (len); i++)
#define Cls(a) memset((a), 0, sizeof(a))
#define Clr(a, x) memset((a), (x), sizeof(a))
#define Full(a) memset((a), 0x7f7f, sizeof(a))
#define lrt rt << 1
#define rrt rt << 1 | 1
#define pi 3.14159265359
#define RT return
#define lowbit(x) x & (-x)
#define onenum(x) __builtin_popcount(x)
typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;
typedef pair<int, int> pii;
typedef pair<string, int> psi;
typedef map<string, int> msi;
typedef vector<int> vi;
typedef vector<LL> vl;
typedef vector<vl> vvl;
typedef vector<bool> vb;

typedef struct Point {
	int x, y;
	Point() {}
	Point(int xx, int yy) : x(xx), y(yy) {}
}Point;
typedef struct Line {
	Point a, b;
	Line() {}
	Line(Point aa, Point bb) : a(aa), b(bb) {}
}Line;
const int maxn = 5050;
const int maxm = 5050;
Line line[maxn];
Point s, e;
int n, m;
int ans[maxm];

int ok(Point p, Line l) {
	RT ((l.b.y-l.a.y)*(p.x-l.a.x)-(p.y-l.a.y)*(l.b.x-l.a.x));
}

int main() {
	// FRead();
	int x1, x2;
	bool flag = 1;
	while(~Rint(n) && n) {
		Cls(ans);
		Rint(m); Rint(s.x); Rint(s.y); Rint(e.x); Rint(e.y);
		Rep(i, n) {
			Rint(x1); Rint(x2);
			line[i] = Line(Point(x1, s.y), Point(x2, e.y));
		}
		line[n] = Line(Point(e.x, s.y), e);
		Point p;
		W(m) {
			Rint(p.x); Rint(p.y);
			int l = 0, r = n;
			int ret;
			while(l <= r) {
				int m = (l + r) >> 1;
				if(ok(p, line[m]) > 0) {
					ret = m;
					r = m - 1;
				}
				else l = m + 1;
			}
			ans[ret]++;
		}
		flag ? flag = 0 : printf("\n");
		Rep(i, n+1) printf("%d: %d\n", i, ans[i]);
	}
	RT 0;
}
