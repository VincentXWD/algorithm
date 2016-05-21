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
typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;
typedef pair<int, int> pii;
typedef pair<string, int> psi;
typedef map<string, int> msi;
typedef vector<LL> vl;
typedef vector<vl> vvl;
typedef vector<bool> vb;

typedef struct Query {
	int idx;
	int u, v;
	Query() {}
	Query(int uu, int vv, int ii) : u(uu), v(vv), idx(ii) {}
}Query;

typedef struct Edge {
	int v, w;
	Edge() {}
	Edge(int vv, int ww) : v(vv), w(ww) {}
}Edge;

typedef struct Ans {
	int idx;
	int ans;
	Ans() {}
	Ans(int aa, int ii) :ans(aa), idx(ii) {}
}Ans;

const int maxn = 40010;
const int maxm = 222;
int n, m, qcnt, acnt;
int depth[maxn];
int in[maxn];
bool vis[maxn];
int pre[maxn];
Query q[maxm];
Ans ans[maxn];
vector<Edge> G[maxn];
int u, v, w;

int find(int x) {
	return x == pre[x] ? x : pre[x] = find(pre[x]);
}

void unite(int x, int y) {
	x = find(x);
	y = find(y);
	if(x != y) pre[y] = x;
}

void dfs(int u, int d) {
	// pre[u] = u;
	depth[u] = d;
	Rep(i, G[u].size()) {
		int v = G[u][i].v;
		if(!vis[v]) {
			dfs(v, d+G[u][i].w);
			unite(u, v);
		}
	}
	vis[u] = 1;
	Rep(i, qcnt) {
		int uu = q[i].u;
		int vv = q[i].v;
		int idx = q[i].idx;
		if(vis[uu] && vv == u) {
			ans[acnt].idx = idx;
			ans[acnt++].ans = abs(depth[vv] - depth[uu]);
		}
		if(vis[vv] && uu == u) {
			ans[acnt].idx = idx;
			ans[acnt++].ans = abs(depth[uu] - depth[vv]);
		}
	}
}

bool cmp(Ans x, Ans y) {
	return x.idx < y.idx;
}

int main() {
	// FRead();
	int T;
	Rint(T);
	W(T) {
		Rint(n); Rint(m);
		Cls(vis); Cls(depth); Cls(ans); Cls(G);
		acnt = qcnt = 0; Rep(i, n+5) G[i].cl(), pre[i] = i;
		Rep(i, n-1) {
			Rint(u); Rint(v); Rint(w);
			G[u].push_back(Edge(v, w));
			in[v]++;
		}
		Rep(i, m) {
			Rint(u); Rint(v);
			q[qcnt++] = Query(u, v, i);
		}
		For(i, 1, n+1) if(in[i] == 0) dfs(i, 0);
		sort(ans, ans+acnt, cmp);
		Rep(i, acnt) {
			printf("%d\n", ans[i].ans);
		}
	}
	RT 0;
}