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
	int v;
	bool cut;
	Edge() {}
	Edge(int vv) : v(vv) { cut = 0; }
}Edge;

const int maxn = 5500;
const int maxm = 555011;
int n, m;
int dig[maxn];
int dfn[maxn], low[maxn], idx;
vector<Edge> G[maxn];
bool vis[maxn];
int st[maxn], top;
int belong[maxn], bcnt;

void tarjan(int u, int p) {
	int v;
	low[u] = dfn[u] = ++idx;
	vis[u] = 1;
	st[top++] = u;
	Rep(i, G[u].size()) {
		v = G[u][i].v;
		if(v == p) continue;
		if(!dfn[v]) {
			tarjan(v, u);
			low[u] = min(low[u], low[v]);
			if(low[v] > dfn[u]) {
				G[u][i].cut = 1;
				Rep(j, G[v].size()) {				
					if(G[v][j].v== u) {
						G[v][j].cut = 1;
						break;
					}
				}
			}
		}
		else if(vis[v]) low[u] = min(low[u], dfn[v]);
	}
	if(low[u] == dfn[u]) {
		bcnt++;
		do {
			v = st[--top];
			vis[v] = 0;
			belong[v] = bcnt;
		} while(v != u);
	}
}

int main() {
	// FRead();
	int u, v;
	while(~Rint(n) && ~Rint(m)) {
		Rep(i, n+50) G[i].cl();
		Cls(vis); Cls(dig); Cls(dfn); Cls(low);
		top = 0; idx = 0; bcnt = 0;
		Rep(i, m) {
			Rint(u); Rint(v);
			G[u].pb(Edge(v)); G[v].pb(Edge(u));
		}
		tarjan(1, 0);
		int ret = 0;
		For(u, 1, n+1) {
			Rep(i, G[u].size()) {
				if(G[u][i].cut) {
					dig[belong[u]]++;
				}
			}
		}
		For(i, 1, bcnt+1) {
			if(dig[i] == 1) ret++;
		}
		printf("%d\n", (ret+1)>>1);
	}
	RT 0;
}
