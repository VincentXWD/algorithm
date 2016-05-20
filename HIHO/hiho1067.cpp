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
typedef map<int, string> mis;
typedef vector<LL> vl;
typedef vector<vl> vvl;
typedef vector<bool> vb;

const int maxn = 110010;
vector<int> G[maxn];
msi ns;
mis sn;
int n, m, cnt;
string a, b;
int pre[maxn], depth[maxn], in[maxn];

void dfs(int u, int p, int lv) {
	pre[u] = p;
	depth[u] = lv;
	Rep(i, G[u].size()) {
		if(p != G[u][i]) {
			dfs(G[u][i], u, lv+1);
		}
	}
}

int lca(string uu, string vv) {
	int u = ns[uu], v = ns[vv];
	while(depth[u] < depth[v]) v = pre[v];
	while(depth[v] < depth[u]) u = pre[u];
	while(u != v) {
		u = pre[u];
		v = pre[v];
	}
	RT v;
}

int main() {
	// FRead();
	while(~Rint(n)) {
		Rep(i, maxn) G[i].clear();
		cnt = 1; ns.cl(); sn.cl(); Cls(pre); Cls(depth); Cls(in);
		Rep(i, n) {
			Cin(a); Cin(b);
			if(ns.find(a) == ns.end()) ns[a] = cnt, sn[cnt++] = a;
			if(ns.find(b) == ns.end()) ns[b] = cnt, sn[cnt++] = b;
			G[ns[a]].push_back(ns[b]); in[ns[b]]++;
		}
		For(i, 1, n+1) if(in[i] == 0) dfs(i, 0, 0);
		Rint(m);
		W(m) {
			Cin(a); Cin(b);
			int ret = lca(a, b);
			cout << sn[ret] << endl;
		}
	}
	RT 0;
}
