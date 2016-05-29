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
#define lp p << 1
#define rp p << 1 | 1
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

typedef struct Edge {
	int u, v, w;
	int idx, next;
	bool cut;
	Edge() {}
	Edge(int uu, int vv, int ww, int ii) : u(uu), v(vv), w(ww), idx(ii) {}
}Edge;
const int maxn = 1010;
const int maxm = maxn*maxn;
int n, m;
int bridge;
Edge edge[maxm];
int head[maxn];
int dfn[maxn], low[maxn];
int ecnt;
int ret;

void adde(int u, int v, int w, int i) {
	edge[ecnt] = Edge(u, v, w, i);
	edge[ecnt].next = head[u];
	edge[ecnt].cut = 0;
	head[u] = ecnt++;
}

void dfs(int u, int d, int p) {
	low[u] = dfn[u] = d;
	for(int i = head[u]; ~i; i=edge[i].next) {
		int v = edge[i].v;
		int idx = edge[i].idx;
		if(p == idx) continue; 
		if(!dfn[v]) {
			dfs(v, d+1, idx);
			low[u] = min(low[u], low[v]);
			if(low[v] > dfn[u]) {
				bridge++;
				edge[i].cut = edge[i^1].cut = 1;
				ret = min(ret, edge[i].w);
			}
		}
		else low[u] = min(low[u], dfn[v]);
	}
}

int main() {
	// FRead();
	int u, v, w;
	while(~Rint(n) && ~Rint(m) && n + m) {
		Clr(head, -1); Cls(dfn); Cls(low);
		ecnt = 0; bridge = 0; ret = 0x7f7f7f;
		For(i, 1, m+1) {
			Rint(u); Rint(v); Rint(w);
			adde(u, v, w, i); adde(v, u, w, i);
		}
		int cnt = 0;
		For(i, 1, n+1) {
			if(!dfn[i]) {
				cnt++;
				dfs(i, 0, 0);
			}
		}
		if(ret == 0) ret = 1;
		if(ret == 0x7f7f7f) ret = -1;
		if(cnt > 1) ret = 0;
		printf("%d\n", ret);
	}
	RT 0;
}
