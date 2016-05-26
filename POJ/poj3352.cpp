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

const int maxn = 1500;
const int maxm = 5011;
int n, m;
int dig[maxn];
int pre[maxn], dfn[maxn], low[maxn];
vector<int> G[maxn];
bool vis[maxn];

void dfs(int u, int p) {
	vis[u] = 1;
	pre[u] = p;
	dfn[u] = low[u] = u;
	Rep(i, G[u].size()) {
		int v = G[u][i];
		if(!vis[v]) dfs(v, u);
		else if(v != p) low[u] = min(low[u], dfn[v]);
	}
}

void update(int u) {
	int d = low[u];
	while(u != d && u != 0) {
		low[u] = d;
		u = pre[u];
	}
}

int main() {
	// FRead();
	int u, v;
	while(~Rint(n) && ~Rint(m)) {
		Rep(i, n+50) G[i].cl();
		Cls(vis); Cls(dig); Cls(dfn); Cls(low); Cls(pre);
		Rep(i, m) {
			Rint(u); Rint(v);
			G[u].pb(v); G[v].pb(u);
		}
		For(i, 1, n+1) if(!vis[i]) dfs(i, 0);
		For(i, 1, n+1) if(dfn[i] != low[i]) update(i);
		For(u, 1, n+1) {
			Rep(i, G[u].size()) {
				int v = G[u][i];
				if(low[u] != low[v]) {
					dig[low[u]]++; dig[low[v]]++;
				}
			}
		}
		int ret = 0;
		For(i, 1, n+1) dig[i] /= 2;
		For(i, 1, n+1) if(low[i] == i && dig[low[i]] == 1) ret++;
		printf("%d\n", ret % 2 == 0 ? ret / 2 : ret / 2 + 1);
	}
	RT 0;
}
