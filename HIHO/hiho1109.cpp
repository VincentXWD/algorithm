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
#define Full(a) memset((a), 0x7f7f7f, sizeof(a))
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
typedef pair<LL, LL> pll;
typedef map<string, int> msi;
typedef vector<int> vi;
typedef vector<LL> vl;
typedef vector<vl> vvl;
typedef vector<bool> vb;

const int maxn = 100100;
const int maxm = 1010000;
typedef struct Edge {
	int u, v, w;
	Edge() {}
	Edge(int uu, int vv, int ww) : u(uu), v(vv), w(ww) {}
	friend bool operator< (Edge a, Edge b) {
		return a.w < b.w;
	}
}Edge;

int n, m;
vector<Edge> e;
int pre[maxn];

int find(int x) { return x == pre[x] ? x : pre[x] = find(pre[x]); }
int unite(int x, int y) {
	x = find(x);
	y = find(y);
	if(x != y) {
		pre[x] = y;
		return 1;
	}
	return 0;
}

int main() {
	// FRead();
	int u, v, w;
	while(~Rint(n) && ~Rint(m)) {
		For(i, 1, n+5) pre[i] = i;
		e.cl();
		Rep(i, m) {
			Rint(u); Rint(v); Rint(w);
			e.pb(Edge(u, v, w));
		}
		int ret = 0;
		sort(e.begin(), e.end());
		Rep(i, m) {
			if(unite(e[i].u, e[i].v)) ret += e[i].w;
		}
		printf("%d\n", ret);
	}
	RT 0;
}